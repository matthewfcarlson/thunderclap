#!/usr/bin/env python3
"""Rename identifiers inside sources, token by token (comments, strings and character literals untouched).

Used by the naming/cleanup batches (clean1) for names with no linkage: locals, parameters, a source's own stub
members. A rename map is JSON: {"matches/0x....cpp": {"old": "new", ...}, ...}. A file whose text already uses a
new name as an identifier (or a preprocessor macro of it) is refused, so a rename never captures another name.

  tools/rename_ids.py MAP.json [--root DIR] [--dry-run]       # apply (to DIR's copies; default the checkout)
  tools/rename_ids.py --scan FILE...                            # list the placeholder names a source still has

Names with linkage (functions, globals, members of include/gen/ classes) go through tools/name_unify.py and
include/gen/ instead, so every user and the definition keep one name.
"""
import argparse
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# comments, string and character literals (kept verbatim), identifiers, anything else
TOKEN = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|[A-Za-z_][A-Za-z0-9_]*|.', re.S)
PLACEHOLDER = re.compile(r'^(?:param_\d+|local_[0-9a-f]+|[a-z]Var\d+|in_[A-Z]+|extraout_\w+|unaff_\w+|this_\d+)$')


def identifiers(text):
    return {t for t in TOKEN.findall(text) if re.match(r'[A-Za-z_]', t)}


def rename_text(text, mapping):
    """Return (new text, number of tokens renamed). Raises ValueError on a capture."""
    ids = identifiers(text)
    for old, new in mapping.items():
        if not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', new):
            raise ValueError("bad name %r" % new)
        if new in ids and new not in mapping:
            raise ValueError("%s -> %s: %s is already used" % (old, new, new))
    if len(set(mapping.values())) != len(mapping):
        raise ValueError("two names map to one")
    out, n = [], 0
    for t in TOKEN.findall(text):
        if t in mapping:
            out.append(mapping[t])
            n += 1
        else:
            out.append(t)
    return "".join(out), n


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("map", nargs="?")
    ap.add_argument("--root", default=ROOT)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--scan", nargs="+")
    a = ap.parse_args()
    if a.scan:
        for f in a.scan:
            ph = sorted(i for i in identifiers(open(f).read()) if PLACEHOLDER.match(i))
            if ph:
                print(f, " ".join(ph))
        return 0
    m = json.load(open(a.map))
    bad = 0
    total = 0
    for rel, mapping in sorted(m.items()):
        if rel.startswith("_"):
            continue
        p = os.path.join(a.root, rel)
        text = open(p).read()
        try:
            new, n = rename_text(text, {k: v for k, v in mapping.items() if k != v})
        except ValueError as e:
            print("refused %s: %s" % (rel, e), file=sys.stderr)
            bad += 1
            continue
        missing = [k for k in mapping if k != mapping[k] and k not in identifiers(text)]
        if missing:
            print("note %s: not in the source: %s" % (rel, " ".join(missing)), file=sys.stderr)
        total += n
        if not a.dry_run and new != text:
            open(p, "w").write(new)
    print("%d files, %d tokens renamed, %d refused" % (len(m) - bad, total, bad))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
