#!/usr/bin/env python3
"""Give invented placeholder type names a per-source suffix so the merged source tree can share declarations.

  build/venv/bin/python tools/rename_placeholders.py --dry-run          # print what would change
  build/venv/bin/python tools/rename_placeholders.py                    # rewrite matches/ and equivalent/
  build/venv/bin/python tools/rename_placeholders.py --report N         # top N names by sources renamed
  build/venv/bin/python tools/rename_placeholders.py --only matches/0x00018c70.cpp ...   # limit the rewrite

Every source in matches/ and equivalent/ declares its own stub types. Invented names (`Obj`, `C`, `X`, `Owner`,
`Base`, ...) mean different things in different files, so the tree generator (tools/gen_tree.py) can't put two
such functions in one translation unit. This tool renames them:

  `Obj` in matches/0x00123450.cpp  ->  `Obj_123450`

The suffix is the source's address in lower-case hex without leading zeros. Not the 8-digit form: equiv.py's
pick_symbol takes the one object function whose name contains the 8-digit address, and gen_tree.py classifies
`_xxxxxxxx` names as address names.

Which names are renamed (decided over the whole corpus, then applied per file):

  * Candidates: type names a source declares at file level (class/struct/union/enum/typedef, also inside a
    namespace; forward declarations count as uses, not definitions), and file-level variable names
    (`extern void* g_vftable[];` vs `extern int g_vftable;`, `g`, `gObj`).
  * Never renamed (real names): RTTI class and namespace names (build/rtti.json, any namespace), class/struct
    names in include/gen/, the class/namespace parts of build/functions.csv names (for variables: every
    identifier of a functions.csv name and the XDK symbols), address names
    (FUN_/DAT_/..._xxxxxxxx), names starting with `_`, the KEEP list below, and any identifier mentioned on a `// equiv-*` line of that source (equiv-map mangled names,
    equiv-conv, equiv-name: the checker matches those textually).
  * A candidate is renamed in a source when
      - two or more sources define it differently (after the renames of earlier rounds; a name whose
        definition mentions a renamed name changes text, so this runs to a fixed point), or
      - it is defined identically in two or more sources and this source's own function definitions use it in
        their qualified name or parameters (clone-propagated sources: three `Set(Obj**, Obj*)` definitions
        would otherwise collide in one TU).
    A name defined identically everywhere and only used inside bodies keeps its name, so the shared
    declaration can still be hoisted into a header.
  * Per source, a name is skipped (and reported) when renaming isn't purely mechanical: it appears after
    `.` / `->` / a foreign `X::` (it is also a member name), inside a preprocessor line, the file has a
    function-like macro (`t##R` pastes names together), or the new name is already used in the file.

Renaming is token-aware (tools/cxx_items.py tokenizer): identifiers only, never inside comments, strings or
preprocessor lines, so the `// STATUS:` header and every `// equiv-*` annotation stay byte-for-byte.
Re-running is safe (a second run plans nothing): a source never renames a name carrying its own suffix. New sources
from the farm lanes get the same treatment against the current corpus. A new source that borrowed a suffixed name
from another source (`Obj_18c70` copied out of matches/0x00018c70.cpp) keeps it while its definition is identical
to the owner's; once it differs, the borrower's copy is renamed to its own suffix (`Obj_18c70` -> `Obj_1b77e0`).
"""
import argparse
import collections
import csv
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SOURCE_DIRS = ("matches", "equivalent")
TYPE_KINDS = {"class", "template class", "enum", "typedef"}
FWD_KINDS = {"fwd", "template fwd"}

# Real names that look invented: CRT / Win32 / XDK / D3D types sources declare by hand. Never renamed.
KEEP = {
    "FILE", "tm", "va_list", "size_t", "ptrdiff_t", "wchar_t", "time_t", "fpos_t", "jmp_buf", "div_t", "ldiv_t",
    "lconv", "exception", "type_info", "bad_alloc", "bad_cast", "bad_typeid", "nothrow_t", "string", "wstring",
    "GUID", "IID", "CLSID", "RECT", "POINT", "SIZE", "BOOL", "BYTE", "WORD", "DWORD", "UINT", "ULONG", "LONG",
    "HANDLE", "HRESULT", "LPVOID", "LPCSTR", "LPSTR", "VOID", "PVOID", "CHAR", "INT", "SHORT", "USHORT", "UCHAR",
    "FLOAT", "LARGE_INTEGER", "ULARGE_INTEGER", "OVERLAPPED", "CRITICAL_SECTION", "SYSTEMTIME", "FILETIME",
    "IUnknown", "IDirectSound", "IDirectSoundBuffer", "IDirect3DDevice8", "Direct3DDevice",
    "XINPUT_STATE", "XINPUT_GAMEPAD", "XINPUT_FEEDBACK", "XINPUT_CAPABILITIES", "XDEVICE_PREALLOC_TYPE",
    "XGBuffer", "XDSOUND", "D3DXVECTOR3", "D3DVECTOR", "D3DMATRIX", "D3DXMATRIX", "D3DCOLOR",
    "errno", "environ", "std", "pure3d", "core", "fight", "hulkfight", "physics", "audio",
}
# Library-style prefixes: Win32/XDK/D3D/DirectSound type names are all upper case with underscores.
LIB_RE = re.compile(r"^(?:_|D3D|XG|XINPUT_|XDEVICE_|XONLINE|DSOUND|DS[A-Z]|WAVEFORMAT|LP[A-Z]|IDirect)")
# Address names (equiv.py binds `HEX_NAME`s by the address they carry): never renamed.
ADDR_RE = re.compile(r"(?:^|_)(?:FUN|DAT|LAB|PTR|SUB|UNK|BYTE|WORD|DWORD|FLOAT|thunk_FUN|switchD|caseD|g|s|data|func)"
                     r"_(?:0x)?[0-9a-fA-F]{5,8}(?![0-9a-fA-F])|_[0-9a-fA-F]{8}(?![0-9a-fA-F])")
SUFFIXED = re.compile(r"^(\w+?)_([0-9a-f]{5,6})$")    # a name this tool gave: Obj_123450
EQUIV_LINE = re.compile(r"//\s*equiv-[\w-]*:?([^\n]*)")
ID = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


def suffix(addr):
    return "%x" % addr


# ---------------------------------------------------------------------------------------------
def protected_names():
    """(type names, value names): identifiers that are real names somewhere and are never renamed.

    Types: RTTI classes and namespaces (any namespace: a global `struct FaceTargetAction` stands for
    hulkfight::ai::FaceTargetAction and is the RTTI-stub task's to fix), include/gen/ classes, the class and
    namespace parts of build/functions.csv names. Values additionally: every identifier of a functions.csv
    name and the XDK symbols."""
    types = set(KEEP)
    try:
        for c in json.load(open(os.path.join(ROOT, "build/rtti.json")))["classes"]:
            n = re.sub(r"\b(class|struct|enum|union) ", "", c.get("name") or "")
            types.update(ID.findall(n))
    except (OSError, ValueError):
        sys.exit("build/rtti.json is needed")
    for p in glob.glob(os.path.join(ROOT, "include/gen/*.h")):
        for m in re.finditer(r"\b(?:class|struct|union|enum)\s+([A-Za-z_]\w*)", open(p, encoding="latin1").read()):
            types.add(m.group(1))
    values = set(types)
    p = os.path.join(ROOT, "build/functions.csv")
    with open(p) as f:
        for r in csv.DictReader(f):
            n = r["name"]
            if n.startswith(("FUN_", "thunk_FUN_")):
                continue
            values.update(ID.findall(n))
            q = re.sub(r"(?:::)?~?[A-Za-z_]\w*$", "", n)       # drop the function's own name
            types.update(ID.findall(q))
    p = os.path.join(ROOT, "build/xbsymbols.txt")
    if os.path.exists(p):
        for line in open(p):
            m = re.match(r"\s*(\w+)__(\w+)\s*=", line)
            if m:
                values.update(m.groups())
    return types, values


def is_candidate_name(n, protected):
    return ID.fullmatch(n) and not (n in protected or n.startswith("_") or ADDR_RE.search(n) or LIB_RE.match(n)
                or n.startswith("<") or n in cxx_items.KEYWORDS or len(n) > 60)


class Source:
    def __init__(self, rel, text):
        self.rel = rel
        self.addr = int(re.search(r"0x([0-9a-fA-F]{8})\.cpp$", rel).group(1), 16)
        self.text = text
        self.ok = True
        self.defs = collections.defaultdict(list)   # name -> [norm token lists] of its type definitions
        self.fwds = set()
        self.vars = collections.defaultdict(list)   # name -> [norm token lists] of its file-level variables
        self.sig_ids = set()                        # identifiers in own function definitions' names/params
        self.equiv_ids = set()
        self.equiv_text = ""
        for m in EQUIV_LINE.finditer(text):
            self.equiv_ids.update(ID.findall(m.group(1)))
            self.equiv_text += m.group(1) + "\n"
        try:
            self.toks = cxx_items.tokenize(text)
            items = cxx_items.parse(text)
        except ValueError:
            self.ok = False
            return
        for it in items:
            if it.kind in TYPE_KINDS or it.key and it.key[0] in TYPE_KINDS:
                if it.name:
                    self.defs[it.name].append(it.norm.split(" "))
            elif it.kind == "var" and it.name and "::" not in it.key[1]:
                self.vars[it.name].append(it.norm.split(" "))
            elif it.kind in FWD_KINDS or it.key and it.key[0] in FWD_KINDS:
                if it.name:
                    self.fwds.add(it.name)
            elif it.kind == "funcdef" and not it.is_inline:
                vs = [t.v for t in it.toks]
                head = vs[:vs.index("{")] if "{" in vs else vs
                self.sig_ids.update(v for v in head if ID.fullmatch(v))
        self.pp_ids = set()
        self.fmacro = False
        for t in self.toks:
            if t.t == "pp":
                self.pp_ids.update(ID.findall(t.v))
                self.fmacro = self.fmacro or bool(re.match(r"#\s*define\s+\w+\(", t.v))

    def blockers(self, name, new):
        """Why `name` can't be renamed mechanically in this source (None if it can)."""
        if name in self.equiv_ids or name + "@" in self.equiv_text:     # `PBUKey@@` in a mangled name
            return "named on an equiv-* line"
        if self.fmacro:
            return "function-like macros in the file (token pasting can build the name)"
        if name in self.pp_ids:
            return "used in a preprocessor line"
        ids = {t.v for t in self.toks if t.t == "id"}
        if new in ids:
            return "new name already used"
        toks = self.toks
        for i, t in enumerate(toks):
            if t.t != "id" or t.v != name or i == 0:
                continue
            p = toks[i - 1].v
            if p in (".", "->"):
                return "also a member name (after %s)" % p
            if p == "::" and i >= 2:
                q = toks[i - 2]
                if q.t == "id" and q.v != name and q.v not in self.namespaces():
                    return "qualified by %s::" % q.v
        return None

    def namespaces(self):
        ns = getattr(self, "_ns", None)
        if ns is None:
            ns = self._ns = {self.toks[i + 1].v for i, t in enumerate(self.toks[:-1]) if t.v == "namespace"}
        return ns

    def renamed_text(self, mapping):
        out, last = [], 0
        for t in self.toks:
            if t.t == "id" and t.v in mapping:
                out.append(self.text[last:t.s])
                out.append(mapping[t.v])
                last = t.e
        out.append(self.text[last:])
        return "".join(out)


def load_sources(only=None):
    srcs = []
    for d in SOURCE_DIRS:
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if not re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                continue
            rel = "%s/%s" % (d, fn)
            text = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
            srcs.append(Source(rel, text))
    return srcs


def plan(srcs, protected, verbose=False):
    """{rel: {old: new}} and skips [(rel, name, why)]. Fixed point over corpus-wide definitions."""
    rename = collections.defaultdict(dict)
    skipped = {}
    blocked = collections.defaultdict(set)      # rel -> names that can't be renamed there
    rounds = 0
    owners = {s.addr for s in srcs}
    while True:
        rounds += 1
        # current definition text of every candidate name, per source, with this plan's renames applied
        variants = collections.defaultdict(lambda: collections.defaultdict(list))   # name -> norm -> [src]
        for s in srcs:
            if not s.ok:
                continue
            m = rename.get(s.rel, {})
            for space, decls, prot in (("type", s.defs, protected[0]), ("value", s.vars, protected[1])):
                for name, norms in decls.items():
                    if name in m or not is_candidate_name(name, prot) or space == "value" and name in s.defs:
                        continue
                    key = tuple(" ".join(m.get(v, v) for v in n) for n in norms)
                    variants[(space, name)][key].append(s)
        changed = 0
        for (space, name), vs in variants.items():
            nsrc = sum(len(x) for x in vs.values())
            if nsrc < 2:
                continue
            conflicting = len(vs) > 1
            for key, ss in vs.items():
                for s in ss:
                    if not conflicting and name not in s.sig_ids:
                        continue
                    if name in blocked[s.rel]:
                        continue
                    sm = SUFFIXED.match(name)
                    if sm and int(sm.group(2), 16) not in owners:
                        sm = None                   # not one of ours (`g_4dd700` names a global)
                    if sm and sm.group(2) == suffix(s.addr):
                        continue                    # this source owns the name
                    new = "%s_%s" % (sm.group(1) if sm else name, suffix(s.addr))
                    why = s.blockers(name, new)
                    if why:
                        blocked[s.rel].add(name)
                        skipped[(s.rel, name)] = why
                        continue
                    rename[s.rel][name] = new
                    changed += 1
                    if verbose and SUFFIXED.match(name):
                        print("  borrowed %s in %s -> %s" % (name, s.rel, new), file=sys.stderr)
        if verbose:
            print("round %d: +%d renames" % (rounds, changed), file=sys.stderr)
        if not changed:
            break
    return rename, skipped, rounds


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true", help="print the renames, change nothing")
    ap.add_argument("--report", type=int, metavar="N", help="print the N names renamed in the most sources")
    ap.add_argument("--only", nargs="+", metavar="REL", help="rewrite only these sources (plan uses the corpus)")
    ap.add_argument("--exclude", metavar="FILE", help="file of sources (one rel path per line) never rewritten")
    ap.add_argument("--plan-json", metavar="FILE", help="write the plan {rel: {old: new}} as JSON")
    ap.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args(argv)
    os.chdir(ROOT)
    protected = protected_names()
    srcs = load_sources()
    bad = [s.rel for s in srcs if not s.ok]
    rename, skipped, rounds = plan(srcs, protected, a.verbose)
    excl = set()
    if a.exclude and os.path.exists(a.exclude):
        excl = {l.strip() for l in open(a.exclude) if l.strip()}
    only = set(a.only) if a.only else None
    by_rel = {s.rel: s for s in srcs}
    todo = sorted(r for r in rename if rename[r] and r not in excl and (only is None or r in only))
    if a.plan_json:
        with open(a.plan_json, "w") as f:
            json.dump({r: rename[r] for r in todo}, f, indent=0, sort_keys=True)
    names = collections.Counter(n for r in todo for n in rename[r])
    print("sources: %d (%d unparsable, not touched); fixed point after %d rounds" % (len(srcs), len(bad), rounds))
    print("sources to rewrite: %d; renames: %d; distinct names: %d; skipped (name, source) pairs: %d" % (
        len(todo), sum(len(rename[r]) for r in todo), len(names), len(skipped)))
    if a.report:
        for n, c in names.most_common(a.report):
            print("  %-28s %6d" % (n, c))
        why = collections.Counter(re.sub(r"\(after .*\)|by \w+::", "", w).strip() for w in skipped.values())
        print("skips:", dict(why))
    if a.dry_run:
        for r in todo:
            print("%s: %s" % (r, ", ".join("%s->%s" % kv for kv in sorted(rename[r].items()))))
        for (r, n), w in sorted(skipped.items()):
            print("skip %s %s: %s" % (r, n, w))
        return 0
    if a.report:
        return 0
    n = 0
    for r in todo:
        s = by_rel[r]
        new = s.renamed_text(rename[r])
        if new != s.text:
            with open(os.path.join(ROOT, r), "w", encoding="latin1", newline="") as f:
                f.write(new)
            n += 1
            print("renamed %s: %s" % (r, ", ".join("%s->%s" % kv for kv in sorted(rename[r].items()))))
    print("rewrote %d sources" % n, file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
