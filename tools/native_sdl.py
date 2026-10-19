#!/usr/bin/env python3
"""SDL3 for the native audio and input backends (docs/native-audio-input.md): a pinned fetch and build of upstream
SDL, our backends on top of it, and their smoke tests.

  build/venv/bin/python tools/native_sdl.py fetch            # download the pinned tarball, check sha256, unpack
  build/venv/bin/python tools/native_sdl.py build            # SDL3 for the host (static) and i686 Windows (SDL3.dll)
  build/venv/bin/python tools/native_sdl.py build --target win32
  build/venv/bin/python tools/native_sdl.py backends         # src/platform/sdl/{audio,input} + the xdk shim files:
                                                             #   host library, win32 objects (hulk_sdl.lib)
  build/venv/bin/python tools/native_sdl.py test             # host tests: tests/native_audio, tests/native_input
  build/venv/bin/python tools/native_sdl.py wine-test        # the same through the XDK-shaped API, i686 under Wine
  build/venv/bin/python tools/native_sdl.py status

Everything goes under build/third_party/ (ignored by git); nothing is installed system-wide.

  dl/SDL-<tag>.tar.gz    the pinned tarball (sha256 below)
  src/SDL/               upstream SDL at the pinned tag (zlib licence)
  out/sdl-host/          libSDL3.a (CMake, static, macOS arm64) + include/
  out/sdl-win32/         SDL3.dll + SDL3.lib (import library) for i686-pc-windows-msvc, build.json (command lines)
  out/sdl-backends/      our audio/input backends: host/ (library + tests), win32/ (objects, hulk_sdl.lib, tests)
  out/LICENSES-SDL.txt   the notice to ship with a binary that links SDL

Targets (as tools/native_gfx.py):
  host   macOS arm64, Apple clang, SDL's CMake build (static library; audio, joystick/gamepad, haptic, hidapi,
         events; video/render/gpu/camera off)
  win32  i686-pc-windows-msvc with Homebrew LLVM's clang and lld-link, mingw-w64's headers (fetched by
         tools/native_gfx.py; no mingw-w64 code or library is linked), SDL's own Windows configuration
         (include/build_config/SDL_build_config_windows.h, the source list of VisualC/SDL/SDL.vcxproj) built as
         SDL3.dll. A DLL keeps SDL's C runtime and Win32 imports out of the game image's symbol space (the tree binds
         plain names like _free and _memcpy to its own things: docs/graphics-backend.md 8): the image only imports
         SDL_* functions from SDL3.lib. SDL3.dll imports msvcrt.dll and the Win32 DLLs; the import libraries come
         from .def files generated from the names SDL needs and the export tables of Wine's own i386 DLLs (only the
         export names are read).
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import tarfile
import time
import urllib.request
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import native_gfx  # noqa: E402  (shared: the mingw-w64 headers pin, Wine location, run())

TP = native_gfx.TP
DL = native_gfx.DL
SRC = native_gfx.SRC
OUT = native_gfx.OUT
LLVM = native_gfx.LLVM
LLD_LINK = os.path.join(LLVM, "lld-link") if os.path.exists(os.path.join(LLVM, "lld-link")) else shutil.which("lld-link")
SDL_SRC = os.path.join(SRC, "SDL")
HOST_DIR = os.path.join(OUT, "sdl-host")
WIN_DIR = os.path.join(OUT, "sdl-win32")
BK_DIR = os.path.join(OUT, "sdl-backends")
PLAT = os.path.join(ROOT, "src/platform/sdl")

# Pinned upstream SDL: (tag, sha256 of codeload's tar.gz). release-3.4.18 was published 2026-10-02.
SDL_TAG = "release-3.4.18"
SDL_SHA256 = "c4b08b950bd29d83caae0ab8d884298d27046a9d30700fb42841c50992665c90"
SDL_URL = "https://codeload.github.com/libsdl-org/SDL/tar.gz/refs/tags/" + SDL_TAG

# Local fixes to the pinned sources, applied after unpacking (exact text; fetch fails if upstream moved). Local
# build fixes only, never sent upstream.
#  - SDL_mslibc.c: clang rejects a static constant inside a naked function (MSVC accepts it): moved to file scope.
PATCHES = [
    ("src/stdlib/SDL_mslibc.c",
     "void __declspec(naked) _ftoul2_legacy()\n{\n    static const Uint64 LLONG_MAX_PLUS_ONE = 0x43e0000000000000ULL;\n",
     "static const Uint64 LLONG_MAX_PLUS_ONE = 0x43e0000000000000ULL; /* hulk: tools/native_sdl.py PATCHES */\n"
     "void __declspec(naked) _ftoul2_legacy()\n{\n"),
]

JOBS = 3            # a shared machine: at most three compiler processes

# The Win32 DLLs SDL3.dll may import from (searched in this order for each name SDL needs)
WIN_DLLS = ["kernel32", "user32", "gdi32", "advapi32", "shell32", "ole32", "oleaut32", "winmm", "imm32", "version",
            "setupapi", "cfgmgr32", "hid", "msvcrt", "ntdll"]
WINE_I386 = os.path.join(os.path.dirname(os.path.dirname(native_gfx.WINE)), "lib/wine/i386-windows")


def log(*a):
    print(*a, file=sys.stderr, flush=True)


def sha256(path):
    return native_gfx.sha256(path)


# ---------------------------------------------------------------------------------------------
def fetch(force=False):
    os.makedirs(DL, exist_ok=True)
    path = os.path.join(DL, "SDL-%s.tar.gz" % SDL_TAG)
    if not os.path.exists(path) or force:
        log("download SDL %s" % SDL_TAG)
        tmp = path + ".part"
        with urllib.request.urlopen(SDL_URL, timeout=600) as r, open(tmp, "wb") as f:
            shutil.copyfileobj(r, f)
        os.replace(tmp, path)
    got = sha256(path)
    if got != SDL_SHA256:
        raise SystemExit("%s: sha256 %s, pinned %s: check the tag and update SDL_SHA256" %
                         (os.path.relpath(path, ROOT), got, SDL_SHA256))
    stamp = os.path.join(SDL_SRC, ".pinned")
    tag = "%s %s %s" % (SDL_TAG, SDL_SHA256, hashlib.sha256(repr(PATCHES).encode()).hexdigest()[:12])
    if not (os.path.exists(stamp) and open(stamp).read().strip() == tag and not force):
        if os.path.exists(SDL_SRC):
            shutil.rmtree(SDL_SRC)
        os.makedirs(SDL_SRC)
        log("unpack SDL")
        with tarfile.open(path) as t:
            members = []
            for m in t.getmembers():
                parts = m.name.split("/", 1)
                if len(parts) < 2 or not parts[1]:
                    continue
                rel = parts[1]
                if m.issym() or m.islnk() or rel.startswith("/") or ".." in rel.split("/"):
                    continue
                m.name = rel
                members.append(m)
            t.extractall(SDL_SRC, members=members, filter="data")
        for rel, old, new in PATCHES:
            f = os.path.join(SDL_SRC, rel)
            text = open(f).read()
            if old not in text:
                raise SystemExit("patch for SDL/%s no longer applies: check PATCHES" % rel)
            open(f, "w").write(text.replace(old, new))
            log("patched SDL/%s" % rel)
        open(stamp, "w").write(tag + "\n")
    # the mingw-w64 headers for the win32 build come from tools/native_gfx.py's pins
    if not os.path.exists(os.path.join(SRC, "mingw-w64", ".pinned")):
        native_gfx.fetch()
    os.makedirs(OUT, exist_ok=True)
    open(os.path.join(OUT, "LICENSES-SDL.txt"), "w").write(
        "Third-party notice for binaries that link SDL (tools/native_sdl.py).\n" + "=" * 78 +
        "\nSDL (https://github.com/libsdl-org/SDL, tag %s)\n\n%s" % (SDL_TAG, open(os.path.join(SDL_SRC, "LICENSE.txt")).read()))


# ---------------------------------------------------------------------------------------------
# host: SDL's CMake build
def build_host():
    bd = os.path.join(HOST_DIR, "cmake")
    os.makedirs(bd, exist_ok=True)
    logf = os.path.join(HOST_DIR, "build.log")
    t0 = time.time()
    cfg = ["cmake", "-S", SDL_SRC, "-B", bd, "-G", "Ninja", "-DCMAKE_BUILD_TYPE=Release",
           "-DCMAKE_OSX_ARCHITECTURES=arm64", "-DCMAKE_OSX_DEPLOYMENT_TARGET=11.0",
           "-DCMAKE_C_COMPILER=/usr/bin/clang", "-DCMAKE_INSTALL_PREFIX=" + HOST_DIR,
           "-DSDL_SHARED=OFF", "-DSDL_STATIC=ON", "-DSDL_TEST_LIBRARY=OFF", "-DSDL_TESTS=OFF", "-DSDL_EXAMPLES=OFF",
           "-DSDL_VIDEO=OFF", "-DSDL_GPU=OFF", "-DSDL_RENDER=OFF", "-DSDL_CAMERA=OFF", "-DSDL_DIALOG=OFF",
           "-DSDL_TRAY=OFF", "-DSDL_POWER=OFF", "-DSDL_SENSOR=ON", "-DSDL_AUDIO=ON", "-DSDL_JOYSTICK=ON",
           "-DSDL_HAPTIC=ON", "-DSDL_HIDAPI=ON"]
    with open(logf, "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(JOBS)], ["cmake", "--install", bd]):
            f.write("$ " + " ".join(cmd) + "\n")
            f.flush()
            r = subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT)
            if r.returncode:
                raise SystemExit("host SDL build failed at %s (log %s)" % (cmd[1], os.path.relpath(logf, ROOT)))
    lib = os.path.join(HOST_DIR, "lib/libSDL3.a")
    log("host: %s %d KB in %d s" % (os.path.relpath(lib, ROOT), os.path.getsize(lib) >> 10, time.time() - t0))
    json.dump({"target": "host", "tag": SDL_TAG, "configure": " ".join(cfg), "lib": os.path.relpath(lib, ROOT)},
              open(os.path.join(HOST_DIR, "build.json"), "w"), indent=1)


# ---------------------------------------------------------------------------------------------
# win32: SDL3.dll from SDL's Windows source list with clang + lld-link
def mingw_inc():
    mg = os.path.join(SRC, "mingw-w64/mingw-w64-headers")
    return ["-isystem", os.path.join(mg, "crt"), "-isystem", os.path.join(mg, "include")]


def win32_cflags():
    return [os.path.join(LLVM, "clang"), "--target=i686-pc-windows-msvc", "-fms-extensions", "-O2", "-msse2",
            "-fno-stack-protector", "-fno-builtin-memcpy", "-fno-builtin-memset"] + mingw_inc() + [
            "-fgnuc-version=4.2.1", "-D_X86_=1", "-D_WIN32_WINNT=0x0601", "-DWINVER=0x0601", "-DNDEBUG",
            "-D__MSVCRT_VERSION__=0x700", "-D__USE_MINGW_ANSI_STDIO=0", "-D_CRT_SECURE_NO_WARNINGS",
            "-Wno-pragma-pack", "-Wno-unknown-pragmas", "-Wno-ignored-attributes", "-Wno-macro-redefined",
            "-Wno-nonportable-include-path", "-Wno-microsoft-enum-value", "-Wno-incompatible-pointer-types",
            "-Wno-int-conversion", "-Wno-deprecated-declarations", "-Wno-unused-command-line-argument"]


# SDL's Windows configuration with what this build leaves out (the image needs audio, joystick/gamepad, haptic,
# events and threads; SDL's video core stays because joystick code calls into it). SDL_internal.h honours the
# *_DISABLED macros.
WIN_CONFIG = """/* generated by tools/native_sdl.py: SDL's Windows configuration for the native image's SDL3.dll */
#ifndef HULK_SDL_BUILD_CONFIG_H
#define HULK_SDL_BUILD_CONFIG_H
/* no C runtime: SDL's own stdlib/libm and SDL_mslibc.c (_chkstk, 64-bit division, _fltused), its own DLL entry */
#define HAVE_LIBC 0
#include "SDL_build_config_windows.h"
#undef HAVE_LIBC
#define SDL_CAMERA_DISABLED 1
#define SDL_GPU_DISABLED 1
#define SDL_RENDER_DISABLED 1
#undef SDL_VIDEO_VULKAN
#undef SDL_VIDEO_OPENGL_EGL
#undef SDL_VIDEO_OPENGL_ES2
#undef SDL_VIDEO_RENDER_D3D12
/* stb_image (PNG/JPEG surfaces) is not needed, and its __forceinline clashes with mingw-w64's GNU definition */
#define SDL_DISABLE_STB 1
/* mingw-w64's sal.h lacks this annotation (MSVC's has it): empty */
#define _Scanf_format_string_impl_
#endif
"""
WIN_SKIP = ()

# What SDL3.dll needs beyond SDL's own sources when there is no C runtime: COM GUIDs uuid.lib would give (from
# mingw-w64's public headers with INITGUID) and hypot (one force-feedback driver calls it).
WIN_GLUE = """/* generated by tools/native_sdl.py */
#define INITGUID
#include <windows.h>
#include <shobjidl.h>
#define _Scanf_format_string_impl_
#include <SDL3/SDL_stdinc.h>
double hypot(double x, double y) { return SDL_sqrt(x * x + y * y); }
"""


def win32_sources():
    proj = open(os.path.join(SDL_SRC, "VisualC/SDL/SDL.vcxproj")).read()
    srcs = []
    for m in re.finditer(r'<ClCompile Include="([^"]+)"', proj):
        rel = m.group(1).replace("\\", "/")
        p = os.path.normpath(os.path.join(SDL_SRC, "VisualC/SDL", rel))
        if not p.endswith((".c", ".cpp")) or any(s in p for s in WIN_SKIP):
            continue
        srcs.append(p)
    # SDL's math library (the VisualC project leaves it to the CRT)
    libm = os.path.join(SDL_SRC, "src/libm")
    srcs += [os.path.join(libm, f) for f in os.listdir(libm) if f.endswith(".c")]
    return sorted(set(srcs))


def wine_exports(dll):
    p = os.path.join(WINE_I386, dll + ".dll")
    r = subprocess.run([os.path.join(LLVM, "llvm-readobj"), "--coff-exports", p], capture_output=True, text=True)
    return set(re.findall(r"^\s*Name: (\S+)$", r.stdout, re.M))


def import_libs(objs, outdir, logf, extra_defined=()):
    """Import libraries (llvm-dlltool) for every external name the objects use, each from the first DLL of WIN_DLLS
    whose (Wine) export table has the name. Returns ([.lib], {dll: [names]}, [unresolved])."""
    nm = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--undefined-only", "--no-sort"] + objs, capture_output=True,
                        text=True)
    defs = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--defined-only", "--no-sort"] + objs, capture_output=True,
                          text=True)
    defined = {l.split()[-1] for l in defs.stdout.splitlines() if len(l.split()) >= 3} | set(extra_defined)
    undef = sorted({l.split()[-1] for l in nm.stdout.splitlines() if l.strip().startswith("U ")} - defined)
    exports = {d: wine_exports(d) for d in WIN_DLLS}
    by_dll, unresolved = {}, []
    for sym in undef:
        imp = sym.startswith("__imp_")
        s = sym[6:] if imp else sym
        # i386 decoration: _name (cdecl) or _name@N (stdcall)
        base = s[1:] if s.startswith("_") else s
        name = base.split("@")[0]
        for d in WIN_DLLS:
            if name in exports[d]:
                by_dll.setdefault(d, set()).add(base)
                break
        else:
            unresolved.append(sym)
    libs = []
    for d, names in sorted(by_dll.items()):
        df = os.path.join(outdir, "%s.def" % d)
        with open(df, "w") as f:
            f.write("LIBRARY %s.dll\nEXPORTS\n" % d)
            for n in sorted(names):
                f.write("%s\n" % n)
        lib = os.path.join(outdir, "%s.lib" % d)
        r = subprocess.run([os.path.join(LLVM, "llvm-dlltool"), "-m", "i386", "-d", df, "-l", lib, "-k"],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("llvm-dlltool %s: %s" % (d, r.stderr[-2000:]))
        libs.append(lib)
    return libs, {d: sorted(v) for d, v in by_dll.items()}, unresolved




def sdl_version_defs():
    major, minor, micro = SDL_TAG.split("-")[1].split(".")
    return ["-DSDL_BUILD_MAJOR_VERSION=" + major, "-DSDL_BUILD_MINOR_VERSION=" + minor,
            "-DSDL_BUILD_MICRO_VERSION=" + micro]


def build_win32():
    od = WIN_DIR
    obj_dir = os.path.join(od, "obj")
    cfg_dir = os.path.join(od, "config")
    os.makedirs(obj_dir, exist_ok=True)
    os.makedirs(cfg_dir, exist_ok=True)
    open(os.path.join(cfg_dir, "SDL_build_config.h"), "w").write(WIN_CONFIG)
    logf = os.path.join(od, "build.log")
    open(logf, "w").close()
    cc = win32_cflags() + ["-I" + cfg_dir, "-I" + os.path.join(SDL_SRC, "include"),
                           "-I" + os.path.join(SDL_SRC, "include/build_config"), "-I" + os.path.join(SDL_SRC, "src"),
                           "-DDLL_EXPORT", "-D_WINDOWS"] + sdl_version_defs()
    open(os.path.join(cfg_dir, "hulk_sdl_glue.c"), "w").write(WIN_GLUE)
    srcs = win32_sources() + [os.path.join(cfg_dir, "hulk_sdl_glue.c")]
    jobs = []
    for s in srcs:
        rel = os.path.relpath(s, SDL_SRC) if s.startswith(SDL_SRC) else os.path.basename(s)
        o = os.path.join(obj_dir, os.path.splitext(rel.replace("/", "_"))[0] + ".obj")
        cmd = list(cc)
        if s.endswith(".cpp"):
            cmd[0] = os.path.join(LLVM, "clang++")
            cmd += ["-std=c++17", "-fno-exceptions", "-fno-rtti", "-fno-threadsafe-statics"]
        jobs.append((s, o, cmd + ["-c", s, "-o", o]))
    t0 = time.time()

    def one(j):
        s, o, cmd = j
        if os.path.exists(o) and os.path.getmtime(o) > os.path.getmtime(s) and \
                os.path.getmtime(o) > os.path.getmtime(os.path.join(cfg_dir, "SDL_build_config.h")):
            return s, 0, ""
        r = native_gfx.run(cmd, logf)
        return s, r.returncode, (r.stdout + r.stderr)[-3000:]
    failed = []
    with ThreadPoolExecutor(JOBS) as ex:
        for s, rc, err in ex.map(one, jobs):
            if rc:
                failed.append(s)
                log("FAILED %s\n%s" % (os.path.relpath(s, SDL_SRC), err))
    if failed:
        raise SystemExit("win32 SDL: %d of %d units failed (log %s)" % (len(failed), len(jobs), os.path.relpath(logf, ROOT)))
    objs = [j[1] for j in jobs]
    imp_dir = os.path.join(od, "imports")
    os.makedirs(imp_dir, exist_ok=True)
    libs, by_dll, unresolved = import_libs(objs, imp_dir, logf)
    # names no DLL exports: clang's helpers that an MSVC CRT provides as code (_chkstk alias, ...)
    if unresolved:
        log("win32 SDL: unresolved after the import libraries: %s" % " ".join(unresolved))
    dll = os.path.join(od, "SDL3.dll")
    implib = os.path.join(od, "SDL3.lib")
    cmd = [LLD_LINK, "/nologo", "/dll", "/machine:x86", "/nodefaultlib", "/opt:ref",
           "/entry:_DllMainCRTStartup", "/subsystem:windows", "/out:" + dll, "/implib:" + implib,
           "/map:" + os.path.join(od, "SDL3.map")] + objs + libs
    if unresolved:
        cmd.append("/force:unresolved")
    r = native_gfx.run(cmd, logf)
    if r.returncode:
        raise SystemExit("SDL3.dll link failed:\n" + (r.stdout + r.stderr)[-4000:])
    info = {"target": "win32", "tag": SDL_TAG, "seconds": round(time.time() - t0), "units": len(objs),
            "dll": os.path.relpath(dll, ROOT), "implib": os.path.relpath(implib, ROOT),
            "imports": {d: len(v) for d, v in by_dll.items()}, "unresolved": unresolved,
            "compile": " ".join(cc), "link": " ".join(cmd[:12])}
    json.dump(info, open(os.path.join(od, "build.json"), "w"), indent=1)
    log("win32: SDL3.dll %d KB, %d units, imports %s, unresolved %d, %d s" %
        (os.path.getsize(dll) >> 10, len(objs), info["imports"], len(unresolved), info["seconds"]))
    return info


# ---------------------------------------------------------------------------------------------
# our backends: src/platform/sdl/audio, src/platform/sdl/input and the xdk shim files that use them
BACKEND_SOURCES = ["audio/hulk_audio.cpp", "audio/xadpcm.cpp", "audio/reverb.cpp", "input/hulk_input.cpp"]
SHIM_SOURCES = ["xdk/audio_dsound.cpp", "xdk/audio_soundtracks.cpp", "xdk/input_xpp.cpp"]
HOST_FLAGS = ["/usr/bin/clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-std=c++17", "-O2", "-g",
              "-fno-exceptions", "-fno-rtti", "-Wall", "-Wextra", "-Wno-unused-parameter", "-Werror"]


# the image's own flags for src/platform/sdl/xdk (tools/native_host.py compile_dir) + the backend switch
SHIM_CXX = [os.path.join(LLVM, "clang++"), "--target=i686-pc-windows-msvc", "-fms-extensions", "-std=c++14", "-O1",
            "-mno-sse", "-mfpmath=387", "-fno-builtin", "-Werror", "-DHULK_NATIVE_SDL=1",
            # (native9: the drive's find-first in audio_soundtracks.cpp forwards to fs1's file_io.cpp in the image;
            # these tests link the audio/input stand-ins alone and keep its stand-in answer, "nothing there")
            "-DHULK_NATIVE_NO_FS=1"]


def win32_cxx():
    return [os.path.join(LLVM, "clang++"), "--target=i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility",
            "-std=c++17", "-O2", "-msse2", "-fno-exceptions", "-fno-rtti", "-fno-stack-protector",
            "-fno-threadsafe-statics", "-nostdinc++", "-fgnuc-version=4.2.1", "-D_X86_=1", "-D_WIN32_WINNT=0x0601",
            "-DWINVER=0x0601",
            "-D__MSVCRT_VERSION__=0x700", "-D__USE_MINGW_ANSI_STDIO=0", "-D_Scanf_format_string_impl_=", "-Wall",
            "-Wno-unused-parameter",
            "-Wno-pragma-pack", "-Wno-ignored-attributes", "-Werror"]


def sdl_inc(target):
    return ["-I" + os.path.join(HOST_DIR if target == "host" else SDL_SRC, "include")]


def compile_many(jobs, logf):
    def one(j):
        s, o, cmd = j
        r = native_gfx.run(cmd, logf)
        return s, r.returncode, (r.stdout + r.stderr)[-4000:]
    with ThreadPoolExecutor(JOBS) as ex:
        for s, rc, err in ex.map(one, jobs):
            if rc:
                raise SystemExit("%s failed:\n%s" % (os.path.relpath(s, ROOT), err))
    return [j[1] for j in jobs]


def backends(target="all"):
    res = {}
    if target in ("host", "all"):
        d = os.path.join(BK_DIR, "host")
        os.makedirs(os.path.join(d, "obj"), exist_ok=True)
        logf = os.path.join(d, "build.log")
        open(logf, "w").close()
        jobs = []
        for rel in BACKEND_SOURCES:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "obj", rel.replace("/", "_")[:-4] + ".o")
            jobs.append((s, o, HOST_FLAGS + sdl_inc("host") + ["-I" + PLAT, "-c", s, "-o", o]))
        objs = compile_many(jobs, logf)
        lib = os.path.join(d, "libhulk_sdl.a")
        if os.path.exists(lib):
            os.unlink(lib)
        native_gfx.run(["/usr/bin/ar", "rcs", lib] + objs, logf)
        res["host"] = lib
        log("backends host: %s" % os.path.relpath(lib, ROOT))
    if target in ("win32", "all"):
        d = os.path.join(BK_DIR, "win32")
        os.makedirs(os.path.join(d, "obj"), exist_ok=True)
        logf = os.path.join(d, "build.log")
        open(logf, "w").close()
        jobs = []
        for rel in BACKEND_SOURCES:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "obj", rel.replace("/", "_")[:-4] + ".obj")
            jobs.append((s, o, win32_cxx() + sdl_inc("win32") + mingw_inc() + ["-I" + PLAT, "-c", s, "-o", o]))
        objs = compile_many(jobs, logf)
        lib = os.path.join(d, "hulk_sdl.lib")
        if os.path.exists(lib):
            os.unlink(lib)
        r = native_gfx.run([os.path.join(LLVM, "llvm-lib"), "/nologo", "/out:" + lib] + objs, logf)
        if r.returncode:
            raise SystemExit("hulk_sdl.lib: " + r.stderr[-2000:])
        # the xdk stand-ins as tools/native_host.py compile_dir builds them for the image, plus HULK_NATIVE_SDL
        os.makedirs(os.path.join(d, "shim"), exist_ok=True)
        jobs = []
        for rel in SHIM_SOURCES:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "shim", os.path.basename(rel)[:-4] + ".obj")
            jobs.append((s, o, SHIM_CXX + ["-c", s, "-o", o]))
        shim = compile_many(jobs, logf)
        res["win32"] = lib
        res["shim"] = shim
        log("backends win32: %s (%d objects), xdk stand-ins %d objects" % (os.path.relpath(lib, ROOT), len(objs),
                                                                            len(shim)))
    return res


# ---------------------------------------------------------------------------------------------
# tests
HOST_LINK = ["-framework", "CoreAudio", "-framework", "AudioToolbox", "-framework", "CoreFoundation",
             "-framework", "IOKit", "-framework", "GameController", "-framework", "CoreHaptics",
             "-framework", "ForceFeedback", "-framework", "Foundation", "-framework", "AVFoundation",
             "-framework", "CoreMotion", "-framework", "Carbon", "-framework", "AppKit", "-framework", "Metal",
             "-framework", "QuartzCore", "-framework", "UniformTypeIdentifiers", "-framework", "CoreVideo",
             "-framework", "CoreMedia", "-liconv"]
TESTS = {"native_audio": "tests/native_audio/audio_test.cpp", "native_input": "tests/native_input/input_test.cpp"}


def test_host(only=None):
    lib = backends("host")["host"]
    d = os.path.join(BK_DIR, "host")
    logf = os.path.join(d, "test-build.log")
    open(logf, "w").close()
    rc_all = 0
    for name, rel in TESTS.items():
        if only and only != name:
            continue
        s = os.path.join(ROOT, rel)
        exe = os.path.join(d, name)
        r = native_gfx.run(HOST_FLAGS + sdl_inc("host") + ["-I" + PLAT, s, "-o", exe, lib,
                                                           os.path.join(HOST_DIR, "lib/libSDL3.a")] + HOST_LINK, logf)
        if r.returncode:
            raise SystemExit("%s build failed:\n%s" % (name, (r.stdout + r.stderr)[-4000:]))
        env = dict(os.environ, SDL_AUDIO_DRIVER="dummy", HULK_TEST_OUT=os.path.join(d, name + "-out"))
        os.makedirs(env["HULK_TEST_OUT"], exist_ok=True)
        p = subprocess.run([exe], capture_output=True, text=True, timeout=300, env=env)
        sys.stdout.write(p.stdout)
        sys.stderr.write(p.stderr[-4000:])
        log("%s: exit %d" % (name, p.returncode))
        rc_all |= p.returncode
    return rc_all


def test_wine(only=None):
    """The tests again, i686 under Wine: tests/*/ compiled with HULK_TEST_XDK=1 call the XDK-shaped stand-ins
    (hulk_xdk_*) with 32-bit handles and pointers, as the game image does, against SDL3.dll."""
    built = backends("win32")
    lib = built["win32"]
    d = os.path.join(BK_DIR, "win32")
    logf = os.path.join(d, "test-build.log")
    open(logf, "w").close()
    imp_dir = os.path.join(d, "imports")
    os.makedirs(imp_dir, exist_ok=True)
    # the shim's trace hooks live in src/platform/sdl/xdk/trace.cpp (native9's): the tests link a copy-free
    # stand-in of the two entry points instead (tests/native_audio/xdk_trace_stub.cpp)
    rc_all = 0
    for name, rel in TESTS.items():
        if only and only != name:
            continue
        s = os.path.join(ROOT, rel)
        o = os.path.join(d, name + ".obj")
        stub = os.path.join(ROOT, "tests/native_audio/test_runtime_win32.cpp")
        so = os.path.join(d, name + "-rt.obj")
        for src, obj in ((s, o), (stub, so)):
            r = native_gfx.run(win32_cxx() + sdl_inc("win32") + mingw_inc() + ["-I" + PLAT, "-DHULK_TEST_XDK=1",
                                                                              "-c", src, "-o", obj], logf)
            if r.returncode:
                raise SystemExit("%s build failed:\n%s" % (os.path.relpath(src, ROOT), (r.stdout + r.stderr)[-4000:]))
        lib_objs = [os.path.join(d, "obj", rel.replace("/", "_")[:-4] + ".obj") for rel in BACKEND_SOURCES]
        libs, _by, unresolved = import_libs([o, so] + built["shim"] + lib_objs, imp_dir, logf,
                                            extra_defined=_sdl_exports())
        exe = os.path.join(d, name + ".exe")
        cmd = [LLD_LINK, "/nologo", "/machine:x86", "/subsystem:console",
               "/entry:hulk_test_entry", "/nodefaultlib", "/out:" + exe, o, so] + built["shim"] + [lib,
               os.path.join(WIN_DIR, "SDL3.lib")] + libs
        r = native_gfx.run(cmd, logf)
        if r.returncode:
            raise SystemExit("%s link failed:\n%s" % (name, (r.stdout + r.stderr)[-4000:]))
        shutil.copy2(os.path.join(WIN_DIR, "SDL3.dll"), os.path.join(d, "SDL3.dll"))
        out = os.path.join(d, name + "-out")
        os.makedirs(out, exist_ok=True)
        prefix = os.path.join(ROOT, "build/native/wineprefix")
        env = native_gfx_wine_env(prefix)
        env.update(SDL_AUDIO_DRIVER="dummy", HULK_TEST_OUT="Z:" + out.replace("/", "\\"))
        p = subprocess.run([native_gfx.WINE, exe], capture_output=True, text=True, timeout=600, env=env, cwd=d)
        sys.stdout.write(p.stdout)
        sys.stderr.write(p.stderr[-3000:])
        log("%s (wine): exit %d" % (name, p.returncode))
        rc_all |= p.returncode
    return rc_all


def native_gfx_wine_env(prefix):
    env = dict(os.environ, WINEPREFIX=prefix, WINEDEBUG=os.environ.get("WINEDEBUG", "-all"),
               WINEDLLOVERRIDES="mscoree,mshtml=")
    return env


def _sdl_exports():
    """Names SDL3.lib provides (so import_libs doesn't look for them in Win32 DLLs)."""
    r = subprocess.run([os.path.join(LLVM, "llvm-nm"), os.path.join(WIN_DIR, "SDL3.lib")], capture_output=True, text=True)
    return {l.split()[-1] for l in r.stdout.splitlines() if len(l.split()) >= 2 and l.split()[-2] in ("T", "D", "I")}


def status():
    p = os.path.join(DL, "SDL-%s.tar.gz" % SDL_TAG)
    print("SDL %s tarball %s unpacked %s" % (SDL_TAG, "yes" if os.path.exists(p) else "no",
                                           "yes" if os.path.exists(os.path.join(SDL_SRC, ".pinned")) else "no"))
    for d in (HOST_DIR, WIN_DIR):
        bj = os.path.join(d, "build.json")
        print("%-10s %s" % (os.path.basename(d), json.load(open(bj)) if os.path.exists(bj) else "not built"))


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    f = sub.add_parser("fetch")
    f.add_argument("--force", action="store_true")
    b = sub.add_parser("build")
    b.add_argument("--target", choices=("host", "win32", "all"), default="all")
    k = sub.add_parser("backends")
    k.add_argument("--target", choices=("host", "win32", "all"), default="all")
    t = sub.add_parser("test")
    t.add_argument("--only", choices=sorted(TESTS))
    w = sub.add_parser("wine-test")
    w.add_argument("--only", choices=sorted(TESTS))
    sub.add_parser("status")
    a = ap.parse_args(argv)
    if a.cmd == "fetch":
        fetch(a.force)
    elif a.cmd == "build":
        fetch()
        if a.target in ("host", "all"):
            build_host()
        if a.target in ("win32", "all"):
            build_win32()
    elif a.cmd == "backends":
        backends(a.target)
    elif a.cmd == "test":
        return test_host(a.only)
    elif a.cmd == "wine-test":
        return test_wine(a.only)
    elif a.cmd == "status":
        status()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
