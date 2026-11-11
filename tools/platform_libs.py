"""Which prebuilt platform libraries (hulk_fs.lib, hulk_movies.lib, hulk_sdl.lib) still fit src/platform/sdl.

wine_link.refresh_platform_libs() rebuilds a library whose sources changed. It used to compare mtimes, which only mean
something in the checkout the library was built in: a build host's lineage holds copies of the sources (new mtimes)
and the libraries come from the shipped inputs, so every library looked stale there, and the rebuild then failed for
lack of the SDL3 sources (builds needed HULK_WINE_REFRESH_LIBS=0). Now each library has a stamp beside it,
`<lib>.srchash`: the content hash of the sources it was built from. It is written when a library is rebuilt, and
when a library is fresh by mtime on a machine that builds them (the checkout with build/third_party/src), which is
where `wine_build_job.py submit` stamps the libraries before it ships them. A library with a stamp is stale exactly
when its sources' hash differs; one without falls back to mtimes.
"""
import hashlib
import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
PLAT = os.path.join(ROOT, "src/platform/sdl")

# (library under the third-party output dir, source dirs under src/platform/sdl, more files there, rebuild command
#  (a tools/ script and its arguments), refreshed only if it was built before). The top-level files of
# src/platform/sdl count for every library.
LIBS = [
    ("fs1/win32/hulk_fs.lib", ["fs"], [], ["wine_fs.py", "backends", "--target", "win32"], True),
    # (wine_ffmpeg.py movies also rebuilds hulk_sdl.lib; the library is movies/bink_player.cpp, which includes
    #  audio/hulk_audio.h; xdk/movies_bink.cpp is built beside it)
    ("ffmpeg-win32/movies/hulk_movies.lib", ["movies"], ["audio/hulk_audio.h", "xdk/movies_bink.cpp"],
     ["wine_ffmpeg.py", "movies"], True),
    ("sdl-backends/win32/hulk_sdl.lib", ["audio", "input", "replay"], [], ["wine_sdl.py", "backends", "--target", "win32"],
     False),
]
SKIP = ("__pycache__", ".DS_Store", ".git")
SKIP_SUFFIX = (".pyc", ".orig", ".rej")     # (guard1: what never reaches a build host; tools/input_guard.py hashes the same)


def _keep(f):
    return f not in SKIP and not f.endswith(SKIP_SUFFIX)


def sources(dirs, files=(), plat=PLAT):
    """The library's source files (absolute paths), sorted."""
    out = [os.path.join(plat, f) for f in os.listdir(plat) if os.path.isfile(os.path.join(plat, f)) and _keep(f)]
    for d in dirs:
        for dp, dn, fn in os.walk(os.path.join(plat, d)):
            dn[:] = [x for x in dn if x not in SKIP]
            out += [os.path.join(dp, f) for f in fn if _keep(f)]
    out += [os.path.join(plat, f) for f in files if os.path.exists(os.path.join(plat, f))]
    return sorted(set(out))


def source_hash(dirs, files=(), plat=PLAT):
    h = hashlib.sha1()
    for p in sources(dirs, files, plat):
        h.update(os.path.relpath(p, plat).encode() + b"\0")
        with open(p, "rb") as f:
            h.update(hashlib.sha1(f.read()).digest())
    return h.hexdigest()


def stamp_path(lib):
    return lib + ".srchash"


def read_stamp(lib):
    try:
        with open(stamp_path(lib)) as f:
            return f.read().strip() or None
    except OSError:
        return None


def write_stamp(lib, digest):
    tmp = stamp_path(lib) + ".%d.tmp" % os.getpid()
    with open(tmp, "w") as f:
        f.write(digest + "\n")
    os.replace(tmp, stamp_path(lib))


def can_build(root=ROOT):
    """Whether this machine can rebuild the libraries (the pinned SDL3 and mingw-w64 sources are unpacked here)."""
    src = os.path.join(root, "build/third_party/src")
    return os.path.isdir(os.path.join(src, "SDL/include")) and os.path.isdir(os.path.join(src, "mingw-w64"))


def state(lib, dirs, files=(), plat=PLAT, trust_mtime=True):
    """("missing" | "fresh" | "stale" | "unknown", how). With a stamp: by content. Without: by mtime, but only where
    mtimes mean something (trust_mtime: the machine the libraries are built on), else "unknown"."""
    if not os.path.exists(lib):
        return "missing", "no library"
    st = read_stamp(lib)
    if st:
        return ("fresh" if st == source_hash(dirs, files, plat) else "stale"), "content hash"
    if not trust_mtime:
        return "unknown", "no source stamp"
    newest = max([0.0] + [os.path.getmtime(p) for p in sources(dirs, files, plat)])
    return ("fresh" if os.path.getmtime(lib) >= newest else "stale"), "mtime"


def stamp_fresh(out_dir, plat=PLAT):
    """Stamp the libraries under out_dir that are fresh by mtime and have no stamp (the machine they were built on).
    Returns {library: state}."""
    res = {}
    for rel, dirs, files, _cmd, _opt in LIBS:
        lib = os.path.join(out_dir, rel)
        s, how = state(lib, dirs, files, plat)
        if s == "fresh" and how == "mtime":
            write_stamp(lib, source_hash(dirs, files, plat))
        res[rel] = s
    return res
