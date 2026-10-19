#!/usr/bin/env python3
"""clang-format equivalent/ sources, keeping a formatted file only if it compiles to the same object code.

  tools/format_equivalents.py equivalent/0x000835a0.cpp ...   # specific files
  tools/format_equivalents.py --all [--jobs 8]                # every file in equivalent/

The `// STATUS:` and `// name @ addr` header lines stay verbatim (a duplicated name line is dropped). Whitespace
can't change codegen except through __LINE__, so the original and the formatted file are both compiled and every
function's bytes, relocation targets and the data sections must be identical; otherwise the original is kept.
"""
import argparse
import os
import re
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(__file__))
from compare import DEFAULT_FLAGS, CompileError, Coff, compile_obj  # noqa: E402
from format_matches import CLANG_FORMAT, ROOT  # noqa: E402
import subprocess  # noqa: E402

HEADER = re.compile(r"(?://[^\n]*\n)+")


def object_code(src, tmp):
    """{function name: (bytes, [relocation target names])} plus the non-code sections, or None if it won't compile."""
    try:
        coff = Coff(compile_obj(src, DEFAULT_FLAGS, tmp))
    except CompileError:
        return None
    funcs = {}
    for sym in coff.function_symbols():
        name, raw, _ = coff.function(sym)
        funcs[name] = (raw, [(off, s[0] if s else None, typ) for off, s, typ, _ in coff.function_relocs(sym)])
    data = sorted((n, raw) for n, raw, _ in coff.sections if not n.startswith((".text", ".debug", ".drectve")))
    return funcs, data


def fmt_one(path):
    original = open(path).read()
    m = HEADER.match(original)
    header = m.group(0) if m else ""
    body = original[len(header):]
    lines = header.splitlines(keepends=True)
    header = "".join(l for i, l in enumerate(lines) if i == 0 or l != lines[i - 1])  # (a repeated name line)
    r = subprocess.run([CLANG_FORMAT, "--style=file:" + os.path.join(ROOT, ".clang-format"), "--assume-filename=x.cpp"],
                       input=body, capture_output=True, text=True)
    if r.returncode != 0:
        return "format_error"
    formatted = header + r.stdout
    if formatted == original:
        return "unchanged"
    with tempfile.TemporaryDirectory() as tmp:
        a, b = os.path.join(tmp, "a"), os.path.join(tmp, "b")
        os.mkdir(a)
        os.mkdir(b)
        name = os.path.basename(path)
        open(os.path.join(a, name), "w").write(original)
        open(os.path.join(b, name), "w").write(formatted)
        before, after = object_code(os.path.join(a, name), a), object_code(os.path.join(b, name), b)
    if before is None or before != after:
        return "kept_original"
    open(path, "w").write(formatted)
    return "formatted"


def main():
    p = argparse.ArgumentParser()
    p.add_argument("files", nargs="*")
    p.add_argument("--all", action="store_true")
    p.add_argument("--jobs", type=int, default=8)
    a = p.parse_args()
    d = os.path.join(ROOT, "equivalent")
    files = a.files or (sorted(os.path.join(d, f) for f in os.listdir(d) if f.endswith(".cpp")) if a.all else [])
    counts = Counter()
    with Pool(a.jobs) as pool:
        for path, res in zip(files, pool.imap(fmt_one, files, chunksize=4)):
            counts[res] += 1
            if res != "formatted" and len(files) <= 50:
                print("  %s: %s" % (os.path.basename(path), res))
    print(dict(counts))


if __name__ == "__main__":
    main()
