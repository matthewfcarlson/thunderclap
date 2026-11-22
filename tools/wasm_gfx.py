#!/usr/bin/env python3
"""The pddi front end for the wasm32 module (docs/wasm-port.md "The macOS app").

The front end (src/platform/sdl/pddi/, the classes that stand in for pure3d's d3d classes) is compiled like the tree's
TUs (tools/wasm_port.py): clang's MS ABI front end for i686-pc-windows-msvc, then bind_tu's rewrite to wasm32 IR. Its
`GameBase::FUN_<addr>` calls bind to the tree's pddi base functions by address, its vftable slots get dispatch entries
(local functions used as values), and every other name is the module's own: the C library (emscripten's), the draw
sink's bridge (bgfx_bridge.h, the wasm side's src/platform/wasm/gfx/gfx.c: `hulk` imports) and operator new / delete
(the arena: hulk_gfx_op_*). HULK_PDDI_NATIVE selects the bridge sink, HULK_PDDI_WASM keeps the game's 32-bit layout.

  HULK_WASM_GFX=1 HULK_WASM_DIR=OUT build/venv/bin/python tools/wasm_gfx.py compile [--jobs 2]   # -> OUT/gfx/pddi.o

Needs OUT/compile.json (wasm_port.py compile: the game's definitions and their signatures) and mingw-w64's headers
(tools/wine_gfx.py fetch). The objects are linked by `wasm_port.py link` when HULK_WASM_GFX=1."""
import argparse
import concurrent.futures
import hashlib
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import wasm_port as wp  # noqa: E402

ROOT = wp.ROOT
PDDI = os.environ.get("HULK_PDDI_SRC") or os.path.join(ROOT, "src/platform/sdl/pddi")
TP = os.path.join(ROOT, "build/third_party")
MINGW = os.path.join(TP, "src/mingw-w64/mingw-w64-headers")
# the front end's units: every pddi unit but the sink (the runner's) and the Wine image's CRT glue
SKIP = ("bgfx_sink.cpp", "win32_glue.cpp")
# synthetic addresses of local functions used as values: TU indices after the tree's
TU_BASE = 4000
# operator new / delete: the arena (src/platform/wasm/gfx/gfx.c), as the Wine image's pddi objects take msvcrt's
CXX_RENAME = {"??2@YAPAXI@Z": "hulk_gfx_op_new", "??3@YAXPAX@Z": "hulk_gfx_op_delete",
              "??_U@YAPAXI@Z": "hulk_gfx_op_new_array", "??_V@YAXPAX@Z": "hulk_gfx_op_delete_array"}
# the C library's allocations too (texture levels, prim buffers' copies): the arena, so the front end's objects never
# hold pointers into the module's own malloc heap, whose layout follows the host's history (wroll1)
C_RENAME = {"malloc": "hulk_gfx_malloc", "calloc": "hulk_gfx_calloc", "realloc": "hulk_gfx_realloc",
            "free": "hulk_gfx_free"}
# The front end's statics are game state (wroll1): its objects are in the arena and the statics point at them
# (the pending uploads, the active shader, the device) or count with them (texture ordinals, prim buffer serials), so
# a snapshot carries them. Every mutable global goes to one data section, which src/platform/wasm/gfx/gfx.c hands
# the snapshot (__start_/__stop_hulk_pddi_state) with its own resource table. Left out: the frame pacer's host times.
STATE_SECTION = "hulk_pddi_state"
HOST_STATICS = ("platformFramePace",)


def state_section(ir):
    """Every mutable internal global of the bound front end in STATE_SECTION (one line each: `@x = internal global T
    V, align N`)."""
    out, n = [], 0
    for line in ir.split("\n"):
        if (line.startswith("@") and " = internal global " in line and ", section " not in line
                and not any(h in line.split(" = ", 1)[0] for h in HOST_STATICS)):
            line, k = re.subn(r", align (\d+)$", r', section "%s", align \1' % STATE_SECTION, line)
            if not k:
                raise SystemExit("wasm_gfx: unexpected global form: %s" % line[:200])
            n += 1
        out.append(line)
    return "\n".join(out), n


def units():
    return sorted(f for f in os.listdir(PDDI) if f.endswith(".cpp") and f not in SKIP)


def front_flags():
    gen = os.path.join(wp.OUT, "gfx", "gen")
    return [wp.CLANG, "--target=i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility", "-std=c++20",
            "-O1", "-Xclang", "-disable-llvm-passes", "-fno-strict-return", "-fno-finite-loops", "-fno-builtin",
            "-S", "-emit-llvm", "-fno-exceptions", "-fno-rtti", "-fno-threadsafe-statics", "-fno-sized-deallocation",
            "-fno-aligned-allocation", "-nostdinc++", "-isystem", os.path.join(MINGW, "crt"), "-isystem",
            os.path.join(MINGW, "include"), "-fgnuc-version=4.2.1", "-D_X86_=1", "-D_WIN32_WINNT=0x0601",
            "-DWINVER=0x0601", "-DWIN32_LEAN_AND_MEAN", "-DNOMINMAX", "-D_CRT_SECURE_NO_WARNINGS",
            "-D_HAS_EXCEPTIONS=0", "-D__MSVCRT_VERSION__=0x700", "-D__USE_MINGW_ANSI_STDIO=0",
            "-Wno-ignored-attributes", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror",
            "-ffp-contract=off", "-ffp-eval-method=source",
            # bx's scalar SIMD (its SSE intrinsics have no wasm lowering) and mingw-w64's math without its x87 asm
            "-U__SSE2__", "-U__SSE__", "-D__CRT__NO_INLINE", "-I" + PDDI, "-I" + gen, "-I" + os.path.join(TP, "src/bx/include"),
            "-I" + os.path.join(TP, "src/bx/include/compat/msvc"), "-I" + os.path.dirname(PDDI),
            "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_NATIVE=1", "-DHULK_PDDI_WASM=1", "-DBX_CONFIG_DEBUG=0"]


def gen_dir():
    """pddi_combiners.h (the self-test's combiner keys); the front end embeds no shaders (the sink is the runner's)."""
    import wine_gfx
    gen = os.path.join(wp.OUT, "gfx", "gen")
    wine_gfx.embed_shaders(gen, [])
    return gen


def front_unit(name):
    """x86 IR of one unit (cached by its text, the headers and the flags): path, or (None, error)."""
    d = os.path.join(wp.OUT, "gfx", "ir")
    os.makedirs(d, exist_ok=True)
    src = os.path.join(PDDI, name)
    flags = front_flags()
    key = hashlib.sha1(open(src, "rb").read() + " ".join(flags).encode() +
                       b"".join(open(os.path.join(PDDI, h), "rb").read() for h in sorted(os.listdir(PDDI))
                                if h.endswith(".h"))).hexdigest()[:16]
    ll = os.path.join(d, "%s.%s.ll" % (name[:-4], key))
    if not os.path.exists(ll):
        r = subprocess.run(flags + [src, "-o", ll + ".tmp"], capture_output=True, text=True, errors="replace")
        if r.returncode:
            return None, "front: " + r.stderr[-3000:]
        os.replace(ll + ".tmp", ll)
    return ll, None


def cmd_compile(a):
    """The units' x86 IR, linked into one module (so a vftable or a function pointer that names another unit's
    function is a local function used as a value: a synthetic address with a dispatch entry), bound once."""
    rep = json.load(open(os.path.join(wp.OUT, "compile.json")))
    sigs = {int(k, 16): v for k, v in rep["sigs"].items()}
    deftys = {int(k, 16): tuple(v) for k, v in rep["deftys"].items()}
    d = os.path.join(wp.OUT, "gfx")
    os.makedirs(d, exist_ok=True)
    gen_dir()
    us = units()
    lls, errs = [], {}
    with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
        for name, (ll, err) in zip(us, ex.map(front_unit, us)):
            if err:
                errs[name] = err
            else:
                lls.append(ll)
    keep = {os.path.basename(x) for x in lls}
    for f in os.listdir(os.path.join(d, "ir")):
        if f not in keep:
            os.unlink(os.path.join(d, "ir", f))
    obj = os.path.join(d, "pddi.o")
    info = {}
    if not errs:
        key = hashlib.sha1(" ".join(sorted(keep)).encode() + wp.VERSION.encode()
                           + open(os.path.abspath(__file__), "rb").read()).hexdigest()[:16]
        stamp = os.path.join(d, "pddi.key")
        if not (os.path.exists(obj) and os.path.exists(stamp) and open(stamp).read() == key):
            linked = os.path.join(d, "pddi.x86.ll")
            r = subprocess.run([os.path.join(wp.LLVM, "llvm-link"), "-S"] + lls + ["-o", linked], capture_output=True,
                               text=True, errors="replace")
            if r.returncode:
                errs["llvm-link"] = r.stderr[-3000:]
            else:
                ir = open(linked, errors="surrogateescape").read()
                if "llvm.global_ctors" in ir:
                    errs["static constructors"] = "the module runs none for the front end: make them lazy"
                else:
                    for old, new in CXX_RENAME.items():
                        ir = ir.replace('@"%s"' % old, "@" + new)
                    for old, new in C_RENAME.items():
                        ir = re.sub(r'(?<![\w."$?@])@%s(?=[\s(),])' % old, "@" + new, ir)
                    ir = wp.prepare(ir)
                    text, info = wp.bind_tu(ir, os.path.join(PDDI, "pddi.cpp"), TU_BASE, {}, {}, {}, set(sigs), sigs,
                                            deftys)
                    text, info["state_globals"] = state_section(text)
                    bound = os.path.join(d, "pddi.ll")
                    with open(bound, "w", errors="surrogateescape") as f:
                        f.write(text)
                    r = subprocess.run([wp.CLANG] + wp.BACK + ["-x", "ir", bound, "-o", obj], capture_output=True,
                                       text=True, errors="replace")
                    if r.returncode:
                        errs["back"] = r.stderr[-3000:]
                    else:
                        open(stamp, "w").write(key)
                        os.unlink(linked)
    for f in os.listdir(d):
        if f.endswith(".o") and f != "pddi.o":
            os.unlink(os.path.join(d, f))
    json.dump({"objects": [] if errs else [obj], "failed": errs, "info": info},
              open(os.path.join(d, "gfx.json"), "w"), indent=1)
    print("gfx: %d front-end units -> %s%s" % (len(us), os.path.relpath(obj, wp.OUT), " FAILED" if errs else ""))
    for k, v in errs.items():
        print("  %s: %s" % (k, v[:2000]))
    return 1 if errs else 0


def objects():
    """The front end's objects for the link (HULK_WASM_GFX=1)."""
    p = os.path.join(wp.OUT, "gfx", "gfx.json")
    if not os.path.exists(p):
        raise SystemExit("HULK_WASM_GFX=1: no front end (tools/wasm_gfx.py compile)")
    j = json.load(open(p))
    if j["failed"]:
        raise SystemExit("HULK_WASM_GFX=1: the front end failed to compile: %s" % ", ".join(j["failed"]))
    return j["objects"]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("compile")
    c.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args(argv)
    return {"compile": cmd_compile}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
