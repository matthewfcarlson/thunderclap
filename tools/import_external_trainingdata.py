#!/usr/bin/env python3
"""Import training data from external decomp repos (halo first).

The halo repo (github.com/punpckhdq/halo, CC0) ships real decompiled C with
per-file symbol maps (address, size, name). We compile that C with our own
cl 13.10 under wibo, disassemble the objects, and emit training rows in the
same schema as hulk-sft: packet-style prompt (asm symbolized from the object,
types/constants/prototypes as context) -> self-contained C translation unit.
No external binary needed: the pair (asm, C) is self-verified by our compile.

  build/venv/bin/python tools/import_external_trainingdata.py halo \
      [--repo build/external/halo] [--out build/farm/dataset/external-halo.jsonl]
      [--jobs 8] [--limit 0] [--max-context 4000] [--max-tu 12000]

Rows carry "source": "halo" and land in a separate file so SFT can order
external-first, our-data-last. Prompts mirror tools/packet.py framing.
"""
import argparse
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from collections import Counter
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

import capstone

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
from compare import Coff, WIBO, MSVC  # noqa: E402

DEFAULT_REPO = os.path.join(ROOT, "build/external/halo")
COMPAT = ["StdDef.h", "xtl.h", "xbdm.h", "condefs.h", "secdef.h", "windows.h"]
SECTION_RE = re.compile(r"^/\* ---------- (\w[\w ]*) \*/\s*$", re.M)
FORBIDDEN_RE = re.compile(r"\b(__asm|_asm|asm|_emit|naked)\b|#\s*pragma")


def sh(msg):
    print(msg, file=sys.stderr)


# ---------------------------------------------------------------- repo config

def load_config(repo):
    cfg = json.load(open(os.path.join(repo, "config/config.json")))
    proj = cfg["projects"][0]
    base = proj.get("options", {})
    per_file = {}
    for o in proj.get("objects", []):
        opts = o.get("options") or {}
        per_file[o["name"].replace("\\", "/")] = {
            "cflags": opts.get("cflags"),
            "defines": opts.get("defines"),
            "include_dirs": opts.get("include_dirs"),
        }
    return {
        "cflags": base.get("cflags") or ["/nologo", "/c", "/O2", "/Oy-", "/MT"],
        "include_dirs": base.get("include_dirs") or [],
        "defines": base.get("defines") or [],
        "per_file": per_file,
    }


def make_compat_include(repo):
    """Tiny shims for the XDK-only headers halo references (angle includes)."""
    d = os.path.join(ROOT, "build/external/halo-compat")
    os.makedirs(d, exist_ok=True)
    shims = {
        "StdDef.h": "#include <stddef.h>\n#include <limits.h>\n",
        "xtl.h": """/* xtl shim: minimal XDK types halo's headers reference in decls only */
#include <stddef.h>
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef long HRESULT;
typedef void *HANDLE;
typedef struct { unsigned char ab[36]; } XNADDR;
typedef struct { unsigned char ab[8]; } XNKID;
typedef struct { unsigned char ab[16]; } XNKEY;
typedef struct _EXCEPTION_POINTERS { void *ExceptionRecord; void *ContextRecord; } EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
""",
        "xbdm.h": "/* xbdm shim: not used by imported units */\n",
        "condefs.h": "/* condefs shim */\n",
        "secdef.h": "/* secdef shim */\n",
        "windows.h": "/* windows shim: NTAPI decl types only */\n#include <stddef.h>\n",
    }
    for name, body in shims.items():
        with open(os.path.join(d, name), "w") as f:
            f.write(body)
    return d


# -------------------------------------------------------------------- compile

def compile_one(repo, rel, flags, includes, defines, outdir):
    src = os.path.join(repo, rel)
    obj = os.path.join(outdir, rel.replace("/", "__") + ".obj")
    env = dict(os.environ, INCLUDE=";".join(includes))
    cmd = [WIBO, os.path.join(MSVC, "Bin/cl.exe")] + flags + [f"/D{d}" for d in defines] + ["/Fo" + obj, rel]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=repo)
    if r.returncode != 0 or not os.path.exists(obj):
        err = (r.stdout + r.stderr).strip().splitlines()
        return rel, None, " | ".join(err[-3:])[:200]
    return rel, obj, None


# ---------------------------------------------------------------- halo source

def parse_symbol_map(head):
    """File-header comment map (placeholder files only):  00093C00 0050:\n\t_name (0000)
    -> {name: (addr, size)}. Code-bearing files have no map; they get pseudo-addrs."""
    out = {}
    addr = size = None
    for line in head.splitlines():
        m = re.match(r"^([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]+):\s*$", line.strip())
        if m:
            addr, size = int(m.group(1), 16), int(m.group(2), 16)
            continue
        m = re.match(r"^\t(\S+) \(([0-9A-Fa-f]{4})\)\s*$", line.rstrip())
        if m and addr is not None:
            out[m.group(1)] = (addr, int(m.group(2), 16))
    return out


def pseudo_addr(name):
    """Stable cosmetic address for the packet header (serving packets carry real
    Hulk addresses; the number itself carries no meaning in training rows)."""
    import hashlib
    return int(hashlib.md5(name.encode()).hexdigest()[:8], 16) % 0x1000000 * 16


def split_sections(text):
    """halo decompiled files are laid out with /* ---------- section */ markers."""
    marks = list(SECTION_RE.finditer(text))
    secs = {}
    for i, m in enumerate(marks):
        end = marks[i + 1].start() if i + 1 < len(marks) else len(text)
        k = m.group(1).strip().lower()
        body = text[m.end():end].strip("\n")
        secs[k] = secs[k] + "\n\n" + body if k in secs else body  # a file may repeat a section
    return secs


def clean_c(s):
    s = re.sub(r"/\* fake name \*/", "", s)
    s = re.sub(r"[ \t]+\n", "\n", s)
    return re.sub(r"\n{3,}", "\n\n", s).strip()


def extract_functions(code_text):
    """(name, definition) for each top-level function in a code section.

    Brace-matching state machine: at depth 0 accumulate header text until '{';
    accept it as a function definition if it has a parameter list, is not a
    typedef/struct/enum, and does not end in ';' or '[' (globals).
    """
    out = []
    header, depth, in_fn, in_macro = [], 0, False, False
    for line in code_text.splitlines():
        if not in_fn and (in_macro or line.lstrip().startswith("#")):
            in_macro = line.rstrip().endswith("\\")  # preprocessor line (+ continuations)
            header = []
            continue
        if not in_fn:
            header.append(line)
            h = "\n".join(header)
            if depth == 0 and h.rstrip().endswith(";"):
                header = []  # declaration or global — reset
                continue
            if "{" in line:
                before_paren = h.split("(")[0] if "(" in h else ""
                looks_like_fn = (
                    re.search(r"\)\s*\{?\s*$", h.rstrip())
                    and not re.match(r"\s*(typedef|struct|union|enum|for|while|if|switch)\b", h.lstrip())
                    and "[" not in before_paren
                    and "=" not in before_paren
                )
                if looks_like_fn:
                    m = re.search(r"([A-Za-z_]\w*)\s*\(", h)
                    name = m.group(1) if m else None
                    in_fn = True
                    depth = line.count("{") - line.count("}")
                    body = [h]
                    if depth == 0:
                        out.append((name, h)); in_fn = False; header = []
                else:
                    header = []
            elif not h.strip():
                header = []
        else:
            body.append(line)
            depth += line.count("{") - line.count("}")
            if depth <= 0:
                out.append((name, "\n".join(body)))
                in_fn, header = False, []
    return out


# ------------------------------------------------------------------- obj asm

def disasm_function(coff, sym, md):
    """Render one obj function in packet.py style: symbolized calls + data refs."""
    name, value, secnum, _, _ = sym
    _, raw, relocs = coff.sections[secnum - 1]
    funcs = coff.function_symbols()
    ends = sorted(s[1] for s in funcs if s[2] == secnum and s[1] > value)
    end = ends[0] if ends else len(raw)
    code = raw[value:end]
    rel_at = {}
    for vaddr, symidx, _ in relocs:
        if value <= vaddr < end:
            rel_at[vaddr - value] = coff.by_index.get(symidx, (None,))[0]
    data_refs, lines = {}, []
    for insn in md.disasm(code, 0):
        text = "%s %s" % (insn.mnemonic, insn.op_str)
        # any reloc whose 4 bytes fall inside this instruction
        rel = next((rel_at[o] for o in range(insn.address, insn.address + insn.size) if o in rel_at), None)
        is_flow = insn.group(capstone.CS_GRP_CALL) or insn.group(capstone.CS_GRP_JUMP)
        if is_flow:
            if rel:
                text = "%s %s" % (insn.mnemonic, pretty_sym(rel))
            elif insn.operands and insn.operands[0].type == capstone.x86.X86_OP_IMM:
                t = insn.operands[0].imm
                if 0 <= t < len(code):
                    text = "%s %04x" % (insn.mnemonic, t)
        elif rel:
            # The relocated field prints as its inline addend: [0], [4], [eax*4 + 0x10], push 0.
            # Replace that number with symbol+addend.
            off = next(o for o in range(insn.address, insn.address + insn.size) if o in rel_at)
            addend = struct.unpack_from("<i", code, off)[0]
            sym = pretty_sym(rel)
            # Which field is relocated decides where the symbol goes: [disp] or the immediate.
            in_disp = insn.disp_offset and off - insn.address == insn.disp_offset
            br = re.search(r"\[[^\]]*\]", insn.op_str)
            lo, hi = (br.span() if in_disp and br else (0, len(insn.op_str)))
            nums = [n for n in re.finditer(r"(?<![\w])(0x[0-9a-fA-F]+|\d+)(?![\w])", insn.op_str)
                    if lo <= n.start() < hi and (in_disp or not br or not br.start() <= n.start() < br.end())]
            hit = [n for n in nums if int(n.group(1), 0) in (addend, addend & 0xFFFFFFFF)]
            if hit:
                n = hit[-1]
                rep = sym if addend == 0 else "%s%+#x" % (sym, addend)
                ops = insn.op_str[: n.start(1)] + rep + insn.op_str[n.end(1):]
                text = "%s %s" % (insn.mnemonic, ops)
            data_refs[sym] = True
        lines.append("  %04x  %s" % (insn.address, text))
    return lines, sorted(data_refs)


def pretty_sym(name):
    if not name:
        return "ext"
    return re.sub(r"^_", "", name)  # cdecl C symbols carry a leading underscore


# ---------------------------------------------------------------- assembly

def build_def_index(repo):
    """name -> definition, across all .c and .h files (halo headers hold
    __inline vector/math helpers that MSVC emits when not inlined)."""
    index = {}
    for p in Path(repo, "source").rglob("*.[ch]"):
        rel = str(p.relative_to(repo))
        try:
            text = open(p, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        for k in ("public code", "private code"):
            for name, d in extract_functions(split_sections(text).get(k, "")):
                index.setdefault(name, (rel, d))
    return index


CODE_SECTIONS = ("public code", "private code")
C_WORDS = set("""auto break case char const continue default do double else enum extern float for goto if
int long register return short signed sizeof static struct switch typedef union unsigned void volatile while
__cdecl __stdcall __fastcall __inline inline defined""".split())
TYPE_STARTS = ("#", "typedef", "struct", "union", "enum")
IDENT_RE = re.compile(r"(?<![\w.>])[A-Za-z_]\w*")


HALO_DEFINES = {"DEBUG", "xbox"}


def preproc_true(kw, arg):
    """Evaluate #if/#ifdef/#ifndef for halo's build (/DDEBUG /Dxbox); unknown #if exprs: taken."""
    if kw == "ifdef":
        return arg in HALO_DEFINES
    if kw == "ifndef":
        return arg not in HALO_DEFINES
    m = re.fullmatch(r"(!)?\s*defined\s*\(?\s*(\w+)\s*\)?", arg)
    if m:
        return (m.group(2) in HALO_DEFINES) != bool(m.group(1))
    return arg not in ("0",)


def decl_chunks(text):
    """Split a declaration section into top-level declarations: [(names, text)].

    #define lines (with continuations) and ;-terminated statements at brace depth 0.
    names = what the chunk declares: macro, tag, typedef, enumerators, function, global.
    """
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    out, cur, depth = [], [], 0
    lines = text.splitlines()
    active = [True]  # #if stack: keep only the branch halo's build takes
    i = 0
    while i < len(lines):
        line = lines[i]
        s = line.strip()
        if s.startswith("#"):
            block = [line]
            while block[-1].rstrip().endswith("\\") and i + 1 < len(lines):
                i += 1
                block.append(lines[i])
            i += 1
            d = re.match(r"#\s*(\w+)\s*(.*)", s)
            kw, arg = (d.group(1), d.group(2).strip()) if d else ("", "")
            if kw in ("if", "ifdef", "ifndef"):
                active.append(active[-1] and preproc_true(kw, arg))
            elif kw in ("else", "elif") and len(active) > 1:
                active[-1] = active[-2] and not active[-1] and (kw == "else" or preproc_true("if", arg))
            elif kw == "endif" and len(active) > 1:
                active.pop()
            elif kw == "define" and active[-1] and not cur:
                out.append(({re.match(r"(\w+)", arg).group(1)}, "\n".join(block).strip()))
            continue
        if not active[-1]:
            i += 1
            continue
        if s or cur:
            cur.append(line)
            depth += line.count("{") - line.count("}")
            if depth <= 0 and s.endswith(";"):
                out.append((chunk_names("\n".join(cur)), "\n".join(cur).strip()))
                cur, depth = [], 0
        i += 1
    return [(n, t) for n, t in out if n]


def chunk_names(t):
    names = set()
    flat = re.sub(r"\s+", " ", t)
    m = re.match(r"(?:typedef\s+)?(?:static\s+|extern\s+)?(?:struct|union|enum)\s+(\w+)\s*\{", flat)
    if m:
        names.add(m.group(1))
    if re.match(r"(?:typedef\s+)?enum\b", flat):
        body = flat[flat.find("{") + 1: flat.rfind("}")]
        names.update(re.findall(r"(?:^|,)\s*([A-Za-z_]\w*)", body))
    # Declarator part: drop brace bodies (struct body, initializer) and the initializer.
    shell = flat
    while re.search(r"\{[^{}]*\}", shell):
        shell = re.sub(r"\{[^{}]*\}", " ", shell)
    shell = re.sub(r"=.*;\s*$", ";", shell)
    if shell.startswith("typedef"):
        fp = re.search(r"\(\s*(?:__\w+\s+)?\*\s*(\w+)\s*\)\s*\(", shell)
        m = fp or re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*;\s*$", shell)
    elif "(" in shell:  # prototype
        m = re.search(r"(\w+)\s*\([^()]*(?:\([^()]*\)[^()]*)*\)\s*;\s*$", shell)
    else:  # global, or a bare struct/enum definition (declarator-less)
        m = re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*;\s*$", shell)
        if re.match(r"(?:struct|union|enum)\s+\w+\s*\{.*\}\s*;\s*$", flat):
            m = None  # plain definition, no declarator
    if m and m.group(1) not in C_WORDS:
        names.add(m.group(1))
    return names


# <math.h>/<stddef.h> names halo gets from system headers; the farm forbids #include.
BUILTIN_DECLS = {
    "NULL": "#define NULL 0",
    "M_PI": "#define M_PI 3.14159265358979323846",
    "rand": 'extern "C" int rand(void);',
    "srand": 'extern "C" void srand(unsigned int);',
    "qsort": 'extern "C" void qsort(void *, unsigned int, unsigned int, int (__cdecl *)(const void *, const void *));',
    **{f: 'extern "C" double %s(double);' % f for f in
       ("sin", "cos", "tan", "sqrt", "fabs", "asin", "acos", "atan", "exp", "log", "log10", "floor", "ceil")},
    "atan2": 'extern "C" double atan2(double, double);',
    "fmod": 'extern "C" double fmod(double, double);',
    "pow": 'extern "C" double pow(double, double);',
    "memset": 'extern "C" void *memset(void *, int, unsigned int);',
    "memcpy": 'extern "C" void *memcpy(void *, const void *, unsigned int);',
    "memmove": 'extern "C" void *memmove(void *, const void *, unsigned int);',
    "memcmp": 'extern "C" int memcmp(const void *, const void *, unsigned int);',
    "strlen": 'extern "C" unsigned int strlen(const char *);',
    "strcmp": 'extern "C" int strcmp(const char *, const char *);',
    "strcpy": 'extern "C" char *strcpy(char *, const char *);',
    "strncpy": 'extern "C" char *strncpy(char *, const char *, unsigned int);',
    "strcat": 'extern "C" char *strcat(char *, const char *);',
    "abs": 'extern "C" int abs(int);',
}


def build_decl_index(repo):
    """rel -> {name: [chunk]} for every source file's declaration sections."""
    per_file = {}
    for p in Path(repo, "source").rglob("*.[ch]"):
        rel = str(p.relative_to(repo))
        text = open(p, encoding="utf-8", errors="replace").read()
        idx = {}
        for k, body in split_sections(text).items():
            if k in CODE_SECTIONS:
                for name, d in extract_functions(body):
                    if not name:
                        continue
                    head = d[: d.index("{")].rstrip()
                    if re.search(r"\b(__inline|inline)\b", head):
                        t = d.strip()  # inlined into callers: they need the body
                    else:
                        t = re.sub(r"^\s*static\s+", "", head) + ";"
                    idx.setdefault(name, [t])
                for names, t in decl_chunks(body):  # macros defined between functions
                    if t.startswith("#"):
                        for n in names:
                            idx.setdefault(n, [t])
                continue
            for names, t in decl_chunks(re.sub(r"/\*=.*?\*/", "", body, flags=re.S)):
                if t.startswith("static ") and "(" in t and "{" not in t:
                    t = t[len("static "):]  # we define every function extern (see build_rows)
                for n in names:
                    idx.setdefault(n, [])
                    if t not in idx[n]:
                        idx[n].append(t)
        per_file[rel] = idx
    merged = {n: [t] for n, t in BUILTIN_DECLS.items()}
    for rel in sorted(per_file, key=lambda r: (not r.endswith(".h"), r)):  # headers first
        for n, ts in per_file[rel].items():
            merged.setdefault(n, ts)
    return per_file, merged


def closure(fn, own, merged, self_name=None):
    """Declarations fn needs, dependencies first: own-file definitions win over headers."""
    emitted, order = set(), []
    seen = {self_name}  # idents resolved with every kind of declaration
    seen_types = set()  # idents resolved inside a type (types/macros only)

    def visit(text, depth, types_only):
        if types_only:  # "struct x *p" needs no definition of x (C++ elaborated type)
            text = re.sub(r"\b(?:struct|union)\s+\w+(?=\s*(?:const\s*)?\*)", "", text)
        for ident in dict.fromkeys(IDENT_RE.findall(text)):
            if ident in seen or ident in C_WORDS or (types_only and ident in seen_types):
                continue
            (seen_types if types_only else seen).add(ident)
            for chunk in own.get(ident) or merged.get(ident) or []:
                # Inside a struct/typedef/global only follow types and macros: a field
                # named like a global must not drag that global (and its types) in.
                if chunk in emitted or depth > 12 or (types_only and not chunk.startswith(TYPE_STARTS)):
                    continue
                emitted.add(chunk)
                # Macro and inline-function bodies call things: follow everything there.
                is_code = chunk.startswith("#") or ("{" in chunk and not chunk.startswith(TYPE_STARTS[1:])
                                                    and re.match(r"[^{=;]*\)\s*\{", chunk, re.S))
                visit(chunk, depth + 1, not is_code)
                order.append(chunk)

    visit(fn, 0, False)
    return order


def build_rows(repo, rel, obj_path, cfg, args, def_index, decls):
    text = open(os.path.join(repo, rel), encoding="utf-8", errors="replace").read()
    if FORBIDDEN_RE.search(text):
        return [], "inline asm/pragma"
    secs = split_sections(text)
    if not secs:
        return [], "no sections"
    coff = Coff(obj_path)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.syntax = capstone.CS_OPT_SYNTAX_INTEL
    md.detail = True

    per_file, merged = decls
    own = per_file.get(rel, {})

    rows, skipped = [], Counter()
    for sym in coff.function_symbols():
        sname = pretty_sym(sym[0])
        if not sname or sname.startswith("_") or "$" in sname:
            skipped["odd_name"] += 1
            continue
        try:
            lines, drefs = disasm_function(coff, sym, md)
        except Exception as e:
            skipped["disasm_error"] += 1
            continue
        if len(coff.function(sym)[1].rstrip(b"\xcc")) < 4:
            skipped["trivial"] += 1  # bare ret / xor eax,eax: nothing to learn
            continue
        hit = def_index.get(sname)
        fn = hit[1] if hit else None
        if not fn:
            skipped["no_source_def"] += 1
            continue
        # An unreferenced static/inline function is not emitted at all: define it extern.
        fn = re.sub(r"^\s*(?:static\s+|__inline\s+|inline\s+)+", "", fn)
        addr = pseudo_addr(sname)
        size = len(coff.function(sym)[1])
        asm = "\n".join(lines)
        # Self-contained TU: exactly the declarations fn uses (types, constants,
        # prototypes, globals from this file or any header), then fn. The prompt
        # shows the same declarations as context.
        context = clean_c("\n\n".join(closure(fn, own, merged, sname)))
        if len(context) > args.max_context:
            skipped["context_too_large"] += 1
            continue
        tu = "\n\n".join(x for x in (context, fn) if x and x.strip())
        if args.flags_line:  # halo builds with /Oy- (ebp frames); farm TUs say so in their first line
            tu = args.flags_line + "\n" + tu
        if len(tu) + len(asm) + len(context) > args.max_tu:
            skipped["too_large"] += 1
            continue
        head = ["Target function 0x%08x  %s  (%d bytes)" % (addr, sname, size)]
        parts = head + ["", "Assembly (offsets relative to function start):", asm]
        if drefs:
            parts += ["", "Data referenced:"] + ["  %s" % d for d in drefs]
        if context:
            parts += ["", "Context (types, constants, prototypes from the original source):", context]
        packet = "\n".join(parts)
        rows.append({
            "_fn": fn,
            "id": "halo:%s:%s" % (rel, sname),
            "addr": "0x%08x" % addr,
            "name": sname,
            "size_bytes": size,
            "source": "halo",
            "messages": [],  # filled by caller (needs the system prompt)
            "packet": packet,
            "tu": tu,
            "_orig": coff.function(sym)[1].hex(),
            "_sym": sname,
        })
    return rows, dict(skipped)


def verify_row(row):
    """Compile the answer TU alone, exactly as the farm would (no includes, farm flags +
    its cl-flags line), and require byte-identical code to the original object's function.
    Drops answers that lean on types the prompt doesn't show, and C that isn't valid C++."""
    from compare import CompileError, DEFAULT_FLAGS, compile_obj, diff, strip_padding
    with tempfile.TemporaryDirectory(prefix="halo-v-") as tmp:
        src = os.path.join(tmp, "tu.cpp")
        with open(src, "w") as f:
            f.write(row["tu"])
        try:
            coff = Coff(compile_obj(src, DEFAULT_FLAGS, tmp))
        except CompileError as e:
            err = next((l for l in str(e).splitlines() if " error " in l), str(e)[:100])
            return row["id"], "verify_compile", re.sub(r"^.*?error ", "", err)[:120]
        name = row["_sym"]
        syms = [s for s in coff.function_symbols()
                if s[0] in ("_" + name, name) or s[0].startswith("?%s@@" % name)]
        if not syms:
            return row["id"], "verify_no_function", None
        _, ours, mask = coff.function(syms[0])
        d = diff(strip_padding(bytes.fromhex(row["_orig"])), strip_padding(ours), mask)
        if os.environ.get("HALO_DUMP_MISMATCH") and not d["exact"]:
            with open(os.environ["HALO_DUMP_MISMATCH"], "a") as f:
                f.write(json.dumps({"id": row["id"], "tu": row["tu"], "orig": row["_orig"], "sym": row["_sym"], "score": d["matched"] / d["total"],
                                    "rows": [r for r in d["rows"] if r[0] != "  "][:6]}) + "\n")
        return row["id"], None if d["exact"] else "verify_mismatch", None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source", choices=["halo"])
    ap.add_argument("--repo", default=DEFAULT_REPO)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/farm/dataset/external-halo.jsonl"))
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0, help="only the first N source files")
    ap.add_argument("--max-context", type=int, default=8000)
    ap.add_argument("--max-tu", type=int, default=28000, help="packet+TU cap in chars (~7k tokens)")
    ap.add_argument("--no-verify", action="store_true", help="skip the standalone compile check")
    args = ap.parse_args()
    args.flags_line = "// cl-flags: /Oy-"

    cfg = load_config(args.repo)
    compat = make_compat_include(args.repo)
    includes = [os.path.join(MSVC, "Include"), compat] + [
        os.path.join(args.repo, d) for d in cfg["include_dirs"]]
    # halo units expect the headers.h PCH to have pulled in the world; force-include it.
    flags = cfg["cflags"] + ["/FIheaders.h"]

    files = []
    for p in Path(args.repo, "source").rglob("*.c"):
        rel = str(p.relative_to(args.repo))
        if rel.endswith("headers.c"):
            continue
        files.append(rel)
    files.sort()
    if args.limit:
        files = files[: args.limit]
    sh("files: %d" % len(files))

    rows, fails, seen, names_seen = [], Counter(), set(), {}
    def_index = build_def_index(args.repo)
    decls = build_decl_index(args.repo)
    sh("def index: %d names" % len(def_index))
    with tempfile.TemporaryDirectory(prefix="halo-obj-") as outdir:
        with ProcessPoolExecutor(max_workers=args.jobs) as ex:
            futs = [ex.submit(compile_one, args.repo, rel, flags, includes, cfg["defines"], outdir)
                    for rel in files]
            for f in futs:
                rel, obj, err = f.result()
                if err:
                    fails["compile"] += 1
                    continue
                got, why = build_rows(args.repo, rel, obj, cfg, args, def_index, decls)
                if isinstance(why, dict):
                    for k, v in why.items():
                        fails[k] += v
                elif why:
                    fails[why] += 1
                # inline helpers repeat across objects; dedupe by definition text,
                # but keep distinct same-named statics (suffixed ids)
                keep = []
                for r in got:
                    key = hash(r.pop("_fn"))
                    if key in seen:
                        continue
                    if r["name"] in names_seen:
                        r["id"] += ":%d" % names_seen[r["name"]]
                        r["name"] += "_%d" % names_seen[r["name"]]
                    names_seen[r["name"]] = names_seen.get(r["name"], 0) + 1
                    seen.add(key)
                    keep.append(r)
                rows.extend(keep)

    if not args.no_verify:
        with ProcessPoolExecutor(max_workers=args.jobs) as ex:
            results = list(ex.map(verify_row, rows, chunksize=8))
        bad = {rid: why for rid, why, _ in results if why}
        for why in bad.values():
            fails[why] += 1
        errs = Counter(re.sub(r"'[^']*'", "'X'", d) for _, _, d in results if d)
        sh("top compile errors: %s" % errs.most_common(8))
        errors_by_ident = Counter(m for _, _, d in results if d for m in re.findall(r"'([^']*)'", d)[:1])
        sh("top missing identifiers: %s" % errors_by_ident.most_common(25))
        rows = [r for r in rows if r["id"] not in bad]
        sh("verified: %d rows compile standalone and match" % len(rows))

    # system prompt: byte-parity with our own dataset
    sft0 = os.path.join(ROOT, "build/farm/dataset/hulk-sft-v1.jsonl")
    if not os.path.exists(sft0):
        raise SystemExit("run tools/export_dataset.py first (need the system prompt)")
    system = json.loads(open(sft0).readline())["messages"][0]["content"]

    with open(args.out, "w") as f:
        for r in rows:
            r.pop("_fn", None)
            r.pop("_orig", None)
            r.pop("_sym", None)
            # Same shape as hulk-sft: the answer is a submit_cpp call, the prompt ends like
            # farm/src/prompt.ts taskPrompt. All external rows train; eval stays on Hulk.
            r["messages"] = [
                {"role": "system", "content": system},
                {"role": "user", "content": r["packet"] + "\n\nYou have 8 submissions. Call submit_cpp now."},
                {"role": "assistant", "content": "", "tool_calls": [{"name": "submit_cpp", "arguments": {"code": r["tu"]}}]},
            ]
            r["split"] = "train"
            r["has_thinking"] = False
            f.write(json.dumps(r) + "\n")
    sh("rows: %d -> %s" % (len(rows), args.out))
    sh("fails: %s" % dict(fails))
    stats = {"files": len(files), "rows": len(rows), "fails": dict(fails)}
    json.dump(stats, open(args.out + ".stats.json", "w"), indent=1)


if __name__ == "__main__":
    main()
