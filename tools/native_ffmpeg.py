#!/usr/bin/env python3
"""FFmpeg's Bink decoder for the native movie player (docs/native-movies.md): a pinned fetch and minimal shared build
of upstream FFmpeg, our movie decoder and Bink-shaped player on it, and their tests against the ffmpeg command line.

  build/venv/bin/python tools/native_ffmpeg.py fetch              # download the pinned tarball, check sha256, unpack
  build/venv/bin/python tools/native_ffmpeg.py build              # shared libraries for the host (macOS arm64)
  build/venv/bin/python tools/native_ffmpeg.py build --target win32   # DLLs for i686 Windows (Wine)
  build/venv/bin/python tools/native_ffmpeg.py refs               # the independent decode (ffmpeg CLI) of the test movies
  build/venv/bin/python tools/native_ffmpeg.py test               # host test: tests/native_movies
  build/venv/bin/python tools/native_ffmpeg.py wine-test          # the same through the xdk stand-ins, i686 under Wine
  build/venv/bin/python tools/native_ffmpeg.py movies             # i686: the player objects, hulkmovie.dll + import library
  build/venv/bin/python tools/native_ffmpeg.py inventory          # every shipped movie decoded whole, against the ffmpeg CLI
  build/venv/bin/python tools/native_ffmpeg.py status

Everything goes under build/third_party/ (ignored by git); nothing is installed system-wide, and no game data is
copied anywhere that git sees: the tests read the movies in place from the extracted archives (isos/extracted/) and
write the reference decode under build/third_party/out/movies/.

FFmpeg is LGPL 2.1+ and used as shared libraries only (never linked statically into the game image):
  ./configure --disable-everything --enable-shared --disable-static --disable-programs --disable-doc
              --disable-avdevice --disable-avfilter --disable-swscale --disable-swresample --disable-network
              --disable-autodetect --enable-decoder=bink,binkaudio_dct,binkaudio_rdft --enable-demuxer=bink
No GPL or nonfree component is enabled (configure prints `License: LGPL version 2.1 or later`). The notice to ship
with a binary that carries these libraries is written to build/third_party/out/LICENSES-FFMPEG.txt.
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

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import native_gfx  # noqa: E402
import native_sdl  # noqa: E402

TP = native_gfx.TP
DL = native_gfx.DL
SRC = native_gfx.SRC
OUT = native_gfx.OUT
LLVM = native_gfx.LLVM
PLAT = os.path.join(ROOT, "src/platform/sdl")
FF_SRC = os.path.join(SRC, "ffmpeg")
HOST_DIR = os.path.join(OUT, "ffmpeg-host")
WIN_DIR = os.path.join(OUT, "ffmpeg-win32")
MOV_DIR = os.path.join(OUT, "movies")
JOBS = 3

# Pinned upstream FFmpeg (the n8.0 release tag; codeload's tar.gz)
FF_TAG = "n8.0"
FF_SHA256 = "dd4030dbfdc34d9ff255a116bdd1caade42500ac2981efa27f8b151cc54c7b9e"
FF_URL = "https://codeload.github.com/FFmpeg/FFmpeg/tar.gz/refs/tags/" + FF_TAG

FF_CONFIGURE = ["--disable-everything", "--disable-autodetect", "--disable-programs", "--disable-doc",
                "--disable-avdevice", "--disable-avfilter", "--disable-swscale", "--disable-swresample",
                "--disable-network", "--disable-debug", "--disable-iconv", "--disable-zlib", "--disable-bzlib",
                "--disable-lzma", "--enable-decoder=bink,binkaudio_dct,binkaudio_rdft", "--enable-demuxer=bink",
                "--enable-protocol=file"]

# the movies the tests use: (archive, name) -> stem; extracted with their offsets from the archives' directories
TEST_MOVIES = {"m": ("movies1.rcf", "movies\\1A_anim.rmv"),     # six mono tracks (5.1), 640 x 336
               "s": ("mog_mov1.rcf", "movies\\mog1.rmv"),      # one stereo track, 640 x 480
               "d": ("movies2.rcf", "movies\\dolby.rmv")}      # six mono tracks, 4 s: played whole, all six routed


def log(*a):
    print(*a, file=sys.stderr, flush=True)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def fetch(force=False):
    os.makedirs(DL, exist_ok=True)
    path = os.path.join(DL, "FFmpeg-%s.tar.gz" % FF_TAG)
    if not os.path.exists(path) or force:
        log("download FFmpeg %s" % FF_TAG)
        tmp = path + ".part"
        with urllib.request.urlopen(FF_URL, timeout=600) as r, open(tmp, "wb") as f:
            shutil.copyfileobj(r, f)
        os.replace(tmp, path)
    got = sha256(path)
    if got != FF_SHA256:
        raise SystemExit("%s: sha256 %s, pinned %s (GitHub regenerated the archive, or it was tampered with): check "
                         "the tag and update FF_SHA256" % (os.path.relpath(path, ROOT), got, FF_SHA256))
    stamp = os.path.join(FF_SRC, ".pinned")
    tag = "%s %s" % (FF_TAG, FF_SHA256)
    if os.path.exists(stamp) and open(stamp).read().strip() == tag and not force:
        return
    if os.path.exists(FF_SRC):
        shutil.rmtree(FF_SRC)
    os.makedirs(FF_SRC)
    with tarfile.open(path) as t:
        for m in t.getmembers():
            parts = m.name.split("/", 1)
            if len(parts) < 2 or not parts[1]:
                continue
            m.name = parts[1]
            t.extract(m, FF_SRC, filter="data")
    open(stamp, "w").write(tag + "\n")
    log("unpacked FFmpeg %s" % FF_TAG)


def write_license_notice():
    p = os.path.join(OUT, "LICENSES-FFMPEG.txt")
    text = """FFmpeg (https://ffmpeg.org), release %s: libavformat, libavcodec and libavutil.
Licensed under the GNU Lesser General Public License, version 2.1 or later. Used as shared libraries only,
configured with the Bink video / audio decoders and the Bink demuxer (no GPL or nonfree components):
%s
The full source is the upstream tarball %s (sha256 %s).
The libraries may be replaced with another build of the same FFmpeg ABI (the game loads them by name).
""" % (FF_TAG, " ".join(FF_CONFIGURE), FF_URL, FF_SHA256)
    os.makedirs(OUT, exist_ok=True)
    open(p, "w").write(text)
    lic = os.path.join(FF_SRC, "COPYING.LGPLv2.1")
    if os.path.exists(lic):
        shutil.copy2(lic, os.path.join(OUT, "COPYING.LGPLv2.1-FFMPEG"))


# ---------------------------------------------------------------------------------------------
# host build: FFmpeg's own configure + make
def build_host():
    fetch()
    od = os.path.join(HOST_DIR, "obj")
    prefix = os.path.join(HOST_DIR, "install")
    os.makedirs(od, exist_ok=True)
    logf = os.path.join(HOST_DIR, "build.log")
    t0 = time.time()
    cfg = [os.path.join(FF_SRC, "configure"), "--prefix=" + prefix, "--cc=/usr/bin/clang", "--enable-shared",
           "--disable-static", "--install-name-dir=" + os.path.join(prefix, "lib")] + FF_CONFIGURE
    with open(logf, "w") as f:
        for cmd in (cfg, ["make", "-j", str(JOBS)], ["make", "install"]):
            f.write("$ " + " ".join(cmd) + "\n")
            f.flush()
            r = subprocess.run(cmd, cwd=od, stdout=f, stderr=subprocess.STDOUT)
            if r.returncode:
                raise SystemExit("host FFmpeg build failed at %s (log %s)" % (cmd[0], os.path.relpath(logf, ROOT)))
    lic = [l for l in open(logf) if l.startswith("License:")]
    json.dump({"target": "host", "tag": FF_TAG, "configure": " ".join(cfg), "license": lic[0].strip() if lic else "?"},
              open(os.path.join(HOST_DIR, "build.json"), "w"), indent=1)
    write_license_notice()
    log("host: FFmpeg %s in %d s (%s)" % (FF_TAG, time.time() - t0, lic[0].strip() if lic else "?"))


# ---------------------------------------------------------------------------------------------
# the movies: reference decode from the ffmpeg command line
def rcf_entries(archive):
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/rcf.py"), "list",
                        os.path.join(ROOT, "isos/extracted", archive)], capture_output=True, text=True, check=True)
    out = {}
    for line in r.stdout.splitlines():
        m = re.match(r"^\s*([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\d+)\s+(.+)$", line)
        if m:
            out[m.group(4)] = (int(m.group(2), 16), int(m.group(3)))
    return out


def movie_spec(stem):
    archive, name = TEST_MOVIES[stem]
    off, size = rcf_entries(archive)[name]
    return "%s|%d|%d" % (os.path.join(ROOT, "isos/extracted", archive), off, size)


def ffmpeg_cli():
    p = shutil.which("ffmpeg")
    if not p:
        raise SystemExit("the ffmpeg command line is needed for the reference decode (brew install ffmpeg)")
    return p


def refs(frames):
    ff = ffmpeg_cli()
    os.makedirs(MOV_DIR, exist_ok=True)
    seconds = frames / 29.97 + 3
    for stem in TEST_MOVIES:
        path, off, size = movie_spec(stem).split("|")
        cut = os.path.join(MOV_DIR, stem + ".bik")
        with open(path, "rb") as f, open(cut, "wb") as g:
            f.seek(int(off))
            g.write(f.read(int(size)))
        for out, args in (("%s.yuv" % stem, ["-frames:v", str(frames), "-fps_mode", "passthrough", "-pix_fmt",
                                             "yuv420p", "-f", "rawvideo"]),
                          ("%s.bgra" % stem, ["-frames:v", str(frames), "-fps_mode", "passthrough", "-pix_fmt",
                                              "bgra", "-f", "rawvideo"]),
                          ("%s.f32" % stem, ["-map", "0:a:0", "-t", "%.3f" % seconds, "-f", "f32le"])):
            dst = os.path.join(MOV_DIR, out)
            if args[0] == "-map":
                cmd = [ff, "-v", "error", "-y", "-i", cut] + args + [dst]
            else:
                cmd = [ff, "-v", "error", "-y", "-i", cut, "-an"] + args + [dst]
            r = subprocess.run(cmd, capture_output=True, text=True)
            if r.returncode:
                raise SystemExit("ffmpeg %s: %s" % (out, r.stderr[-1000:]))
        if stem == "d":     # every track of the short one (the 5.1 routing test)
            for i in range(1, 6):
                subprocess.run([ff, "-v", "error", "-y", "-i", cut, "-map", "0:a:%d" % i, "-f", "f32le",
                                os.path.join(MOV_DIR, "d%d.f32" % i)], check=True)
        os.unlink(cut)
        log("reference %s: %s" % (stem, ", ".join("%s %d KB" % (n, os.path.getsize(os.path.join(MOV_DIR, n)) >> 10)
                                                 for n in sorted(os.listdir(MOV_DIR)) if n.startswith(stem + "."))))


# ---------------------------------------------------------------------------------------------
# host: our movie sources + the audio backend + the test
MOVIE_C = ["movies/movie.c"]
MOVIE_CPP = ["movies/bink_player.cpp"]


def host_inc():
    return ["-I" + os.path.join(HOST_DIR, "install/include")]


def host_ffmpeg_libs():
    lib = os.path.join(HOST_DIR, "install/lib")
    return ["-L" + lib, "-Wl,-rpath," + lib, "-lavformat", "-lavcodec", "-lavutil"]


def test_host(frames):
    if not os.path.exists(os.path.join(HOST_DIR, "install/lib")):
        build_host()
    lib = native_sdl.backends("host")["host"]
    d = os.path.join(HOST_DIR, "test")
    os.makedirs(d, exist_ok=True)
    logf = os.path.join(d, "build.log")
    open(logf, "w").close()
    objs = []
    for rel in MOVIE_C:
        o = os.path.join(d, os.path.basename(rel)[:-2] + ".o")
        r = native_gfx.run(["/usr/bin/clang", "-arch", "arm64", "-mmacosx-version-min=11.0", "-O2", "-g", "-Wall",
                            "-Wextra", "-Wno-unused-parameter", "-Werror"] + host_inc() + ["-c", os.path.join(PLAT, rel),
                                                                                         "-o", o], logf)
        if r.returncode:
            raise SystemExit("%s:\n%s" % (rel, (r.stdout + r.stderr)[-4000:]))
        objs.append(o)
    exe = os.path.join(d, "movies_test")
    src = [os.path.join(PLAT, rel) for rel in MOVIE_CPP] + [os.path.join(ROOT, "tests/native_movies/movies_test.cpp")]
    r = native_gfx.run(native_sdl.HOST_FLAGS + native_sdl.sdl_inc("host") + ["-DHULK_MOVIE_STATIC=1", "-I" + PLAT, "-I" + os.path.join(ROOT, "tests/native_audio")] +
                       src + objs + ["-o", exe, lib, os.path.join(native_sdl.HOST_DIR, "lib/libSDL3.a")] +
                       native_sdl.HOST_LINK + host_ffmpeg_libs(), logf)
    if r.returncode:
        raise SystemExit("movies_test build failed:\n%s" % (r.stdout + r.stderr)[-4000:])
    refs_ok = all(os.path.exists(os.path.join(MOV_DIR, f)) for f in ("m.yuv", "m.bgra", "m.f32", "s.yuv", "d5.f32"))
    if not refs_ok:
        refs(frames)
    out = os.path.join(d, "out")
    os.makedirs(out, exist_ok=True)
    env = dict(os.environ, SDL_AUDIO_DRIVER="dummy", HULK_TEST_OUT=out, HULK_TEST_REF=MOV_DIR,
               HULK_TEST_FRAMES=str(frames), HULK_TEST_MOVIE=movie_spec("m"), HULK_TEST_MOVIE2=movie_spec("s"), HULK_TEST_MOVIE3=movie_spec("d"))
    p = subprocess.run([exe], capture_output=True, text=True, timeout=900, env=env)
    sys.stdout.write(p.stdout)
    sys.stderr.write(p.stderr[-4000:])
    log("movies_test (host): exit %d" % p.returncode)
    return p.returncode


# ---------------------------------------------------------------------------------------------
# win32: FFmpeg's configure and compile steps with clang for i686-pc-windows-msvc (mingw-w64 headers only, no
# mingw-w64 code or CRT: msvcrt.dll by import, as the SDL3.dll build), our own DLL link with lld-link
def write_wrappers():
    d = os.path.join(WIN_DIR, "tools")
    os.makedirs(d, exist_ok=True)
    cc = os.path.join(d, "cc.sh")
    flags = " ".join("'%s'" % a for a in native_sdl.win32_cflags()[1:])
    with open(cc, "w") as f:
        f.write("#!/bin/sh\n# tools/native_ffmpeg.py: clang for i686-pc-windows-msvc with the mingw-w64 headers\n"
                "case \"$1\" in -\\?) exit 1;; esac\n"      # configure's `cc -?` probe: this is not clang-cl
                "exec %s/clang %s \"$@\"\n" % (LLVM, flags))
    os.chmod(cc, 0o755)
    ld = os.path.join(d, "ld.sh")
    with open(ld, "w") as f:
        f.write("#!/bin/sh\n# tools/native_ffmpeg.py: configure's link tests (gcc-style arguments) on lld-link\n"
                "exec %s %s _ld \"$@\"\n" % (sys.executable, os.path.abspath(__file__)))
    os.chmod(ld, 0o755)
    return cc, ld


# C library names that the classic msvcrt.dll exports only with an underscore (MSVC's oldnames.lib maps them). Wine's
# msvcrt has stubs under the plain names too, which abort when called: always import the underscore name.
OLDNAMES = set("""access chdir chmod chsize close creat dup dup2 eof execl execle execlp execlpe execv execve execvp
execvpe fcvt fdopen fgetchar fileno fputchar getch getche getcwd getpid getw hypot isatty itoa kbhit lfind lsearch
lseek memccpy memicmp mktemp open putch putenv putw read rmdir setmode sopen spawnl spawnle spawnlp spawnlpe spawnv
spawnve spawnvp spawnvpe strcmpi strdup stricmp strlwr strnicmp strnset strrev strset strupr swab tell tempnam tzset
umask ungetch unlink wcsdup wcsicmp wcsnicmp wcsnset wcsrev wcsset wcslwr wcsupr write""".split())


def win32_import_libs(objs, tmp, extra_defined=()):
    """Import libraries for the names the objects use from the Win32 DLLs (Wine's export tables, only the names are
    read), plus the moldname aliases mingw-w64's headers expect (hypot -> msvcrt's _hypot and the like)."""
    ex = native_sdl.wine_exports("msvcrt")
    nm = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--undefined-only", "--no-sort"] + objs, capture_output=True,
                        text=True)
    undef = {l.split()[-1] for l in nm.stdout.splitlines() if l.strip().startswith("U ")}
    old = {sym for sym in undef if sym.startswith("_") and sym[1:] in OLDNAMES and sym not in extra_defined}
    libs, _by, unresolved = native_sdl.import_libs(objs, tmp, os.devnull, extra_defined=set(extra_defined) | old)
    mold = [sym[1:] for sym in old if "_" + sym[1:] in ex]
    for sym in unresolved:
        c = sym[1:] if sym.startswith("_") else sym
        if "@" not in c and "_" + c in ex:
            mold.append(c)
    if mold:
        df = os.path.join(tmp, "moldname.def")
        with open(df, "w") as f:
            f.write("LIBRARY msvcrt.dll\nEXPORTS\n")
            for c in sorted(set(mold)):
                f.write("_%s\n" % c)
        lib = os.path.join(tmp, "moldname.lib")
        subprocess.run([os.path.join(native_sdl.LLVM, "llvm-dlltool"), "-m", "i386", "-d", df, "-l", lib, "-k"],
                       capture_output=True)
        if os.path.exists(lib):
            libs.append(lib)
    # (the program's reference to C name X is symbol _X; the import library defines __X for the DLL's export _X)
    return libs, ["/alternatename:_%s=__%s" % (c, c) for c in sorted(set(mold))]


def ld_wrapper(args):
    """configure's link tests: objects + -l flags -> lld-link against import libraries made from Wine's export
    tables for exactly the names the objects use (native_sdl.import_libs)."""
    out = "a.out"
    objs = []
    i = 0
    while i < len(args):
        a = args[i]
        if a == "-o":
            out = args[i + 1]
            i += 1
        elif a.endswith((".o", ".obj", ".a", ".lib")):
            objs.append(a)
        i += 1
    tmp = out + ".imp"
    os.makedirs(tmp, exist_ok=True)
    # names no DLL exports are left to the linker (the mingw-w64 headers' inline functions mention some; a name the
    # program really needs fails the link, which is the answer)
    libs, alts = win32_import_libs(objs, tmp)
    r = subprocess.run([native_sdl.LLD_LINK, "/nologo", "/machine:x86", "/subsystem:console", "/entry:main",
                        "/nodefaultlib", "/opt:ref", "/out:" + out] + alts + objs + libs, capture_output=True, text=True)
    sys.stderr.write(r.stdout + r.stderr)
    return r.returncode


def build_wasm():
    """Feasibility for the web port (docs/native-movies.md): the same minimal FFmpeg as static libraries with
    emscripten. Not shipped; shows the size a browser would carry."""
    fetch()
    od = os.path.join(OUT, "ffmpeg-wasm", "obj")
    os.makedirs(od, exist_ok=True)
    logf = os.path.join(OUT, "ffmpeg-wasm", "build.log")
    cfg = [os.path.join(FF_SRC, "configure"), "--prefix=" + os.path.join(OUT, "ffmpeg-wasm", "install"),
           "--enable-cross-compile", "--target-os=none", "--arch=x86_32", "--cpu=generic", "--cc=emcc", "--cxx=em++",
           "--ar=emar", "--ranlib=emranlib", "--nm=emnm", "--strip=true", "--disable-asm", "--disable-x86asm",
           "--disable-pthreads", "--disable-w32threads", "--disable-os2threads", "--disable-stripping",
           "--disable-shared", "--enable-static", "--extra-cflags=-Oz"] + FF_CONFIGURE
    with open(logf, "w") as f:
        for cmd in (cfg, ["make", "-j", str(JOBS)], ["make", "install"]):
            f.write("$ " + " ".join(cmd) + "\n")
            f.flush()
            r = subprocess.run(cmd, cwd=od, stdout=f, stderr=subprocess.STDOUT)
            if r.returncode:
                raise SystemExit("wasm FFmpeg build failed at %s (log %s)" % (cmd[0], os.path.relpath(logf, ROOT)))
    libs = os.path.join(OUT, "ffmpeg-wasm", "install/lib")
    # the movie wrapper and the libraries linked into one module exporting hulk_movie_*: what a page would download
    wasm = os.path.join(OUT, "ffmpeg-wasm", "hulkmovie.wasm")
    exports = ",".join("_" + n for n in ("hulk_movie_open", "hulk_movie_close", "hulk_movie_info", "hulk_movie_track",
                                         "hulk_movie_select_tracks", "hulk_movie_decode_video", "hulk_movie_pump_audio",
                                         "hulk_movie_audio_queued", "hulk_movie_audio_read", "hulk_movie_at_end",
                                         "hulk_movie_demux_done", "hulk_movie_to_bgra", "malloc", "free"))
    r = subprocess.run(["emcc", "-Oz", "-I" + os.path.join(OUT, "ffmpeg-wasm", "install/include"),
                        os.path.join(PLAT, "movies/movie.c"), "-L" + libs, "-lavformat", "-lavcodec", "-lavutil",
                        "--no-entry", "-sSTANDALONE_WASM", "-sALLOW_MEMORY_GROWTH", "-sEXPORTED_FUNCTIONS=" + exports,
                        "-o", wasm], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("wasm link failed:\n" + (r.stdout + r.stderr)[-3000:])
    size = os.path.getsize(wasm)
    log("wasm: hulkmovie.wasm %d KB (movie wrapper + libavformat / libavcodec / libavutil, Bink only)" % (size >> 10))
    return size


def link_dll(dllname, lib, objs, implibs, outdir, compat=None, prefix="_av"):
    """One FFmpeg library as a DLL: every external `av*` symbol is exported (libav*.v), the rest of its imports
    come from the Win32 DLLs and the libraries it depends on (`implibs`). Returns (dll, import library)."""
    nm = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--defined-only", "--extern-only", "--no-sort"] + objs,
                        capture_output=True, text=True)
    objs = objs + ([compat] if compat else [])
    exports = sorted({l.split()[-1] for l in nm.stdout.splitlines() if len(l.split()) >= 3 and l.split()[-2] in ("T", "D", "R", "B")
                      and l.split()[-1].startswith(prefix)})
    tmp = os.path.join(outdir, lib + "-imports")
    os.makedirs(tmp, exist_ok=True)
    dep_syms = set()
    for il in implibs:
        r = subprocess.run([os.path.join(LLVM, "llvm-nm"), il], capture_output=True, text=True)
        dep_syms |= {l.split()[-1] for l in r.stdout.splitlines() if len(l.split()) >= 3 and l.split()[-2] in ("T", "D")}
    libs, alts = win32_import_libs(objs, tmp, extra_defined=dep_syms)
    dll = os.path.join(outdir, dllname + ".dll")
    implib = os.path.join(outdir, lib + ".lib")
    defs = os.path.join(outdir, lib + ".def")
    with open(defs, "w") as f:
        f.write("LIBRARY %s.dll\nEXPORTS\n" % dllname)
        for e in exports:
            f.write("%s\n" % e[1:])
    cmd = [native_sdl.LLD_LINK, "/nologo", "/machine:x86", "/dll", "/noentry", "/nodefaultlib", "/opt:ref", "/def:" + defs,
           "/out:" + dll, "/implib:" + implib] + alts + objs + implibs + libs
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("%s link failed:\n%s" % (dllname, (r.stdout + r.stderr)[-4000:]))
    log("  %s: %d objects, %d exports, %d KB" % (os.path.basename(dll), len(objs), len(exports), os.path.getsize(dll) >> 10))
    return dll, implib


def build_win32():
    fetch()
    cc, ld = write_wrappers()
    od = os.path.join(WIN_DIR, "obj")
    os.makedirs(od, exist_ok=True)
    logf = os.path.join(WIN_DIR, "build.log")
    cfg = [os.path.join(FF_SRC, "configure"), "--enable-cross-compile", "--arch=x86_32", "--target-os=mingw32",
           "--cc=" + cc, "--ld=" + ld, "--host-cc=/usr/bin/clang", "--nm=" + os.path.join(LLVM, "llvm-nm"),
           "--ar=" + os.path.join(LLVM, "llvm-ar"), "--ranlib=" + os.path.join(LLVM, "llvm-ranlib"),
           "--strip=" + os.path.join(LLVM, "llvm-strip"), "--disable-asm", "--disable-x86asm", "--disable-pthreads",
           "--disable-w32threads", "--disable-os2threads", "--disable-stripping", "--enable-shared",
           "--disable-static", "--extra-cflags=-U__USE_MINGW_ANSI_STDIO -D__USE_MINGW_ANSI_STDIO=0 -Wno-deprecated-declarations"] + FF_CONFIGURE
    with open(logf, "w") as f:
        f.write("$ " + " ".join(cfg) + "\n")
        f.flush()
        r = subprocess.run(cfg, cwd=od, stdout=f, stderr=subprocess.STDOUT)
    if r.returncode:
        raise SystemExit("win32 FFmpeg configure failed (log %s, ffbuild/config.log)" % os.path.relpath(logf, ROOT))
    log("win32: configured")
    t0 = time.time()
    with open(logf, "a") as f:
        r = subprocess.run(["make", "-k", "-j", str(JOBS)], cwd=od, stdout=f, stderr=subprocess.STDOUT)
        r2 = subprocess.run(["make", "install-headers", "DESTDIR=" + os.path.join(WIN_DIR, "stage")], cwd=od,
                            stdout=f, stderr=subprocess.STDOUT)
    if r2.returncode:
        raise SystemExit("make install-headers failed (log %s)" % os.path.relpath(logf, ROOT))
    # the objects are what counts: make's own link step cannot run without a GNU-style linker
    dlls = {}
    prev = []
    ld = os.path.join(WIN_DIR, "dll")
    os.makedirs(ld, exist_ok=True)
    compat = os.path.join(ld, "ffcompat_win32.obj")
    r = subprocess.run([cc, "-O2", "-c", os.path.join(PLAT, "movies/ffcompat_win32.c"), "-o", compat],
                       capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("ffcompat_win32.c:\n" + r.stderr[-3000:])
    for lib, ver in (("avutil", "60"), ("avcodec", "62"), ("avformat", "62")):
        objs = []
        for root, _dirs, files in os.walk(os.path.join(od, "lib" + lib)):
            objs += [os.path.join(root, x) for x in files if x.endswith(".o")]
        if not objs:
            raise SystemExit("no objects for lib%s: see %s" % (lib, os.path.relpath(logf, ROOT)))
        dlls[lib] = link_dll("%s-%s" % (lib, ver), lib, sorted(objs), prev, ld, compat)
        prev = prev + [dlls[lib][1]]
    inc = os.path.join(WIN_DIR, "install/include")
    stage = os.path.join(WIN_DIR, "stage")
    for root, _d, files in os.walk(stage):
        for x in files:
            if x.endswith(".h"):
                rel = os.path.relpath(os.path.join(root, x), stage)
                rel = rel.split("include/", 1)[1] if "include/" in rel else rel
                dst = os.path.join(inc, rel)
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                shutil.copy2(os.path.join(root, x), dst)
    json.dump({"target": "win32", "tag": FF_TAG, "configure": " ".join(cfg), "dlls": {k: v[0] for k, v in dlls.items()}},
              open(os.path.join(WIN_DIR, "build.json"), "w"), indent=1)
    write_license_notice()
    log("win32: FFmpeg %s DLLs in %d s: %s" % (FF_TAG, time.time() - t0, ", ".join(os.path.basename(v[0]) for v in dlls.values())))


def win32_movie_dll(logf):
    """hulkmovie.dll: src/platform/sdl/movies/movie.c over the FFmpeg DLLs (the game image imports only hulk_movie_*)."""
    d = os.path.join(WIN_DIR, "movies")
    os.makedirs(d, exist_ok=True)
    cc = os.path.join(WIN_DIR, "tools/cc.sh")
    obj = os.path.join(d, "movie.obj")
    r = native_gfx.run([cc, "-O2", "-Wall", "-Wextra", "-Wno-unused-parameter", "-Werror",
                        "-I" + os.path.join(WIN_DIR, "install/include"), "-c", os.path.join(PLAT, "movies/movie.c"),
                        "-o", obj], logf)
    if r.returncode:
        raise SystemExit("movie.c (win32):\n" + (r.stdout + r.stderr)[-4000:])
    ffl = [os.path.join(WIN_DIR, "dll", x + ".lib") for x in ("avutil", "avcodec", "avformat")]
    return link_dll("hulkmovie", "hulkmovie", [obj], ffl, d, prefix="_hulk_movie_")


def movies_win32(logf=None):
    """What the native image links for movies (the player objects, the movie DLL's import library) and runs with (the
    DLLs): all under build/third_party/out/ffmpeg-win32/movies/. Returns a dict of paths."""
    if not os.path.exists(os.path.join(WIN_DIR, "dll/avformat-62.dll")):
        build_win32()
    sdl = native_sdl.backends("win32")
    d = os.path.join(WIN_DIR, "movies")
    os.makedirs(d, exist_ok=True)
    logf = logf or os.path.join(d, "build.log")
    mdll, mlib = win32_movie_dll(logf)
    cxx = native_sdl.win32_cxx() + native_sdl.sdl_inc("win32") + native_sdl.mingw_inc() + ["-I" + PLAT]
    res = {"hulk_sdl_lib": sdl["win32"], "movie_dll": mdll, "movie_implib": mlib,
           "sdl_dll": os.path.join(native_sdl.WIN_DIR, "SDL3.dll"), "sdl_implib": os.path.join(native_sdl.WIN_DIR, "SDL3.lib"),
           "ffmpeg_dlls": [os.path.join(WIN_DIR, "dll", x + ".dll") for x in ("avutil-60", "avcodec-62", "avformat-62")]}
    # the player (our code; SDL's headers, no C++ runtime) as an object in a library, and the xdk stand-ins' object
    # compiled the way tools/native_host.py compile_dir does for the image (+ HULK_NATIVE_SDL)
    jobs = [("bink_player", os.path.join(PLAT, "movies/bink_player.cpp"), cxx),
            ("movies_bink", os.path.join(PLAT, "xdk/movies_bink.cpp"), native_sdl.SHIM_CXX)]
    objs = {}
    for name, src, flags in jobs:
        o = os.path.join(d, name + ".obj")
        r = native_gfx.run(flags + ["-c", src, "-o", o], logf)
        if r.returncode:
            raise SystemExit("%s failed:\n%s" % (os.path.relpath(src, ROOT), (r.stdout + r.stderr)[-4000:]))
        objs[name] = o
    lib = os.path.join(d, "hulk_movies.lib")
    if os.path.exists(lib):
        os.unlink(lib)
    r = native_gfx.run([os.path.join(LLVM, "llvm-lib"), "/nologo", "/out:" + lib, objs["bink_player"]], logf)
    if r.returncode:
        raise SystemExit("hulk_movies.lib: " + r.stderr[-2000:])
    res.update(movies_lib=lib, shim_obj=objs["movies_bink"], player_obj=objs["bink_player"])
    json.dump(res, open(os.path.join(d, "build.json"), "w"), indent=1)
    return res


def test_wine(frames):
    built = movies_win32()
    d = os.path.join(WIN_DIR, "test")
    os.makedirs(d, exist_ok=True)
    logf = os.path.join(d, "build.log")
    open(logf, "w").close()
    mdll, mlib, lib = built["movie_dll"], built["movie_implib"], built["hulk_sdl_lib"]
    cxx = native_sdl.win32_cxx() + native_sdl.sdl_inc("win32") + native_sdl.mingw_inc() + ["-I" + PLAT]
    objs = {}
    for name, src, flags in (("test", os.path.join(ROOT, "tests/native_movies/movies_test.cpp"),
                              cxx + ["-I" + os.path.join(ROOT, "tests/native_audio"), "-DHULK_TEST_XDK=1"]),
                             ("rt", os.path.join(ROOT, "tests/native_audio/test_runtime_win32.cpp"), cxx)):
        o = os.path.join(d, name + ".obj")
        r = native_gfx.run(flags + ["-c", src, "-o", o], logf)
        if r.returncode:
            raise SystemExit("%s failed:\n%s" % (os.path.relpath(src, ROOT), (r.stdout + r.stderr)[-4000:]))
        objs[name] = o
    # the game's own I/O callbacks the test hands the player (verified sources: game code, not Bink's)
    for rel in ("equivalent/0x00334960.cpp", "matches/0x00334f60.cpp", "matches/0x0026fd50.cpp", "matches/0x0026fd80.cpp"):
        o = os.path.join(d, "game_" + os.path.basename(rel)[:-4] + ".obj")
        r = native_gfx.run(cxx + ["-Wno-error", "-c", os.path.join(ROOT, rel), "-o", o], logf)
        if r.returncode:
            raise SystemExit("%s failed:\n%s" % (rel, (r.stdout + r.stderr)[-3000:]))
        objs[rel] = o
    olist = [objs["test"], objs["rt"], built["player_obj"], built["shim_obj"]] + [
        v for k, v in objs.items() if k.endswith(".cpp")]
    lib_objs = [os.path.join(native_sdl.BK_DIR, "win32/obj", rel.replace("/", "_")[:-4] + ".obj")
                for rel in native_sdl.BACKEND_SOURCES]
    imp_dir = os.path.join(d, "imports")
    os.makedirs(imp_dir, exist_ok=True)
    # (the test calls the wrapper directly through the import library; the player loads the same DLL at run time)
    nm = subprocess.run([os.path.join(LLVM, "llvm-nm"), mlib], capture_output=True, text=True)
    mexp = {l.split()[-1] for l in nm.stdout.splitlines() if len(l.split()) >= 3 and l.split()[-2] in ("T", "D")}
    libs, _by, unresolved = native_sdl.import_libs(olist + lib_objs, imp_dir, logf,
                                                   extra_defined=native_sdl._sdl_exports() | mexp)
    exe = os.path.join(d, "movies_test.exe")
    cmd = [native_sdl.LLD_LINK, "/nologo", "/machine:x86", "/subsystem:console", "/entry:hulk_test_entry", "/nodefaultlib",
           "/out:" + exe] + olist + [lib, built["sdl_implib"], mlib] + libs
    r = native_gfx.run(cmd, logf)
    if r.returncode:
        raise SystemExit("movies_test.exe link failed:\n%s" % (r.stdout + r.stderr)[-4000:])
    for f in [built["sdl_dll"], mdll] + built["ffmpeg_dlls"]:
        shutil.copy2(f, os.path.join(d, os.path.basename(f)))
    refs_ok = all(os.path.exists(os.path.join(MOV_DIR, f)) for f in ("m.yuv", "m.bgra", "m.f32", "s.yuv", "d5.f32"))
    if not refs_ok:
        refs(frames)
    out = os.path.join(d, "out")
    os.makedirs(out, exist_ok=True)

    def z(p):
        return "Z:" + p.replace("/", "\\")

    def zs(spec):
        path, off, size = spec.split("|")
        return "|".join((z(path), off, size))

    prefix = os.path.join(ROOT, "build/native/wineprefix")
    env = native_sdl.native_gfx_wine_env(prefix)
    env.update(SDL_AUDIO_DRIVER="dummy", HULK_TEST_OUT=z(out), HULK_TEST_REF=z(MOV_DIR), HULK_TEST_FRAMES=str(frames),
               HULK_TEST_MOVIE=zs(movie_spec("m")), HULK_TEST_MOVIE2=zs(movie_spec("s")), HULK_TEST_MOVIE3=zs(movie_spec("d")))
    p = subprocess.run([native_gfx.WINE, exe], capture_output=True, text=True, timeout=1800, env=env, cwd=d)
    sys.stdout.write(p.stdout)
    sys.stderr.write(p.stderr[-3000:])
    log("movies_test (wine): exit %d" % p.returncode)
    return p.returncode


def build_dump():
    if not os.path.exists(os.path.join(HOST_DIR, "install/lib")):
        build_host()
    d = os.path.join(HOST_DIR, "test")
    os.makedirs(d, exist_ok=True)
    logf = os.path.join(d, "build.log")
    obj = os.path.join(d, "movie.o")
    r = native_gfx.run(["/usr/bin/clang", "-arch", "arm64", "-mmacosx-version-min=11.0", "-O2", "-g", "-Wall", "-Wextra",
                        "-Wno-unused-parameter", "-Werror"] + host_inc() + ["-c", os.path.join(PLAT, "movies/movie.c"),
                                                                         "-o", obj], logf)
    if r.returncode:
        raise SystemExit("movie.c:\n" + (r.stdout + r.stderr)[-3000:])
    exe = os.path.join(d, "movies_dump")
    r = native_gfx.run(["/usr/bin/clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-std=c++17", "-O2", "-g",
                        "-Wall", "-Wextra", "-Wno-unused-parameter", "-Werror", "-I" + PLAT,
                        os.path.join(ROOT, "tests/native_movies/movies_dump.cpp"), obj, "-o", exe] + host_ffmpeg_libs(), logf)
    if r.returncode:
        raise SystemExit("movies_dump build failed:\n" + (r.stdout + r.stderr)[-3000:])
    return exe


def all_movies():
    """[(archive, name, offset, size)] of every movie in the game's archives."""
    res = []
    for archive in ("movies1.rcf", "movies2.rcf", "mog_mov1.rcf", "mog_mov2.rcf", "mog_mov3.rcf"):
        for name, (off, size) in rcf_entries(archive).items():
            res.append((archive, name, off, size))
    return res


def inventory(only=None):
    """Every shipped movie decoded whole by our wrapper and by the ffmpeg command line, compared: the Adler-32 of every
    planar frame and every audio track's samples (ffmpeg's decoded floats, rounded the way movie.c does). Writes
    build/mv1/inventory.json (a copy of the header facts and the verdicts; no game data)."""
    import zlib
    exe = build_dump()
    ff = ffmpeg_cli()
    rows = []
    os.makedirs(MOV_DIR, exist_ok=True)
    for archive, name, off, size in all_movies():
        if only and only not in name:
            continue
        spec = "%s|%d|%d" % (os.path.join(ROOT, "isos/extracted", archive), off, size)
        t0 = time.time()
        cut = os.path.join(MOV_DIR, "inv.bik")
        with open(os.path.join(ROOT, "isos/extracted", archive), "rb") as fi, open(cut, "wb") as fo:
            fi.seek(off)
            fo.write(fi.read(size))
        refdir = os.path.join(MOV_DIR, "inv")
        shutil.rmtree(refdir, ignore_errors=True)
        os.makedirs(refdir)
        probe = subprocess.run([ff.replace("ffmpeg", "ffprobe"), "-v", "error", "-select_streams", "a", "-show_entries",
                                "stream=index", "-of", "csv=p=0", cut], capture_output=True, text=True)
        nat = len(probe.stdout.split())
        for i in range(nat):    # ffmpeg's decode of each audio track (its decoders' own floats)
            subprocess.run([ff, "-v", "error", "-i", cut, "-map", "0:a:%d" % i, "-f", "f32le",
                            os.path.join(refdir, "a%d.f32" % i)], check=True)
        t0 = time.time()
        p = subprocess.run([exe, spec, refdir], capture_output=True, text=True)
        mine_secs = time.time() - t0
        if p.returncode:
            rows.append({"name": name, "error": "dump exit %d" % p.returncode})
            os.unlink(cut)
            continue
        mine_frames, tracks, head = [], [], None
        for line in p.stdout.splitlines():
            f = line.split()
            if f[0] == "F":
                mine_frames.append(int(f[2], 16))
            elif f[0] == "movie":
                head = [int(x) for x in f[1:]]
            elif f[0] == "track":
                tracks.append({"id": int(f[1]), "rate": int(f[2]), "channels": int(f[3]), "frames": int(f[4]),
                               "samples": int(f[6]), "equal": int(f[7]), "within1": int(f[8]), "maxdiff": int(f[9])})
        # ffmpeg's decode of the video, frame by frame (Adler-32 of the packed planar frame, as the dump prints)
        fb = head[0] * head[1] + 2 * ((head[0] + 1) // 2) * ((head[1] + 1) // 2)
        ref_frames = []
        pr = subprocess.Popen([ff, "-v", "error", "-i", cut, "-an", "-fps_mode", "passthrough", "-pix_fmt", "yuv420p",
                               "-f", "rawvideo", "-"], stdout=subprocess.PIPE)
        while True:
            chunk = pr.stdout.read(fb)
            if len(chunk) < fb:
                break
            ref_frames.append(zlib.adler32(chunk))
        pr.wait()
        os.unlink(cut)
        shutil.rmtree(refdir, ignore_errors=True)
        bad = sum(1 for a, b in zip(mine_frames, ref_frames) if a != b)
        audio_ok = [dict(t, ref_tracks=nat) for t in tracks]
        row = {"name": name, "archive": archive, "bytes": size, "width": head[0], "height": head[1], "frames": head[2],
               "fps": "%d/%d" % (head[3], head[4]), "alpha": head[5], "tracks": tracks, "video_frames_mine": len(mine_frames),
               "video_frames_ref": len(ref_frames), "video_frames_differing": bad, "seconds": round(mine_secs, 1)}
        rows.append(row)
        samples = sum(t["samples"] for t in tracks)
        eq = sum(t["equal"] for t in tracks)
        w1 = sum(t["within1"] for t in tracks)
        mx = max([t["maxdiff"] for t in tracks] or [0])
        log("%-24s %dx%d %5d frames, %d trk: video %d/%d frames identical%s; audio %d/%d samples equal (%d within 1, max diff %d) [%.1f s]" % (
            name, head[0], head[1], head[2], len(tracks), len(mine_frames) - bad, len(ref_frames),
            "" if len(mine_frames) == len(ref_frames) else " (COUNT DIFFERS)", eq, samples, w1, mx, mine_secs))
    out = os.path.join(ROOT, "build/mv1/inventory.json")
    os.makedirs(os.path.dirname(out), exist_ok=True)
    json.dump(rows, open(out, "w"), indent=1)
    log("wrote %s" % os.path.relpath(out, ROOT))
    return 0 if all("error" not in r and r["video_frames_differing"] == 0 and r["video_frames_mine"] == r["video_frames_ref"]
                    and all(t["equal"] == t["samples"] and t["samples"] == t["frames"] * t["channels"] for t in r["tracks"])
                    for r in rows) else 1


def status():
    p = os.path.join(DL, "FFmpeg-%s.tar.gz" % FF_TAG)
    print("FFmpeg %s tarball %s unpacked %s" % (FF_TAG, "yes" if os.path.exists(p) else "no",
                                               "yes" if os.path.exists(os.path.join(FF_SRC, ".pinned")) else "no"))
    for d in (HOST_DIR, WIN_DIR):
        bj = os.path.join(d, "build.json")
        print("%-14s %s" % (os.path.basename(d), json.load(open(bj)) if os.path.exists(bj) else "not built"))


def main(argv):
    if argv and argv[0] == "_ld":
        return ld_wrapper(argv[1:])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("fetch")
    b = sub.add_parser("build")
    b.add_argument("--target", choices=("host", "win32", "wasm", "all"), default="host")
    r = sub.add_parser("refs")
    r.add_argument("--frames", type=int, default=60)
    t = sub.add_parser("test")
    t.add_argument("--frames", type=int, default=60)
    w = sub.add_parser("wine-test")
    w.add_argument("--frames", type=int, default=60)
    sub.add_parser("status")
    sub.add_parser("movies", help="build what the native image links and runs with for movies (i686)")
    iv = sub.add_parser("inventory")
    iv.add_argument("--only", default=None)
    a = ap.parse_args(argv)
    if a.cmd == "fetch":
        fetch()
    elif a.cmd == "build":
        if a.target in ("host", "all"):
            build_host()
        if a.target in ("win32", "all"):
            build_win32()
        if a.target == "wasm":
            build_wasm()
    elif a.cmd == "refs":
        refs(a.frames)
    elif a.cmd == "test":
        return test_host(a.frames)
    elif a.cmd == "wine-test":
        return test_wine(a.frames)
    elif a.cmd == "movies":
        built = movies_win32()
        for k, v in built.items():
            print("%-14s %s" % (k, v if isinstance(v, str) else " ".join(v)))
        for k in ("player_obj", "shim_obj"):
            nm = subprocess.run([os.path.join(LLVM, "llvm-nm"), "--undefined-only", built[k]], capture_output=True, text=True)
            print("%s needs: %s" % (k, " ".join(sorted(l.split()[-1] for l in nm.stdout.splitlines() if l.strip()))))
    elif a.cmd == "inventory":
        return inventory(a.only)
    elif a.cmd == "status":
        status()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
