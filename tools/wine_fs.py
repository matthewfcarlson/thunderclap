#!/usr/bin/env python3
"""Files and saves for the native image (docs/wine-files-saves.md): builds src/platform/sdl/fs (the SDL3 file and
save backend) and the xdk stand-ins that use it (file_io.cpp, saves.cpp with -DHULK_NATIVE_SDL=1), and runs
tests/native_fs on the host and as i686 under Wine. Reuses tools/wine_sdl.py's pinned SDL3 builds.

  build/venv/bin/python tools/wine_fs.py backends [--target host|win32|all]
  build/venv/bin/python tools/wine_fs.py test          # host: typed API
  build/venv/bin/python tools/wine_fs.py wine-test     # i686 under Wine: through the hulk_xdk_* stand-ins

Output: build/third_party/out/fs1/{host,win32}/ (hulk_fs.lib + shim objects for the native link).
"""
import argparse
import os
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import wine_sdl as S  # noqa: E402

ROOT = S.ROOT
PLAT = S.PLAT
OUT = os.path.join(S.OUT, "fs1")
FS_SOURCES = ["fs/hulk_fs.cpp", "fs/hulk_saves.cpp"]
SHIM = ["xdk/file_io.cpp", "xdk/saves.cpp"]
TEST = "tests/native_fs/fs_test.cpp"
RT = "tests/native_fs/test_runtime_win32.cpp"


def backends(target):
    res = {}
    if target in ("host", "all"):
        d = os.path.join(OUT, "host")
        os.makedirs(os.path.join(d, "obj"), exist_ok=True)
        logf = os.path.join(d, "build.log")
        open(logf, "w").close()
        jobs = []
        for rel in FS_SOURCES:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "obj", os.path.basename(rel)[:-4] + ".o")
            jobs.append((s, o, S.HOST_FLAGS + S.sdl_inc("host") + ["-I" + PLAT, "-c", s, "-o", o]))
        objs = S.compile_many(jobs, logf)
        lib = os.path.join(d, "libhulk_fs.a")
        if os.path.exists(lib):
            os.unlink(lib)
        S.wine_gfx.run(["/usr/bin/ar", "rcs", lib] + objs, logf)
        res["host"] = lib
        S.log("fs host: %s" % os.path.relpath(lib, ROOT))
    if target in ("win32", "all"):
        d = os.path.join(OUT, "win32")
        os.makedirs(os.path.join(d, "obj"), exist_ok=True)
        os.makedirs(os.path.join(d, "shim"), exist_ok=True)
        logf = os.path.join(d, "build.log")
        open(logf, "w").close()
        jobs = []
        for rel in FS_SOURCES:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "obj", os.path.basename(rel)[:-4] + ".obj")
            jobs.append((s, o, S.win32_cxx() + S.sdl_inc("win32") + S.mingw_inc() + ["-I" + PLAT, "-c", s, "-o", o]))
        objs = S.compile_many(jobs, logf)
        lib = os.path.join(d, "hulk_fs.lib")
        if os.path.exists(lib):
            os.unlink(lib)
        r = S.wine_gfx.run([os.path.join(S.LLVM, "llvm-lib"), "/nologo", "/out:" + lib] + objs, logf)
        if r.returncode:
            raise SystemExit("hulk_fs.lib: " + r.stderr[-2000:])
        jobs = []
        for rel in SHIM:
            s = os.path.join(PLAT, rel)
            o = os.path.join(d, "shim", os.path.basename(rel)[:-4] + ".obj")
            jobs.append((s, o, S.SHIM_CXX + ["-c", s, "-o", o]))
        shim = S.compile_many(jobs, logf)
        res.update(win32=lib, shim=shim, objs=objs)
        S.log("fs win32: %s, xdk stand-ins %d objects" % (os.path.relpath(lib, ROOT), len(shim)))
    return res


def test_host():
    lib = backends("host")["host"]
    d = os.path.join(OUT, "host")
    logf = os.path.join(d, "test-build.log")
    open(logf, "w").close()
    exe = os.path.join(d, "wine_fs")
    r = S.wine_gfx.run(S.HOST_FLAGS + S.sdl_inc("host") + ["-I" + PLAT, os.path.join(ROOT, TEST), "-o", exe, lib,
                                                              os.path.join(S.HOST_DIR, "lib/libSDL3.a")] + S.HOST_LINK, logf)
    if r.returncode:
        raise SystemExit("wine_fs build failed:\n%s" % (r.stdout + r.stderr)[-4000:])
    out = os.path.join(d, "wine_fs-out")
    os.makedirs(out, exist_ok=True)
    p = subprocess.run([exe], capture_output=True, text=True, timeout=600, env=dict(os.environ, HULK_TEST_OUT=out))
    sys.stdout.write(p.stdout)
    sys.stderr.write(p.stderr[-4000:])
    S.log("wine_fs: exit %d" % p.returncode)
    return p.returncode


def test_wine():
    built = backends("win32")
    d = os.path.join(OUT, "win32")
    logf = os.path.join(d, "test-build.log")
    open(logf, "w").close()
    imp_dir = os.path.join(d, "imports")
    os.makedirs(imp_dir, exist_ok=True)
    objs = []
    for src, name in ((TEST, "wine_fs.obj"), (RT, "wine_fs-rt.obj")):
        o = os.path.join(d, name)
        r = S.wine_gfx.run(S.win32_cxx() + S.sdl_inc("win32") + S.mingw_inc() + ["-I" + PLAT, "-DHULK_TEST_XDK=1", "-c",
                                                                                  os.path.join(ROOT, src), "-o", o], logf)
        if r.returncode:
            raise SystemExit("%s build failed:\n%s" % (src, (r.stdout + r.stderr)[-4000:]))
        objs.append(o)
    libs, _by, _un = S.import_libs(objs + built["shim"] + built["objs"], imp_dir, logf, extra_defined=S._sdl_exports())
    exe = os.path.join(d, "wine_fs.exe")
    cmd = [S.LLD_LINK, "/nologo", "/machine:x86", "/subsystem:console", "/entry:hulk_test_entry", "/nodefaultlib",
           "/out:" + exe] + objs + built["shim"] + [built["win32"], os.path.join(S.WIN_DIR, "SDL3.lib")] + libs
    r = S.wine_gfx.run(cmd, logf)
    if r.returncode:
        raise SystemExit("wine_fs link failed:\n%s" % (r.stdout + r.stderr)[-4000:])
    shutil.copy2(os.path.join(S.WIN_DIR, "SDL3.dll"), os.path.join(d, "SDL3.dll"))
    out = os.path.join(d, "wine_fs-out")
    os.makedirs(out, exist_ok=True)
    env = S.native_gfx_wine_env(os.path.join(ROOT, "build/native/wineprefix"))
    env.update(HULK_TEST_OUT="Z:" + out.replace("/", "\\"))
    p = subprocess.run([S.wine_gfx.WINE, exe], capture_output=True, text=True, timeout=900, env=env, cwd=d)
    sys.stdout.write(p.stdout)
    sys.stderr.write(p.stderr[-3000:])
    S.log("wine_fs (wine): exit %d" % p.returncode)
    return p.returncode


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("backends")
    b.add_argument("--target", choices=("host", "win32", "all"), default="all")
    sub.add_parser("test")
    sub.add_parser("wine-test")
    a = ap.parse_args(argv)
    if a.cmd == "backends":
        backends(a.target)
    elif a.cmd == "test":
        return test_host()
    else:
        return test_wine()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
