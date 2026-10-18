#!/usr/bin/env python3
"""Source edits for the native (clang) build that no generator rule can make (docs/native-build.md fix 4).

  build/venv/bin/python tools/native_fix.py                    # plan only: what would change
  build/venv/bin/python tools/native_fix.py --apply --verify   # rewrite, each source only if it still verifies
  build/venv/bin/python tools/native_fix.py --apply --verify --rule template-spec --only matches/0x001c7ca0.cpp

Each edit is standard C++ that MSVC 7.1 accepts as well, and `--verify` writes a rewrite only after the rewritten
text passes the verification the source passed (compare.py MATCH for matches/, equiv.py --inputs 3000 EQUIVALENT
for equivalent/; tools/reconcile_stubs.verify_rewrite) and only if the file didn't change since it was read.
Log: build/native-fix.log (one JSON line per source); changed paths: build/native/fix4-sources.txt.

Rules:

  template-spec   A member of an implicitly instantiated class template specialization defined without
                  `template <>` (`int om::MetaTypeAttrib<float>::vfunc_2(...) {`): an MSVC extension, which
                  clang rejects. `template <> ` goes in front. Not when the source explicitly specializes that
                  class (`template <> class X<...> {`), where the member definition must not have it.
  dependent-base  A class template using a typedef of its dependent base unqualified (`Closure0(..., Fn f)` in
                  `template <class T, class R> class Closure0 : public Method0<T, R>`): MSVC looks into the
                  dependent base, clang (two-phase lookup) doesn't, or finds another `Fn`. The use becomes
                  `typename Method0<T, R>::Fn`.
  return-struct   A struct defined in a function declaration's return type (`extern "C" struct Pair {...}
                  __cdecl Hash(const char*);`, `struct W {...} *f();`): the struct is defined first, then the
                  function declared with it (and the same linkage).
  patch           One-off edits listed in PATCHES below (exact text, each with its reason).

equivalent/ sources shadowed by a matches/ source of the same address are skipped (the tree uses the match).
"""
import argparse
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
LOG = os.path.join(ROOT, "build/native-fix.log")
CHANGED = os.path.join(ROOT, "build/native/fix4-sources.txt")
ORIG = os.path.join(ROOT, "build/native/fix4-orig")

# (source, old text, new text, why). Exact, unique occurrences; anything else is reported and skipped.
PATCHES = [
    ("equivalent/0x000c0e40.cpp", "for(int i=0;i<128;++i) { records[i].items[0]", "int i; for(i=0;i<128;++i) { records[i].items[0]",
     "for-scope: `i` is used after its loop (MSVC 7.1 /Zc:forScope-): declared before it"),
    ("equivalent/0x00322cd0.cpp", "for(int j=0;j<count;++j)weights[j]*=scale;", "int j;for(j=0;j<count;++j)weights[j]*=scale;",
     "for-scope: `j` is used after its loop: declared before it"),
    ("matches/0x001ff730.cpp", 'return x ? "Volume" : "Locator";', 'return (char*)(x ? "Volume" : "Locator");',
     "string literals returned as char*: the conditional's type is const char*"),
    ("equivalent/0x000d4b60.cpp", "extern union { float f; unsigned int u; } DAT_004a06b4;",
     "union U_4a06b4 { float f; unsigned int u; };\nextern U_4a06b4 DAT_004a06b4;",
     "an extern variable of an unnamed type (no linkage: clang can't refer to it from another TU)"),
    ("equivalent/0x0033a880.cpp", "hook != FUN_0033a620)", "hook != (Hook_33a880)FUN_0033a620)",
     "comparison with an overloaded function name (the merged TU declares FUN_0033a620 three ways): the cast picks one"),
    ("matches/0x00238190.cpp", 'extern "C" int __cdecl FUN_00238190(int index) {\n    extern int table_238190[1];\n',
     'extern int table_238190[1];\nextern "C" int __cdecl FUN_00238190(int index) {\n',
     "a block-scope extern inside an extern \"C\" function has C linkage, the TU's declaration C++ linkage"),
    ("matches/0x0035c720.cpp", 'extern "C" struct Result_35c720 __cdecl FUN_0027b020(', 'extern "C" Result_35c720 __cdecl FUN_0027b020(',
     "`extern \"C\" struct X f()` is read as a declaration of the struct, so gen_tree can't give f C++ linkage"),
    ("matches/0x000f6ef0.cpp", "    X_f6ef0();\n    int m[0x100];", "    int X_f6ef0();\n    int m[0x100];",
     "a member function declared without a return type (implicit int)"),
    ("matches/0x0031ee00.cpp", "            q->pddiRenderState::pddiRenderState();",
     "            ((pddiRenderState*)q)->pddiRenderState::pddiRenderState();",
     "an explicit constructor call (MSVC extension, which clang accepts too) through a pointer of dependent type "
     "`T*`: clang can't resolve the injected class name there; the cast makes the object expression non-dependent "
     "(placement new would add MSVC 7.1's null check)"),
]


def load_sources():
    out = []
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                rel = "%s/%s" % (d, fn)
                out.append((rel, int(fn[2:10], 16), open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()))
    return out


SPEC_CLASS = re.compile(r"\btemplate\s*<\s*>\s*(?:class|struct|union)\s+([\w:]+)\s*<")


def template_spec(text):
    """(new text, [names]) for the template-spec rule."""
    if "<" not in text:
        return text, []
    try:
        items = cxx_items.parse(text)
    except ValueError:
        return text, []
    explicit = {m.group(1).split("::")[-1] for m in SPEC_CLASS.finditer(text)}
    edits, names = [], []
    for it in items:
        if it.kind != "funcdef" or not it.key or it.key[0].startswith("template"):
            continue
        vs = [t.v for t in it.toks]
        if "template" in vs[:vs.index("(")] if "(" in vs else True:
            continue
        q = it.key[1]
        if "::" not in q:
            continue
        cls = q.rsplit("::", 1)[0]
        if "<" not in cls:
            continue
        # the class template-ids in the qualifier: X<...>::  (the last one before the member name)
        heads = re.findall(r"(\w+)\s*<", cls)
        if not heads or any(h in explicit for h in heads):
            continue
        edits.append(it.toks[0].s)
        names.append(q)
    for s in sorted(edits, reverse=True):
        text = text[:s] + "template <> " + text[s:]
    return text, names


TEMPLATE_CLASS = re.compile(r"\btemplate\s*<([^<>]*)>\s*(?:class|struct)\s+(\w+)\s*:\s*(?:public\s+)?(\w+)\s*<([^<>{};]*)>\s*\{")


def _body(text, i):
    """End index (exclusive) of the brace block opening at text[i] == '{'."""
    depth = 0
    for j in range(i, len(text)):
        c = text[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j + 1
    return -1


def base_typedefs(text, base):
    """Typedef names declared in the body of `template <...> class base`."""
    m = re.search(r"\btemplate\s*<[^<>]*>\s*(?:class|struct)\s+%s\b[^;{]*\{" % re.escape(base), text)
    if not m:
        return set()
    e = _body(text, m.end() - 1)
    body = text[m.end():e]
    out = set()
    for d in re.finditer(r"\btypedef\b([^;]*);", body):
        decl = d.group(1)
        f = re.search(r"\(\s*[\w:]*::\*\s*(\w+)\s*\)", decl) or re.search(r"\(\s*\*\s*(\w+)\s*\)", decl) \
            or re.search(r"(\w+)\s*$", decl)
        if f:
            out.add(f.group(1))
    return out


def dependent_base(text):
    """(new text, [names]) for the dependent-base rule."""
    edits, names = [], []
    for m in TEMPLATE_CLASS.finditer(text):
        params = [p.split()[-1] for p in m.group(1).split(",") if p.split()]
        args = [a.strip() for a in m.group(4).split(",")]
        if not params or not all(a in params for a in args):
            continue                      # the base is dependent only on the derived class's own parameters
        derived, base = m.group(2), m.group(3)
        tds = base_typedefs(text, base)
        if not tds:
            continue
        e = _body(text, m.end() - 1)
        body = text[m.end():e]
        own = set(re.findall(r"\btypedef\b[^;]*?(\w+)\s*\)?\s*(?:\([^;]*\))?\s*;", body))
        for td in sorted(tds - own):
            for u in re.finditer(r"(?<![\w:])%s\b" % re.escape(td), body):
                edits.append((m.end() + u.start(), m.end() + u.end(),
                              "typename %s<%s>::%s" % (base, m.group(4).strip(), td)))
                names.append("%s: %s" % (derived, td))
    for s, e, rep in sorted(edits, reverse=True):
        text = text[:s] + rep + text[e:]
    return text, sorted(set(names))


RETURN_STRUCT = re.compile(r'(^[ \t]*)(extern "C" )?struct (\w+) (\{[^{}]*\})[ \t]*(\*?[ \t]*(?:__cdecl[ \t]+)?\w+[ \t]*\()', re.M)


def return_struct(text):
    """(new text, [names]) for the return-struct rule: `[extern "C"] struct P {...} f(...);` -> `struct P {...};`
    then `[extern "C"] P f(...);` (a type defined in a return type: an MSVC extension)."""
    names = []

    def rep(m):
        names.append(m.group(3))
        return "%sstruct %s %s;\n%s%s%s %s" % (m.group(1), m.group(3), m.group(4), m.group(1), m.group(2) or "",
                                                m.group(3), m.group(5))
    return RETURN_STRUCT.sub(rep, text), names


def patch(rel, text):
    out, names = text, []
    for p_rel, old, new, why in PATCHES:
        if p_rel != rel:
            continue
        if out.count(old) != 1:
            names.append("SKIP (%d occurrences): %s" % (out.count(old), why))
            continue
        out = out.replace(old, new)
        names.append(why)
    return out, names


RULES = {"template-spec": lambda rel, t: template_spec(t), "dependent-base": lambda rel, t: dependent_base(t),
         "return-struct": lambda rel, t: return_struct(t), "patch": patch}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--rule", action="append", choices=sorted(RULES))
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--jobs", type=int, default=3, help="verifications at once (default 3)")
    a = ap.parse_args(argv)
    rules = a.rule or sorted(RULES)
    srcs = load_sources()
    in_matches = {addr for rel, addr, _ in srcs if rel.startswith("matches/")}
    planned = []
    for rel, addr, text in srcs:
        if a.only and rel not in a.only:
            continue
        if rel.startswith("equivalent/") and addr in in_matches:
            continue
        new, why = text, []
        for r in rules:
            new, w = RULES[r](rel, new)
            why += ["%s: %s" % (r, x) for x in w]
        if new != text:
            planned.append((rel, addr, text, new, why))
    print("planned: %d sources (%d matches, %d equivalent)" % (
        len(planned), sum(p[0].startswith("matches/") for p in planned), sum(p[0].startswith("equivalent/") for p in planned)))
    if not a.apply:
        for rel, addr, text, new, why in planned:
            print("  %s  %s" % (rel, "; ".join(why)[:200]))
        return 0
    if a.verify:
        import reconcile_stubs
    os.makedirs(os.path.dirname(CHANGED), exist_ok=True)
    verdicts = {}
    if a.verify:
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(a.jobs) as ex:
            futs = {p[0]: ex.submit(reconcile_stubs.verify_rewrite, p[0], p[1], p[3]) for p in planned}
            verdicts = {rel: f.result() for rel, f in futs.items()}
    written = 0
    with open(LOG, "a") as log, open(CHANGED, "a") as ch:
        for rel, addr, text, new, why in planned:
            v = None
            if a.verify:
                v = verdicts[rel]
                cur = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
                if cur != text:
                    v = "changed meanwhile"
                print("  %-26s %-11s %s" % (rel, v, "; ".join(why)[:150]), flush=True)
                if v not in ("MATCH", "EQUIVALENT"):
                    log.write(json.dumps({"file": rel, "edits": why, "skipped": v}) + "\n")
                    continue
            keep = os.path.join(ORIG, rel)
            if not os.path.exists(keep):
                os.makedirs(os.path.dirname(keep), exist_ok=True)
                with open(keep, "w", encoding="latin1", newline="") as f:
                    f.write(text)
            with open(os.path.join(ROOT, rel), "w", encoding="latin1", newline="") as f:
                f.write(new)
            log.write(json.dumps(dict({"file": rel, "edits": why}, **({"verified": v} if v else {}))) + "\n")
            ch.write(rel + "\n")
            written += 1
    print("rewrote %d of %d planned sources (log: %s)" % (written, len(planned), os.path.relpath(LOG, ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
