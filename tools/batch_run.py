#!/usr/bin/env python3
"""Match functions through OpenRouter's Batch API (half price, results within 24 h).

The batch API has no live tool loop, so attempts run in rounds: every pending function gets one
request per round; replies are compiled, scored and reference-checked locally; misses go into the
next round with their best code and diff. Prompts stay small (packet + best attempt + last diff).

  tools/batch_run.py NAME --queue Q --model anthropic/claude-haiku-5.5 [--rounds 4] [--limit 500]
                     [--budget 5] [--install]
State lives in build/farm/batch/NAME/ (state.json + attempts), so a run can be stopped and resumed.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
import urllib.error
import urllib.request
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
PY = os.path.join(ROOT, "build/venv/bin/python")
API = "https://openrouter.ai/api/v1/batches"
FORBIDDEN = re.compile(r"\b(__asm|_asm|asm|_emit|__emit)\b|naked|#\s*pragma")
SOFT = {"vftable_of_other_class", "aliased_target", "call_target_not_known_function", "function_address_as_data"}


def log(*a):
    print(time.strftime("%H:%M:%S"), *a, flush=True)


def system_prompt():
    js = "import('%s').then(m => process.stdout.write(m.SYSTEM_PROMPT))" % os.path.join(ROOT, "farm/src/prompt.ts")
    s = subprocess.run(["node", "-e", js], capture_output=True, text=True, check=True).stdout
    s = s.replace("Workflow: call submit_cpp with a complete, self-contained .cpp translation unit. It is compiled",
                  "Workflow: reply with a complete, self-contained .cpp translation unit in one ```cpp block. It is compiled")
    s = s.replace("Respond only with submit_cpp tool calls. No explanations.",
                  "Respond with exactly one ```cpp code block and nothing else.")
    return s


def packet(addr):
    p = os.path.join(ROOT, "build/farm/packets", addr + ".txt")
    if os.path.exists(p):
        return open(p).read()
    return subprocess.run([PY, os.path.join(ROOT, "tools/packet.py"), "show", addr],
                          capture_output=True, text=True).stdout


def clip(s, n):
    return s if len(s) <= n else s[:n] + "\n... (clipped)"


def user_prompt(addr, st, rounds_left):
    text = packet(addr)
    if st.get("best"):
        b = st["best"]
        text += "\nEarlier attempts (score = fraction of instructions matched): %s\n" % ", ".join(
            "%.2f" % h for h in st["scores"])
        text += "Best attempt so far:\n```cpp\n%s\n```\nIts result:\n%s\n" % (clip(b["code"], 8000), clip(b["report"], 4000))
        if st.get("last") and st["last"]["code"] != b["code"]:
            text += "Most recent attempt's result:\n%s\n" % clip(st["last"]["report"], 2000)
        text += "Fix the earliest difference; try a different approach if the score is stuck.\n"
    text += "\n%d attempt(s) left. Reply with the full .cpp in one ```cpp block." % rounds_left
    return text


def http(method, url, key, body=None):
    data = json.dumps(body).encode() if body is not None else None
    req = urllib.request.Request(url, data=data, method=method,
                                 headers={"Authorization": "Bearer " + key, "Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=600) as r:
        return json.load(r)


def run_tool(args):
    r = subprocess.run([PY] + args, capture_output=True, text=True, timeout=300)
    try:
        return json.loads(r.stdout)
    except ValueError:
        return {"status": "tool_error", "report": (r.stdout + r.stderr)[-500:]}


def evaluate(addr, code, path, install):
    with open(path, "w") as f:
        f.write(code)
    if FORBIDDEN.search(code):
        return {"status": "forbidden", "score": 0, "report": "Inline asm, _emit, naked and #pragma are not allowed."}
    r = run_tool([os.path.join(ROOT, "tools/compare.py"), path, addr, "--json"])
    if r.get("status") == "compile_error":
        hint = subprocess.run(["node", "-e", "import('%s').then(m=>process.stdout.write(m.compileHints(process.argv[1])))"
                               % os.path.join(ROOT, "farm/src/hints.ts"), r.get("report", "")],
                              capture_output=True, text=True).stdout
        r["report"] = r.get("report", "") + hint
    if r.get("status") == "match":
        v = run_tool([os.path.join(ROOT, "tools/verify_relocs.py"), path, "--addr", addr, "--json"])
        hard = [i for i in v.get("issues", []) if i[0] not in SOFT]
        if v.get("status") == "ok":
            if install:
                dest = os.path.join(ROOT, "matches", addr + ".cpp")
                if not os.path.exists(dest):
                    with open(dest, "w") as f:
                        f.write(code)
                    subprocess.run([PY, os.path.join(ROOT, "tools/format_matches.py"), dest, "--jobs", "1"],
                                   capture_output=True)
            return {"status": "match", "score": 1.0, "report": "MATCH"}
        return {"status": "bad_refs", "score": 0.99,
                "report": "Code matches but references point at the wrong targets: %s. Fix string literals, "
                          "float constants, or which function/global each reference names." % "; ".join("%s %s" % tuple(i) for i in hard)[:400]}
    return {"status": r.get("status", "error"), "score": r.get("score") or 0.0, "report": r.get("report", "")[:6000]}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("name")
    p.add_argument("--queue", required=True)
    p.add_argument("--model", default="anthropic/claude-haiku-5.5")
    p.add_argument("--rounds", type=int, default=4)
    p.add_argument("--limit", type=int, default=500)
    p.add_argument("--budget", type=float, default=5.0, help="stop when this run's cost reaches $N")
    p.add_argument("--max-tokens", type=int, default=8192)
    p.add_argument("--reasoning", default="low")
    p.add_argument("--poll", type=int, default=60)
    p.add_argument("--install", action="store_true")
    a = p.parse_args()

    key = os.environ.get("OPENROUTER_API_KEY") or subprocess.run(
        ["pi", "auth", "print-api-key", "--provider", "openrouter"], capture_output=True, text=True).stdout.strip()
    d = os.path.join(ROOT, "build/farm/batch", a.name)
    os.makedirs(d, exist_ok=True)
    sp = os.path.join(d, "state.json")
    state = json.load(open(sp)) if os.path.exists(sp) else {"model": a.model, "cost": 0.0, "round": 0, "batch": None, "fns": {}}

    def save():
        tmp = sp + ".tmp"
        json.dump(state, open(tmp, "w"), indent=1)
        os.replace(tmp, sp)

    if not state["fns"]:
        for line in open(a.queue):
            addr = line.split()[0] if line.strip() else ""
            if not addr:
                continue
            addr = "0x%08x" % int(addr, 16)
            if os.path.exists(os.path.join(ROOT, "matches", addr + ".cpp")):
                continue
            state["fns"][addr] = {"status": "pending", "scores": []}
            if len(state["fns"]) >= a.limit:
                break
        save()
    system = system_prompt()

    while True:
        if not state["batch"]:
            pending = [x for x, s in state["fns"].items()
                       if s["status"] == "pending" and not os.path.exists(os.path.join(ROOT, "matches", x + ".cpp"))]
            if state["round"] >= a.rounds or not pending:
                break
            if state["cost"] >= a.budget:
                log("budget $%.2f reached; stopping" % a.budget)
                break
            reqs = [{"custom_id": x, "body": {
                "messages": [{"role": "system", "content": system},
                             {"role": "user", "content": user_prompt(x, state["fns"][x], a.rounds - state["round"])}],
                "max_tokens": a.max_tokens, "reasoning": {"effort": a.reasoning}}} for x in pending]
            body = {"endpoint": "/v1/chat/completions", "model": state["model"] + ":batch", "requests": reqs}
            try:
                b = http("POST", API, key, body)
            except urllib.error.HTTPError as e:
                log("submit failed:", e.code, e.read()[:300])
                sys.exit(1)
            state["batch"] = b["id"]
            save()
            log("round %d: submitted %d requests as %s" % (state["round"] + 1, len(reqs), b["id"]))
        while True:
            try:
                b = http("GET", API + "/" + state["batch"], key)
            except (urllib.error.URLError, TimeoutError) as e:
                log("poll error:", e)
                time.sleep(a.poll)
                continue
            st = b.get("status")
            if st in ("completed", "failed", "expired", "cancelled"):
                break
            c = b.get("request_counts") or {}
            log("  %s %s %s/%s" % (state["batch"], st, c.get("completed"), c.get("total")))
            time.sleep(a.poll)
        if st != "completed":
            log("batch %s ended %s: %s" % (state["batch"], st, str(b.get("error"))[:300]))
        results = b.get("results") or []
        state["cost"] += float((b.get("usage") or {}).get("cost") or 0)  # per-request bodies carry no cost
        rd = state["round"] + 1
        jobs = []
        for res in results:
            addr = res["custom_id"]
            fs = state["fns"][addr]
            body = (res.get("response") or {}).get("body") or {}
            text = ((body.get("choices") or [{}])[0].get("message") or {}).get("content") or ""
            m = re.findall(r"```(?:cpp|c\+\+|c)?\s*\n(.*?)```", text, re.S)
            code = max(m, key=len) if m else ""
            if not code:
                fs["last"] = {"code": "", "report": "No ```cpp block in the reply." if not res.get("error") else "request error"}
                fs["scores"].append(0.0)
                continue
            path = os.path.join(d, addr.replace("0x", "") + "_r%d.cpp" % rd)
            jobs.append((addr, code, path))
        with ThreadPoolExecutor(6) as ex:
            outs = list(ex.map(lambda j: evaluate(j[0], j[1], j[2], a.install), jobs))
        n_match = 0
        for (addr, code, _), r in zip(jobs, outs):
            fs = state["fns"][addr]
            fs["scores"].append(round(r["score"], 3))
            fs["last"] = {"code": code, "report": r["report"]}
            if not fs.get("best") or r["score"] > fs["best"]["score"]:
                fs["best"] = {"code": code, "report": r["report"], "score": r["score"]}
            if r["status"] == "match":
                fs["status"] = "match"
                n_match += 1
        state["round"] = rd
        state["batch"] = None
        save()
        total = sum(1 for s in state["fns"].values() if s["status"] == "match")
        log("round %d: %d/%d matched this round, %d/%d total, run cost $%.3f" % (
            rd, n_match, len(results), total, len(state["fns"]), state["cost"]))
        with open(os.path.join(ROOT, "build/farm/results-batch.jsonl"), "a") as f:
            f.write(json.dumps({"run": a.name, "model": state["model"], "round": rd, "requests": len(results),
                                "matched": n_match, "cost": state["cost"], "t": time.time()}) + "\n")
    total = sum(1 for s in state["fns"].values() if s["status"] == "match")
    log("done: %d/%d matched, $%.3f" % (total, len(state["fns"]), state["cost"]))


if __name__ == "__main__":
    main()
