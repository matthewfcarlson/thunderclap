#!/usr/bin/env python3
"""bgfx for the graphics backend (docs/graphics-backend.md, stage G0): a pinned fetch and build of bx, bimg and bgfx.

  build/venv/bin/python tools/wine_gfx.py fetch            # download the pinned tarballs, check sha256, unpack
  build/venv/bin/python tools/wine_gfx.py build            # static libraries for macOS (host) and i686 Windows
  build/venv/bin/python tools/wine_gfx.py build --target win32
  build/venv/bin/python tools/wine_gfx.py shaderc          # bgfx's shaderc for the host (GENie + make, ~7 min)
  build/venv/bin/python tools/wine_gfx.py d3d4linux        # Wine bridge for HLSL: windows/d3d4linux.exe (+ Wine's d3dcompiler_47)
  build/venv/bin/python tools/wine_gfx.py shaders          # compile src/platform/sdl/pddi/shaders/*.sc
  build/venv/bin/python tools/wine_gfx.py pddi             # the pddi skeleton: host library + smoke test, win32 objects
  build/venv/bin/python tools/wine_gfx.py smoke            # run the host smoke test (a window, clear + one triangle)
  build/venv/bin/python tools/wine_gfx.py window-test [--target win32]   # SDL3 window + event pump + sa1's pad backend
  build/venv/bin/python tools/wine_gfx.py slots            # check the skeleton's MS-ABI vtable slots against rtti.json
  build/venv/bin/python tools/wine_gfx.py combiners        # regenerate shaders/vp/combiners.txt (then `pddi` again)
  build/venv/bin/python tools/wine_gfx.py status           # pins, what is fetched and built

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
  win32  i686-pc-windows-msvc with Homebrew LLVM's clang (the toolchain tools/wine_link.py uses): MS C++ ABI,
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
OUT = os.environ.get("HULK_TP_OUT") or os.path.join(TP, "out")   # play2: a private output dir
from clang_probe import LLVM  # noqa: E402  (resolver: $HULK_LLVM, Homebrew, ~/llvm)
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
     "#\tif BX_CRT_MSVC && !defined(_M_IX86) // hulk: keep __stdcall on i686 (tools/wine_gfx.py PATCHES)\n"
     "#\t\tdefine __stdcall\n#\tendif // BX_CRT_MSVC"),
    #  - bgfx's Vulkan renderer: GPU timer queries off when HULK_VK_NO_TIMER_QUERY is defined. Under Wine on macOS
    #    (MoltenVK) the i686 build divides by zero in TimerQueryVK::begin; the timers only feed bgfx's profiler stats.
    ("bgfx", "src/renderer_vk.cpp",
     "\t\t\t\tm_timerQuerySupport = m_deviceProperties.limits.timestampComputeAndGraphics;",
     "\t\t\t\tm_timerQuerySupport = m_deviceProperties.limits.timestampComputeAndGraphics;\n"
     "#if defined(HULK_VK_NO_TIMER_QUERY) // hulk: tools/wine_gfx.py PATCHES\n"
     "\t\t\t\tm_timerQuerySupport = false;\n#endif"),
    #  - bgfx's Vulkan renderer: vkMapMemory through a wrapper that maps into an 8-byte slot when HULK_VK_MAP_WRAP is
    #    defined (G4). Wine 7.7's 32-bit winevulkan writes a 64-bit pointer through ppData: the word after a 4-byte
    #    pointer member is zeroed, e.g. OcclusionQueryVK::m_control.m_size right after m_queryResult (the first
    #    occlusion query then divides by zero; TimerQueryVK has the same layout, which is what the timer patch above
    #    avoided). Real Windows writes 4 bytes; the wrapper is harmless there.
    ("bgfx", "src/renderer_vk.cpp",
     "VK_IMPORT_DEVICE\n#undef VK_IMPORT_DEVICE_FUNC\n#undef VK_IMPORT_INSTANCE_FUNC\n#undef VK_IMPORT_FUNC\n",
     "VK_IMPORT_DEVICE\n#undef VK_IMPORT_DEVICE_FUNC\n#undef VK_IMPORT_INSTANCE_FUNC\n#undef VK_IMPORT_FUNC\n"
     "#if defined(HULK_VK_MAP_WRAP) // hulk: tools/wine_gfx.py PATCHES\n"
     "\tstatic PFN_vkMapMemory s_hulkMapMemory;\n"
     "\tstatic VkResult VKAPI_CALL hulkMapMemory(::VkDevice _device, ::VkDeviceMemory _memory, VkDeviceSize _offset,\n"
     "\t\tVkDeviceSize _size, VkMemoryMapFlags _flags, void** _data)\n"
     "\t{\n"
     "\t\tunion { void* ptr; uint64_t wide; } slot;\n"
     "\t\tslot.wide = 0;\n"
     "\t\tconst VkResult result = s_hulkMapMemory(_device, _memory, _offset, _size, _flags, &slot.ptr);\n"
     "\t\t*_data = slot.ptr;\n"
     "\t\treturn result;\n"
     "\t}\n"
     "#endif\n"),
    ("bgfx", "src/renderer_vk.cpp",
     "VK_IMPORT_DEVICE\n#undef VK_IMPORT_DEVICE_FUNC\n\n\t\t\tif (!imported)",
     "VK_IMPORT_DEVICE\n#undef VK_IMPORT_DEVICE_FUNC\n"
     "#if defined(HULK_VK_MAP_WRAP) // hulk: tools/wine_gfx.py PATCHES\n"
     "\t\t\tif (NULL != vkMapMemory && hulkMapMemory != vkMapMemory)\n"
     "\t\t\t{\n"
     "\t\t\t\ts_hulkMapMemory = vkMapMemory;\n"
     "\t\t\t\tvkMapMemory = hulkMapMemory;\n"
     "\t\t\t}\n"
     "#endif\n"
     "\n\t\t\tif (!imported)"),
    #  - bgfx's Vulkan renderer: precise occlusion queries where the device has them, when HULK_VK_PRECISE_OCCLUSION is
    #    defined (G4). The game's visibility test divides the passed samples by the area (d3dExtVisibilityTest,
    #    BillboardQuadGroup FUN_002ba220); without VK_QUERY_CONTROL_PRECISE_BIT Vulkan may answer any non-zero
    #    number (MoltenVK answers 1). D3D11 and Metal count.
    ("bgfx", "src/renderer_vk.cpp",
     "\t\t\t\t\t.occlusionQueryPrecise                   = VK_FALSE,",
     "#if defined(HULK_VK_PRECISE_OCCLUSION) // hulk: tools/wine_gfx.py PATCHES\n"
     "\t\t\t\t\t.occlusionQueryPrecise                   = supportedFeatures.occlusionQueryPrecise,\n"
     "#else\n"
     "\t\t\t\t\t.occlusionQueryPrecise                   = VK_FALSE,\n"
     "#endif"),
    ("bgfx", "src/renderer_vk.cpp",
     "\t\tvkCmdBeginQuery(commandBuffer, m_queryPool, _handle.idx, 0);",
     "#if defined(HULK_VK_PRECISE_OCCLUSION) // hulk: tools/wine_gfx.py PATCHES\n"
     "\t\tvkCmdBeginQuery(commandBuffer, m_queryPool, _handle.idx\n"
     "\t\t\t, s_renderVK->m_deviceFeatures.occlusionQueryPrecise ? VK_QUERY_CONTROL_PRECISE_BIT : 0);\n"
     "#else\n"
     "\t\tvkCmdBeginQuery(commandBuffer, m_queryPool, _handle.idx, 0);\n"
     "#endif"),
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
    parts = ["Third-party notices for binaries that link the graphics backend (tools/wine_gfx.py).\n"]
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
    text = """// generated by tools/wine_gfx.py: force-included into the i686-pc-windows-msvc build of bx/bimg/bgfx
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
                              "-DBGFX_CONFIG_RENDERER_OPENGL=43", "-DBGFX_CONFIG_RENDERER_VULKAN=1",
                              "-DHULK_VK_NO_TIMER_QUERY=1", "-DHULK_VK_MAP_WRAP=1",
                              "-DHULK_VK_PRECISE_OCCLUSION=1"]
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
    """bgfx's shaderc for the host, with HLSL (s_5_0, Direct3D 11) through upstream's d3d4linux bridge: shaderc runs
    tools/windows/d3d4linux.exe under Wine, which calls Wine's own d3dcompiler_47.dll (Wine's implementation, LGPL;
    nothing of Microsoft's). d3d4linux() builds that helper."""
    genie = _bx("tools/bin/darwin/genie")
    bg = _bgfx()
    r = subprocess.run([genie, "--with-tools", "--gcc=osx-arm64", "gmake"], cwd=bg, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("genie failed:\n" + r.stdout[-3000:] + r.stderr[-3000:])
    proj = os.path.join(bg, ".build/projects/gmake-osx-arm64")
    t0 = time.time()
    logf = os.path.join(OUT, "shaderc-build.log")
    with open(logf, "w") as f:
        # SHADERC_CONFIG_HAS_D3DCOMPILER: upstream turns the d3d4linux path on for Linux only; macOS works the same way
        # (bgfx's copy of DirectX-Headers' WSL stubs includes <sal.h> without shipping it: mingw-w64's, alone in a
        # directory of its own so nothing else of mingw-w64 is found)
        sal = os.path.join(COMPAT, "sal")
        os.makedirs(sal, exist_ok=True)
        for h in ("sal.h", "concurrencysal.h"):
            shutil.copy2(os.path.join(SRC, "mingw-w64/mingw-w64-headers/include", h), os.path.join(sal, h))
        r = subprocess.run(["make", "-j%d" % JOBS, "config=release", "shaderc",
                            "CPPFLAGS=-DSHADERC_CONFIG_HAS_D3DCOMPILER=1 -I" + sal], cwd=proj, stdout=f,
                           stderr=subprocess.STDOUT)
    if r.returncode:
        raise SystemExit("shaderc build failed (log %s)" % os.path.relpath(logf, ROOT))
    exe = os.path.join(bg, ".build/osx-arm64/bin/shadercRelease")
    os.makedirs(os.path.join(TP, "tools"), exist_ok=True)
    shutil.copy2(exe, os.path.join(TP, "tools/shaderc"))
    log("shaderc built in %d s" % (time.time() - t0))


# ---------------------------------------------------------------------------------------------
# d3d4linux.exe: upstream bgfx's 3rdparty/d3d4linux server (WTFPL, Sam Hocevar), built as an i686 PE with the image's
# toolchain. It needs a C++ standard library only for std::string / std::vector, which the mingw-w64 headers don't
# provide: a minimal stand-in of our own (compat/d3d4linux/, generated below) covers the members it uses.
WINE_DIR = os.path.expanduser("~/Library/Application Support/com.isaacmarovitz.Whisky/Libraries/Wine")
WINE = os.environ.get("WINE") or os.path.join(WINE_DIR, "bin/wine64")
D3D4LINUX_DIR = os.path.join(TP, "windows")                # shaderc looks in ../windows/ from its own directory
SHADER_PREFIX = os.path.join(ROOT, "build/g0/wineprefix")  # our own Wine prefix for the compiler runs

D3D4LINUX_STD = {
    "string": """#pragma once
// minimal std::string for d3d4linux.cpp (tools/wine_gfx.py): the members it uses
#include <stdlib.h>
#include <string.h>
namespace std {
class string {
  public:
    string() : m_p(0), m_n(0) { reserve(0); m_p[0] = 0; }
    string(const char* s) : m_p(0), m_n(0) { assign(s, strlen(s)); }
    string(const string& o) : m_p(0), m_n(0) { assign(o.m_p, o.m_n); }
    ~string() { free(m_p); }
    string& operator=(const string& o) { if (this != &o) assign(o.m_p, o.m_n); return *this; }
    string& operator+=(const char* s) { size_t k = strlen(s); size_t n = m_n; resize(n + k); memcpy(m_p + n, s, k); return *this; }
    string& operator+=(char c) { size_t n = m_n; resize(n + 1); m_p[n] = c; return *this; }
    void resize(size_t n) { reserve(n); if (n > m_n) memset(m_p + m_n, 0, n - m_n); m_n = n; m_p[n] = 0; }
    const char* c_str() const { return m_p; }
    size_t size() const { return m_n; }
    size_t length() const { return m_n; }
    char& operator[](size_t i) { return m_p[i]; }
  private:
    void reserve(size_t n) { m_p = (char*)realloc(m_p, n + 1); }
    void assign(const char* s, size_t n) { resize(n); memcpy(m_p, s, n); }
    char* m_p;
    size_t m_n;
};
}
""",
    "vector": """#pragma once
// minimal std::vector for d3d4linux.cpp (tools/wine_gfx.py): the members it uses
#include <stdlib.h>
#include <string.h>
namespace std {
template <class T> class vector {
  public:
    vector() : m_p(0), m_n(0) {}
    ~vector() { free(m_p); }
    void resize(size_t n) { m_p = (T*)realloc(m_p, n * sizeof(T) + 1); if (n > m_n) memset(m_p + m_n, 0, (n - m_n) * sizeof(T)); m_n = n; }
    T* data() { return m_p; }
    size_t size() const { return m_n; }
    T& operator[](size_t i) { return m_p[i]; }
  private:
    vector(const vector&);
    T* m_p;
    size_t m_n;
};
}
""",
    "cstdio": "#pragma once\n#include <stdio.h>\n",
    "cstdint": "#pragma once\n#include <stdint.h>\n",
}


def wine_wrapper():
    """d3d4linux execs D3D4LINUX_WINE with argv[0] "wine"; on macOS Wine finds its libraries from argv[0], so it gets
    a two-line script that execs Wine by its full path."""
    p = os.path.join(D3D4LINUX_DIR, "wine.sh")
    text = '#!/bin/sh\n# tools/wine_gfx.py: Wine by its full path (it locates its libraries from argv[0])\nexec "%s" "$@"\n' % WINE
    os.makedirs(D3D4LINUX_DIR, exist_ok=True)
    if not os.path.exists(p) or open(p).read() != text:
        open(p, "w").write(text)
        os.chmod(p, 0o755)
    return p


def d3d4linux():
    """build/third_party/windows/d3d4linux.exe (+ d3dcompiler_47.dll: a link to Wine's own x86_64 build).

    x86_64, as upstream builds it: d3d4linux.cpp calls D3DCompile & co. through plain function pointers, which on
    i686 would be cdecl calls into stdcall functions."""
    mg = os.path.join(SRC, "mingw-w64/mingw-w64-headers")
    cxx = [os.path.join(LLVM, "clang++"), "--target=x86_64-pc-windows-msvc", "-fms-extensions", "-fms-compatibility",
           "-std=c++17", "-O1", "-fno-exceptions", "-fno-rtti", "-fno-stack-protector", "-fno-threadsafe-statics",
           "-nostdinc++", "-isystem", os.path.join(mg, "crt"), "-isystem", os.path.join(mg, "include"),
           "-fgnuc-version=4.2.1", "-D_AMD64_=1", "-DWIN32_LEAN_AND_MEAN", "-D_WIN32_WINNT=0x0601", "-DWINVER=0x0601", "-D__MSVCRT_VERSION__=0x700",
           "-D__USE_MINGW_ANSI_STDIO=0", "-D_CRT_SECURE_NO_WARNINGS"]
    od = os.path.join(OUT, "d3d4linux")
    comp = os.path.join(od, "compat")
    os.makedirs(comp, exist_ok=True)
    for name, text in D3D4LINUX_STD.items():
        open(os.path.join(comp, name), "w").write(text)
    entry = os.path.join(od, "entry.cpp")
    open(entry, "w").write(
        "// d3d4linux.exe's entry point: no C runtime start-up in this image, so call main ourselves\n"
        "#include <stdio.h>\n#include <stdlib.h>\nint main(void);\n"
        "extern \"C\" FILE* __cdecl __iob_func(void);\n"
        "extern \"C\" FILE* __cdecl __acrt_iob_func(unsigned i) { return __iob_func() + i; }\n"
        "extern \"C\" void __cdecl d3d4linux_entry(void) { exit(main()); }\n"
        "extern \"C\" int _fltused = 0x9875;\n")
    src = _bgfx("3rdparty/d3d4linux/d3d4linux.cpp")
    objs = []
    for s_, o in ((src, os.path.join(od, "d3d4linux.obj")), (entry, os.path.join(od, "entry.obj"))):
        r = run(cxx + ["-I" + comp, "-I" + _bgfx("3rdparty/d3d4linux/include"), "-Wno-everything", "-c", s_, "-o", o])
        if r.returncode:
            raise SystemExit("d3d4linux: %s failed:\n%s" % (os.path.basename(s_), (r.stdout + r.stderr)[-3000:]))
        objs.append(o)
    # import libraries for what the two objects use (llvm-nm), from our own .def files: kernel32 for the
    # Windows API (LoadLibraryA, GetProcAddress), msvcrt for the rest (with msvcrt.dll's spellings of POSIX names)
    nm = run([os.path.join(LLVM, "llvm-nm"), "--undefined-only"] + objs)
    undef = sorted({l.split()[-1] for l in nm.stdout.splitlines() if l.strip().startswith("U ")})
    oldnames = {"fileno": "_fileno", "setmode": "_setmode", "strdup": "_strdup"}
    kernel32_api = {"LoadLibraryA", "LoadLibraryW", "GetProcAddress", "FreeLibrary", "GetLastError"}
    kernel32, msvcrt = [], []
    for u in undef:
        n = u[len("__imp_"):] if u.startswith("__imp_") else u
        if n in kernel32_api:
            kernel32.append(n)
        elif n in ("main", "__acrt_iob_func"):
            continue
        else:
            msvcrt.append("%s == %s" % (n, oldnames[n]) if n in oldnames else n)
    libs = []
    for dll, names in (("kernel32", kernel32), ("msvcrt", msvcrt)):
        d = os.path.join(od, dll + ".def")
        open(d, "w").write("LIBRARY %s.dll\nEXPORTS\n%s\n" % (dll, "\n".join(sorted(set(names)))))
        lib = os.path.join(od, dll + ".lib")
        r = run([os.path.join(LLVM, "llvm-dlltool"), "-m", "i386:x86-64", "-d", d, "-l", lib])
        if r.returncode:
            raise SystemExit("d3d4linux: dlltool %s: %s" % (dll, r.stderr[-1000:]))
        libs.append(lib)
    os.makedirs(D3D4LINUX_DIR, exist_ok=True)
    exe = os.path.join(D3D4LINUX_DIR, "d3d4linux.exe")
    lld = os.path.join(LLVM, "lld-link") if os.path.exists(os.path.join(LLVM, "lld-link")) else "lld-link"
    r = run([lld, "/nologo", "/machine:x64", "/subsystem:console", "/entry:d3d4linux_entry", "/nodefaultlib",
             "/out:" + exe] + objs + libs)
    if r.returncode:
        raise SystemExit("d3d4linux link failed:\n" + (r.stdout + r.stderr)[-3000:])
    dll = os.path.join(D3D4LINUX_DIR, "d3dcompiler_47.dll")
    wine_dll = os.path.join(WINE_DIR, "lib/wine/x86_64-windows/d3dcompiler_47.dll")
    if os.path.lexists(dll):
        os.unlink(dll)
    if os.path.exists(wine_dll):
        os.symlink(wine_dll, dll)
    wine_wrapper()
    log("d3d4linux: %s (%d imports), d3dcompiler_47.dll -> %s" % (os.path.relpath(exe, ROOT), len(undef), wine_dll))
    return exe


SHADER_PROFILES = {          # bgfx shaderc --platform / --profile per backend we can compile on macOS
    "metal": ("osx", "metal"),
    "spirv": ("linux", "spirv"),
    "glsl": ("linux", "430"),
    "essl": ("android", "300_es"),
    "wgsl": ("linux", "wgsl"),
}


# Direct3D 11/12 bytecode through d3d4linux + Wine's d3dcompiler_47 (shaderc(), d3d4linux()): opt-in, HULK_GFX_DXBC=1.
# The pipeline runs, but Whisky's Wine 7.7 compiler can't build bgfx's HLSL (no calls to user functions, no ternary
# operator, no lerp/transpose/asfloat: docs/graphics-backend.md G1); with a newer Wine (or on Linux) it is the route.
if os.environ.get("HULK_GFX_DXBC") == "1":
    SHADER_PROFILES["dxbc"] = ("windows", "s_5_0")


# ---------------------------------------------------------------------------------------------
# Combiners (docs/graphics-backend.md section 10): one fragment program per texture-stage combiner key the shader
# classes can produce. shaders/vp/combiners.txt lists the keys (tracked; `combiners` regenerates it by running the
# classes' pass set-up in the host build); each becomes fs_cmb_<FNV-1a of the key>.sc under out/shaders-gen/, the
# stages as constants for fs_vp_stage.sh, compiled with the other shaders and embedded. A key without one is drawn by
# the generic combiner (the stages as uniforms).
COMBINERS = os.path.join(PDDI, "shaders", "vp", "combiners.txt")
GEN_SHADERS = os.path.join(OUT, "shaders-gen")
SHADER_JOBS = 3


def combiner_hash(key):
    h = 2166136261
    for c in key.encode():
        h = ((h ^ c) * 16777619) & 0xffffffff
    return h


def read_combiners(path=COMBINERS):
    """[(key, hash, example)] from combiners.txt (key TAB hash TAB example; # comments)."""
    out = []
    if not os.path.exists(path):
        return out
    for line in open(path):
        line = line.rstrip("\n")
        if not line or line.startswith("#"):
            continue
        key, h, example = (line.split("\t") + ["", ""])[:3]
        if int(h, 16) != combiner_hash(key):
            raise SystemExit("combiners.txt: hash of %r is %08x, not %s" % (key, combiner_hash(key), h))
        out.append((key, combiner_hash(key), example))
    return out


def parse_combiner(key):
    """'c4.0.2a4.0.2r1|...' -> [(colour op, arg1, arg2, alpha op, arg1, arg2, result)]; '-' -> []"""
    import re
    if key == "-":
        return []
    stages = []
    for part in key.split("|"):
        m = re.fullmatch(r"c(\d+)\.(\d+)\.(\d+)a(\d+)\.(\d+)\.(\d+)r(\d+)", part)
        if not m:
            raise SystemExit("bad combiner key %r" % key)
        stages.append(tuple(int(g) for g in m.groups()))
    return stages


def generate_combiner_shaders():
    """out/shaders-gen/fs_cmb_<hash>.sc for every key of combiners.txt (rewritten only when changed; others of ours
    removed). Returns the file names."""
    os.makedirs(GEN_SHADERS, exist_ok=True)
    names = []
    for key, h, example in read_combiners():
        st = parse_combiner(key)
        lines = ["$input v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3", "",
                 "// generated by tools/wine_gfx.py from src/platform/sdl/pddi/shaders/vp/combiners.txt: the",
                 "// combiner %s (first made by: %s)" % (key, example),
                 "#define CMB_N %d" % len(st)]
        for i, (cop, ca1, ca2, aop, aa1, aa2, res) in enumerate(st):
            lines.append("#define CMB_K%d vec4(%d.0, %d.0, %d.0, %d.0)" % (i, cop, ca1, ca2, aop))
            lines.append("#define CMB_L%d vec4(%d.0, %d.0, %d.0, 0.0)" % (i, aa1, aa2, res))
        lines += ["#include <bgfx_shader.sh>", '#include "fs_vp_stage.sh"', ""]
        text = "\n".join(lines)
        fn = "fs_cmb_%08x.sc" % h
        path = os.path.join(GEN_SHADERS, fn)
        if not os.path.exists(path) or open(path).read() != text:
            open(path, "w").write(text)
        names.append(fn)
    for fn in os.listdir(GEN_SHADERS):
        if fn.startswith("fs_cmb_") and fn not in names:
            os.unlink(os.path.join(GEN_SHADERS, fn))
    return names


def compile_shaders(out_dir=None):
    """Compile every src/platform/sdl/pddi/shaders/{vs,fs}_*.sc, shaders/vp/{vs,fs}_*.sc (the vertex-program
    shaders, the fixed-function path and the generic combiners that pair with them: their own varying.def.sc) and
    shaders/fx/{vs,fs}_*.sc (the framebuffer effects' full-screen passes, G4: their own varyings), and
    the generated combiner programs (out/shaders-gen/fs_cmb_*.sc, with shaders/vp's varyings and fs_vp_stage.sh),
    for each profile into out/shaders/<profile>/ (one flat namespace: the file names are unique). Outputs newer than
    their inputs (the source, its varyings, the .sh headers, shaderc) are kept."""
    sc = os.path.join(TP, "tools/shaderc")
    if not os.path.exists(sc):
        raise SystemExit("no shaderc: run `tools/wine_gfx.py shaderc` first")
    out_dir = out_dir or os.path.join(OUT, "shaders")
    vp = os.path.join(PDDI, "shaders", "vp")
    fx = os.path.join(PDDI, "shaders", "fx")       # G4: the full-screen passes (their own varyings)
    res = {}
    units = []          # (source dir, file, varying dir, extra include dirs)
    for sd in (os.path.join(PDDI, "shaders"), vp, fx):
        units += [(sd, fn, sd, []) for fn in sorted(os.listdir(sd))
                  if fn.endswith(".sc") and fn[:3] in ("vs_", "fs_")]
    gen = generate_combiner_shaders()
    units += [(GEN_SHADERS, fn, vp, [vp]) for fn in gen]
    # stale generated programs (keys no longer listed) must not be embedded
    for prof in SHADER_PROFILES:
        od = os.path.join(out_dir, prof)
        if os.path.isdir(od):
            for fn in os.listdir(od):
                if fn.startswith("fs_cmb_") and fn[:-4] + ".sc" not in gen:
                    os.unlink(os.path.join(od, fn))

    def deps(sd, vd, inc):
        files = [os.path.join(vd, "varying.def.sc"), sc]
        for d in {sd, vd, *inc}:
            files += [os.path.join(d, f) for f in os.listdir(d) if f.endswith(".sh")]
        return max(os.path.getmtime(f) for f in files if os.path.exists(f))

    jobs = []
    for sd, fn, vd, inc in units:
        kind = {"vs": "vertex", "fs": "fragment"}[fn[:2]]
        newest = max(deps(sd, vd, inc), os.path.getmtime(os.path.join(sd, fn)))
        for prof, (plat, p) in SHADER_PROFILES.items():
            od = os.path.join(out_dir, prof)
            os.makedirs(od, exist_ok=True)
            out = os.path.join(od, fn[:-3] + ".bin")
            if os.path.exists(out) and os.path.getmtime(out) >= newest:
                res["%s/%s" % (prof, fn)] = "ok %d B (up to date)" % os.path.getsize(out)
                continue
            cmd = [sc, "-f", os.path.join(sd, fn), "-o", out, "--type", kind, "--platform", plat, "-p", p,
                   "-i", _bgfx("src"), "--varyingdef", os.path.join(vd, "varying.def.sc")]
            for d in inc:
                cmd += ["-i", d]
            jobs.append((prof, fn, out, cmd))

    def one(job):
        prof, fn, out, cmd = job
        env = None
        if prof == "dxbc":
            if not os.path.exists(os.path.join(D3D4LINUX_DIR, "d3d4linux.exe")):
                return job, None, "FAILED no d3d4linux.exe (tools/wine_gfx.py d3d4linux)"
            os.makedirs(SHADER_PREFIX, exist_ok=True)
            env = dict(os.environ, WINEPREFIX=SHADER_PREFIX, D3D4LINUX_WINE=wine_wrapper(), WINEDEBUG="-all",
                       WINEDLLOVERRIDES="mscoree,mshtml=")
        r = subprocess.run(cmd, capture_output=True, text=True, env=env)
        return job, r, None

    with ThreadPoolExecutor(1 if "dxbc" in SHADER_PROFILES else SHADER_JOBS) as ex:
        for (prof, fn, out, cmd), r, err in ex.map(one, jobs):
            if err:
                res["%s/%s" % (prof, fn)] = err
            elif r.returncode == 0:
                res["%s/%s" % (prof, fn)] = "ok %d B" % os.path.getsize(out)
            else:
                if os.path.exists(out):
                    os.unlink(out)
                res["%s/%s" % (prof, fn)] = "FAILED " + (r.stdout + r.stderr)[-500:]
    return res


def combiners():
    """Regenerate shaders/vp/combiners.txt: the host smoke binary runs every shader class's pass set-up over its
    parameters (bgfx_combiner.cpp enumerateCombinerKeys) and lists the keys. Rebuild afterwards (`pddi`)."""
    exe = os.path.join(PDDI_HOST_DIR, "pddi_smoke")
    if not os.path.exists(exe):
        raise SystemExit("build it first: tools/wine_gfx.py pddi --target host")
    tmp = os.path.join(PDDI_HOST_DIR, "combiners.raw")
    r = subprocess.run([exe, "--combiner-keys", tmp], capture_output=True, text=True, timeout=120)
    if r.returncode:
        raise SystemExit("combiner enumeration failed:\n" + r.stdout + r.stderr)
    rows = [l.rstrip("\n").split("\t") for l in open(tmp) if l.strip()]
    head = ["# The texture-stage combiner keys the shader classes' pass set-up can produce, one generated fragment",
            "# program each (docs/graphics-backend.md section 10). Generated by `tools/wine_gfx.py combiners` (the host",
            "# build runs every class's slots 12/14/13 over the parameters that change its stages); do not edit.",
            "# key: per active stage c<colour op>.<arg1>.<arg2>a<alpha op>.<arg1>.<arg2>r<result> (Xbox D3DTOP/D3DTA",
            "# values; arguments an op doesn't read are 0), stages joined by '|'; '-': no stage (the diffuse colour).",
            "# hash: FNV-1a 32 of the key (the program is fs_cmb_<hash>); example: the first set-up that made it.",
            "# key\thash\texample"]
    body = ["%s\t%s\t%s" % (k, h, e) for k, h, e in sorted(rows, key=lambda r: (r[0].count("|"), r[0]))]
    open(COMBINERS, "w").write("\n".join(head + body) + "\n")
    log("combiners: %d keys -> %s" % (len(body), os.path.relpath(COMBINERS, ROOT)))
    return len(body)


# ---------------------------------------------------------------------------------------------
# The pddi skeleton (src/platform/sdl/pddi)
PDDI_HOST_DIR = os.path.join(OUT, "pddi-host")
SDL3 = "/opt/homebrew/opt/sdl3"          # the smoke test's window (Homebrew's SDL3, already a port dependency)
PDDI_WIN_DIR = os.path.join(OUT, "pddi-win32")
PLATFORM_EVENTS = os.path.join(ROOT, "src/platform/sdl/platform_events.cpp")


def pddi_sources():
    """The backend's units plus the program's window/event code (src/platform/sdl/platform_events.cpp)."""
    return sorted(os.path.join(PDDI, f) for f in os.listdir(PDDI) if f.endswith(".cpp")) + [PLATFORM_EVENTS]


def drop_stale(objdir, srcs, suffix):
    """Objects of units that no longer exist (win32_platform.cpp became sdl_platform.cpp): wine_link links every
    object in the directory."""
    keep = {os.path.basename(s)[:-4] + suffix for s in srcs}
    for f in os.listdir(objdir) if os.path.isdir(objdir) else []:
        if f.endswith(suffix) and f not in keep and f != "smoke_main" + suffix:
            os.unlink(os.path.join(objdir, f))


def sdl_headers(target):
    """-I for SDL3's headers: Homebrew's for the host smoke test, the pinned source's for the i686 build (the
    window code only calls SDL; tools/wine_sdl.py fetch unpacks it)."""
    inc = os.path.join(SDL3, "include") if target == "host" else os.path.join(SRC, "SDL/include")
    if not os.path.isdir(os.path.join(inc, "SDL3")):
        raise SystemExit("SDL3 headers missing (%s): build/venv/bin/python tools/wine_sdl.py fetch" % inc)
    # (mingw-w64's sal.h lacks the scanf annotation SDL's headers use on Windows: empty, as tools/wine_sdl.py)
    return ["-I" + inc, "-I" + os.path.dirname(PDDI)] + (["-D_Scanf_format_string_impl_="] if target == "win32" else [])


def pddi_host():
    """The skeleton as a host static library, the shaders embedded for Metal, and the smoke test linked against it."""
    res = compile_shaders()
    bad = [k for k, v in res.items() if not v.startswith("ok") and not k.startswith("dxbc/")]   # (dxbc: Wine)
    if bad:
        raise SystemExit("shaders failed: %s" % {k: res[k] for k in bad})
    gen = os.path.join(PDDI_HOST_DIR, "gen")
    embed_shaders(gen, "metal")
    cxx, ar, _ = target_cfg("host")
    inc = ["-I" + PDDI, "-I" + gen, "-I" + _bx("include"), "-I" + _bgfx("include"), "-I" + _bimg("include"),
           "-DHULK_PDDI_HOST=1", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror"]
    objs = []
    os.makedirs(os.path.join(PDDI_HOST_DIR, "obj"), exist_ok=True)
    drop_stale(os.path.join(PDDI_HOST_DIR, "obj"), pddi_sources(), ".o")
    logf = os.path.join(PDDI_HOST_DIR, "build.log")
    open(logf, "w").close()
    jobs = []
    for s in pddi_sources() + [os.path.join(PDDI, "smoke/smoke_main.cpp")]:
        o = os.path.join(PDDI_HOST_DIR, "obj", os.path.basename(s)[:-4] + ".o")
        jobs.append((s, o, cxx + inc + sdl_headers("host") + ["-c", s, "-o", o]))
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


def embed_shaders(gen, profiles):
    """pddi_shaders.h: each compiled shader of each profile as a byte array, and a table the backend picks from by
    renderer at run time (bgfx_context.cpp findShader): {name, profile, data, size}."""
    os.makedirs(gen, exist_ok=True)
    if isinstance(profiles, str):
        profiles = [profiles]
    lines = ["// generated by tools/wine_gfx.py from src/platform/sdl/pddi/shaders (%s)" % ", ".join(profiles)]
    table = []
    for profile in profiles:
        sd = os.path.join(OUT, "shaders", profile)
        if not os.path.isdir(sd):
            continue
        for fn in sorted(os.listdir(sd)):
            if not fn.endswith(".bin"):
                continue
            data = open(os.path.join(sd, fn), "rb").read()
            name = "g_%s_%s" % (fn[:-4], profile)
            table.append('    {"%s", "%s", %s, %d},' % (fn[:-4], profile, name, len(data)))
            lines.append("static const unsigned char %s[%d] = {" % (name, len(data)))
            for i in range(0, len(data), 24):
                lines.append("    " + ",".join(str(b) for b in data[i:i + 24]) + ",")
            lines.append("};")
    lines += ["struct PddiEmbeddedShader { const char* name; const char* profile; const unsigned char* data; "
              "unsigned size; };", "static const PddiEmbeddedShader g_pddi_shaders[] = {"] + table + \
             ["    {0, 0, 0, 0},", "};"]
    open(os.path.join(gen, "pddi_shaders.h"), "w").write("\n".join(lines) + "\n")
    # the combiner keys (the self-test's sweep draws every one through its program and the generic combiner)
    keys = ["// generated by tools/wine_gfx.py from src/platform/sdl/pddi/shaders/vp/combiners.txt",
            "static const char* const g_pddi_combiner_keys[] = {"]
    keys += ['    "%s",' % k for k, _h, _e in read_combiners()] + ["    0,", "};"]
    open(os.path.join(gen, "pddi_combiners.h"), "w").write("\n".join(keys) + "\n")


def pddi_win32():
    """The skeleton for the native image: i686-pc-windows-msvc objects (HULK_PDDI_GAME=1), archived."""
    cxx, ar, _ = target_cfg("win32")
    gen = os.path.join(PDDI_WIN_DIR, "gen")
    embed_shaders(gen, ["dxbc", "spirv"])     # Direct3D 11 (Wine, Windows) and Vulkan; the backend picks by renderer
    inc = ["-I" + PDDI, "-I" + gen, "-I" + _bx("include"), "-I" + _bgfx("include"), "-I" + _bimg("include"),
           "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_EMBED_SHADERS=1", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field", "-Werror",
           "-fno-threadsafe-statics"] + sdl_headers("win32")
    os.makedirs(os.path.join(PDDI_WIN_DIR, "obj"), exist_ok=True)
    drop_stale(os.path.join(PDDI_WIN_DIR, "obj"), pddi_sources(), ".obj")
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


def window_test(target):
    """The window + one event pump + sa1's gamepad backend in one process (pddi/smoke/window_test.cpp):
    host (Homebrew SDL3, Metal machine) or win32 (SDL3.dll, i686 under Wine, the build the game image loads)."""
    import wine_sdl      # (imports this module back: kept lazy)
    smoke_dir = os.path.join(PDDI, "smoke")
    plat = os.path.dirname(PDDI)
    inputs = [os.path.join(plat, "input/hulk_input.cpp")]
    test = os.path.join(smoke_dir, "window_test.cpp")
    d = os.path.join(OUT, "window-test-" + target)
    os.makedirs(d, exist_ok=True)
    logf = os.path.join(d, "build.log")
    open(logf, "w").close()
    srcs = [test, PLATFORM_EVENTS] + inputs
    if target == "host":
        flags = ["/usr/bin/clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-std=c++17", "-O1", "-g",
                 "-fno-exceptions", "-fno-rtti", "-Wall", "-Wno-unused-parameter", "-Werror"] + sdl_headers("host")
        objs = []
        for s_ in srcs:
            o = os.path.join(d, os.path.basename(s_)[:-4] + ".o")
            r = run(flags + ["-c", s_, "-o", o], logf)
            if r.returncode:
                raise SystemExit("window-test: %s failed:\n%s" % (os.path.relpath(s_, ROOT), (r.stdout + r.stderr)[-3000:]))
            objs.append(o)
        exe = os.path.join(d, "window_test")
        r = run(["/usr/bin/clang++", "-arch", "arm64", "-o", exe] + objs + [
                "-framework", "Cocoa", "-framework", "IOKit", "-framework", "CoreHaptics", "-framework", "GameController",
                "-L" + os.path.join(SDL3, "lib"), "-lSDL3", "-Wl,-rpath," + os.path.join(SDL3, "lib")], logf)
        if r.returncode:
            raise SystemExit("window-test link failed:\n" + (r.stdout + r.stderr)[-3000:])
        p = subprocess.run([exe], capture_output=True, text=True, timeout=300)
    else:
        flags = wine_sdl.win32_cxx() + sdl_headers("win32") + wine_sdl.mingw_inc() + ["-DHULK_TEST_RT=1"]
        rt = os.path.join(ROOT, "tests/native_audio/test_runtime_win32.cpp")
        objs = []
        for s_ in srcs + [rt]:
            o = os.path.join(d, os.path.basename(s_)[:-4] + ".obj")
            r = run(flags + ["-c", s_, "-o", o], logf)
            if r.returncode:
                raise SystemExit("window-test: %s failed:\n%s" % (os.path.relpath(s_, ROOT), (r.stdout + r.stderr)[-3000:]))
            objs.append(o)
        imp = os.path.join(d, "imports")
        os.makedirs(imp, exist_ok=True)
        libs, _by, unresolved = wine_sdl.import_libs(objs, imp, logf, extra_defined=wine_sdl._sdl_exports())
        exe = os.path.join(d, "window_test.exe")
        r = run([wine_sdl.LLD_LINK, "/nologo", "/machine:x86", "/subsystem:console", "/entry:hulk_test_entry",
                 "/nodefaultlib", "/out:" + exe] + objs + [os.path.join(wine_sdl.WIN_DIR, "SDL3.lib")] + libs, logf)
        if r.returncode:
            raise SystemExit("window-test link failed:\n" + (r.stdout + r.stderr)[-3000:])
        shutil.copy2(os.path.join(wine_sdl.WIN_DIR, "SDL3.dll"), os.path.join(d, "SDL3.dll"))
        env = wine_sdl.native_gfx_wine_env(os.path.join(ROOT, "build/native/wineprefix"))
        env.update(SDL_AUDIO_DRIVER="dummy", SDL_JOYSTICK_HIDAPI="0")
        p = subprocess.run([WINE, exe], capture_output=True, text=True, timeout=300, env=env, cwd=d)
    sys.stdout.write(p.stdout)
    sys.stderr.write(p.stderr[-3000:])
    log("window-test (%s): exit %d" % (target, p.returncode))
    return p.returncode


def smoke(frames=60, png=None, page=None):
    """The host smoke test: every page of the self-test scene (or one), a screenshot each, every probe checked."""
    exe = os.path.join(PDDI_HOST_DIR, "pddi_smoke")
    if not os.path.exists(exe):
        raise SystemExit("build it first: tools/wine_gfx.py pddi")
    png = png or os.path.join(PDDI_HOST_DIR, "smoke.tga")
    cmd = [exe, "--frames", str(frames), "--capture", png, "--drawlog", os.path.join(PDDI_HOST_DIR, "smoke.pdl")]
    if page is not None:
        cmd += ["--page", str(page)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
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
           "-DHULK_PDDI_GAME=1", "-DHULK_PDDI_EMBED_SHADERS=1"] + sdl_headers("win32")
    if not os.path.exists(os.path.join(PDDI_WIN_DIR, "gen", "pddi_shaders.h")):
        embed_shaders(os.path.join(PDDI_WIN_DIR, "gen"), ["dxbc", "spirv"])
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
    sub.add_parser("d3d4linux")
    sub.add_parser("shaders")
    p = sub.add_parser("pddi")
    p.add_argument("--target", choices=("host", "win32", "all"), default="all")
    s = sub.add_parser("smoke")
    s.add_argument("--frames", type=int, default=60, help="frames per page")
    s.add_argument("--capture", help="where to write the captured frame (TGA; page N: name-pageN.tga)")
    s.add_argument("--page", type=int, help="one page of the self-test scene (default: all)")
    w = sub.add_parser("window-test")
    w.add_argument("--target", choices=["host", "win32"], default="host")
    sub.add_parser("slots")
    sub.add_parser("status")
    sub.add_parser("combiners")
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
    elif a.cmd == "d3d4linux":
        d3d4linux()
    elif a.cmd == "shaders":
        print(json.dumps(compile_shaders(), indent=1))
    elif a.cmd == "pddi":
        if a.target in ("host", "all"):
            pddi_host()
        if a.target in ("win32", "all"):
            pddi_win32()
    elif a.cmd == "window-test":
        return window_test(a.target)
    elif a.cmd == "smoke":
        return smoke(a.frames, a.capture, a.page)
    elif a.cmd == "slots":
        return slots()
    elif a.cmd == "combiners":
        combiners()
    elif a.cmd == "status":
        status()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
