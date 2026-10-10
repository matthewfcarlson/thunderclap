#!/usr/bin/env python3
"""Export farm transcripts (pi-durable snapshot) into SFT/RL datasets.

Reads a farm.sqlite snapshot, rebuilds each job doc from its base+delta revisions,
reconstructs matched conversations, verifies winners against matches/, and writes:

  dataset/raw/<addr>-t<tier>.json   verbatim per-conversation export (optional)
  dataset/hulk-sft-v1.jsonl         curated chat examples (multi-turn, thinking kept)
  dataset/grpo-prompts-v1.jsonl     one prompt per unique function (for RL, reward = compare.py)
  dataset/stats-v1.json             counts, thinking coverage, sizes, splits

Usage:
  build/venv/bin/python tools/export_dataset.py [--db build/farm/dataset/farm-snapshot.sqlite]
"""
import argparse
import hashlib
import re
import json
import os
import sqlite3
from collections import Counter, defaultdict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SNAPSHOT = os.path.join(ROOT, "build/farm/dataset/farm-snapshot.sqlite")
MATCHES = os.path.join(ROOT, "matches")
PACKETS = os.path.join(ROOT, "build/farm/packets")

# Deltas are arrays of ops: ["s",path,val] set, ["a",path,val] append,
# ["t",path,n] truncate string/list to n.
def apply_ops(state, ops):
    for op in ops:
        p = op[1][0]
        if op[0] == "s":
            state[p] = op[2]
        elif op[0] == "a":
            cur = state.get(p, "")
            state[p] = cur + op[2] if isinstance(cur, str) else op[2]
        elif op[0] == "t":
            state[p] = (state.get(p, "") or "")[: op[2]]
        else:
            raise ValueError(f"unknown delta op {op[0]!r}")
    return state


def load_jobs(db):
    """job_id -> final state (addr, tier, attempts, status, bestScore, bestCode...)."""
    jobs = {}
    for did, rec in db.execute("SELECT id, record FROM documents WHERE kind='\"hulk.job\"'"):
        meta = json.loads(rec)
        state = None
        for k, c in db.execute(
            "SELECT kind, content FROM document_revisions WHERE document_id=? ORDER BY seq", (did,)
        ):
            if k == "base":
                state = json.loads(c)
            else:
                state = apply_ops(state, json.loads(c))
        if state:
            state["_cid"] = meta.get("scope", {}).get("conversationId")
            jobs[did] = state
    return jobs


def load_conversation(db, cid):
    """entries in id order -> dict(kind -> records)."""
    out = []
    for (r,) in db.execute("SELECT record FROM entries WHERE conversation_id=? ORDER BY id", (cid,)):
        out.append(json.loads(r))
    return out


def system_text(entry):
    rec = entry.get("model") or [{}]
    c = rec[0].get("content")
    if isinstance(c, str) and c:
        return c
    sections = (c or {}).get("sections") if isinstance(c, dict) else None
    if sections:
        return sections.get("preamble", "") or ""
    return ""


def user_text(entry):
    rec = entry.get("model") or [{}]
    c = rec[0].get("content", "")
    return c if isinstance(c, str) else ""


def tool_result_text(entry):
    rec = entry.get("model") or [{}]
    blocks = rec[0].get("content") or []
    for b in blocks:
        if b.get("type") == "text":
            return b.get("text", "")
    return ""


def build_example(job, entries, addr, tier, max_turns):
    """Curated chat example from one matched conversation, or None."""
    system = next((system_text(e) for e in entries if e["kind"] == "pi.system"), "")
    packet = next((user_text(e) for e in entries if e["kind"] == "pi.user"), "")
    if not packet:
        return None

    # pair each submit_cpp toolCall with its result (by id, in order)
    tool_by_id = {}
    for e in entries:
        if e["kind"] != "pi.tool-result":
            continue
        rec = (e.get("model") or [{}])[0]
        call_id = rec.get("toolCallId")
        if call_id:
            tool_by_id[call_id] = tool_result_text(e)
        else:
            tool_by_id.setdefault(f"__seq{len(tool_by_id)}", tool_result_text(e))

    turns = []  # (thinking, [toolCalls], [toolResults])
    for e in entries:
        if e["kind"] != "pi.assistant":
            continue
        rec = (e.get("model") or [{}])[0]
        blocks = rec.get("content")
        if not isinstance(blocks, list):
            continue
        thinking = "\n".join(b.get("thinking", "") for b in blocks if b.get("type") == "thinking")
        text = "\n".join(b.get("text", "") for b in blocks if b.get("type") == "text")
        calls = [
            {"id": b.get("id"), "name": b.get("name"), "arguments": b.get("arguments")}
            for b in blocks
            if b.get("type") == "toolCall"
        ]
        if not thinking and not text and not calls:
            continue  # empty keepalive/resume turn
        results = [tool_by_id.get(c["id"], "") for c in calls]
        turns.append({"thinking": thinking, "text": text, "calls": calls, "results": results})

    turns = [t for t in turns if t["calls"]]
    if not turns:
        return None
    if len(turns) > max_turns:
        turns = turns[-max_turns:]  # keep the most recent diff-feedback chain

    msgs = [{"role": "system", "content": system}, {"role": "user", "content": packet}]
    for t in turns:
        m = {"role": "assistant", "content": t["text"]}
        if t["thinking"]:
            m["reasoning"] = t["thinking"]
        if t["calls"]:
            m["tool_calls"] = [
                {"name": c["name"], "arguments": c["arguments"]} for c in t["calls"]
            ]
        msgs.append(m)
        for r in t["results"]:
            msgs.append({"role": "tool", "content": r})

    code = turns[-1]["calls"][-1]["arguments"].get("code", "")
    return {
        "id": f"{addr}:t{tier}",
        "addr": addr,
        "tier": tier,
        "model": (entries and [(e.get("model") or [{}])[0] for e in entries if e["kind"] == "pi.assistant"] or [{}])[0].get("model"),
        "attempts": len(turns),
        "size_bytes": None,  # filled by caller from packet
        "messages": msgs,
        "winner_code": code,
        "has_thinking": any("reasoning" in m for m in msgs),
    }


def packet_size(packet):
    line = packet.split("\n", 1)[0]
    if "(" in line and line.rstrip().endswith(")"):
        inner = line[line.rfind("(") + 1 : -1].strip()
        if inner.endswith("bytes"):
            try:
                return int(inner[:-5].strip())
            except ValueError:
                return None
    return None


def squash(s):
    return re.sub(r"\s+", "", s)


def strip_comments(s):
    return re.sub(r"//[^\n]*|/\*.*?\*/", "", s, flags=re.S)


def split_of(addr):
    h = int(hashlib.md5(addr.encode()).hexdigest()[:8], 16) % 100
    return "test" if h >= 98 else "val" if h >= 96 else "train"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--db", default=SNAPSHOT)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/farm/dataset"))
    ap.add_argument("--max-turns", type=int, default=6)
    ap.add_argument("--skip-raw", action="store_true")
    args = ap.parse_args()

    os.makedirs(os.path.join(args.out, "raw"), exist_ok=True)
    db = sqlite3.connect(f"file:{args.db}?mode=ro", uri=True)
    jobs = load_jobs(db)
    print(f"jobs: {len(jobs)}")

    matched = [j for j in jobs.values() if j.get("status") == "match" and j.get("_cid")]
    print(f"matched with conversation: {len(matched)}")

    # one example per (addr,tier); prefer conversations with thinking on packet duplicates
    per_addr = defaultdict(list)
    for j in matched:
        per_addr[j["addr"]].append(j)

    sft, stats = [], Counter()
    winner_ok = winner_bad = 0
    for addr, group in sorted(per_addr.items()):
        cands = []
        for j in group:
            entries = load_conversation(db, j["_cid"])
            ex = build_example(j, entries, addr, j.get("tier", 0), args.max_turns)
            if not ex:
                stats["skipped_no_transcript"] += 1
                continue
            ex["size_bytes"] = packet_size(ex["messages"][1]["content"])
            cands.append((ex, entries, j))
        if not cands:
            continue
        # prefer one with thinking, then fewest turns
        cands.sort(key=lambda x: (not x[0]["has_thinking"], x[0]["attempts"]))
        ex, entries, job = cands[0]
        stats["skipped_duplicate_addr"] += len(cands) - 1

        # Cross-check winner against matches/<addr>.cpp. The authoritative match
        # proof is the farm's own compare.py verdict (status==match, score 1.0);
        # matches/ is often clang-formatted or hand-curated afterwards.
        #   exact | formatting_only (whitespace-insensitive) | comments_only |
        #   curated_diff (a later, differently-written variant) | no_file
        path = os.path.join(MATCHES, f"{addr}.cpp")
        if os.path.exists(path):
            target = open(path).read()
            if target == ex["winner_code"]:
                ex["matches_variant"] = "exact"
            elif squash(target) == squash(ex["winner_code"]):
                ex["matches_variant"] = "formatting_only"
            elif squash(strip_comments(target)) == squash(strip_comments(ex["winner_code"])):
                ex["matches_variant"] = "comments_only"
            else:
                ex["matches_variant"] = "curated_diff"
        else:
            ex["matches_variant"] = "no_file"
        winner_ok += ex["matches_variant"] in ("exact", "formatting_only", "comments_only")
        winner_bad += ex["matches_variant"] == "curated_diff"
        ex["score"] = j_best = max(
            (h.get("score", -1) for h in (job.get("history") or [])), default=1
        )
        ex["split"] = split_of(addr)
        sft.append(ex)
        if not args.skip_raw:
            with open(os.path.join(args.out, "raw", f"{addr}-t{ex['tier']}.json"), "w") as f:
                json.dump({"addr": addr, "tier": ex["tier"], "entries": entries}, f, indent=1)

    # RL prompt set: every function that has a packet (reward = tools/compare.py score)
    grpo = []
    matched_addrs = {ex["addr"] for ex in sft}
    if os.path.isdir(PACKETS):
        for fn in sorted(os.listdir(PACKETS)):
            if not fn.endswith(".txt"):
                continue
            addr = fn[:-4]
            packet = open(os.path.join(PACKETS, fn)).read()
            grpo.append(
                {
                    "addr": addr,
                    "prompt": packet,
                    "matched": addr in matched_addrs,
                    "size_bytes": packet_size(packet),
                }
            )

    sft_path = os.path.join(args.out, "hulk-sft-v1.jsonl")
    with open(sft_path, "w") as f:
        for ex in sft:
            f.write(json.dumps(ex) + "\n")
    grpo_path = os.path.join(args.out, "grpo-prompts-v1.jsonl")
    with open(grpo_path, "w") as f:
        for r in grpo:
            f.write(json.dumps(r) + "\n")

    def approx_tokens(s):
        return len(s) // 4

    split_counts = Counter(ex["split"] for ex in sft)
    think = sum(ex["has_thinking"] for ex in sft)
    attempts_hist = Counter(ex["attempts"] for ex in sft)
    sizes = sorted(ex["size_bytes"] for ex in sft if ex["size_bytes"] is not None)
    tok = [approx_tokens(json.dumps(ex["messages"])) for ex in sft]
    stats_out = {
        "sft_examples": len(sft),
        "with_thinking": think,
        "thinking_pct": round(100 * think / max(len(sft), 1), 1),
        "matches_check": dict(Counter(ex["matches_variant"] for ex in sft)),
        "split_counts": dict(split_counts),
        "attempts_hist": dict(sorted(attempts_hist.items())),
        "size_bytes_p50": sizes[len(sizes) // 2] if sizes else None,
        "size_bytes_max": sizes[-1] if sizes else None,
        "est_tokens_p50": sorted(tok)[len(tok) // 2] if tok else None,
        "est_tokens_p95": sorted(tok)[int(len(tok) * 0.95)] if tok else None,
        "est_tokens_total": sum(tok),
        "grpo_prompts": len(grpo),
        "grpo_unmatched": sum(1 for r in grpo if not r["matched"]),
        "skipped": dict(stats),
    }
    with open(os.path.join(args.out, "stats-v1.json"), "w") as f:
        json.dump(stats_out, f, indent=1)
    print(json.dumps(stats_out, indent=1))


if __name__ == "__main__":
    main()
