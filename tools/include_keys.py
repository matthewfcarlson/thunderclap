#!/usr/bin/env python3
"""Per-TU include digests for the content-keyed object caches (tools/build_tree.py, tools/clang_probe.py).

A cached object is only valid while every header its compile can read is unchanged, so a cache key that names "the
headers of the TU" must cover every file any of the TU's `#include`s could resolve to, transitively. closure() works
that out from the text alone, conservatively:

  * every `#include "x"` / `#include <x>` line counts, also inside `#if 0` and block comments (more files than the
    compiler reads is safe; fewer is not);
  * a quoted name is looked up in the directory of every file of the closure so far (MSVC and clang's MS mode search
    the directories of all open includers, not only the current file's) and in every search directory; an angle name
    in the search directories; EVERY existing candidate is taken, not only the first, so a header added in front of
    another changes the key too; the closure is grown until no new directory or file comes in;
  * files under a SYSTEM directory (the compiler's own headers, covered by the toolchain stamp) are not read or hashed;
  * an `#include MACRO` (a computed name) makes the digest None: the caller must fall back to hashing every header.

digest() is sha1 over the closure's paths (relative to ROOT, so lineages on one host share their caches) and contents.
File texts are cached per (path, mtime, size) and lookups until reset(), which build_tree calls whenever files may have come
or gone (before each compile pass).
"""
import hashlib
import os
import re
import threading

INC = re.compile(rb'^[ \t]*#[ \t]*include[ \t]*(?:"([^"\n]+)"|<([^>\n]+)>|(\S))', re.M)

_lock = threading.Lock()
_cache = {}     # abs path -> (stat key, sha1 hex, [(quoted, name)], computed include?)
_isfile = {}    # abs path -> bool (until the next reset(): the caller resets whenever files may have come or gone)


def reset():
    with _lock:
        _cache.clear()
        _isfile.clear()


def _exists(p):
    r = _isfile.get(p)
    if r is None:
        r = _isfile[p] = os.path.isfile(p)
    return r


def _parse(path):
    try:
        st = os.stat(path)
    except OSError:
        return None
    sk = (st.st_mtime_ns, st.st_size)
    with _lock:
        hit = _cache.get(path)
    if hit and hit[0] == sk:
        return hit[1:]
    with open(path, "rb") as f:
        data = f.read()
    incs, computed = [], False
    for m in INC.finditer(data):
        if m.group(1) is not None:
            incs.append((True, m.group(1).decode("latin1")))
        elif m.group(2) is not None:
            incs.append((False, m.group(2).decode("latin1")))
        else:
            computed = True
    rec = (sk, hashlib.sha1(data).hexdigest(), incs, computed)
    with _lock:
        _cache[path] = rec
    return rec[1:]


def closure(tu, search, system=(), force=()):
    """(files {abs path: sha1} other than TU itself, or None for a computed include) of TU (abs path), with SEARCH the
    -I / INCLUDE directories in order (abs paths), SYSTEM directories whose headers are left out and FORCE the names
    of force-included headers (clang -include, MSVC /FI: looked up as quoted names of the TU)."""
    system = tuple(os.path.normpath(s) + os.sep for s in system)
    first = _parse(tu)
    if first is None:
        return {}
    if first[2]:
        return None
    files, dirs = {}, [os.path.dirname(tu)]
    names = set(first[1]) | {(True, n) for n in force}
    seen_names = set()
    while True:
        todo = sorted(names - seen_names)
        if not todo:
            # a new directory can resolve a name looked up before it came in: look every quoted name up again
            nd = len(dirs)
            for d in sorted({os.path.dirname(p) for p in files}):
                if d not in dirs:
                    dirs.append(d)
            if len(dirs) == nd:
                break
            seen_names = {n for n in seen_names if not n[0]}
            continue
        for quoted, name in todo:
            seen_names.add((quoted, name))
            cands = [os.path.join(d, name) for d in (dirs if quoted else []) + list(search)] if not os.path.isabs(name) else [name]
            for c in cands:
                c = os.path.normpath(c)
                if c in files or c == tu or c.startswith(system) or not _exists(c):
                    continue
                rec = _parse(c)
                if rec is None:
                    continue
                if rec[2]:
                    return None
                files[c] = rec[0]
                names.update(rec[1])
    return files


def digest(tu, search, system=(), root=None, force=()):
    """sha1 hex of TU's include closure (paths relative to ROOT when under it), or None (a computed include)."""
    files = closure(tu, search, system, force)
    if files is None:
        return None
    h = hashlib.sha1(b"inc1")
    for p in sorted(files, key=lambda p: _rel(p, root)):
        h.update(_rel(p, root).encode() + b"\0" + files[p].encode() + b"\n")
    return h.hexdigest()


def _rel(p, root):
    if root:
        r = os.path.relpath(p, root)
        if not r.startswith(".."):
            return r.replace(os.sep, "/")
    return p
