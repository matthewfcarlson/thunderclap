#!/usr/bin/env python3
"""RETIRED (gen1, 2026-11-13): include/gen/ is hand-maintained source, so this tool, which fed the header
generator's inputs (include/gen/evidence*.json) or rewrote matches/ onto the generated headers, refuses to run.
Edit the headers and the blocks in src/ by hand (docs/headers.md). Kept for reference; its module-level
helpers still import.

Rewrite the sources' references to include/gen/ fields renamed by include/gen/evidence-names.json (clean1).

tools/gen_headers.py names a field from include/gen/evidence-names.json instead of f_<offset>. Every source that
uses the field must then say the new name. A token `f_10` means a different field in each class, so this resolves
each reference with libclang (the source's 32-bit clang parse, as tools/equiv64.py prepares it) against the
headers as they are BEFORE the rename: a member reference whose field is declared in include/gen/ by a unit the
evidence renames, at that offset's old name, is rewritten in place. A source is refused (left unchanged, listed)
when it has a token spelled like a renamed field's old name that the parse does not account for (a declaration or
a reference it resolved), or a reference in a macro.

An implicit member reference (`f_10` inside a member function) becomes `this->name` when the source uses the new
name for anything else, so a local or parameter can never capture it.

  tools/rename_fields.py [--names include/gen/evidence-names.json] [--root DIR] [--dry-run] [--json OUT] [FILE...]
"""
import argparse
import collections
import json
import os
import re
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
TOKEN = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|[A-Za-z_][A-Za-z0-9_]*|.', re.S)


def qualified(c):
    parts = []
    k = c
    while k is not None and k.kind.name != "TRANSLATION_UNIT":
        if k.spelling:
            parts.append(re.sub(r"<.*$", "", k.spelling))
        k = k.semantic_parent
    return "::".join(reversed(parts))


def token_offsets(text):
    """[(offset, token)] for identifiers outside comments and literals"""
    out, pos = [], 0
    for t in TOKEN.findall(text):
        if re.match(r'[A-Za-z_]', t):
            out.append((pos, t))
        pos += len(t)
    return out


def line_starts(text):
    s = [0]
    for i, ch in enumerate(text):
        if ch == "\n":
            s.append(i + 1)
    return s


def analyse(src, renames, include_dir, root):
    """renames: {(unit uid, old name): new name}. Returns (edits [(offset, old, new, implicit)], problems)."""
    import equiv64
    ci = equiv64.ci()
    import gen_tree
    olds = {o for _, o in renames}
    text = open(src).read()
    toks = [(o, t) for o, t in token_offsets(text) if t in olds]
    if not toks:
        return [], []
    d = tempfile.mkdtemp()
    if True:
        with open(os.path.join(d, "tree_prelude.h"), "w") as f:
            f.write("\n".join(gen_tree.PRELUDE_LINES) + "\n")
        prepared = gen_tree.crt_guard_text(gen_tree.native_spelling(text))
        w = os.path.join(d, "src.cpp")
        with open(w, "w") as f:
            f.write('#include "tree_prelude.h"\n#line 1 "%s"\n%s' % (os.path.abspath(src), prepared))
        args = [a for a in equiv64.front_flags("i686-pc-windows-msvc") if a != "-O0"] + ["-w", "-I" + d, "-I" + include_dir]
        tu = ci.Index.create().parse(w, args=args)
        errs = [str(x) for x in tu.diagnostics if x.severity >= 3]
    # the prepared text must keep the source's lines and columns for the tokens we touch
    plines, slines = prepared.split("\n"), text.split("\n")
    starts = line_starts(text)
    seen = {}      # source offset -> (kind, renamed key or None, implicit)
    gen_dir = os.path.realpath(include_dir) + os.sep

    def visit(c):
        for k in c.get_children():
            loc = k.location
            # libclang reports spelling locations: the wrapper's, two lines (prelude include, #line) below the source's
            if loc.file is not None and os.path.abspath(loc.file.name) == os.path.abspath(w) and k.spelling in olds:
                ln, col = loc.line - 2, loc.column
                if 1 <= ln <= len(slines) and plines[ln - 1] == slines[ln - 1]:
                    off = starts[ln - 1] + col - 1
                    key = None
                    implicit = False
                    if k.kind.name in ("MEMBER_REF_EXPR", "MEMBER_REF"):
                        r = k.referenced
                        if r is not None and r.kind.name == "FIELD_DECL" and r.location.file is not None and \
                                os.path.realpath(r.location.file.name).startswith(gen_dir):
                            uid = qualified(r.semantic_parent)
                            if (uid, k.spelling) in renames:
                                key = (uid, k.spelling)
                                if k.kind.name == "MEMBER_REF_EXPR":
                                    before = text[:off].rstrip()
                                    implicit = not (before.endswith("->") or before.endswith("."))
                    prev = seen.get(off)
                    if prev is None or prev[1] is None:
                        seen[off] = (k.kind.name, key, implicit)
            visit(k)
    visit(tu.cursor)
    import shutil
    shutil.rmtree(d, ignore_errors=True)
    problems, edits = [], []
    if errs:
        problems.append("parse errors: " + "; ".join(errs[:2]))
    for off, t in toks:
        s = seen.get(off)
        if s is None:
            problems.append("unresolved %s at offset %d" % (t, off))
            continue
        if s[1] is not None:
            edits.append((off, t, renames[s[1]], s[2]))
    return edits, problems


def apply_edits(text, edits):
    ids = {t for t in TOKEN.findall(text) if re.match(r'[A-Za-z_]', t)}
    out = text
    for off, old, new, implicit in sorted(edits, reverse=True):
        rep = ("this->" + new) if implicit and new in ids else new
        assert out[off:off + len(old)] == old
        out = out[:off] + rep + out[off + len(old):]
    return out


def main():
    sys.exit("tools/rename_fields.py is retired (gen1, 2026-11-13): include/gen/ is hand-maintained source "
             "(docs/headers.md)")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*")
    ap.add_argument("--names", default=os.path.join(ROOT, "include/gen/evidence-names.json"))
    ap.add_argument("--include", default=os.path.join(ROOT, "include"),
                    help="include directory whose include/gen/ still has the OLD names")
    ap.add_argument("--root", default=ROOT, help="tree whose matches/ and equivalent/ are rewritten")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--json")
    a = ap.parse_args()
    names = json.load(open(a.names))["fields"]
    renames = {(uid, "f_%02x" % int(o, 16)): v["name"] for uid, offs in names.items() if not uid.startswith("_")
               for o, v in offs.items()}
    olds = {o for _, o in renames}
    files = a.files
    if not files:
        # candidates: sources on include/gen/ with an old spelling that name a renamed unit's class or a class
        # derived from one (a reference needs the object's type: a cast, a declaration or a member definition)
        import gen_headers as G
        g = G.Gen({})
        units = {uid for uid, _ in renames}
        related = set()
        for c in g.classes:
            if c.unit is not None and (c.unit.uid in units or any(b.unit is not None and b.unit.uid in units
                                                                for b, *_ in c.all_bases)):
                related.add(c.short)
        rel_rx = re.compile(r"\b(?:%s)\b" % "|".join(sorted(map(re.escape, related))))
        old_rx = re.compile(r"\b(?:%s)\b" % "|".join(sorted(olds)))
        files = []
        for d in ("matches", "equivalent"):
            for f in sorted(os.listdir(os.path.join(a.root, d))):
                if f.endswith(".cpp"):
                    p = os.path.join(a.root, d, f)
                    t = open(p, errors="replace").read()
                    if "gen/" in t and old_rx.search(t) and rel_rx.search(t):
                        files.append(p)
        print("%d candidate sources (%d related classes)" % (len(files), len(related)), flush=True)
    report = {"edited": {}, "refused": {}, "unchanged": 0}
    used = collections.Counter()
    for p in files:
        rel = os.path.relpath(p, a.root)
        try:
            edits, problems = analyse(p, renames, a.include, a.root)
        except Exception as e:      # noqa: BLE001 - a parse failure refuses the source
            edits, problems = [], ["error: %s" % str(e)[:200]]
        if problems and (edits or any(not x.startswith("parse errors") for x in problems)):
            report["refused"][rel] = problems[:4]
            continue
        if not edits:
            report["unchanged"] += 1
            continue
        report["edited"][rel] = len(edits)
        for _, old, new, _ in edits:
            used[new] += 1
        if not a.dry_run:
            text = open(p).read()
            open(p, "w").write(apply_edits(text, edits))
    if a.json:
        json.dump(report, open(a.json, "w"), indent=1, sort_keys=True)
    print("%d sources: %d edited (%d references), %d refused, %d with no renamed reference" % (
        len(files), len(report["edited"]), sum(report["edited"].values()), len(report["refused"]), report["unchanged"]))
    for rel, pr in sorted(report["refused"].items()):
        print("  refused %s: %s" % (rel, pr[0]))
    return 1 if report["refused"] else 0


if __name__ == "__main__":
    sys.exit(main())
