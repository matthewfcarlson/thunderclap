#!/usr/bin/env python3
"""Run the native image under Wine and summarize its start-up trace (docs/native-build.md "Start-up").

  build/venv/bin/python tools/native_run.py                    # build/native/link/hulk-strict.exe, 120 s timeout
  build/venv/bin/python tools/native_run.py --timeout 30 --exe build/native/link/hulk-strict.exe
  build/venv/bin/python tools/native_run.py --hello            # only check that Wine runs a trivial i686 PE

Wine: Whisky's Wine (WINE env var to override), always in our own prefix, build/native/wineprefix (WINEPREFIX is
set by this tool; the user's bottles are never touched). Graphics: HULK_GFX_RENDERER defaults to vulkan here (Whisky's
MoltenVK, found through DYLD_FALLBACK_LIBRARY_PATH); HULK_GFX_* options in src/platform/sdl/pddi/win32_platform.cpp. The image reads the extracted game files from
isos/extracted (HULK_DATA_DIR) and writes saves under build/native/run/save (HULK_SAVE_DIR) and title storage
(`T:\\`) under build/native/tdata (HULK_TDATA_DIR).

Outputs (build/native/run/, not tracked): trace.txt (the image's own trace: src/platform/sdl/xdk/startup.cpp),
stdout.txt / stderr.txt (Wine's), summary.json and summary.txt: the trace with every code address turned into the
symbol of the linked image that contains it (the lld-link map) and, for tree functions, the XBE address in its
name or the binding map's definition table.
"""
import argparse
import bisect
import json
import os
import re
import subprocess
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUT_DEFAULT = os.environ.get("HULK_NATIVE_DIR") or os.path.join(ROOT, "build/native")
WINE = os.environ.get("WINE") or os.path.expanduser(
    "~/Library/Application Support/com.isaacmarovitz.Whisky/Libraries/Wine/bin/wine64")
LLVM = "/opt/homebrew/opt/llvm/bin"


def wine_env(prefix):
    env = dict(os.environ, WINEPREFIX=prefix, WINEDEBUG=os.environ.get("WINEDEBUG", "-all"),
               WINEDLLOVERRIDES="mscoree,mshtml=")
    # the graphics backend (docs/graphics-backend.md G1): under Whisky's Wine the image draws through bgfx's Vulkan
    # renderer on Whisky's own MoltenVK (D3D11 presents, but Wine 7.7's d3dcompiler can't build the shaders);
    # Wine's winevulkan finds libMoltenVK.dylib through the dynamic loader's fallback path
    env.setdefault("HULK_GFX_RENDERER", "vulkan")
    # sa1's SDL3 audio backend: muted by default in agent runs (the mixer still runs on SDL's dummy device)
    env.setdefault("SDL_AUDIO_DRIVER", "dummy")
    lib = os.path.join(os.path.dirname(os.path.dirname(WINE)), "lib")
    if os.path.exists(os.path.join(lib, "libMoltenVK.dylib")) and "DYLD_FALLBACK_LIBRARY_PATH" not in env:
        env["DYLD_FALLBACK_LIBRARY_PATH"] = lib + ":/usr/lib"
    return env


def to_wine_path(p):
    return "Z:" + os.path.abspath(p).replace("/", "\\")


def kill_wineserver(prefix):
    ws = os.path.join(os.path.dirname(WINE), "wineserver")
    if os.path.exists(ws):
        subprocess.run([ws, "-k"], env=wine_env(prefix), capture_output=True)


def run(exe, prefix, timeout, env_extra, rundir):
    os.makedirs(rundir, exist_ok=True)
    env = wine_env(prefix)
    env.update(env_extra)
    t0 = time.time()
    with open(os.path.join(rundir, "stdout.txt"), "wb") as so, open(os.path.join(rundir, "stderr.txt"), "wb") as se:
        p = subprocess.Popen([WINE, os.path.abspath(exe)], env=env, stdout=so, stderr=se, cwd=rundir)
        try:
            rc = p.wait(timeout=timeout)
            timed_out = False
        except subprocess.TimeoutExpired:
            p.kill()
            rc, timed_out = None, True
    if timed_out:
        kill_wineserver(prefix)
    return {"rc": rc, "timed_out": timed_out, "seconds": round(time.time() - t0, 1)}


def hello(prefix, rundir):
    """Build and run a trivial i686 PE with the image's toolchain (clang, lld-link, an msvcrt import library)."""
    d = os.path.join(rundir, "hello")
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "msvcrt.def"), "w") as f:
        f.write("LIBRARY msvcrt.dll\nEXPORTS\nhulk_host_printf == printf\n")
    with open(os.path.join(d, "hello.c"), "w") as f:
        f.write('int hulk_host_printf(const char*, ...);\n'
                'int __cdecl hello_entry(void) { hulk_host_printf("hello from i686 %d\\n", 42); return 7; }\n')
    subprocess.run([os.path.join(LLVM, "llvm-dlltool"), "-m", "i386", "-d", os.path.join(d, "msvcrt.def"), "-l",
                    os.path.join(d, "msvcrt.lib")], check=True)
    subprocess.run([os.path.join(LLVM, "clang"), "--target=i686-pc-windows-msvc", "-O1", "-c", os.path.join(d, "hello.c"),
                    "-o", os.path.join(d, "hello.obj")], check=True)
    lld = os.path.join(LLVM, "lld-link") if os.path.exists(os.path.join(LLVM, "lld-link")) else "lld-link"
    subprocess.run([lld, "/nologo", "/machine:x86", "/subsystem:console", "/entry:hello_entry", "/nodefaultlib",
                    os.path.join(d, "hello.obj"), os.path.join(d, "msvcrt.lib"), "/out:" + os.path.join(d, "hello.exe")],
                   check=True)
    r = run(os.path.join(d, "hello.exe"), prefix, 120, {}, d)
    r["stdout"] = open(os.path.join(d, "stdout.txt"), errors="replace").read()
    return r


# ---------------------------------------------------------------------------------------------
def read_map(path):
    """[(address, symbol)] sorted, from an lld-link /map file (code and data symbols)."""
    out = []
    if not os.path.exists(path):
        return out
    # lld-link writes MSVC's format: ` 0001:00000080       <symbol>   0000000000401080     <object>`
    rx = re.compile(r"^\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8,16})(?:\s+f)?\s+(\S+)?\s*$")
    for line in open(path, errors="replace"):
        m = rx.match(line)
        if m:
            out.append((int(m.group(2), 16), m.group(1)))
    out.sort()
    return out


class Symbolizer:
    def __init__(self, map_path, bindings_path):
        self.syms = read_map(map_path)
        self.addrs = [a for a, _ in self.syms]
        self.xbe_of = {}
        if os.path.exists(bindings_path):
            for a, s in json.load(open(bindings_path)).get("definitions", {}).items():
                self.xbe_of.setdefault(s, a)

    def __call__(self, a):
        i = bisect.bisect_right(self.addrs, a) - 1
        if i < 0:
            return "0x%08x" % a
        s = self.syms[i][1]
        x = self.xbe_of.get(s)
        if x is None:
            m = re.search(r"(?:FUN|thunk_FUN)_(00[0-9a-f]{6})", s)
            x = "0x" + m.group(1) if m else None
        return "%s+0x%x%s" % (s, a - self.syms[i][0], " [xbe %s]" % x if x else "")


def summarize(trace_path, sym):
    lines = open(trace_path, errors="replace").read().splitlines() if os.path.exists(trace_path) else []
    firsts, end, crash, missing, frames, inits = [], None, None, None, [], 0
    out = []
    for l in lines:
        nice = re.sub(r"(?<=[=\s])0x([0-9a-f]{8})\b",
                      lambda m: "0x%s (%s)" % (m.group(1), sym(int(m.group(1), 16))) if int(m.group(1), 16) >= 0x400000
                      and not l.startswith(("init ", "skip ")) else m.group(0), l)
        out.append(nice)
        if l.startswith("first "):
            firsts.append(l.split()[2])
        elif l.startswith("init "):
            inits += 1
        elif l.startswith("end "):
            end = l
        elif l.startswith("crash "):
            crash = nice
        elif l.startswith("missing "):
            missing = nice
        elif l.startswith(("frame ", "scan ")):
            frames.append(nice)
    return {"lines": len(lines), "initializers_run": inits, "first_calls": firsts, "end": end, "crash": crash,
            "missing": missing, "frames": frames[:36]}, out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=OUT_DEFAULT, help="the native_link output directory (default build/native)")
    ap.add_argument("--exe", help="the image (default <out>/link/hulk-strict.exe)")
    ap.add_argument("--timeout", type=float, default=120)
    ap.add_argument("--hello", action="store_true")
    a = ap.parse_args(argv)
    prefix = os.path.join(ROOT, "build/native/wineprefix")
    a.out = os.path.abspath(a.out)
    rundir = os.path.join(a.out, "run")
    if not os.path.exists(WINE):
        print("Wine not found at %s" % WINE)
        return 2
    if a.hello:
        r = hello(prefix, rundir)
        print(json.dumps(r, indent=1))
        return 0 if r["rc"] == 7 else 1
    exe = a.exe or os.path.join(a.out, "link", "hulk-strict.exe")
    # the DLLs the backends load, next to the image (Wine's loader finds them there): SDL3 (sa1), and the movie
    # decoder (mv1: hulkmovie.dll + FFmpeg's, loaded when the first movie opens; without them movies are skipped)
    out3 = os.environ.get("HULK_SDL_OUT") or os.path.join(ROOT, "build/third_party/out")
    for dll in ("sdl-win32/SDL3.dll", "ffmpeg-win32/movies/hulkmovie.dll", "ffmpeg-win32/dll/avutil-60.dll",
                "ffmpeg-win32/dll/avcodec-62.dll", "ffmpeg-win32/dll/avformat-62.dll"):
        if os.path.exists(os.path.join(out3, dll)):
            import shutil
            shutil.copy2(os.path.join(out3, dll), os.path.join(os.path.dirname(os.path.abspath(exe)), os.path.basename(dll)))
    trace = os.path.join(rundir, "trace.txt")
    if os.path.exists(trace):
        os.remove(trace)
    os.makedirs(os.path.join(rundir, "save"), exist_ok=True)
    os.makedirs(os.path.join(a.out, "tdata"), exist_ok=True)     # T:\ (title storage), kept between runs
    env = {"HULK_TRACE_FILE": to_wine_path(trace), "HULK_DATA_DIR": to_wine_path(os.path.join(ROOT, "isos/extracted")),
           "HULK_SAVE_DIR": to_wine_path(os.path.join(rundir, "save")),
           "HULK_TDATA_DIR": to_wine_path(os.path.join(a.out, "tdata"))}
    r = run(exe, prefix, a.timeout, env, rundir)
    sym = Symbolizer(os.path.splitext(exe)[0] + ".map", os.path.join(a.out, "bindings.json"))
    s, nice = summarize(trace, sym)
    s.update(r)
    with open(os.path.join(rundir, "summary.txt"), "w") as f:
        f.write("\n".join(nice) + "\n")
    with open(os.path.join(rundir, "summary.json"), "w") as f:
        json.dump(s, f, indent=1)
    print(json.dumps({k: v for k, v in s.items() if k != "first_calls"}, indent=1))
    print("first calls (%d): %s" % (len(s["first_calls"]), " ".join(s["first_calls"])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
