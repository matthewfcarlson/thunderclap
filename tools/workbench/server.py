#!/usr/bin/env python3
"""Local matching workbench: edit C++, see the aligned assembly diff, auto-install verified matches.

  build/venv/bin/python tools/workbench/server.py [--port 8765] [--host 127.0.0.1] [--no-push]
then open http://127.0.0.1:8765

A byte-identical, reference-verified result is copied to matches/, formatted, committed (that file
only) and pushed. Work in progress is saved to build/workbench/<addr>.cpp on every compile.
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
ROOT = os.path.dirname(TOOLS)
sys.path.insert(0, TOOLS)
from compare import compare, target_bytes, _md  # noqa: E402
from packet import Db  # noqa: E402

PY = os.path.join(ROOT, "build/venv/bin/python")
WORK = os.path.join(ROOT, "build/workbench")
FORBIDDEN = re.compile(r"\b(__asm|_asm|asm|_emit|__emit)\b|naked|#\s*pragma")
SOFT = {"vftable_of_other_class", "aliased_target", "call_target_not_known_function", "function_address_as_data"}
os.makedirs(WORK, exist_ok=True)

compile_lock = threading.Lock()   # capstone/compile helpers share module state
git_lock = threading.Lock()
OPTS = {"push": True}


def log(*a):
    print(time.strftime("%H:%M:%S"), *a, flush=True)


# ---------------------------------------------------------------- function index

def load_index():
    db = Db()
    best, tries = {}, {}

    def note(a, s):
        if a and isinstance(s, (int, float)):
            best[a] = max(best.get(a, 0), s)
            tries[a] = tries.get(a, 0) + 1
    for p in glob.glob(os.path.join(ROOT, "build/farm/results*.jsonl")) + glob.glob(os.path.join(ROOT, "build/farm/lanes/*.jsonl")):
        for l in open(p):
            try:
                r = json.loads(l)
            except ValueError:
                continue
            note(r.get("addr"), r.get("bestScore"))
    for p in glob.glob(os.path.join(ROOT, "build/farm/agents/*.jsonl")) + [os.path.join(ROOT, "build/farm/permute/log.jsonl")]:
        if not os.path.exists(p):
            continue
        for l in open(p):
            try:
                r = json.loads(l)
            except ValueError:
                continue
            note(r.get("addr"), r.get("best_score", r.get("best")))
    fns = []
    for r in db.funcs.values():
        if not db.is_game(r):
            continue
        a = "0x%08x" % int(r["address"], 16)
        fns.append({"addr": a, "name": r["name"], "size": int(r["size"]), "best": round(best.get(a, -1), 3),
                    "tries": tries.get(a, 0)})
    return db, fns


DB, FUNCS = load_index()


def matched(a):
    return os.path.exists(os.path.join(ROOT, "matches", a + ".cpp"))


# ---------------------------------------------------------------- per-function data

def packet_text(a):
    p = os.path.join(ROOT, "build/farm/packets", a + ".txt")
    if os.path.exists(p):
        return open(p).read()
    r = subprocess.run([PY, os.path.join(TOOLS, "packet.py"), "show", a], capture_output=True, text=True, cwd=ROOT)
    return r.stdout or r.stderr


def attempt_files(a):
    pats = ["build/farm/work/*/%s/*.cpp" % a, "build/farm/agent-work/*/%s_*.cpp" % a,
            "build/farm/batch/*/%s_*.cpp" % a[2:], "build/farm/permute/%s/best.cpp" % a]
    files = []
    for p in pats:
        files += glob.glob(os.path.join(ROOT, p))
    return sorted(files, key=os.path.getmtime, reverse=True)


def score_file(path, addr):
    try:
        r = compare(path, addr)
    except Exception:
        return -1.0
    return 1.0 if r.get("status") == "match" else (r.get("score") or 0.0)


def starting_source(a):
    """Saved workbench edit > best-scoring earlier attempt (recent 16) > a stub."""
    mine = os.path.join(WORK, a + ".cpp")
    files = attempt_files(a)[:16]
    origin, src, score = None, None, -1.0
    if files:
        with ThreadPoolExecutor(6) as ex:
            scores = list(ex.map(lambda f: score_file(f, int(a, 16)), files))
        i = max(range(len(files)), key=lambda k: scores[k])
        origin, src, score = os.path.relpath(files[i], ROOT), open(files[i]).read(), scores[i]
    base = {"origin": origin, "source": src, "score": score}
    if os.path.exists(mine):
        return {"origin": "build/workbench/%s.cpp (your saved edit)" % a, "source": open(mine).read(),
                "score": None, "base": base}
    if src is None:
        src = "// No earlier attempt. See the Context tab for Ghidra's decompilation.\n\nvoid Fn()\n{\n}\n"
        base = {"origin": None, "source": src, "score": None}
    return dict(base, base=base)


def target_asm(a):
    tname, data = target_bytes(int(a, 16))
    with compile_lock:
        return tname, ["%04x  %s %s" % (i.address, i.mnemonic, i.op_str) for i in _md.disasm(data, 0)]


# ---------------------------------------------------------------- compile / verify / install

def compile_hints(report):
    js = "import('%s').then(m=>process.stdout.write(m.compileHints(process.argv[1])))" % os.path.join(ROOT, "farm/src/hints.ts")
    try:
        return subprocess.run(["node", "-e", js, report], capture_output=True, text=True, timeout=30).stdout
    except Exception:
        return ""


def run_compare(a, source):
    path = os.path.join(WORK, a + ".cpp")
    with open(path, "w") as f:
        f.write(source)
    if FORBIDDEN.search(source):
        return {"status": "forbidden", "error": "Inline asm, _emit, naked and #pragma are not allowed in matches."}
    with compile_lock:
        r = compare(path, int(a, 16))
    if r["status"] == "compile_error":
        r["error"] += compile_hints(r["error"])
    return r


def verify(a, path):
    from verify_relocs import check
    with compile_lock:
        v = check(path, int(a, 16))
    hard = [i for i in v.get("issues", []) if i[0] not in SOFT]
    return v.get("status") == "ok", ["%s %s" % tuple(i) for i in v.get("issues", [])], hard


def git(*args):
    return subprocess.run(["git"] + list(args), cwd=ROOT, capture_output=True, text=True)


def install(a, source, who="workbench"):
    dest = os.path.join(ROOT, "matches", a + ".cpp")
    with open(dest, "w") as f:
        f.write(source)
    subprocess.run([PY, os.path.join(TOOLS, "format_matches.py"), dest, "--jobs", "1"], capture_output=True, cwd=ROOT)
    name = next((f["name"] for f in FUNCS if f["addr"] == a), a)

    def commit():
        with git_lock:
            msg = ("Match %s %s (%s)\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n"
                   "Claude-Session: https://claude.ai/code/session_01DM8Bn5TvuystUL5qBzT4rA" % (a, name, who))
            for _ in range(10):  # farm lanes commit too; wait out their index lock
                git("add", "matches/%s.cpp" % a)
                r = git("commit", "-q", "-m", msg, "--", "matches/%s.cpp" % a)
                if r.returncode == 0 or "nothing to commit" in r.stdout + r.stderr:
                    break
                time.sleep(3)
            if OPTS["push"]:
                for _ in range(3):
                    if git("pull", "-q", "--rebase", "--autostash", "origin", "main").returncode == 0 and \
                            git("push", "-q").returncode == 0:
                        break
                    time.sleep(5)
            log("committed", a, name)
    threading.Thread(target=commit, daemon=True).start()


def compile_and_maybe_install(a, source):
    r = run_compare(a, source)
    out = {k: r.get(k) for k in ("status", "error", "score", "matched", "total", "target_bytes", "our_bytes", "symbol", "target")}
    out["rows"] = r.get("rows", [])
    if r.get("status") == "match":
        if matched(a):
            out["installed"] = "already"
        else:
            ok, issues, hard = verify(a, os.path.join(WORK, a + ".cpp"))
            out["issues"] = issues
            if ok:
                install(a, source)
                out["installed"] = True
                for f in FUNCS:
                    if f["addr"] == a:
                        f["best"] = 1.0
            else:
                out["status"] = "bad_refs"
                out["error"] = ("Bytes match, but references point at the wrong targets: %s. Fix string literals, float "
                                "constants, or which function/global each reference names." % "; ".join(hard))
    return out


def run_permute(a, source, seconds):
    from permute import permute
    path = os.path.join(WORK, a + ".perm-in.cpp")
    with open(path, "w") as f:
        f.write(source)
    result, text, score = permute(path, int(a, 16), seconds / 60.0, 4, False, log=lambda m: log("permute", m))
    out = {"result": result, "source": text, "score": score}
    if result == "match":
        out.update(compile_and_maybe_install(a, text))
    return out


# ---------------------------------------------------------------- HTTP

class H(BaseHTTPRequestHandler):
    def log_message(self, fmt, *args):
        pass

    def send(self, code, body, ctype="application/json"):
        data = body if isinstance(body, bytes) else (json.dumps(body) if ctype == "application/json" else body).encode()
        self.send_response(code)
        self.send_header("Content-Type", ctype + "; charset=utf-8")
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(data)

    def addr(self, q):
        a = (q.get("addr") or [""])[0]
        if not re.fullmatch(r"0x[0-9a-fA-F]{1,8}", a or ""):
            raise ValueError("bad addr")
        return "0x%08x" % int(a, 16)

    def do_GET(self):
        u = urlparse(self.path)
        q = parse_qs(u.query)
        try:
            if u.path in ("/", "/index.html"):
                return self.send(200, open(os.path.join(HERE, "index.html"), "rb").read(), "text/html")
            if u.path == "/api/functions":
                return self.send(200, [f for f in FUNCS if not matched(f["addr"])] if q.get("all") is None else FUNCS)
            if u.path == "/api/function":
                a = self.addr(q)
                tname, asm = target_asm(a)
                fn = next((f for f in FUNCS if f["addr"] == a), {})
                return self.send(200, {"addr": a, "name": tname, "size": fn.get("size"), "matched": matched(a),
                                       "asm": asm, "packet": packet_text(a), "start": starting_source(a),
                                       "attempts": [os.path.relpath(p, ROOT) for p in attempt_files(a)][:40]})
            if u.path == "/api/attempt":
                p = os.path.realpath(os.path.join(ROOT, (q.get("path") or [""])[0]))
                if not p.startswith(os.path.join(ROOT, "build", "")) or not p.endswith(".cpp"):
                    return self.send(403, {"error": "forbidden path"})
                return self.send(200, {"source": open(p).read()})
            return self.send(404, {"error": "not found"})
        except Exception as e:
            return self.send(500, {"error": repr(e)[:400]})

    def do_POST(self):
        u = urlparse(self.path)
        try:
            body = json.loads(self.rfile.read(int(self.headers.get("Content-Length") or 0)) or b"{}")
            a = self.addr({"addr": [body.get("addr", "")]})
            src = body.get("source", "")
            if len(src) > 200_000:
                return self.send(400, {"error": "source too large"})
            if u.path == "/api/compile":
                return self.send(200, compile_and_maybe_install(a, src))
            if u.path == "/api/permute":
                return self.send(200, run_permute(a, src, max(10, min(600, int(body.get("seconds", 60))))))
            return self.send(404, {"error": "not found"})
        except Exception as e:
            return self.send(500, {"error": repr(e)[:400]})


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--host", default="127.0.0.1")
    p.add_argument("--port", type=int, default=8765)
    p.add_argument("--no-push", action="store_true", help="commit matches locally but don't push")
    a = p.parse_args()
    OPTS["push"] = not a.no_push
    log("workbench: %d game functions, %d unmatched; http://%s:%d" % (
        len(FUNCS), sum(1 for f in FUNCS if not matched(f["addr"])), a.host, a.port))
    ThreadingHTTPServer((a.host, a.port), H).serve_forever()


if __name__ == "__main__":
    main()
