#!/usr/bin/env python3
"""The graphics backend for the native links (`native_mac.py link --ld --gfx`; docs/native-mac.md section 12).

The pddi front end (src/platform/sdl/pddi/, the classes that stand in for the game's d3d pddi classes) is compiled
like the tree: the MS C++ ABI front end for aarch64-pc-windows-msvc (the game calls its objects through MS vftable
slots and binds its base slots to the tree's pddi base functions by address), the IR retargeted to the host
(native_mac.retarget), with HULK_PDDI_GAME + HULK_PDDI_NATIVE. Its C library headers are mingw-w64's (as the Wine
build's pddi objects; headers only). The bgfx sink (bgfx_sink.cpp) and the host half of the C bridge
(bgfx_bridge.cpp, HULK_PDDI_BRIDGE_HOST) are compiled for the host against the host bgfx (tools/wine_gfx.py build:
Metal + noop on macOS), with the program's window and event code (platform_events.cpp); the two sides meet only in
the bridge's extern "C" functions (bgfx_bridge.h).

  build/venv/bin/python tools/native_pddi.py compile [--out DIR]    # both sides (a check without a link)
  build/venv/bin/python tools/native_pddi.py layout                 # the front end's game-record offsets vs gen

Inputs: build/third_party (wine_gfx.py fetch + build: bx/bimg/bgfx sources and the host libraries; shaders: the
compiled Metal shaders, embedded), SDL3 (native_bind.MAC_SDL)."""
import argparse
import concurrent.futures
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import clang_probe as cp  # noqa: E402

ROOT = cp.ROOT
# HULK_PDDI_SRC: another copy of the pddi directory (a lane's uncommitted work: never the shared working copy's,
# whose edits make the Wine build's pddi inputs stale for everyone; its parent stands for src/platform/sdl)
PDDI = os.environ.get("HULK_PDDI_SRC") or os.path.join(ROOT, "src/platform/sdl/pddi")
TP = os.path.join(ROOT, "build/third_party")
MINGW = os.path.join(TP, "src/mingw-w64/mingw-w64-headers")
PLATFORM_EVENTS = os.path.join(os.path.dirname(PDDI), "platform_events.cpp")
# the front end's units natively: every pddi unit but the sink (host side) and the Wine image's CRT glue
MS_SKIP = ("bgfx_sink.cpp", "win32_glue.cpp")
HOST_UNITS = [os.path.join(PDDI, "bgfx_sink.cpp"), os.path.join(PDDI, "bgfx_bridge.cpp")]
# bgfx's Metal renderer and the window (as tools/wine_gfx.py's smoke test links them)
MAC_GFX_FRAMEWORKS = ["Cocoa", "QuartzCore", "Metal", "MetalKit", "IOKit", "VideoToolbox"]
# bgfx's configuration: the host build's (tools/wine_gfx.py COMMON_DEFS + target_cfg("host"))
BGFX_DEFS = ["-DBX_CONFIG_DEBUG=0", "-DBIMG_CONFIG_DECODE_ASTC=0", "-DBGFX_CONFIG_RENDERER_WEBGPU=0",
             "-DBGFX_CONFIG_MULTITHREADED=0", "-D__STDC_LIMIT_MACROS", "-D__STDC_FORMAT_MACROS",
             "-D__STDC_CONSTANT_MACROS"]


def ms_units():
    return sorted(os.path.join(PDDI, f) for f in os.listdir(PDDI)
                  if f.endswith(".cpp") and f not in MS_SKIP)


def gen_dir(out, profiles):
    """pddi_shaders.h (the compiled shaders of `profiles`, embedded) and pddi_combiners.h in OUT/gen."""
    import wine_gfx
    gen = os.path.join(out, "gen")
    wine_gfx.embed_shaders(gen, profiles)
    return gen


def inputs_missing():
    need = [MINGW, os.path.join(TP, "src/bx/include"), os.path.join(TP, "src/bgfx/include"),
            os.path.join(TP, "out/host/lib/bgfx.a")]
    return [os.path.relpath(p, ROOT) for p in need if not os.path.exists(p)]


def ms_flags(gen, triple_front="aarch64-pc-windows-msvc"):
    """The front end's flags for the pddi units (MS ABI, mingw-w64's C headers, the host bgfx's bx headers for
    bx/math.h's inline functions; as the Wine build's pddi objects, tools/wine_gfx.py pddi_win32)."""
    return ["--target=" + triple_front, "-fms-extensions", "-fms-compatibility", "-std=c++20", "-O2",
            "-fno-exceptions", "-fno-rtti", "-fno-threadsafe-statics", "-fno-sized-deallocation", "-nostdinc++",
            "-isystem", os.path.join(MINGW, "crt"), "-isystem", os.path.join(MINGW, "include"),
            "-fgnuc-version=4.2.1", "-D_ARM64_=1", "-D_WIN32_WINNT=0x0601", "-DWINVER=0x0601",
            "-DWIN32_LEAN_AND_MEAN", "-DNOMINMAX", "-D_CRT_SECURE_NO_WARNINGS", "-D_HAS_EXCEPTIONS=0",
            "-D__MSVCRT_VERSION__=0x700", "-D__USE_MINGW_ANSI_STDIO=0", "-Wno-ignored-attributes",
            "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror",
            "-Wshorten-64-to-32", "-Wint-to-pointer-cast", "-Wpointer-to-int-cast",
            "-I" + PDDI, "-I" + gen, "-I" + os.path.join(TP, "src/bx/include"),
            "-I" + os.path.join(TP, "src/bx/include/compat/msvc"), "-I" + os.path.dirname(PDDI),
            "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_EMBED_SHADERS=1", "-DHULK_PDDI_NATIVE=1"] + BGFX_DEFS


def compile_ms(out, gen, retarget, back, save_sig=None, jobs=2):
    """The front end's units -> objects in OUT/ms (front end, retarget(ir) -> host IR, back end argv `back`).
    Returns ({unit: object}, {unit: error})."""
    d = os.path.join(out, "ms")
    os.makedirs(d, exist_ok=True)
    clang = cp.tool("clang++")
    flags = ms_flags(gen)

    def one(rel):
        o = os.path.join(d, os.path.basename(rel)[:-4] + ".o")
        ll = o[:-2] + ".ll"
        r = subprocess.run([clang] + flags + ["-S", "-emit-llvm", rel, "-o", ll],
                           capture_output=True, text=True, errors="replace")
        if r.returncode:
            return rel, None, "front: " + r.stderr[-3000:]
        ir = retarget(open(ll, errors="surrogateescape").read())
        if "llvm.global_ctors" in ir:
            return rel, None, "a static constructor (the native entry would not run it): make it lazy"
        with open(ll + ".m.ll", "w", errors="surrogateescape") as f:
            f.write(ir)
        if save_sig:
            save_sig(ir, o)
        q = subprocess.run([clang] + back + [ll + ".m.ll", "-o", o], capture_output=True, text=True, errors="replace")
        for p in (ll, ll + ".m.ll"):
            if os.path.exists(p):
                os.unlink(p)
        return rel, (o if q.returncode == 0 else None), (None if q.returncode == 0 else "back: " + q.stderr[-3000:])
    objs, errs = {}, {}
    with concurrent.futures.ThreadPoolExecutor(max(1, jobs)) as ex:
        for rel, o, e in ex.map(one, ms_units()):
            if e:
                errs[rel] = e
            else:
                objs[rel] = o
    return objs, errs


def compile_host_mac(out, gen, sdl_cflags, min_os="11.0", jobs=2):
    """The sink, the bridge's host half and the window/event code for arm64 macOS -> OUT/host. Returns (objects,
    {unit: error})."""
    d = os.path.join(out, "host")
    os.makedirs(d, exist_ok=True)
    bgfx_inc = ["-I" + os.path.join(TP, "src/bx/include"), "-I" + os.path.join(TP, "src/bx/include/compat/osx"),
                "-I" + os.path.join(TP, "src/bimg/include"), "-I" + os.path.join(TP, "src/bgfx/include")]
    base = ["xcrun", "clang++", "-arch", "arm64", "-mmacosx-version-min=" + min_os, "-std=c++20", "-O2", "-g",
            "-fno-exceptions", "-fno-rtti", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field",
            "-Wno-deprecated-declarations", "-I" + PDDI, "-I" + gen, "-I" + os.path.dirname(PDDI)]
    jobs_ = []
    for rel in HOST_UNITS:
        jobs_.append((rel, base + bgfx_inc + BGFX_DEFS + ["-DBGFX_CONFIG_RENDERER_METAL=1",
                     "-DHULK_PDDI_HOST=1", "-DHULK_PDDI_EMBED_SHADERS=1", "-DHULK_PDDI_BRIDGE_HOST=1"]))
    jobs_.append((PLATFORM_EVENTS, base + list(sdl_cflags)))

    def one(j):
        rel, cmd = j
        o = os.path.join(d, os.path.basename(rel)[:-4] + ".o")
        r = subprocess.run(cmd + ["-c", rel, "-o", o], capture_output=True, text=True,
                           errors="replace")
        return rel, o, (r.stderr[-3000:] if r.returncode else None)
    objs, errs = [], {}
    with concurrent.futures.ThreadPoolExecutor(max(1, jobs)) as ex:
        for rel, o, e in ex.map(one, jobs_):
            if e:
                errs[rel] = e
            else:
                objs.append(o)
    return objs, errs


def mac_libs():
    lib = os.path.join(TP, "out/host/lib")
    return [os.path.join(lib, n + ".a") for n in ("bgfx", "bimg", "bx")]


# ---------------------------------------------------------------------------------------------- the layout check
# The front end's offsets into game records (bgfx_pddi.h kBase*, PDDI_SPE) against include/gen's 64-bit layout: a
# probe TU compiled by the tree's native front end (tools/native_mac.py FRONT), static_asserts only.
LAYOUT_PROBE = r'''
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define O(c, f) __builtin_offsetof(::pure3d::c, f)
static_assert(O(pddiObject, f_08) == %(kBaseStart)s, "kBaseStart: pddiObject::f_08");
static_assert(O(pddiBaseContext, f_20) == %(kBaseStacks)s, "kBaseStacks: pddiBaseContext::f_20");
static_assert(O(pddiBaseContext, f_48) == %(kBaseView)s, "kBaseView: pddiBaseContext::f_48");
static_assert(O(pddiBaseContext, f_4c) == %(kBaseRender)s, "kBaseRender: pddiBaseContext::f_4c");
static_assert(O(pddiBaseContext, f_50) == %(kBaseLights)s, "kBaseLights: pddiBaseContext::f_50");
static_assert(O(pddiBaseContext, f_54) == %(kBaseFog)s, "kBaseFog: pddiBaseContext::f_54");
static_assert(O(pddiBaseContext, f_58) == %(kBaseStencil)s, "kBaseStencil: pddiBaseContext::f_58");
static_assert(O(pddiBaseContext, _pad_5c) == %(kBaseLightMatrix)s, "kBaseLightMatrix: pddiBaseContext::_pad_5c");
static_assert(sizeof(::pure3d::pddiBaseContext) == %(kBaseEnd)s, "kBaseEnd: sizeof(pddiBaseContext)");
'''


def layout_values():
    s = open(os.path.join(PDDI, "bgfx_pddi.h")).read()
    return {m.group(1): m.group(3) for m in re.finditer(r"\b(kBase\w+) = PDDI_SPE\((0x[0-9a-f]+), (0x[0-9a-f]+)\)", s)}


def layout_check(front):
    """None, or the failing static_asserts of the probe. `front`: the tree's native front-end argv (no -o)."""
    vals = layout_values()
    probe = LAYOUT_PROBE % vals
    d = os.path.join(ROOT, "build/native-pddi")
    os.makedirs(d, exist_ok=True)
    p = os.path.join(d, "layout_probe.cpp")
    with open(p, "w") as f:
        f.write(probe)
    r = subprocess.run([cp.tool("clang++")] + front + ["-I" + os.path.join(ROOT, "include"), "-fsyntax-only", p],
                       capture_output=True, text=True, errors="replace")
    return None if r.returncode == 0 else r.stderr[-3000:]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("compile")
    c.add_argument("--out", default=os.path.join(ROOT, "build/native-pddi"))
    sub.add_parser("layout")
    a = ap.parse_args(argv)
    import native_mac as nmac
    front = [x for x in nmac.FRONT if x not in ("-S", "-emit-llvm")] + cp.common_native()
    if a.cmd == "layout":
        e = layout_check(front)
        print(e or "pddi layout: ok (%d offsets)" % len(layout_values()))
        return 1 if e else 0
    miss = inputs_missing()
    if miss:
        print("missing inputs (tools/wine_gfx.py fetch + build): %s" % ", ".join(miss), file=sys.stderr)
        return 2
    import native_bind as nb
    import native_unbound as nu
    gen = gen_dir(a.out, "metal")
    objs, errs = compile_ms(a.out, gen, nmac.retarget, nmac.BACK, nu.save_signatures)
    cfg = nb.macos_sdl()
    hobjs, herrs = compile_host_mac(a.out, gen, cfg[0] if cfg else [])
    errs.update(herrs)
    print(json.dumps({"front end objects": len(objs), "host objects": len(hobjs), "errors": errs}, indent=1))
    return 1 if errs else 0


if __name__ == "__main__":
    sys.exit(main())
