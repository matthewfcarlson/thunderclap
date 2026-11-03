#!/usr/bin/env python3
"""Android A0 (docs/native-android.md section 12): the game's variadic functions and the TLS uses in the tree.

  build/venv/bin/python tests/android/count_variadics.py [OUT_DIR]     # default build/android/counts

Writes OUT_DIR/variadics.txt (definitions spelled with `...`, and the variadic prototypes the sources declare, with
their call sites by name), OUT_DIR/va_start_idiom.txt (functions that take the address of their last named
parameter: the x86 `va_start` spelling `(char*)&fmt + 4` / `&c + 1` / `&c`, and some harmless uses of a parameter
slot as scratch, to be classified by hand) and OUT_DIR/tls.txt.

Source-level scan (matches/ and equivalent/ are one function per file). Names are the sources' own: a callee declared
under a local alias (`f3`, `Fn`) is counted under that alias, so per-function call counts use the FUN_<addr> name.
"""
import collections
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/android/counts")
SIG = re.compile(r"([A-Za-z_][\w:~]*)\s*\(([^()]*?,\s*)?\.\.\.\s*\)\s*(const\s*)?([{;])", re.S)
DEF = re.compile(r"([A-Za-z_][\w:~<>, ]*?)\s*\(([^()]*)\)\s*(?:const\s*)?\{", re.S)
COMMENT = re.compile(r"//[^\n]*|/\*.*?\*/", re.S)
SCALAR = re.compile(r"\*|\b(int|unsigned|char|short|long|float|double|U_\w+|uint\w*|DWORD|hulk_\w+|size_t|bool)\b")
TLS = re.compile(r"\bthread_local\b|__declspec\s*\(\s*thread\s*\)|\b__thread\b|\b_Thread_local\b|\bTls(Alloc|GetValue|SetValue|Free)\b")


def sources():
    files = {}
    for d in ("matches", "equivalent"):
        for f in sorted(os.listdir(os.path.join(ROOT, d))):
            if f.endswith(".cpp"):
                files["%s/%s" % (d, f)] = COMMENT.sub(" ", open(os.path.join(ROOT, d, f), errors="replace").read())
    return files


def body_of(t, start):
    depth, i = 1, start
    while i < len(t) and depth:
        depth += {"{": 1, "}": -1}.get(t[i], 0)
        i += 1
    return t[start:i]


def addr_of_last_param(files):
    """Definitions whose body passes or offsets the address of their last named (scalar) parameter."""
    hits = []
    for rel, t in files.items():
        for m in DEF.finditer(t):
            params = [p.strip() for p in m.group(2).split(",") if p.strip()]
            variadic = bool(params) and params[-1] == "..."
            named = params[:-1] if variadic else params
            if not named or named[-1] == "void":
                continue
            mm = re.match(r"(.*?)(\w+)\s*$", named[-1])
            if not mm or not mm.group(1).strip() or not SCALAR.search(mm.group(1)):
                continue
            name = mm.group(2)
            body = body_of(t, m.end())
            u = re.search(r"[(,=]\s*(\([^()]*\)\s*)?\(?\s*&\s*\(?\s*%s\b(?!\s*(\.|->|\[))[^;]*" % re.escape(name), body)
            if u:
                fn = m.group(1).split()[-1] if m.group(1).split() else "?"
                hits.append((rel, fn, variadic, re.sub(r"\s+", " ", u.group(0))[:140]))
    return hits


def main():
    files = sources()
    defs, decls = {}, collections.defaultdict(set)
    for rel, text in files.items():
        for m in SIG.finditer(text):
            name = m.group(1).split("::")[-1]
            if name in ("if", "while", "for", "switch", "return", "sizeof", "catch"):
                continue
            (defs.setdefault(name, []).append(rel) if m.group(4) == "{" else decls[name].add(rel))
    names = set(defs) | set(decls)
    calls = collections.defaultdict(list)
    for rel, text in files.items():
        body = SIG.sub(" ", text)
        for n in names:
            k = len(re.findall(r"(?<![\w:])%s\s*\(" % re.escape(n), body))
            if k:
                calls[n].append([rel, k])
    os.makedirs(OUT, exist_ok=True)
    rows = [{"name": n, "defined_in": defs.get(n, []), "declared_in": len(decls[n]), "call_files": len(calls[n]),
             "call_sites": sum(k for _, k in calls[n]), "sites": calls[n]}
            for n in sorted(names, key=lambda n: (n not in defs, -sum(k for _, k in calls[n]), n))]
    json.dump(rows, open(os.path.join(OUT, "variadics.json"), "w"), indent=1)
    with open(os.path.join(OUT, "variadics.txt"), "w") as f:
        for r in rows:
            f.write("%-28s %-5s defs=%-40s call_sites=%d in %d files\n" % (
                r["name"], "DEF" if r["defined_in"] else "decl", ",".join(r["defined_in"]) or "-",
                r["call_sites"], r["call_files"]))
    idiom = addr_of_last_param(files)
    with open(os.path.join(OUT, "va_start_idiom.txt"), "w") as f:
        for rel, fn, variadic, use in idiom:
            a = re.search(r"0x([0-9a-f]{8})", rel).group(1)
            callers = sum(1 for r2, t in files.items() if r2 != rel and re.search(r"\bFUN_%s\b" % a, t))
            f.write("%s %s%s callers_by_addr=%d | %s\n" % (rel, fn, " (...)" if variadic else "", callers, use))
    tls = []
    for d in ("matches", "equivalent", "include", "src"):
        for dp, _, fs in os.walk(os.path.join(ROOT, d)):
            for fn in fs:
                if fn.endswith((".cpp", ".h", ".c", ".hpp", ".s", ".S", ".inc")):
                    p = os.path.join(dp, fn)
                    for i, line in enumerate(open(p, errors="replace"), 1):
                        if TLS.search(line):
                            tls.append("%s:%d:%s" % (os.path.relpath(p, ROOT), i, line.rstrip()))
    open(os.path.join(OUT, "tls.txt"), "w").write("\n".join(tls) + "\n")
    nd = [r for r in rows if r["defined_in"]]
    print("definitions spelled with `...`: %d" % len(nd))
    print("variadic prototypes only declared: %d names, %d call sites by those names"
          % (len(rows) - len(nd), sum(r["call_sites"] for r in rows if not r["defined_in"])))
    print("address-of-last-parameter candidates: %d (va_start_idiom.txt, classify by hand)" % len(idiom))
    print("TLS lines: %d (%s)" % (len(tls), ", ".join(sorted({t.split(":")[0] for t in tls}))))


if __name__ == "__main__":
    main()
