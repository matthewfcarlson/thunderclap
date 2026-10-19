#!/usr/bin/env python3
"""bgfx for the graphics backend (docs/graphics-backend.md, stage G0): a pinned fetch and build of bx, bimg and bgfx.

  build/venv/bin/python tools/native_gfx.py fetch            # download the pinned tarballs, check sha256, unpack
  build/venv/bin/python tools/native_gfx.py build            # static libraries for macOS (host) and i686 Windows
  build/venv/bin/python tools/native_gfx.py build --target win32
  build/venv/bin/python tools/native_gfx.py shaderc          # bgfx's shaderc for the host (GENie + make, ~7 min)
  build/venv/bin/python tools/native_gfx.py shaders          # compile src/platform/sdl/pddi/shaders/*.sc
  build/venv/bin/python tools/native_gfx.py pddi             # the pddi skeleton: host library + smoke test, win32 objects
  build/venv/bin/python tools/native_gfx.py smoke            # run the host smoke test (a window, clear + one triangle)
  build/venv/bin/python tools/native_gfx.py slots            # check the skeleton's MS-ABI vtable slots against rtti.json
  build/venv/bin/python tools/native_gfx.py status           # pins, what is fetched and built

Everything goes under build/third_party/ (ignored by git); nothing is installed system-wide.

  dl/                    the pinned tarballs (sha256 below)
  src/{bx,bimg,bgfx}     upstream sources at the pinned commits (BSD-2-Clause, Branimir Karadzic)
  src/mingw-w64/         mingw-w64 v14.0.0 headers only (windows.h, the C runtime headers, d3d11/dxgi): the i686
                         build compiles against them; no mingw-w64 code or library is linked
  out/<target>/          lib/{bx,bimg,bgfx}.lib|.a, obj/, build.json (the exact command lines)
  out/LICENSES.txt       the notices to ship with a binary that links bgfx
  tools/shaderc          the host shaderc (Metal, SPIR-V, GLSL/ESSL, WGSL; HLSL needs Windows)

Targets:
  host   macOS arm64 (Apple clang from the command line tools): Metal renderer only (+ noop)
  win32  i686-pc-windows-msvc with Homebrew LLVM's clang (the toolchain tools/native_link.py uses): MS C++ ABI,
         no default libraries (the native image binds msvcrt.dll and kernel32/user32/gdi32 at link time),
         renderers Direct3D 11, OpenGL and Vulkan (all three are loaded at run time with LoadLibrary, so no
         import library for them is needed); Direct3D 12 and WebGPU are off.
"""
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tarfile
import time
import urllib.request
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
TP = os.path.join(ROOT, "build/third_party")
DL = os.path.join(TP, "dl")
SRC = os.path.join(TP, "src")
OUT = os.path.join(TP, "out")
LLVM = "/opt/homebrew/opt/llvm/bin"
PDDI = os.path.join(ROOT, "src/platform/sdl/pddi")

# Pinned upstream sources: (name, GitHub repo, commit or tag, sha256 of codeload's tar.gz, members to keep)
PINS = [
    ("bx", "bkaradzic/bx", "dd261e277506d77c29a7ee89d5b6c0a74ad6fc90",
     "dd272e02cb058e2e0540c146265e97bc6bae66935f2138fbfeea76ebd7e82487", None),
    ("bimg", "bkaradzic/bimg", "6d60464eb295333b53ce6ec6fe71eddf7177a799",
     "a4efbe366d166e6f272617d17527c4bad3ed6c491b813176d5dc4d17226252a2", None),
    ("bgfx", "bkaradzic/bgfx", "4410cdfce9e85a8e367d290cab42bad8f5d88e53",
     "58882f851cb18b93ea3e4929be2ab4cc5cd0bbe7c07cc07f589684a8747717b6", None),
    ("mingw-w64", "mingw-w64/mingw-w64", "v14.0.0",
     "d71cc644cd5a37c337f2719f3e0c79d89e8d8d5fb9e2952a62d3fa23623dc137",
     ("mingw-w64-headers/", "COPYING", "COPYING.MinGW-w64/", "COPYING.MinGW-w64-runtime/", "DISCLAIMER",
      "DISCLAIMER.PD")),
]

JOBS = 2            # a shared machine: at most two compiler processes

# Local fixes to the pinned sources, applied after unpacking (exact text; fetch fails if upstream moved):
#  - bx/macros.h defines __stdcall away for clang with the MSVC CRT (meant for x64, where it is meaningless). On
#    i686 that turns every WINAPI and COM (STDMETHODCALLTYPE) call into cdecl: the stack is off after each one.
PATCHES = [
    ("bx", "include/bx/macros.h",
     "#\tif BX_CRT_MSVC\n#\t\tdefine __stdcall\n#\tendif // BX_CRT_MSVC",
     "#\tif BX_CRT_MSVC && !defined(_M_IX86) // hulk: keep __stdcall on i686 (tools/native_gfx.py PATCHES)\n"
     "#\t\tdefine __stdcall\n#\tendif // BX_CRT_MSVC"),
]


def log(*a):
    print(*a, file=sys.stderr, flush=True)


def tarball(name, repo, ref):
    return os.path.join(DL, "%s-%s.tar.gz" % (name, ref)), "https://codeload.github.com/%s/tar.gz/%s" % (repo, ref)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def fetch(force=False):
    os.makedirs(DL, exist_ok=True)
    for name, repo, ref, want, keep in PINS:
        path, url = tarball(name, repo, ref)
        if not os.path.exists(path) or force:
            log("download %s %s" % (name, ref))
            tmp = path + ".part"
            with urllib.request.urlopen(url, timeout=600) as r, open(tmp, "wb") as f:
                shutil.copyfileobj(r, f)
            os.replace(tmp, path)
        got = sha256(path)
        if got != want:
            raise SystemExit("%s: sha256 %s, pinned %s (GitHub regenerated the archive, or it was tampered with): "
                             "check the commit and update PINS" % (os.path.relpath(path, ROOT), got, want))
        dest = os.path.join(SRC, name)
        stamp = os.path.join(dest, ".pinned")
        tag = "%s %s %s" % (ref, want, hashlib.sha256(repr([p for p in PATCHES if p[0] == name]).encode()).hexdigest()[:12])
        if os.path.exists(stamp) and open(stamp).read().strip() == tag and not force:
            continue
        if os.path.exists(dest):
            shutil.rmtree(dest)
        os.makedirs(dest)
        log("unpack %s" % name)
        with tarfile.open(path) as t:
            members = []
            for m in t.getmembers():
                parts = m.name.split("/", 1)
                if len(parts) < 2 or not parts[1]:
                    continue
                rel = parts[1]
                if keep and not any(rel == k or rel.startswith(k) for k in keep):
                    continue
                if m.issym() or m.islnk() or rel.startswith("/") or ".." in rel.split("/"):
                    continue
                m.name = rel
                members.append(m)
            t.extractall(dest, members=members, filter="data")
        if name == "mingw-w64":
            mingw_config(dest)
        for pname, rel, old, new in PATCHES:
            if pname != name:
                continue
            f = os.path.join(dest, rel)
            text = open(f).read()
            if old not in text:
                raise SystemExit("patch for %s/%s no longer applies: check PATCHES" % (name, rel))
            open(f, "w").write(text.replace(old, new))
            log("patched %s/%s" % (name, rel))
        open(stamp, "w").write(tag + "\n")
    licenses()


def mingw_config(dest):
    """mingw-w64-headers' configure only substitutes the default msvcrt version into _mingw.h: do that here."""
    crt = os.path.join(dest, "mingw-w64-headers/crt")
    text = open(os.path.join(crt, "_mingw.h.in")).read().replace("@DEFAULT_MSVCRT_VERSION@", "0x700")
    open(os.path.join(crt, "_mingw.h"), "w").write(text)


def licenses():
    os.makedirs(OUT, exist_ok=True)
    parts = ["Third-party notices for binaries that link the graphics backend (tools/native_gfx.py).\n"]
    for name, repo, ref, _sha, _k in PINS[:3]:
        lic = os.path.join(SRC, name, "LICENSE")
        if os.path.exists(lic):
            parts.append("=" * 78 + "\n%s (https://github.com/%s, commit %s)\n\n%s" % (name, repo, ref, open(lic).read()))
    parts.append("=" * 78 + "\nmingw-w64 v14.0.0 headers: used to compile the i686 Windows build only; no mingw-w64 "
                 "code or library is linked into it.\nSee src/mingw-w64/COPYING and DISCLAIMER* (public domain and "
                 "ZPL-2.1 / permissive notices).\n")
    open(os.path.join(OUT, "LICENSES.txt"), "w").write("\n".join(parts))


# ---------------------------------------------------------------------------------------------
# Static libraries
def _bx(*p):
    return os.path.join(SRC, "bx", *p)


def _bgfx(*p):
    return os.path.join(SRC, "bgfx", *p)


def _bimg(*p):
    return os.path.join(SRC, "bimg", *p)


# BGFX_CONFIG_MULTITHREADED=0: pddi calls come from the game's one render thread, bgfx renders on it too (no
# render thread, no thread-local storage in the image; the web build needs the same setting)
COMMON_DEFS = ["-DBX_CONFIG_DEBUG=0", "-DBIMG_CONFIG_DECODE_ASTC=0", "-DBGFX_CONFIG_RENDERER_WEBGPU=0",
               "-DBGFX_CONFIG_MULTITHREADED=0",
               "-D__STDC_LIMIT_MACROS", "-D__STDC_FORMAT_MACROS", "-D__STDC_CONSTANT_MACROS"]


COMPAT = os.path.join(TP, "compat")


def compat_header():
    """build/third_party/compat/hulk_win32_compat.h, force-included into the i686 Windows build of bx/bimg/bgfx:
    declarations mingw-w64's msvcrt headers lack and bx's BX_CRT_MSVC path names (our text, no SDK material)."""
    os.makedirs(COMPAT, exist_ok=True)
    path = os.path.join(COMPAT, "hulk_win32_compat.h")
    text = """// generated by tools/native_gfx.py: force-included into the i686-pc-windows-msvc build of bx/bimg/bgfx
#pragma once
#include <stdlib.h>
#ifdef __cplusplus
// Dynamic initializers go to .CRT$XHU, not .CRT$XCU: the native image's start-up skips clang's .CRT$XCU on purpose
// (src/platform/sdl/xdk/startup.cpp); src/platform/sdl/pddi/win32_glue.cpp runs the .CRT$XH* ones.
#pragma init_seg(".CRT$XHU")
extern "C" {
#endif
// UCRT-only (not in msvcrt.dll): bx's debug.cpp sets it next to _set_invalid_parameter_handler. The native link
// supplies a stand-in that returns NULL (build/g0/LINK.md).
_invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(_invalid_parameter_handler);
#ifdef __cplusplus
}
#endif
"""
    if not os.path.exists(path) or open(path).read() != text:
        open(path, "w").write(text)
    return path


def target_cfg(target):
    """(compiler argv prefix, per-library extra flags, archiver argv prefix, library suffix)."""
    if target == "host":
        cxx = ["/usr/bin/clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-std=c++20", "-O2",
               "-fno-exceptions", "-fno-rtti", "-Wno-deprecated-declarations", "-x", "objective-c++",
               "-I" + _bx("include/compat/osx")]
        defs = COMMON_DEFS + ["-DBGFX_CONFIG_RENDERER_METAL=1", "-DBGFX_CONFIG_RENDERER_VULKAN=0",
                              "-DBGFX_CONFIG_RENDERER_OPENGL=0"]
        return cxx + defs, ["/usr/bin/ar", "rcs"], ".a"
    if target == "win32":
        mg = os.path.join(SRC, "mingw-w64/mingw-w64-headers")
        cxx = [os.path.join(LLVM, "clang++"), "--target=i686-pc-windows-msvc", "-fms-extensions",
               "-fms-compatibility", "-std=c++20", "-O2", "-msse4.2", "-fno-exceptions", "-fno-rtti",
               "-fno-stack-protector", "-fno-threadsafe-statics", "-fno-sized-deallocation",
               "-fno-aligned-allocation", "-nostdinc++",
               # the C runtime and Windows API headers: mingw-w64's (no MSVC or Windows SDK headers here)
               "-isystem", os.path.join(mg, "crt"), "-isystem", os.path.join(mg, "include"),
               # mingw-w64's headers expect a GNU front end: keep the MS C++ ABI (the triple) but let clang
               # define __GNUC__ too. bx still sees _MSC_VER (BX_CRT_MSVC: msvcrt.dll's names); the one
               # UCRT-only declaration it uses comes from our compat header (compat_header below).
               "-fgnuc-version=4.2.1", "-D_X86_=1", "-include", compat_header(), "-I" + _bx("include/compat/msvc"),
               "-D_WIN32_WINNT=0x0601", "-DWINVER=0x0601", "-DWIN32_LEAN_AND_MEAN", "-DNOMINMAX",
               "-D_CRT_SECURE_NO_WARNINGS", "-D_HAS_EXCEPTIONS=0", "-D__MSVCRT_VERSION__=0x700",
               "-D__USE_MINGW_ANSI_STDIO=0",
               "-Wno-microsoft-enum-value", "-Wno-microsoft-const-init", "-Wno-ignored-attributes",
               "-Wno-nonportable-include-path", "-Wno-pragma-pack", "-Wno-unknown-pragmas",
               "-Wno-deprecated-declarations", "-Wno-invalid-offsetof", "-Wno-macro-redefined"]
        defs = COMMON_DEFS + ["-DBGFX_CONFIG_RENDERER_DIRECT3D11=1", "-DBGFX_CONFIG_RENDERER_DIRECT3D12=0",
                              "-DBGFX_CONFIG_RENDERER_OPENGL=43", "-DBGFX_CONFIG_RENDERER_VULKAN=1"]
        return cxx + defs, [os.path.join(LLVM, "llvm-lib"), "/nologo"], ".lib"
    raise SystemExit("unknown target %s" % target)


def lib_units(target):
    """{library: [(source, extra flags)]}"""
    inc_bx = ["-I" + _bx("include"), "-I" + _bx("3rdparty")]
    inc_bimg = inc_bx + ["-I" + _bimg("include")]
    inc_bgfx = inc_bimg + ["-I" + _bgfx("include"), "-I" + _bgfx("3rdparty"), "-I" + _bgfx("3rdparty/khronos")]
    if target == "win32":
        inc_bgfx += ["-I" + _bgfx("3rdparty/directx-headers/include/directx")]
    return {
        "bx": [(_bx("src/amalgamated.cpp"), inc_bx)],
        "bimg": [(_bimg("src/image.cpp"), inc_bimg)],
        "bgfx": [(_bgfx("src/amalgamated.cpp"), inc_bgfx)],
    }


def run(cmd, logf=None):
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    if logf:
        with open(logf, "a") as f:
            f.write("$ " + " ".join(cmd) + "\n" + r.stdout + r.stderr + "\n")
    return r


def build_target(target):
    cxx, ar, ext = target_cfg(target)
    od = os.path.join(OUT, target)
    os.makedirs(os.path.join(od, "obj"), exist_ok=True)
    os.makedirs(os.path.join(od, "lib"), exist_ok=True)
    logf = os.path.join(od, "build.log")
    open(logf, "w").close()
    units = lib_units(target)
    jobs = []
    for lib, srcs in units.items():
        for src, extra in srcs:
            obj = os.path.join(od, "obj", "%s-%s.o" % (lib, os.path.splitext(os.path.basename(src))[0]))
            jobs.append((lib, src, obj, cxx + extra + ["-c", src, "-o", obj]))
    t0 = time.time()

    def one(j):
        lib, src, obj, cmd = j
        r = run(cmd, logf)
        return lib, obj, r.returncode, (r.stdout + r.stderr)[-4000:]
    failed = []
    with ThreadPoolExecutor(JOBS) as ex:
        for lib, obj, rc, err in ex.map(one, jobs):
            if rc:
                failed.append((lib, err))
                log("FAILED %s %s\n%s" % (target, lib, err))
    if failed:
        raise SystemExit("%s: %d units failed (log %s)" % (target, len(failed), os.path.relpath(logf, ROOT)))
    libs = {}
    for lib in units:
        out = os.path.join(od, "lib", lib + ext)
        if os.path.exists(out):
            os.unlink(out)
        objs = [j[2] for j in jobs if j[0] == lib]
        cmd = ar + (["/out:" + out] + objs if ext == ".lib" else [out] + objs)
        r = run(cmd, logf)
        if r.returncode:
            raise SystemExit("%s: archiving %s failed: %s" % (target, lib, r.stderr[-2000:]))
        libs[lib] = os.path.relpath(out, ROOT)
    info = {"target": target, "seconds": round(time.time() - t0), "libs": libs,
            "pins": {n: ref for n, _r, ref, _s, _k in PINS},
            "commands": [" ".join(j[3]) for j in jobs]}
    json.dump(info, open(os.path.join(od, "build.json"), "w"), indent=1)
    log("%s: %s in %d s" % (target, ", ".join("%s %d KB" % (k, os.path.getsize(os.path.join(ROOT, v)) >> 10)
                                               for k, v in libs.items()), info["seconds"]))
    return info


# ---------------------------------------------------------------------------------------------
# shaderc (host): GENie + make, as upstream builds it
def shaderc():
    genie = _bx("tools/bin/darwin/genie")
    bg = _bgfx()
    r = subprocess.run([genie, "--with-tools", "--gcc=osx-arm64", "gmake"], cwd=bg, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("genie failed:\n" + r.stdout[-3000:] + r.stderr[-3000:])
    proj = os.path.join(bg, ".build/projects/gmake-osx-arm64")
    t0 = time.time()
    logf = os.path.join(OUT, "shaderc-build.log")
    with open(logf, "w") as f:
        r = subprocess.run(["make", "-j%d" % JOBS, "config=release", "shaderc"], cwd=proj, stdout=f,
                           stderr=subprocess.STDOUT)
    if r.returncode:
        raise SystemExit("shaderc build failed (log %s)" % os.path.relpath(logf, ROOT))
    exe = os.path.join(bg, ".build/osx-arm64/bin/shadercRelease")
    os.makedirs(os.path.join(TP, "tools"), exist_ok=True)
    shutil.copy2(exe, os.path.join(TP, "tools/shaderc"))
    log("shaderc built in %d s" % (time.time() - t0))


SHADER_PROFILES = {          # bgfx shaderc --platform / --profile per backend we can compile on macOS
    "metal": ("osx", "metal"),
    "spirv": ("linux", "spirv"),
    "glsl": ("linux", "430"),
    "essl": ("android", "300_es"),
    "wgsl": ("linux", "wgsl"),
}


def compile_shaders(out_dir=None):
    """Compile every src/platform/sdl/pddi/shaders/{vs,fs}_*.sc for each profile into out/shaders/<profile>/."""
    sc = os.path.join(TP, "tools/shaderc")
    if not os.path.exists(sc):
        raise SystemExit("no shaderc: run `tools/native_gfx.py shaderc` first")
    sd = os.path.join(PDDI, "shaders")
    out_dir = out_dir or os.path.join(OUT, "shaders")
    res = {}
    for fn in sorted(os.listdir(sd)):
        if not fn.endswith(".sc") or fn.startswith("varying"):
            continue
        kind = {"vs": "vertex", "fs": "fragment"}[fn[:2]]
        for prof, (plat, p) in SHADER_PROFILES.items():
            od = os.path.join(out_dir, prof)
            os.makedirs(od, exist_ok=True)
            out = os.path.join(od, fn[:-3] + ".bin")
            cmd = [sc, "-f", os.path.join(sd, fn), "-o", out, "--type", kind, "--platform", plat, "-p", p,
                   "-i", _bgfx("src"), "--varyingdef", os.path.join(sd, "varying.def.sc")]
            r = subprocess.run(cmd, capture_output=True, text=True)
            res["%s/%s" % (prof, fn)] = "ok %d B" % os.path.getsize(out) if r.returncode == 0 else \
                "FAILED " + (r.stdout + r.stderr)[-500:]
    return res


# ---------------------------------------------------------------------------------------------
# The pddi skeleton (src/platform/sdl/pddi)
PDDI_HOST_DIR = os.path.join(OUT, "pddi-host")
SDL3 = "/opt/homebrew/opt/sdl3"          # the smoke test's window (Homebrew's SDL3, already a port dependency)
PDDI_WIN_DIR = os.path.join(OUT, "pddi-win32")


def pddi_sources():
    return sorted(os.path.join(PDDI, f) for f in os.listdir(PDDI) if f.endswith(".cpp"))


def pddi_host():
    """The skeleton as a host static library, the shaders embedded for Metal, and the smoke test linked against it."""
    res = compile_shaders()
    bad = [k for k, v in res.items() if not v.startswith("ok")]
    if bad:
        raise SystemExit("shaders failed: %s" % {k: res[k] for k in bad})
    gen = os.path.join(PDDI_HOST_DIR, "gen")
    embed_shaders(gen, "metal")
    cxx, ar, _ = target_cfg("host")
    inc = ["-I" + PDDI, "-I" + gen, "-I" + _bx("include"), "-I" + _bgfx("include"), "-I" + _bimg("include"),
           "-DHULK_PDDI_HOST=1", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror"]
    objs = []
    os.makedirs(os.path.join(PDDI_HOST_DIR, "obj"), exist_ok=True)
    logf = os.path.join(PDDI_HOST_DIR, "build.log")
    open(logf, "w").close()
    jobs = []
    for s in pddi_sources() + [os.path.join(PDDI, "smoke/smoke_main.cpp")]:
        o = os.path.join(PDDI_HOST_DIR, "obj", os.path.basename(s)[:-4] + ".o")
        extra = ["-I" + os.path.join(SDL3, "include")] if s.endswith("smoke_main.cpp") else []
        jobs.append((s, o, cxx + inc + extra + ["-c", s, "-o", o]))
    with ThreadPoolExecutor(JOBS) as ex:
        for (s, o, _c), r in zip(jobs, ex.map(lambda j: run(j[2], logf), jobs)):
            if r.returncode:
                raise SystemExit("pddi host: %s failed:\n%s" % (os.path.relpath(s, ROOT), (r.stdout + r.stderr)[-4000:]))
            objs.append(o)
    lib = os.path.join(PDDI_HOST_DIR, "libhulk_pddi.a")
    if os.path.exists(lib):
        os.unlink(lib)
    run(ar + [lib] + [o for o in objs if not o.endswith("smoke_main.o")], logf)
    hl = os.path.join(OUT, "host/lib")
    exe = os.path.join(PDDI_HOST_DIR, "pddi_smoke")
    r = run(["/usr/bin/clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-o", exe,
             os.path.join(PDDI_HOST_DIR, "obj/smoke_main.o"), lib, os.path.join(hl, "bgfx.a"),
             os.path.join(hl, "bimg.a"), os.path.join(hl, "bx.a"),
             "-framework", "Cocoa", "-framework", "QuartzCore", "-framework", "Metal", "-framework", "IOKit",
             "-framework", "MetalKit", "-framework", "VideoToolbox", "-framework", "CoreMedia",
             "-framework", "CoreVideo", "-L" + os.path.join(SDL3, "lib"), "-lSDL3",
             "-Wl,-rpath," + os.path.join(SDL3, "lib")], logf)
    if r.returncode:
        raise SystemExit("smoke link failed:\n" + (r.stdout + r.stderr)[-4000:])
    log("pddi host: %s, %s" % (os.path.relpath(lib, ROOT), os.path.relpath(exe, ROOT)))
    return {"lib": lib, "exe": exe, "shaders": res}


def embed_shaders(gen, profile):
    """shaders_<profile>.h: each compiled shader as a byte array (the host smoke test loads them from memory)."""
    os.makedirs(gen, exist_ok=True)
    sd = os.path.join(OUT, "shaders", profile)
    lines = ["// generated by tools/native_gfx.py from src/platform/sdl/pddi/shaders (%s)" % profile]
    names = []
    for fn in sorted(os.listdir(sd)):
        if not fn.endswith(".bin"):
            continue
        data = open(os.path.join(sd, fn), "rb").read()
        name = "g_" + fn[:-4]
        names.append(name)
        lines.append("static const unsigned char %s[%d] = {" % (name, len(data)))
        for i in range(0, len(data), 24):
            lines.append("    " + ",".join(str(b) for b in data[i:i + 24]) + ",")
        lines.append("};")
    open(os.path.join(gen, "pddi_shaders.h"), "w").write("\n".join(lines) + "\n")


def pddi_win32():
    """The skeleton for the native image: i686-pc-windows-msvc objects (HULK_PDDI_GAME=1), archived."""
    cxx, ar, _ = target_cfg("win32")
    gen = os.path.join(PDDI_WIN_DIR, "gen")
    embed_shaders(gen, "spirv")          # placeholder until D3D11 binaries can be compiled (needs Windows)
    inc = ["-I" + PDDI, "-I" + gen, "-I" + _bx("include"), "-I" + _bgfx("include"), "-I" + _bimg("include"),
           "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_EMBED_SHADERS=1", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror",
           "-fno-threadsafe-statics"]
    os.makedirs(os.path.join(PDDI_WIN_DIR, "obj"), exist_ok=True)
    logf = os.path.join(PDDI_WIN_DIR, "build.log")
    open(logf, "w").close()
    objs = []
    for s in pddi_sources():
        o = os.path.join(PDDI_WIN_DIR, "obj", os.path.basename(s)[:-4] + ".obj")
        r = run(cxx + inc + ["-c", s, "-o", o], logf)
        if r.returncode:
            raise SystemExit("pddi win32: %s failed:\n%s" % (os.path.relpath(s, ROOT), (r.stdout + r.stderr)[-4000:]))
        objs.append(o)
    lib = os.path.join(PDDI_WIN_DIR, "hulk_pddi.lib")
    if os.path.exists(lib):
        os.unlink(lib)
    r = run(ar + ["/out:" + lib] + objs, logf)
    if r.returncode:
        raise SystemExit("pddi win32 archive failed: " + r.stderr[-2000:])
    log("pddi win32: %s" % os.path.relpath(lib, ROOT))
    return {"lib": lib, "objects": objs}


def smoke(frames=120, png=None):
    exe = os.path.join(PDDI_HOST_DIR, "pddi_smoke")
    if not os.path.exists(exe):
        raise SystemExit("build it first: tools/native_gfx.py pddi")
    png = png or os.path.join(PDDI_HOST_DIR, "smoke.tga")
    r = subprocess.run([exe, "--frames", str(frames), "--capture", png, "--drawlog",
                        os.path.join(PDDI_HOST_DIR, "smoke.pdl")], capture_output=True, text=True, timeout=120)
    sys.stdout.write(r.stdout)
    sys.stderr.write(r.stderr[-4000:])
    return r.returncode


# ---------------------------------------------------------------------------------------------
# Slot check: the skeleton's MS-ABI vtables (clang -fdump-vtable-layouts) against the game's (build/rtti.json)
SLOT_CLASSES = {          # skeleton class -> the game class whose vtable it stands in for
    "bgfxDisplay": "pure3d::d3dDisplay", "bgfxDevice": "pure3d::d3dDevice", "bgfxContext": "pure3d::d3dContext",
    "bgfxTexture": "pure3d::d3dTexture", "bgfxPrimBuffer": "pure3d::d3dPrimBuffer",
    "bgfxPrimBufferStream": "pure3d::d3dPrimBufferStream", "bgfxPrimStream": "pure3d::d3dPrimStream",
    "bgfxSimpleShader": "pure3d::d3dSimpleShader", "bgfxLayeredShader": "pure3d::d3dLayeredShader",
    "bgfxBuildingShader": "pure3d::d3dBuildingShader", "bgfxReflShader": "pure3d::d3dReflShader",
    "bgfxRefractShader": "pure3d::d3dRefractVertexShader", "bgfxFBEffectsShader": "pure3d::d3dFBEffectsShader",
    "bgfxErrorShader": "pure3d::d3dErrorShader",
    "bgfxExtAntialiasControl": "pure3d::d3dExtAntialiasControl",
    "bgfxExtFrameBufferTexture": "pure3d::d3dExtFrameBufferTexture",
    "bgfxExtFramebufferEffects": "pure3d::d3dExtFramebufferEffects",
    "bgfxExtGammaControl": "pure3d::d3dExtGammaControl",
    "bgfxExtGlobalProjectedTexture": "pure3d::d3dExtGlobalProjectedTexture",
    "bgfxExtHardwareSkinning": "pure3d::d3dExtHardwareSkinning", "bgfxExtReadPixels": "pure3d::d3dExtReadPixels",
    "bgfxExtVertexProgram": "pure3d::d3dExtVertexProgram", "bgfxExtVisibilityTest": "pure3d::d3dExtVisibilityTest",
}


def slots():
    """Compile the skeleton for i686-pc-windows-msvc with clang's vtable dump: every class must have the game class's
    slot count, and every method named vfunc_N must sit at index N."""
    import re
    rt = json.load(open(os.path.join(ROOT, "build/rtti.json")))
    want = {c["name"]: len(c["vtables"][0]["slots"]) for c in rt["classes"] if c.get("vtables")}
    cxx, _ar, _ = target_cfg("win32")
    inc = ["-I" + PDDI, "-I" + os.path.join(PDDI_WIN_DIR, "gen"), "-I" + _bx("include"), "-I" + _bgfx("include"),
           "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_EMBED_SHADERS=1"]
    if not os.path.exists(os.path.join(PDDI_WIN_DIR, "gen", "pddi_shaders.h")):
        embed_shaders(os.path.join(PDDI_WIN_DIR, "gen"), "spirv")
    got, bad = {}, []
    for s in pddi_sources():
        r = subprocess.run(cxx + inc + ["-S", "-o", os.devnull, "-Xclang", "-fdump-vtable-layouts", s],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("%s: %s" % (s, r.stderr[-2000:]))
        for m in re.finditer(r"VFTable for ((?:'[\w:]+'(?: in )?)+) \((\d+) entries\)", r.stdout):
            got.setdefault(re.findall(r"'([\w:]+)'", m.group(1))[-1].split("::")[-1], int(m.group(2)))
        for blk in re.finditer(r"VFTable indices for '([\w:]+)'[^\n]*\n((?:\s+\d+ \|[^\n]*\n)+)", r.stdout):
            cls = blk.group(1).split("::")[-1]
            for line in blk.group(2).splitlines():
                m = re.match(r"\s+(\d+) \| .*::vfunc_(\d+)\(", line)
                if m and m.group(1) != m.group(2):
                    bad.append("%s: vfunc_%s at index %s" % (cls, m.group(2), m.group(1)))
    rows, ok = [], not bad
    for ours, theirs in sorted(SLOT_CLASSES.items()):
        n, w = got.get(ours), want.get(theirs)
        good = n is not None and n == w
        ok &= good
        rows.append("%-30s %-40s ours %-4s game %-4s %s" % (ours, theirs, n, w, "ok" if good else "MISMATCH"))
    print("\n".join(rows + sorted(set(bad))))
    print("slots: %s (%d classes; every vfunc_N at index N: %s)" % ("ok" if ok else "MISMATCH", len(rows),
                                                                   "yes" if not bad else "no"))
    return 0 if ok else 1


def status():
    for name, repo, ref, sha, _k in PINS:
        path, _url = tarball(name, repo, ref)
        stamp = os.path.join(SRC, name, ".pinned")
        print("%-10s %-42s tarball %-3s unpacked %s" % (name, ref, "yes" if os.path.exists(path) else "no",
                                                        "yes" if os.path.exists(stamp) else "no"))
    for t in ("host", "win32"):
        bj = os.path.join(OUT, t, "build.json")
        if os.path.exists(bj):
            b = json.load(open(bj))
            print("%-6s %s" % (t, ", ".join("%s %d KB" % (k, os.path.getsize(os.path.join(ROOT, v)) >> 10)
                                            for k, v in b["libs"].items() if os.path.exists(os.path.join(ROOT, v)))))
        else:
            print("%-6s not built" % t)
    sc = os.path.join(TP, "tools/shaderc")
    print("shaderc %s" % ("%d MB" % (os.path.getsize(sc) >> 20) if os.path.exists(sc) else "not built"))
    for d in (PDDI_HOST_DIR, PDDI_WIN_DIR):
        print("%-10s %s" % (os.path.basename(d), "built" if os.path.isdir(d) else "not built"))


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    f = sub.add_parser("fetch")
    f.add_argument("--force", action="store_true")
    b = sub.add_parser("build")
    b.add_argument("--target", choices=("host", "win32", "all"), default="all")
    sub.add_parser("shaderc")
    sub.add_parser("shaders")
    p = sub.add_parser("pddi")
    p.add_argument("--target", choices=("host", "win32", "all"), default="all")
    s = sub.add_parser("smoke")
    s.add_argument("--frames", type=int, default=120)
    s.add_argument("--capture", help="where to write the captured frame (TGA)")
    sub.add_parser("slots")
    sub.add_parser("status")
    a = ap.parse_args(argv)
    if a.cmd == "fetch":
        fetch(a.force)
    elif a.cmd == "build":
        fetch()
        for t in (("host", "win32") if a.target == "all" else (a.target,)):
            build_target(t)
    elif a.cmd == "shaderc":
        fetch()
        shaderc()
    elif a.cmd == "shaders":
        print(json.dumps(compile_shaders(), indent=1))
    elif a.cmd == "pddi":
        if a.target in ("host", "all"):
            pddi_host()
        if a.target in ("win32", "all"):
            pddi_win32()
    elif a.cmd == "smoke":
        return smoke(a.frames, a.capture)
    elif a.cmd == "slots":
        return slots()
    elif a.cmd == "status":
        status()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
