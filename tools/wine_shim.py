#!/usr/bin/env python3
"""Platform-shim and CRT inventory of the native link (docs/wine-build.md "Start-up milestone").

  build/venv/bin/python tools/wine_shim.py          # after tools/wine_link.py: build/native/shim-inventory.json

What the linked image still needs from outside the tree, from tools/wine_link.py's build/native/unbound.txt
(symbols still undefined after binding) and bindings.json (the XBE address each one stands for), sorted by
tools/platform_map.py's subsystems (build/port/platform_calls.json: library targets by address, library data by
name / address, kernel imports). One row per library function (by address): the names the tree calls it by,
symbols, references, and the library region it lives in (D3D, DSOUND, XAPI, XPP, BINK, XGRPH, LIBC, kernel).

Groups covered: platform imports, CRT / C++ runtime, library data. The other groups (unverified functions,
stub names at unverified addresses, ...) are sized by wine_link.py's report.json.

  build/venv/bin/python tools/wine_shim.py --skeleton   # also write src/platform/sdl/xdk/ (files not there yet)

The skeleton (docs/wine-build.md "Platform shim"): imports.h (every platform import with its XBE address and
one machine-level prototype: the calling convention, stack bytes and return register its callers' symbols agree
on, disagreements noted) and one stand-in file per subsystem; xdk_shim.h and trace.cpp are hand-written. Run it on
an inventory from before the shim existed: once wine_link.py links the shim, the imports leave unbound.txt.
"""
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
NATIVE = os.path.join(ROOT, "build/native")
GROUPS = {"platform import": "platform", "CRT / C++ runtime": "crt", "data: library": "library data"}
ADDR_RX = re.compile(r"(?:FUN|DAT|thunk_FUN|PTR|LAB)_(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")
SIMPLE = re.compile(r"(?:^|::)(~?[A-Za-z_]\w*)(?:<.*>)?\s*\(")


def simple_name(sym, dem):
    if dem and "(" not in dem:
        return dem
    m = SIMPLE.search(dem or "")
    if m:
        return m.group(1)
    s = sym.lstrip("_?").split("@")[0]
    return s


# ---------------------------------------------------------------------------------------------
# The calling convention each caller assumes (from its symbol), and one per function
CONV_RX = re.compile(r"^(.*?)\b(__cdecl|__stdcall|__fastcall|__thiscall)\s+([^\s(]+)\((.*)\)(?:\s*const)?$")
INTEGRAL = re.compile(r"^(?:(?:un)?signed\s+)?(?:char|short|int|long|bool|wchar_t)(?:\s+int)?$|^(?:un)?signed$|^enum\s")


def _split_params(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "<(":
            depth += 1
        elif ch in ">)":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _size(ty):
    """Stack bytes of one parameter (None: a struct passed by value, size unknown here)."""
    ty = re.sub(r"\b(?:const|volatile)\b", "", ty).strip()
    if ty.endswith(("*", "&")) or "(" in ty:
        return 4
    if ty in ("double", "__int64", "unsigned __int64", "long double"):
        return 8
    if ty == "float" or INTEGRAL.match(ty):
        return 4
    return None


def _ret(ty):
    ty = re.sub(r"^(?:(?:public|private|protected): )?(?:static |virtual )*", "", ty).strip()
    ty = re.sub(r"\b(?:const|volatile)\b", "", ty).strip()
    if ty.endswith(("*", "&")):
        return "u32"
    if ty == "void":
        return "void"
    if ty in ("float", "double", "long double"):
        return "fp"
    if ty in ("__int64", "unsigned __int64"):
        return "u64"
    if INTEGRAL.match(ty):
        return "u32"
    return "struct"


def signature(sym, dem):
    """{conv, stack (bytes the callee pops, cdecl: None), args, ret} that the caller of sym assumes, or None."""
    m = re.fullmatch(r"([_@])(\w+?)@(\d+)", sym)
    if m and not dem.strip("_"):
        n = int(m.group(3))
        if m.group(1) == "@":
            return {"conv": "fastcall", "stack": max(0, n - 8), "args": n // 4, "ret": None}
        return {"conv": "stdcall", "stack": n, "args": n // 4, "ret": None}
    if re.fullmatch(r"_\w+", sym) and not dem.strip("_"):
        return {"conv": "cdecl", "stack": None, "args": None, "ret": None}
    m = CONV_RX.match(dem)
    if not m:
        return None
    ret, conv, params = m.group(1), m.group(2)[2:], m.group(4).strip()
    ps = [] if params in ("", "void") else _split_params(params)
    sizes = [_size(p) for p in ps if p != "..."]
    if None in sizes:
        return {"conv": conv, "stack": None, "args": None, "ret": _ret(ret), "note": "struct by value"}
    total = sum(sizes)
    if conv == "cdecl":
        stack = None
    elif conv == "fastcall":
        regs = sum(1 for s in sizes[:2] if s == 4)       # (the first two dword-sized arguments go in ecx/edx)
        stack = total - 4 * regs
    else:                                                   # stdcall, thiscall (ecx = this, the rest as stdcall)
        stack = total
    return {"conv": "stdcall" if conv == "thiscall" else conv, "stack": stack, "args": total // 4,
            "ret": _ret(ret), **({"note": "called as a member function (thiscall)"} if conv == "thiscall" else {})}


def consensus(refs):
    """One machine-level signature for a library function from all the symbols the tree calls it by."""
    sigs = [s for s in (signature(sym, dem) for sym, dem in refs) if s]
    keys = collections.Counter((s["conv"], s["stack"]) for s in sigs if s["conv"] != "cdecl" or s["stack"] is not None)
    cdecl = sum(1 for s in sigs if s["conv"] == "cdecl")
    notes = sorted({s["note"] for s in sigs if s.get("note")})
    if keys:
        (conv, stack), _ = keys.most_common(1)[0]
        # (a cdecl caller of a callee that pops nothing is the same call at machine level)
        if len(keys) > 1 or (cdecl and stack):
            notes.append("callers disagree: %s" % ", ".join(
                "%s/%s x%d" % (c, s, n) for (c, s), n in sorted(keys.items(), key=str)) +
                (", cdecl x%d" % cdecl if cdecl else ""))
    else:
        conv, stack = "cdecl", None
    args = max([s["args"] for s in sigs if s["args"] is not None and s["conv"] == conv] or [0])
    if conv == "stdcall" and stack is not None:
        args = stack // 4
    rets = collections.Counter(s["ret"] for s in sigs if s["ret"])
    ret = "fp" if rets.get("fp") else "u64" if rets.get("u64") else "u32"
    if rets.get("struct"):
        notes.append("a caller expects a struct returned by value")
    return {"conv": conv, "stack": stack, "args": args, "ret": ret, "notes": notes}


# ---------------------------------------------------------------------------------------------
# The shim skeleton (src/platform/sdl/xdk/)
SKELETON = os.path.join(ROOT, "src/platform/sdl/xdk")
FILES = [  # (file, title, rows it takes: (subsystem, region) predicate)
    ("graphics_d3d8.cpp", "graphics: Direct3D 8 (Xbox)", lambda s, r, n: s == "graphics" and r != "XGRPH" or n.startswith("D3D")),
    ("graphics_xgraphics.cpp", "graphics: XGraphics", lambda s, r, n: s == "graphics" and r == "XGRPH"),
    ("audio_dsound.cpp", "audio: DirectSound (Xbox)", lambda s, r, n: s == "audio" and r == "DSOUND"),
    ("audio_soundtracks.cpp", "audio: user soundtracks", lambda s, r, n: s == "audio"),
    ("movies_bink.cpp", "movies: Bink", lambda s, r, n: s == "movies"),
    ("input_xpp.cpp", "input: XPP / XInput", lambda s, r, n: s == "input"),
    ("file_io.cpp", "file I/O", lambda s, r, n: s == "file I/O"),
    ("saves.cpp", "saves / storage", lambda s, r, n: s == "saves/storage"),
    ("threads.cpp", "threads / sync / fibers", lambda s, r, n: s == "threads/sync"),
    ("timing.cpp", "timing", lambda s, r, n: s == "timing"),
    ("memory.cpp", "memory", lambda s, r, n: s == "memory"),
    ("system.cpp", "process / system settings", lambda s, r, n: s == "process/system"),
    ("debug.cpp", "debug", lambda s, r, n: s.startswith("debug")),
]


def shim_name(row):
    n = row["names"][0]
    if n.startswith("FUN_") and row["region"] == "BINK":
        return "Bink_%s" % row["addr"][4:]
    return re.sub(r"\W+", "_", n.split(" (")[0]).strip("_")


def _proto(name, abi, with_names=False):
    ret = {"fp": "float", "u64": "hulk_u64", "u32": "hulk_u32"}[abi["ret"]]
    conv = {"stdcall": "HULK_STDCALL", "fastcall": "HULK_FASTCALL", "cdecl": "HULK_CDECL"}[abi["conv"]]
    params = ", ".join(("hulk_u32 a%d" % i) if with_names else "hulk_u32" for i in range(abi["args"])) or "void"
    return "%s %s hulk_xdk_%s(%s)" % (ret, conv, name, params)


def skeleton(rows, force=False):
    plat = [r for r in rows if r["group"] == "platform"]
    files = collections.OrderedDict((f, []) for f, _, _ in FILES)
    for r in plat:
        f = next(f for f, _, pred in FILES if pred(r["subsystem"], r["region"], r["names"][0]))
        files[f].append(r)
    names = collections.Counter(shim_name(r) for r in plat)
    assert all(v == 1 for v in names.values()), [k for k, v in names.items() if v > 1]
    gen = "tools/wine_shim.py --skeleton"
    hdr = ["// The XDK / XAPI / Bink imports of the native image: one stand-in per library function the tree calls.",
           "// First written by %s from build/native/shim-inventory.json (docs/wine-build.md \"Platform shim\");" % gen,
           "// maintained by hand from here on (the tool refuses to overwrite it).",
           "//",
           "// The tree calls a library function under many names (one per source that declares it, with its own",
           "// parameter types); tools/wine_link.py aliases every one of them to the hulk_xdk_<name> below by the",
           "// XBE address in its HULK_XDK_IMPORTS line. Each prototype keeps only what the callers' machine code",
           "// depends on: the calling convention, the stack bytes the callee pops, and the return register",
           "// (float: st0). Typed signatures come with the real backends (src/platform/sdl/, SDL3).",
           "#ifndef HULK_PLATFORM_SDL_XDK_IMPORTS_H",
           "#define HULK_PLATFORM_SDL_XDK_IMPORTS_H",
           "",
           '#include "xdk_shim.h"',
           "",
           "// One X(xbe address, name, subsystem) per import; the stand-in is hulk_xdk_<name>.",
           "#define HULK_XDK_IMPORTS(X) \\"]
    lines = []
    for f, title, _ in FILES:
        for r in sorted(files[f], key=lambda r: r["addr"]):
            lines.append("    X(%s, %s, \"%s\")" % (r["addr"], shim_name(r), title))
    hdr += [l + " \\" for l in lines[:-1]] + [lines[-1]] + ["", 'extern "C" {']
    for f, title, _ in FILES:
        if not files[f]:
            continue
        hdr += ["", "// --- %s (%s, %d functions)" % (title, f, len(files[f]))]
        for r in sorted(files[f], key=lambda r: r["addr"]):
            n = shim_name(r)
            note = "; ".join(r["abi"]["notes"])
            orig = ", ".join(r["names"])
            hdr.append(("%s;  // %s %s%s" % (_proto(n, r["abi"]), r["addr"], orig if orig != n else "",
                                             (" [%s]" % note) if note else "")).rstrip())
    hdr += ["", '}  // extern "C"', "", "#endif", ""]
    out = {"imports.h": "\n".join(hdr)}
    for f, title, _ in FILES:
        if not files[f]:
            continue
        body = ["// Stand-ins for %s: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle," % title,
                "// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by",
                "// %s; real implementations replace these one by one (docs/wine-build.md" % gen,
                "// \"Platform shim\"). Native builds only: tools/wine_link.py compiles and links this directory.",
                '#include "imports.h"', ""]
        for r in sorted(files[f], key=lambda r: r["addr"]):
            n = shim_name(r)
            zero = {"fp": "0.0f", "u64": "0", "u32": "0"}[r["abi"]["ret"]]
            body += ['extern "C" %s {' % _proto(n, r["abi"], True)]
            body += ["    " + " ".join("(void)a%d;" % i for i in range(r["abi"]["args"]))] if r["abi"]["args"] else []
            body += ['    HULK_XDK_TRACE("%s");' % n, "    return %s;" % zero, "}", ""]
        out[f] = "\n".join(body)
    os.makedirs(SKELETON, exist_ok=True)
    wrote = []
    for f, text in out.items():
        p = os.path.join(SKELETON, f)
        if os.path.exists(p) and not force:
            continue
        with open(p, "w") as fh:
            fh.write(text)
        wrote.append(f)
    return wrote, {f: len(v) for f, v in files.items()}


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--skeleton", action="store_true",
                    help="also write src/platform/sdl/xdk/ (imports.h + one stub file per subsystem) for files "
                         "that don't exist yet")
    ap.add_argument("--force", action="store_true", help="with --skeleton: overwrite existing files")
    opts = ap.parse_args(argv)
    pc = json.load(open(os.path.join(ROOT, "build/port/platform_calls.json")))
    by_addr = {}
    for k, v in pc["targets"].items():
        by_addr[int(v["address"], 16)] = (k.split("!")[-1], v["region"], v["subsystem"])
    by_name = {k.split("!")[-1]: v for k, v in pc["targets"].items()}
    data_sub = {}
    for k, v in pc["data_refs"].items():
        data_sub[k.split("!")[-1]] = v["subsystem"]
        m = ADDR_RX.search(k)
        if m:
            data_sub[int(m.group(1), 16)] = v["subsystem"]
    kernel = {int(a, 16): n.split(":")[-1] for a, n in pc["kernel_imports"].items()}
    spans = [(int(s["start"], 16), int(s["end"], 16), s["label"]) for s in pc["lib_spans_in_text"]]
    bind = json.load(open(os.path.join(NATIVE, "bindings.json")))["bindings"]
    rows = collections.defaultdict(lambda: {"names": set(), "symbols": 0, "references": 0})
    for line in open(os.path.join(NATIVE, "unbound.txt"), encoding="utf-8", errors="replace"):
        g, n, sym, dem = (line.rstrip("\n").split("\t") + [""])[:4]
        grp = next((v for k, v in GROUPS.items() if g.startswith(k)), None)
        if grp is None:
            continue
        b = bind.get(sym)
        a = int(b["addr"], 16) if b else None
        if a is None:
            m = ADDR_RX.search(sym)
            a = int(m.group(1), 16) if m else None
        name = simple_name(sym, dem)
        if grp == "library data":
            sub = data_sub.get(a) or data_sub.get(name) or data_sub.get(sym.lstrip("_"))
            if sub is None and a in kernel:
                sub, name = "kernel import slot", kernel[a]
            sub = sub or "library data (unsorted)"
            region = next((lab for lo, hi, lab in spans if a is not None and lo <= a < hi), "data")
            key = (grp, sub, region, a if a is not None else name)
        else:
            t = by_addr.get(a) if a is not None else None
            if t is None and name in by_name:
                v = by_name[name]
                t = (name, v["region"], v["subsystem"])
                a = int(v["address"], 16)
            if t is None and a in kernel:
                t = (kernel[a], "kernel", "kernel")
            if t is None:
                region = next((lab for lo, hi, lab in spans if a is not None and lo <= a < hi), "?")
                t = (name, region, "CRT / C++ runtime" if grp == "crt" else "unsorted")
            key = (grp, t[2], t[1], a if a is not None else name)
            name = t[0] if not t[0].startswith("FUN_") else name
        r = rows[key]
        r["names"].add(name)
        r["symbols"] += 1
        r["references"] += int(n)
        r.setdefault("refs", []).append([sym, dem])
    out = []
    for (grp, sub, region, a), r in sorted(rows.items(), key=lambda kv: (kv[0][0], kv[0][1], kv[0][2], str(kv[0][3]))):
        row = {"group": grp, "subsystem": sub, "region": region,
               "addr": "0x%08x" % a if isinstance(a, int) else None, "names": sorted(r["names"]),
               "symbols": r["symbols"], "references": r["references"], "refs": sorted(r["refs"])}
        if grp == "platform":
            row["abi"] = consensus(row["refs"])
        out.append(row)
    summ = collections.defaultdict(lambda: [0, 0, 0])
    for o in out:
        s = summ[(o["group"], o["subsystem"])]
        s[0] += 1
        s[1] += o["symbols"]
        s[2] += o["references"]
    # the imports src/platform/sdl/xdk/ already stands in for (their symbols are no longer in unbound.txt)
    hdr = os.path.join(SKELETON, "imports.h")
    shim = [l.split(",")[1].strip() for l in open(hdr) if l.strip().startswith("X(0x")] if os.path.exists(hdr) else []
    with open(os.path.join(NATIVE, "shim-inventory.json"), "w") as f:
        json.dump({"summary": [{"group": g, "subsystem": s, "functions": v[0], "symbols": v[1], "references": v[2]}
                               for (g, s), v in sorted(summ.items())], "rows": out,
                   "shim_imports": len(shim)}, f, indent=1)
    print("%-14s %-24s %9s %8s %6s" % ("group", "subsystem", "functions", "symbols", "refs"))
    for (g, s), v in sorted(summ.items()):
        print("%-14s %-24s %9d %8d %6d" % (g, s, v[0], v[1], v[2]))
    print("platform imports with a stand-in in src/platform/sdl/xdk/: %d (not listed above)" % len(shim))
    if opts.skeleton:
        wrote, per = skeleton(out, opts.force)
        print("src/platform/sdl/xdk/: wrote %s; functions per file %s" % (wrote or "nothing (files exist)", per))
    return 0


if __name__ == "__main__":
    sys.exit(main())
