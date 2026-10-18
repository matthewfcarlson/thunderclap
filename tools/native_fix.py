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
    ("equivalent/0x0008d480.cpp", "int bounds[4]; FUN_00209f01(bounds);", "int bounds[8]; FUN_00209f01(bounds);",
     "GlobalMemoryStatus fills a 32-byte MEMORYSTATUS (the original reserves 0x20 bytes for it): natively the "
     "16-byte array let it overwrite the saved registers and return address (start-up trace, init 216)"),
    ("matches/0x0008d690.cpp",
     "int __cdecl first(int);\nvoid __cdecl second(int);\nvoid __cdecl FUN_0008d690(int x) {",
     "int __cdecl first();\nvoid* __cdecl second(int, int);\nvoid* __cdecl FUN_0008d690(int x) {",
     "the game's operator new: `push size; call first; push eax; call second` is second(first(), size) (MSVC "
     "pushes the right-hand argument first), not second(first(size)) with the size left on the stack, and it "
     "returns second's pointer: natively the old text passed second a garbage size and returned nothing"),
    ("matches/0x0008d690.cpp", "    second(first(x));\n    _ReadWriteBarrier();\n", "    return second(first(), x);\n",
     "(the same edit, second part)"),
    ("equivalent/0x0026c040.cpp", "// equiv-conv: FUN_0026be70 stack eax\nextern void *FUN_0026be70(unsigned nb, MState *av);",
     "// equiv-conv: FUN_0026be70 eax stack\nextern void *FUN_0026be70(MState *av, unsigned nb);",
     "a register-convention callee declared with its parameters in another order than its own source "
     "(equivalent/0x0026be70.cpp: `eax stack`, (arena, size)): equiv.py maps each side to the original's registers, "
     "natively both are __cdecl and the callee read the size as its arena (start-up trace, init 216)"),
    ("equivalent/0x0026c040.cpp", "            return FUN_0026be70(nb, av);", "            return FUN_0026be70(av, nb);",
     "(the same edit, the call)"),    # start-up round 2 (docs/native-build.md "Start-up, continued")
    ("equivalent/0x00219cc0.cpp", "void __cdecl FUN_00219be0(void*);\nvoid __cdecl FUN_00219c30(void*);\n",
     "// equiv-conv: FUN_00219be0 esi edi stack\nvoid __cdecl FUN_00219be0(Item*, void*, void*);\n"
     "// equiv-conv: FUN_00219c30 ebx esi stack\nvoid __cdecl FUN_00219c30(void*, Item*, void*);\n",
     "two register-convention callees (their own notes: `esi edi stack`, `ebx esi stack`) called with only their "
     "stack word and no note: the original passes (item, the second argument, owner) and (owner, item, arg) in "
     "those registers (native_conv_check check 5, callers without a note; start-up trace, main: luaH_new)"),
    ("equivalent/0x00219cc0.cpp", "    FUN_00219be0(owner);\n    FUN_00219c30(arg);\n",
     "    FUN_00219be0(item, unused, owner);\n    FUN_00219c30(owner, item, arg);\n", "(the same edit, the calls)"),
    ("matches/0x00275110.cpp", "void __stdcall FUN_00274e60(void* p);\n",
     "struct Request_275110 {\n    Request_275110* FUN_00274e60(void* p);\n};\n",
     "a thiscall constructor (0x00274e60: `mov esi, ecx`, `ret 4`) declared as a free __stdcall function: the "
     "original's ecx still held `this` from the caller, natively nothing sets it (native_conv_check check 8; "
     "start-up trace, main: FileCloseRequest)"),
    ("matches/0x00275110.cpp", "    FUN_00274e60(p);\n", "    ((Request_275110*)this)->FUN_00274e60(p);\n",
     "(the same edit, the call)"),
    ("equivalent/0x00277260.cpp", '// equiv-conv: FUN_0026fcf0 stack stack stack\nextern "C" int __cdecl FUN_0026fcf0(unsigned int, const char *, unsigned int);',
     '// equiv-conv: FUN_0026fcf0 stack stack stack stack\nextern "C" int __cdecl FUN_0026fcf0(unsigned int, const char *, unsigned int, unsigned int);',
     "a tail call passing on more arguments than the source declares: the original `jmp 0x0026fcf0` hands it all "
     "four of its own (result, name, options, details); with three, natively 0x0026fcf0 read the drive path from "
     "beyond the arguments (start-up trace, main: XboxDrive::vfunc_21)"),
    ("equivalent/0x00277260.cpp", "int __cdecl FUN_00277260(unsigned int arg1, const char *path, unsigned int arg3)",
     "int __cdecl FUN_00277260(unsigned int arg1, const char *path, unsigned int arg3, unsigned int arg4)", "(the same edit)"),
    ("equivalent/0x00277260.cpp", "return FUN_0026fcf0(arg1, path, arg3);", "return FUN_0026fcf0(arg1, path, arg3, arg4);",
     "(the same edit, the call)"),
    ("equivalent/0x00251b40.cpp", "    // equiv-conv: FUN_0023fc40 ecx stack stack stack stack stack\n"
     "    ChannelValue *FUN_0023fc40(const char *, int, const Int64 *, int, int);",
     "    // equiv-conv: FUN_0023fc40 ecx stack stack\n    ChannelValue *FUN_0023fc40(const char *, int);",
     "the audio type constructors' string init 0x0023fc40 pops two arguments (`ret 8`); the three the original "
     "pushes before them are the base constructor's (as in matches/0x0024ed10, rule split-temp): declared and "
     "called with two (start-up trace, init 349)"),
    ("equivalent/0x00251b40.cpp", 'channel.FUN_0023fc40("ChVol", 0, &value, 32, 4);', 'channel.FUN_0023fc40("ChVol", 0);',
     "(the same edit, the call)"),
    ("matches/0x0024ed10.cpp",
     "    Data(const char*, int, void*, int, int) throw();\n    ~Data() throw();\n};\nclass Base {\n  public:\n    Base(const Data&) throw();",
     "    Data* Init(const char*, int) throw();\n    ~Data() throw();\n};\nclass Base {\n  public:\n    Base(Data*, void*, int, int) throw();",
     "arguments left on the stack by MSVC and read by the next call: the original pushes (4, 0x50, &key, 0, name), "
     "calls 0x0023fc40, which pops only (name, 0) (`ret 8`: String's init, returning this), then pushes its result and "
     "calls the base constructor 0x002605e0 (`ret 0x10`) with (string, &key, 0x50, 4); the five-argument `Data` "
     "constructor byte-matched, natively it unbalanced the stack (start-up trace, init 329)"),
    ("matches/0x0024ed10.cpp",
     '    : Base(Data("ChSendVol", 0, Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4)) {}',
     '    : Base(Data().Init("ChSendVol", 0), Key(Lookup("SeqEventChannelSendVolumes", 0, 0)), 0x50, 4) {}',
     "(the same edit, the call)"),
    ("equivalent/0x00011000.cpp", "extern float FUN_003441f0();\nfloat __cdecl FUN_00011000(float value)\n{\n"
     "    volatile float result = FUN_003441f0();\n    return result;\n}",
     'extern "C" double __cdecl acos(double);\nfloat __cdecl FUN_00011000(float value)\n{\n'
     "    double result = acos(value);\n    return (float)result;\n}",
     "0x003441f0 is the CRT's _CIacos (argument and result on the x87 stack): `FUN_003441f0()` passed nothing, "
     "natively acos read an empty x87 stack. acos() is MSVC's intrinsic (fld; call __CIacos; now a byte match)"),
    ("equivalent/0x00011010.cpp", "extern float FUN_003442bc();\nfloat __cdecl FUN_00011010(float value) {\n"
     "    float result = FUN_003442bc();\n    volatile float dummy = value;\n    return result;\n}",
     'extern "C" double __cdecl asin(double);\nfloat __cdecl FUN_00011010(float value) {\n'
     "    double result = asin(value);\n    return (float)result;\n}",
     "0x003442bc is _CIasin: as 0x00011000 (now a byte match)"),
    ("equivalent/0x0033b700.cpp", "float __cdecl FUN_003441f0();\n", 'extern "C" double __cdecl acos(double);\n',
     "_CIacos called as `FUN_003441f0()`: its argument is the previous call's x87 result; acos(a) says so"),
    ("equivalent/0x0033b700.cpp", "    float b = FUN_003441f0();\n", "    float b = (float)acos(a);\n",
     "(the same edit, the call)"),
    ("equivalent/0x0008d6d0.cpp", "int __cdecl FUN_00266d90(int);\nvoid __cdecl FUN_00266e00(int, int);\n"
     "void __cdecl FUN_0008d6d0(int value) {",
     "int __cdecl FUN_00266d90();\nvoid* __cdecl FUN_00266e00(int, int);\nvoid* __cdecl FUN_0008d6d0(int value) {",
     "operator new[], the twin of 0x0008d690: second(first(), size) returning second's pointer (its callers use "
     "eax: native_conv_check check 6), not a void function"),
    ("equivalent/0x0008d6d0.cpp", "    int result = FUN_00266d90(value);\n    FUN_00266e00(result, value);\n",
     "    return FUN_00266e00(FUN_00266d90(), value);\n", "(the same edit, the call)"),
    ("matches/0x001d06a0.cpp", "extern void __cdecl FUN_002130e0(void*, int);\nextern int __cdecl FUN_0034483c();\n",
     "extern double __cdecl FUN_002130e0(void*, int);\n",
     "0x0034483c is the CRT's _ftol (argument on the x87 stack): `FUN_002130e0(p, -1); x = FUN_0034483c();` "
     "converted the number 0x002130e0 leaves in st0, which a `void` declaration hides; natively _ftol read an empty "
     "x87 stack (native_conv_check check 6, x87 helpers)"),
    ("matches/0x001d06a0.cpp", "            FUN_002130e0(p, -1);\n            x = FUN_0034483c();\n",
     "            x = (int)FUN_002130e0(p, -1);\n", "(the same edit, the call)"),
    ("equivalent/0x000e8070.cpp", "void FUN_000fad30(); unsigned int FUN_000fad90(); };",
     "float FUN_000fad30(); unsigned int FUN_000fad90(); };",
     "_ftol called as `FUN_0034483c()` on the float FUN_000fad30 leaves in st0: (int)input->FUN_000fad30()"),
    ("equivalent/0x000e8070.cpp", "unsigned int __cdecl FUN_0034483c();\n", "", "(the same edit)"),
    ("equivalent/0x000e8070.cpp", "{ input->FUN_000fad30(); object->stamp=FUN_0034483c(); }",
     "{ object->stamp=(int)input->FUN_000fad30(); }", "(the same edit, the call)"),
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


# ---------------------------------------------------------------------------------------------
# register-order: a caller's declaration of a register-convention callee in its definition's parameter order
_REG_ORDERS = {}


def register_findings():
    """{caller file: [(callee name, caller locations, definition locations)]} from tools/native_conv_check.py
    check 5 (cached per run)."""
    if "f" not in _REG_ORDERS:
        import native_conv_check
        _n, bad = native_conv_check.check_register_orders()
        out = {}
        for b in bad:
            out.setdefault(b["file"], []).append((int(b["addr"], 16), tuple(b["conv"].split()),
                                                   tuple(b["definition_conv"].split())))
        _REG_ORDERS["f"] = out
    return _REG_ORDERS["f"]


def blank_comments(text):
    """text with comments and string/char literals' contents replaced by spaces (offsets kept)."""
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out[i:j] = " " * (j - i)
            i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out[i:j] = [ch if ch == "\n" else " " for ch in text[i:j]]
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            out[i + 1:j] = " " * (j - i - 1)
            i = j + 1
        else:
            i += 1
    return "".join(out)


def split_args(text, start, end, angle=False):
    """[(s, e)] spans of the top-level comma-separated items of text[start:end]."""
    spans, depth, s = [], 0, start
    opens, closes = "([{" + ("<" if angle else ""), ")]}" + (">" if angle else "")
    for i in range(start, end):
        ch = text[i]
        if ch in opens:
            depth += 1
        elif ch in closes:
            depth -= 1
        elif ch == "," and depth == 0:
            spans.append((s, i))
            s = i + 1
    if text[start:end].strip():
        spans.append((s, end))
    return spans


def order_plan(locs, def_locs):
    """[index into the caller's parameters] for each of the definition's, or None when the caller lacks one of the
    definition's locations (it would have to pass a value it doesn't have). Stack slots keep their order."""
    used, plan = set(), []
    for l in def_locs:
        j = next((k for k, x in enumerate(locs) if x == l and k not in used), None)
        if j is None:
            return None
        used.add(j)
        plan.append(j)
    return plan


def register_order(rel, text):
    """The register-order rule for one source: reorder (and drop the caller's extra) parameters of every
    declaration and argument of every call of a callee whose `// equiv-conv` note lists its parameters in another
    order than the callee's own note, and the note itself. Callees whose definition reads a location the caller
    doesn't pass are left alone (reported)."""
    finds = register_findings().get(rel)
    if not finds:
        return text, []
    names = []
    for addr, locs, def_locs in finds:
        plan = order_plan(locs, def_locs)
        if plan is None:
            names.append("SKIP 0x%08x: the definition reads %s, the caller passes %s" % (addr, " ".join(def_locs), " ".join(locs)))
            continue
        nm = re.search(r"//\s*equiv-conv:\s*(\S*%06x)\s+%s\s*$" % (addr & 0xFFFFFF, r"\s+".join(locs)), text, re.M | re.I)
        if not nm:
            names.append("SKIP 0x%08x: note not found" % addr)
            continue
        name = nm.group(1)
        blank = blank_comments(text)
        edits = []
        ok = True
        for m in re.finditer(r"\b%s\s*\(" % re.escape(name), blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            a0, a1 = m.end(), i - 1
            after = blank[i:i + 40].lstrip()
            k = max(blank.rfind(";", 0, m.start()), blank.rfind("{", 0, m.start()), blank.rfind("}", 0, m.start()))
            prefix = blank[k + 1:m.start()].strip()
            is_decl = after.startswith((";", "{", "throw")) and prefix and not re.search(r"[=(,!&|+\-/<>?:\[]$|\breturn$", prefix) \
                and not re.search(r"\breturn\b|=", prefix)
            spans = split_args(blank, a0, a1, angle=is_decl)
            if len(spans) != len(locs):
                ok = False
                break
            items = [text[s:e].strip() for s, e in spans]
            new = ", ".join(items[j] for j in plan)
            edits.append((a0, a1, new))
        if not ok or not edits:
            names.append("SKIP 0x%08x: %s" % (addr, "argument count differs from the note" if not ok else "no uses"))
            continue
        out = text
        for a0, a1, new in sorted(edits, reverse=True):
            out = out[:a0] + new + out[a1:]
        out = re.sub(r"(//\s*equiv-conv:\s*%s\s+)%s(\s*)$" % (re.escape(name), r"\s+".join(locs)),
                     lambda mm: mm.group(1) + " ".join(def_locs) + mm.group(2), out, count=1, flags=re.M)
        text = out
        names.append("0x%08x %s: %s -> %s (%d sites)" % (addr, name, " ".join(locs), " ".join(def_locs), len(edits)))
    return text, names


# ---------------------------------------------------------------------------------------------
# void-return: a `void` definition whose original callers use the result it leaves in eax
_VOID_RET = {}
TREE_REPORT = os.environ.get("HULK_TREE_REPORT") or os.path.join(ROOT, "build/tree/report.json")


def void_return_findings():
    """{definition file: {symbol}} of tools/native_conv_check.py check 6 (eax uses only; cached per run)."""
    if "f" not in _VOID_RET:
        import native_conv_check
        _n, bad, _h = native_conv_check.check_returns(tree_report=TREE_REPORT)
        out = {}
        for b in bad:
            if b["declared"] == "void" and "eax" in b["why"]:
                out.setdefault(b["file"], set()).add(b["symbol"])
        _VOID_RET["f"] = out
    return _VOID_RET["f"]


def _plain_name(sym):
    if sym.startswith("?"):
        m = re.match(r"\?([\w$]+)@", sym)
        return m.group(1) if m else None
    m = re.fullmatch(r"[_@]?(\w+?)(?:@\d+)?", sym)
    return m.group(1) if m else None


DECL_WORDS = r"(?:virtual\s+|static\s+|extern\s+|inline\s+|__inline\s+|__forceinline\s+)*"
CONV_WORD = r"(?:__cdecl\s+|__stdcall\s+|__thiscall\s+|__fastcall\s+)?"


def void_return(rel, text):
    """The void-return rule for one source: its definition returns `void` but the original's callers use eax after
    calling it (check 6), and its body ends in a call (`...; g(x);`, the original `call g; ret` or `jmp g`): the
    definition returns that call's value. The callee's declaration in this source gets the return type `int` if it
    was `void` too (a pointer- or int-returning callee keeps its own type, which the definition takes over)."""
    syms = void_return_findings().get(rel)
    if not syms:
        return text, []
    names = []
    for sym in sorted(syms):
        name = _plain_name(sym)
        if not name:
            continue
        blank = blank_comments(text)
        defs = []
        for m in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank):
            i, depth = m.end(), 1
            while i < len(blank) and depth:
                depth += {"(": 1, ")": -1}.get(blank[i], 0)
                i += 1
            rest = re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank[i:])
            if rest:
                defs.append((m, i + rest.end() - 1))
        if len(defs) != 1:
            names.append("SKIP %s: %d definitions" % (name, len(defs)))
            continue
        m, b0 = defs[0]
        depth, j = 0, b0
        while j < len(blank):
            depth += {"{": 1, "}": -1}.get(blank[j], 0)
            if depth == 0:
                break
            j += 1
        body = blank[b0 + 1:j]
        tail = body.rstrip()
        if not tail.endswith(";"):
            names.append("SKIP %s: the body does not end in a statement" % name)
            continue
        k = max(tail.rfind(";", 0, len(tail) - 1), tail.rfind("{", 0, len(tail) - 1), tail.rfind("}", 0, len(tail) - 1))
        stmt = tail[k + 1:-1]
        st = stmt.strip()
        if not st.endswith(")") or re.match(r"(return|if|while|for|switch|do|else|delete)\b", st) or re.search(r"(?<![=!<>])=(?!=)", st):
            names.append("SKIP %s: the last statement is not a call (%s)" % (name, " ".join(st.split())[:60]))
            continue
        # the callee: the identifier before the last top-level argument list
        q, depth = len(st) - 1, 0
        while q >= 0:
            depth += {")": 1, "(": -1}.get(st[q], 0)
            if depth == 0:
                break
            q -= 1
        cm = re.search(r"(\w+)\s*$", st[:q])
        if not cm:
            names.append("SKIP %s: no callee name" % name)
            continue
        callee = cm.group(1)
        ret_type = "int"
        new = text
        cdecls = list(re.finditer(r"(?m)(^|[;{}(,]|\b(?:virtual|static|extern|inline)\b)\s*" + r"(?:extern\s+\"C\"\s+)?" + DECL_WORDS +
                                  r"([\w:<>\s\*&]+?)\s+" + CONV_WORD + r"(?:\w+::)*" + re.escape(callee) + r"\s*\(",
                                  blank_comments(new)))
        def ctype(c):
            return " ".join(re.sub(r"^(?:public|private|protected)\s*:\s*", "", c.group(2).strip()).split())
        types = {ctype(c) for c in cdecls if c.group(2).strip() not in ("return", "else", "new", "delete")}
        types.discard("")
        if types == {"void"}:
            new2 = new
            for c in sorted(cdecls, key=lambda c: -c.start(2)):
                if ctype(c) == "void":
                    new2 = new2[:c.start(2)] + re.sub(r"\bvoid\b", "int", new2[c.start(2):c.end(2)]) + new2[c.end(2):]
            new = new2
        elif len(types) == 1 and not re.search(r"\b(float|double|void)\b", next(iter(types))):
            ret_type = next(iter(types))
        elif not types and callee in ("_isnan",):
            ret_type = "int"
        elif not types:
            names.append("SKIP %s: no declaration of %s in the source" % (name, callee))
            continue
        else:
            names.append("SKIP %s: %s declared as %s" % (name, callee, sorted(types)))
            continue
        # (offsets: the callee declarations come before the definition in these sources, so recompute)
        blank2 = blank_comments(new)
        m2 = re.search(r"\bvoid(\s+" + CONV_WORD + r"(?:\w+::)*" + re.escape(name) + r"\s*\()", blank2)
        dm = [x for x in re.finditer(r"\bvoid\s+" + CONV_WORD + r"((?:\w+::)*)" + re.escape(name) + r"\s*\(", blank2)]
        defm = None
        for x in dm:
            i, depth = x.end(), 1
            while i < len(blank2) and depth:
                depth += {"(": 1, ")": -1}.get(blank2[i], 0)
                i += 1
            if re.match(r"\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?\{", blank2[i:]):
                defm = x
        if defm is None or m2 is None:
            names.append("SKIP %s: definition moved" % name)
            continue
        # the statement position in the new text: the last `stmt;` before the definition's closing brace
        b1 = blank2.index("{", defm.end())
        depth, j = 0, b1
        while j < len(blank2):
            depth += {"{": 1, "}": -1}.get(blank2[j], 0)
            if depth == 0:
                break
            j += 1
        tail_end = blank2.rstrip()[:0]
        body_end = len(blank2[:j].rstrip()) - 1          # the statement's `;`
        stmt_start = body_end - len(stmt)
        if blank2[stmt_start:body_end] != stmt:
            names.append("SKIP %s: statement moved" % name)
            continue
        lead = len(stmt) - len(stmt.lstrip())
        new = new[:stmt_start + lead] + "return " + new[stmt_start + lead:]
        new = new[:defm.start()] + ret_type + new[defm.start() + 4:]
        # its other declarations: the member's in its class body, or a free function's forward declarations
        qual = defm.group(1).rstrip(":").split("::")[-1] if defm.group(1) else None
        decl_rx = re.compile(r"\bvoid(\s+" + CONV_WORD + re.escape(name) + r"\s*\([^;{]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?;)")
        if qual:
            bl = blank_comments(new)
            cm2 = re.search(r"\b(?:struct|class)\s+%s\b[^;{]*\{" % re.escape(qual), bl)
            if cm2:
                depth, e = 0, cm2.end() - 1
                while e < len(bl):
                    depth += {"{": 1, "}": -1}.get(bl[e], 0)
                    if depth == 0:
                        break
                    e += 1
                body_txt = new[cm2.end():e]
                body_txt = decl_rx.sub(lambda mm: ret_type + mm.group(1), body_txt)
                new = new[:cm2.end()] + body_txt + new[e:]
        else:
            head, rest_ = new[:defm.start()], new[defm.start():]
            new = decl_rx.sub(lambda mm: ret_type + mm.group(1), head) + rest_
        text = new
        names.append("%s returns %s (%s)" % (name, ret_type, callee))
    return text, names


# ---------------------------------------------------------------------------------------------
# split-temp: the audio type constructors' five-argument temporary (arguments left on the stack)
def split_temp(text):
    """`Base(Temp(name, 0, key, n, m))` with `Temp(const char*, int, K, int, int)` and `Base(const Temp&)` (or
    `Base(Temp*)` with `&Temp(...)`): the original pushes all five, calls 0x0023fc40, which pops only (name, 0)
    (`ret 8`: a string init returning this), and the base constructor 0x002605e0 (`ret 0x10`) takes the string and
    the three words left on the stack. MSVC compiles the five-argument spelling to the same bytes; natively the
    callee pops 8 where the caller expects 20 (native_conv_check check 7). Rewritten as what the machine code does:
    `Base(Temp().Init(name, 0), key, n, m)` with `Temp* Init(const char*, int)` and `Base(Temp*, K, int, int)`."""
    m = re.search(r"(\n\s*)(\w+)\(const char\*, int, ([^,()]+), int, int\) throw\(\);", text)
    if not m:
        return text, []
    T, K = m.group(2), m.group(3).strip()
    b = re.search(r"(\w+)\((?:const %s&|%s\*)\) throw\(\);" % (re.escape(T), re.escape(T)), text)
    c = re.search(r"\b(\w+)\(&?%s\(" % re.escape(T), text)
    if not b or not c or c.group(1) != b.group(1):
        return text, []
    B = b.group(1)
    i, depth = c.end(), 1
    while i < len(text) and depth:
        depth += {"(": 1, ")": -1}.get(text[i], 0)
        i += 1
    inner = text[c.end():i - 1]
    parts, d, s0 = [], 0, 0
    for j, ch in enumerate(inner):
        if ch == "(":
            d += 1
        elif ch == ")":
            d -= 1
        elif ch == "," and d == 0:
            parts.append(inner[s0:j].strip())
            s0 = j + 1
    parts.append(inner[s0:].strip())
    if len(parts) != 5 or i >= len(text) or text[i] != ")":
        return text, []
    call = "%s(%s().Init(%s, %s), %s, %s, %s)" % (B, T, parts[0], parts[1], parts[2], parts[3], parts[4])
    out = text[:c.start()] + call + text[i + 1:]
    out = out.replace(b.group(0), "%s(%s*, %s, int, int) throw();" % (B, T, K), 1)
    out = out.replace(m.group(0), m.group(1) + "%s* Init(const char*, int) throw();" % T, 1)
    return out, ["%s(%s(5 arguments)) -> %s(%s().Init(2), 3 more)" % (B, T, B, T)]


# ---------------------------------------------------------------------------------------------
# code-literal: a function passed by its XBE address as an integer literal
CODE_LITERAL = re.compile(r"\(void\s*\(\*\)\((?:void)?\)\)\s*0x([0-9a-fA-F]{6,8})\b")


def code_literal(text):
    """`atexit((void (*)())0x364490)`: an initializer registering its global's destructor by the XBE address of
    the `$E` cleanup function. MSVC emits the same `push imm32` for the literal as for the name (a relocation the
    byte match masks), natively the image registers 0x00364490, which is no function of the image (it runs at
    exit). Named: `FUN_00364490`, declared `extern "C" void __cdecl FUN_00364490();` (bound by address)."""
    names = []
    for m in CODE_LITERAL.finditer(text):
        names.append("FUN_%08x" % int(m.group(1), 16))
    if not names:
        return text, []
    out = CODE_LITERAL.sub(lambda m: "FUN_%08x" % int(m.group(1), 16), text)
    decls = "".join('extern "C" void __cdecl %s();\n' % n for n in sorted(set(names))
                    if not re.search(r"\b%s\s*\(" % n, text))
    return decls + out, ["%s by name, not by address" % n for n in sorted(set(names))]


# ---------------------------------------------------------------------------------------------
# pass-through: a wrapper that tail-jumps to a callee-popping function, passing its own stack arguments on
_PT = {}


def _xbe_tools():
    if "x" not in _PT:
        import capstone
        from xbe import Xbe
        import native_conv_check
        _PT["x"] = Xbe(native_conv_check.XBE)
        _PT["md"] = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        _PT["ncc"] = native_conv_check
    return _PT["x"], _PT["md"], _PT["ncc"]


def pass_through(rel, addr, text):
    """`int A::run() { return p->f(); }` whose original is `mov ecx, [ecx+0xb8]; jmp f` with f popping 12 bytes
    (`ret 0xc`): the wrapper's callers push three arguments and the jump hands them on. MSVC compiles the
    argument-less spelling to the same bytes; natively f reads three words that aren't there and pops them anyway
    (native_conv_check check 7). The wrapper and the callee's declaration get N/4 `int` parameters, passed on in
    order. Only for a wrapper without parameters whose body is that one call."""
    x, md, ncc = _xbe_tools()
    o = x.offset(addr)
    if o is None:
        return text, []
    ins = []
    for i in md.disasm(x.data[o:o + 64], addr):
        ins.append(i)
        if i.mnemonic in ("jmp", "ret", "int3"):
            break
    if not ins or ins[-1].mnemonic != "jmp" or not ins[-1].op_str.startswith("0x") or \
            any(i.mnemonic in ("push", "call", "sub") or ("esp" in i.op_str) for i in ins[:-1]):
        return text, []
    rets, _t = ncc.xbe_rets(x, md, int(ins[-1].op_str, 16))
    if not rets or len(rets) != 1 or max(rets) == 0 or max(rets) % 4:
        return text, []
    n = max(rets) // 4
    blank = blank_comments(text)
    defs = list(re.finditer(r"(?m)^([\w:<>\*& ]+?\s(?:\w+::)*(\w+))\s*\(\s*(?:void)?\s*\)\s*(const\s*)?\{", blank))
    if len(defs) != 1:
        return text, []
    d = defs[0]
    i, depth = d.end() - 1, 0
    for j in range(i, len(blank)):
        depth += {"{": 1, "}": -1}.get(blank[j], 0)
        if depth == 0:
            break
    body = blank[i + 1:j].strip()
    m = re.fullmatch(r"(return\s+)?(.*?)(\w+)\s*\(\s*\)\s*;", body, re.S)
    if not m:
        return text, []
    callee = m.group(3)
    names = ["a%d" % k for k in range(n)]
    out = text
    # the callee's declarations without parameters: `T callee();` -> `T callee(int, ...)`
    decl_rx = re.compile(r"(\b%s\s*\()\s*(?:void)?\s*(\)\s*(?:const\s*)?;)" % re.escape(callee))
    if not decl_rx.search(blank[:d.start()]):
        return text, []
    head = decl_rx.sub(lambda mm: mm.group(1) + ", ".join(["int"] * n) + mm.group(2), out[:d.start()])
    # the wrapper's own declaration in its class (same name, no parameters)
    head = re.sub(r"(\b%s\s*\()\s*(?:void)?\s*(\)\s*(?:const\s*)?;)" % re.escape(d.group(2)),
                  lambda mm: mm.group(1) + ", ".join(["int"] * n) + mm.group(2), head)
    rest = out[d.start():]
    rest = re.sub(r"(\b%s\s*\()\s*(?:void)?\s*(\))" % re.escape(d.group(2)),
                  lambda mm: mm.group(1) + ", ".join("int " + a for a in names) + mm.group(2), rest, count=1)
    rest = re.sub(r"(\b%s\s*\()\s*(\)\s*;)" % re.escape(callee), lambda mm: mm.group(1) + ", ".join(names) + mm.group(2),
                  rest, count=1)
    return head + rest, ["%s passes its %d stack argument(s) on to %s" % (d.group(2), n, callee)]


# ---------------------------------------------------------------------------------------------
# this-call: a free-function declaration of a thiscall definition, called while ecx holds `this`
_TC = {}


def this_call_findings():
    """{source file: {plain name}} from native_conv_check check 8 (cdecl/stdcall callers of a thiscall
    definition), mapped to the sources of the caller symbol's TU (HULK_TREE_MANIFEST, default build/tree)."""
    if "f" not in _TC:
        import native_conv_check
        man = json.load(open(os.environ.get("HULK_TREE_MANIFEST") or os.path.join(ROOT, "build/tree/manifest.json")))
        by_ns = {}
        for t in man["tus"]:
            srcs = [b["src"] for b in t["blocks"] if b.get("src")]
            if t.get("tu_ns"):
                by_ns.setdefault(t["tu_ns"], []).extend(srcs)
            for b in t["blocks"]:
                if b.get("ns") and b.get("src"):
                    by_ns.setdefault(b["ns"], []).append(b["src"])
        _p, bad = native_conv_check.check_definition_convs(
            os.environ.get("HULK_BINDINGS") or os.path.join(ROOT, "build/native/bindings.json"))
        out = {}
        for b in bad:
            sym = b["symbol"]
            name = _plain_name(sym)
            m = re.search(r"@(fn_[0-9a-f]{8})@@", sym)
            for src in by_ns.get(m.group(1), []) if m else []:
                out.setdefault(src, set()).add(name)
        _TC["f"] = out
    return _TC["f"]


def this_call(rel, text):
    """`void __stdcall FUN_00274e60(void* p);` called as `FUN_00274e60(p);` inside a member function whose original
    calls the thiscall definition with ecx still holding `this` (matches/0x00275110): MSVC compiles the free call to
    the original's bytes, natively nothing sets ecx (native_conv_check check 8). The declaration becomes a member
    of a struct of its own and the call `((X_this*)this)->FUN_00274e60(p)`; the byte match decides whether ecx
    really was `this` (otherwise MSVC adds the `mov ecx` and the rewrite is refused)."""
    names = this_call_findings().get(rel)
    if not names or not rel.startswith("matches/"):
        return text, []
    done = []
    for name in sorted(n for n in names if n):
        blank = blank_comments(text)
        decls = list(re.finditer(r"(?m)^(?:extern\s+(?:\"C\"\s+)?)?([\w:\*& ]+?)\s+(?:__stdcall\s+|__cdecl\s+)?%s\s*\(([^()]*)\)\s*(?:throw\s*\(\s*\))?\s*;[ \t]*\n" % re.escape(name), blank))
        if len(decls) != 1 or in_class(blank, decls[0].start()):
            continue
        d = decls[0]
        calls = [m for m in re.finditer(r"(?<![\w:>.])%s\s*\(" % re.escape(name), blank) if m.start() > d.end()]
        if not calls:
            continue
        struct = "This_%s" % name
        new = text
        for m in sorted(calls, key=lambda m: -m.start()):
            new = new[:m.start()] + "((%s*)this)->%s(" % (struct, name) + new[m.end():]
        ret = d.group(1).strip()
        new = new[:d.start()] + "struct %s {\n    %s %s(%s);\n};\n" % (struct, ret, name, d.group(2)) + new[d.end():]
        text = new
        done.append("%s called as a member through this" % name)
    return text, done


def in_class(blank, pos):
    depth = 0
    for ch in blank[:pos]:
        depth += {"{": 1, "}": -1}.get(ch, 0)
    return depth > 0


RULES = {"template-spec": lambda rel, t: template_spec(t), "dependent-base": lambda rel, t: dependent_base(t),
         "return-struct": lambda rel, t: return_struct(t), "patch": patch, "register-order": register_order,
         "void-return": void_return, "split-temp": lambda rel, t: split_temp(t),
         "code-literal": lambda rel, t: code_literal(t), "pass-through": None,
         "this-call": this_call}


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
            new, w = pass_through(rel, addr, new) if r == "pass-through" else RULES[r](rel, new)
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
