#!/usr/bin/env python3
"""Export farm transcripts (pi-durable snapshot) into SFT/RL datasets.

Reads a farm.sqlite snapshot, rebuilds each job doc from its base+delta revisions,
reconstructs matched conversations, verifies winners against matches/, and writes:

  dataset/raw/<addr>-t<tier>.json   verbatim per-conversation export (optional)
  dataset/hulk-sft-v1.jsonl         curated chat examples (multi-turn, thinking kept)
  dataset/hulk-matches-v1.jsonl     one-turn examples for every other verified match in
                                    matches/ (packet -> submit_cpp(match)), no transcript needed
  dataset/grpo-prompts-v1.jsonl     one prompt per unique function (for RL, reward = compare.py)
  dataset/stats-v1.json             counts, thinking coverage, sizes, splits

Usage:
  build/venv/bin/python tools/export_dataset.py [--db build/farm/dataset/farm-snapshot.sqlite]
"""
import argparse
import glob
import hashlib
import re
import json
import os
import sqlite3
from collections import Counter, defaultdict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SNAPSHOT = os.path.join(ROOT, "build/farm/dataset/farm-snapshot.sqlite")
MATCHES = os.path.join(ROOT, "matches")
EQUIVALENT = os.path.join(ROOT, "equivalent")
LANE_DBS = os.path.join(ROOT, "build/farm/lanes/*.sqlite")
PACKETS = os.path.join(ROOT, "build/farm/packets")
MATCH_PACKETS = os.path.join(ROOT, "build/farm/dataset/packets-matches")  # tools/packet.py build output
PROMPT_TS = os.path.join(ROOT, "farm/src/prompt.ts")

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
    # pi keeps the preamble in the record's own sections (content is "")
    sections = rec[0].get("sections") or ((c or {}).get("sections") if isinstance(c, dict) else None)
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


def farm_system_prompt(name="SYSTEM_PROMPT"):
    """SYSTEM_PROMPT / EQUIV_SYSTEM_PROMPT from farm/src/prompt.ts (plain template literals)."""
    src = open(PROMPT_TS).read()
    start = src.index(f"export const {name} = `") + len(f"export const {name} = `")
    return src[start: src.index("`;", start)]


MATCH_NOISE = re.compile(r"^// (Same code shape as .*|Target: .*|STATUS: .*)\n", re.M)


def match_examples(transcript_codes, attempts, task="match"):
    """One-turn examples from matches/ (or equivalent/) for functions without a transcript example.

    The packet is rebuilt by tools/packet.py (build/farm/packets, else MATCH_PACKETS:
      tools/packet.py build --queue <addrs> --out build/farm/dataset/packets-matches).
    Propagated matches ("Same code shape as ...") repeat another function's code under
    another address: identical code is kept once, so the set doesn't overweight them.
    """
    system = farm_system_prompt("EQUIV_SYSTEM_PROMPT" if task == "equiv" else "SYSTEM_PROMPT")
    src_dir = EQUIVALENT if task == "equiv" else MATCHES
    seen = set(transcript_codes)
    out, stats = [], Counter()
    for fn in sorted(os.listdir(src_dir)):
        if not fn.endswith(".cpp"):
            continue
        addr = fn[:-4]
        if addr in attempts:
            stats["has_transcript"] += 1
            continue
        code = open(os.path.join(src_dir, fn)).read()
        if task == "match" and "STATUS: equivalent" in code:
            stats["equivalent_not_match"] += 1
            continue
        code = MATCH_NOISE.sub("", code).strip() + "\n"
        key = squash(strip_comments(code))
        if key in seen:
            stats["duplicate_code"] += 1
            continue
        packet_path = next((p for p in (os.path.join(PACKETS, addr + ".txt"), os.path.join(MATCH_PACKETS, addr + ".txt"))
                            if os.path.exists(p)), None)
        if not packet_path:
            stats["no_packet"] += 1
            continue
        seen.add(key)
        packet = open(packet_path).read()
        out.append({
            "id": f"{addr}:{'e' if task == 'equiv' else 'm'}",
            "addr": addr,
            "source": "equivalent" if task == "equiv" else "matches",
            "task": task,
            "tier": None,
            "model": None,
            "attempts": 1,
            "size_bytes": packet_size(packet),
            "messages": [
                {"role": "system", "content": system},
                # farm/src/prompt.ts taskPrompt: packet + "\nYou have N submissions..."
                {"role": "user", "content": packet + "\nYou have 8 submissions. Call submit_cpp now."},
                {"role": "assistant", "content": "", "tool_calls": [{"name": "submit_cpp", "arguments": {"code": code}}]},
            ],
            "winner_code": code,
            "has_thinking": False,
            "matches_variant": "exact",
            "score": 1,
            "split": split_of(addr),
        })
    return out, dict(stats)


def winner_variant(path, code):
    """How the transcript's winning code relates to the committed file:
    exact | formatting_only (whitespace-insensitive) | comments_only |
    curated_diff (a later, differently-written variant) | no_file"""
    if not os.path.exists(path):
        return "no_file"
    target = MATCH_NOISE.sub("", open(path).read())
    code = MATCH_NOISE.sub("", code)
    if target.strip() == code.strip():
        return "exact"
    if squash(target) == squash(code):
        return "formatting_only"
    if squash(strip_comments(target)) == squash(strip_comments(code)):
        return "comments_only"
    return "curated_diff"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--db", nargs="*", default=None,
                    help="pi-durable transcript DBs (default: the snapshot + every build/farm/lanes/*.sqlite)")
    ap.add_argument("--out", default=os.path.join(ROOT, "build/farm/dataset"))
    ap.add_argument("--max-turns", type=int, default=6)
    ap.add_argument("--skip-raw", action="store_true")
    ap.add_argument("--no-matches", action="store_true", help="skip hulk-matches-v1.jsonl")
    args = ap.parse_args()
    dbs = args.db if args.db is not None else [SNAPSHOT] + sorted(glob.glob(LANE_DBS))

    os.makedirs(os.path.join(args.out, "raw"), exist_ok=True)
    # Successful jobs from every DB. Lanes and the snapshot can hold the same function;
    # one example per (addr, task) is kept below. task: match (byte-identical, --mode match)
    # or equiv (behaviour-equivalent, --mode equiv; its transcript carries EQUIV_SYSTEM_PROMPT).
    done = []
    for path in dbs:
        db = sqlite3.connect(f"file:{path}?mode=ro", uri=True)
        try:
            jobs = load_jobs(db)
        except sqlite3.DatabaseError as e:
            print(f"{os.path.basename(path)}: skipped ({e})")
            continue
        ok = [j for j in jobs.values() if j.get("status") in ("match", "equivalent") and j.get("_cid")]
        print(f"{os.path.basename(path)}: {len(jobs)} jobs, {len(ok)} successful with conversation")
        done += [(db, j) for j in ok]

    per_addr = defaultdict(list)
    for db, j in done:
        per_addr[(j["addr"], "equiv" if j["status"] == "equivalent" else "match")].append((db, j))

    sft, stats = [], Counter()
    for (addr, task), group in sorted(per_addr.items()):
        cands = []
        for db, j in group:
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
        ex["task"] = task
        if task == "equiv":
            ex["id"] = f"{addr}:e{ex['tier']}"

        # Cross-check the winner against the committed file. The authoritative proof is the
        # farm's own verdict (compare.py match / equiv.py level 3); committed files are often
        # clang-formatted or hand-curated afterwards.
        ex["matches_variant"] = winner_variant(os.path.join(EQUIVALENT if task == "equiv" else MATCHES, f"{addr}.cpp"),
                                               ex["winner_code"])
        ex["score"] = max((h.get("score", -1) for h in (job.get("history") or [])), default=1)
        ex["split"] = split_of(addr)
        sft.append(ex)
        if not args.skip_raw:
            with open(os.path.join(args.out, "raw", f"{ex['id'].replace(':', '-')}.json"), "w") as f:
                json.dump({"addr": addr, "tier": ex["tier"], "task": task, "entries": entries}, f, indent=1)

    # RL prompt set: every function that has a packet (reward = tools/compare.py score)
    grpo = []
    matched_addrs = {ex["addr"] for ex in sft if ex["task"] == "match"}
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
        "sft_by_task": dict(Counter(ex["task"] for ex in sft)),
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
    if not args.no_matches:
        # one-turn examples for committed functions without a transcript; equiv examples need
        # packets for their (larger) functions: tools/packet.py build --out MATCH_PACKETS
        for task, name in (("match", "hulk-matches-v1.jsonl"), ("equiv", "hulk-equiv-v1.jsonl")):
            have = [ex for ex in sft if ex["task"] == task]
            mex, mstats = match_examples({squash(strip_comments(MATCH_NOISE.sub("", ex["winner_code"]))) for ex in have},
                                         {ex["addr"] for ex in have}, task)
            with open(os.path.join(args.out, name), "w") as f:
                for ex in mex:
                    f.write(json.dumps(ex) + "\n")
            stats_out[f"{task}_files_examples"] = len(mex)
            stats_out[f"{task}_files_split_counts"] = dict(Counter(ex["split"] for ex in mex))
            stats_out[f"{task}_files_skipped"] = mstats
    with open(os.path.join(args.out, "stats-v1.json"), "w") as f:
        json.dump(stats_out, f, indent=1)
    print(json.dumps(stats_out, indent=1))


if __name__ == "__main__":
    main()
