#!/usr/bin/env python3
"""clang-format matched TUs, keeping a formatted file only if it still matches with verified references.

  tools/format_matches.py matches/0x00018b40.cpp ...     # specific files
  tools/format_matches.py --all [--jobs 8]               # every file in matches/

Whitespace can't change codegen except through __LINE__ (assert), so every formatted file is
recompiled, compared, and reference-checked; on any failure the original is restored.
"""
import argparse
import os
import shutil
import subprocess
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(__file__))
from verify_relocs import check  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
CLANG_FORMAT = subprocess.run(["xcrun", "--find", "clang-format"], capture_output=True, text=True).stdout.strip() \
    or shutil.which("clang-format")


def fmt_one(path):
    addr = int(os.path.basename(path)[:-4], 16)
    original = open(path).read()
    header = ""
    body = original
    if original.startswith("// Same code shape"):  # keep the provenance line verbatim at the top
        header, body = original.split("\n", 1)
        header += "\n"
    r = subprocess.run([CLANG_FORMAT, "--style=file:" + os.path.join(ROOT, ".clang-format"), "--assume-filename=x.cpp"],
                       input=body, capture_output=True, text=True)
    if r.returncode != 0:
        return "format_error"
    formatted = header + r.stdout
    if formatted == original:
        return "unchanged"
    with tempfile.TemporaryDirectory() as tmp:
        cand = os.path.join(tmp, os.path.basename(path))
        open(cand, "w").write(formatted)
        if check(cand, addr)["status"] != "ok":
            return "kept_original"
    open(path, "w").write(formatted)
    return "formatted"


def main():
    p = argparse.ArgumentParser()
    p.add_argument("files", nargs="*")
    p.add_argument("--all", action="store_true")
    p.add_argument("--jobs", type=int, default=8)
    a = p.parse_args()
    files = a.files or (sorted(os.path.join(ROOT, "matches", f) for f in os.listdir(os.path.join(ROOT, "matches")))
                        if a.all else [])
    counts = Counter()
    with Pool(a.jobs) as pool:
        for i, res in enumerate(pool.imap_unordered(fmt_one, files, chunksize=16)):
            counts[res] += 1
            if (i + 1) % 1000 == 0:
                print("  %d/%d %s" % (i + 1, len(files), dict(counts)), flush=True)
    print(dict(counts))


if __name__ == "__main__":
    main()
