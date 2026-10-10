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
        secs[m.group(1).strip().lower()] = text[m.end():end].strip("\n")
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
    header, depth, in_fn = [], 0, False
    for line in code_text.splitlines():
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
            m = re.search(r"\[\s*(0x[0-9a-fA-F]+|0)\s*\]", text)
            if m:  # absolute addressing: dword ptr [<reloc>]
                text = text[: m.start(1) - 1] + pretty_sym(rel) + text[m.end(1) + 1:]
                data_refs[pretty_sym(rel)] = True
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


def build_rows(repo, rel, obj_path, cfg, args, def_index):
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

    # /*= ... */ blocks are commented initializer dumps, not declarations.
    strip_init = lambda s: re.sub(r"/\*=.*?\*/", "", s, flags=re.S)
    context = "\n\n".join(filter(None, (clean_c(strip_init(secs[k])) for k in ("constants", "macros", "structures", "prototypes") if secs.get(k))))
    globals_c = clean_c(strip_init(secs.get("globals", "")))
    if len(context) > args.max_context:
        return [], "context too large"

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
        hit = def_index.get(sname)
        fn = hit[1] if hit else None
        if not fn:
            skipped["no_source_def"] += 1
            continue
        addr = pseudo_addr(sname)
        size = len(coff.function(sym)[1])
        asm = "\n".join(lines)
        # self-contained TU: types/constants/prototypes + globals + the function
        tu = "\n\n".join(x for x in (context, globals_c, fn) if x and x.strip())
        if not tu.strip():
            skipped["empty_tu"] += 1
            continue
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
        })
    return rows, dict(skipped)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source", choices=["halo"])
    ap.add_argument("--repo", default=DEFAULT_REPO)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/farm/dataset/external-halo.jsonl"))
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0, help="only the first N source files")
    ap.add_argument("--max-context", type=int, default=8000)
    ap.add_argument("--max-tu", type=int, default=28000, help="packet+TU cap in chars (~7k tokens)")
    args = ap.parse_args()

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
                got, why = build_rows(args.repo, rel, obj, cfg, args, def_index)
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

    # system prompt: byte-parity with our own dataset
    sft0 = os.path.join(ROOT, "build/farm/dataset/hulk-sft-v1.jsonl")
    if not os.path.exists(sft0):
        raise SystemExit("run tools/export_dataset.py first (need the system prompt)")
    system = json.loads(open(sft0).readline())["messages"][0]["content"]

    with open(args.out, "w") as f:
        for r in rows:
            r.pop("_fn", None)
            r["messages"] = [
                {"role": "system", "content": system},
                {"role": "user", "content": r["packet"]},
                {"role": "assistant", "content": r["tu"]},
            ]
            f.write(json.dumps(r) + "\n")
    sh("rows: %d -> %s" % (len(rows), args.out))
    sh("fails: %s" % dict(fails))
    stats = {"files": len(files), "rows": len(rows), "fails": dict(fails)}
    json.dump(stats, open(args.out + ".stats.json", "w"), indent=1)


if __name__ == "__main__":
    main()
