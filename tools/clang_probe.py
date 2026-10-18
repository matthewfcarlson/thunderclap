#!/usr/bin/env python3
"""Clang probe: how far the merged source tree (build/tree/) is from compiling as a native program.

  build/venv/bin/python tools/clang_probe.py                 # snapshot (if missing), compile, classify, link probe
  build/venv/bin/python tools/clang_probe.py --snapshot      # refresh the snapshot of build/tree/ + include/ first
  build/venv/bin/python tools/clang_probe.py --configs msvc  # only some configurations (the link probe needs msvc)
  build/venv/bin/python tools/clang_probe.py --only src/game/global/CAction.cpp   # one TU, print its diagnostics

Everything goes to build/clang-probe/ (not tracked):

  snap/               a copy of build/tree/{src,include,manifest.json,report.json}, include/ and the data TUs
                      (build/data/src/), so a concurrent build_tree.py / migrate_data.py run can't change the
                      tree under the probe. `--snapshot` refreshes it (only do that after a complete tree build).
  cache/<config>/     per-TU result (diagnostics; objects for `msvc`), keyed by TU text + snapshot headers + flags
  report.json         the measurement: per configuration TUs compiling, diagnostics by category / producer,
                      example sites, source scans, the link probe
  undefined.txt       the link probe's undefined symbols with their group (demangled)

Configurations (all 32-bit x86 unless named 64; see docs/native-build.md):

  msvc    clang++ --target=i686-pc-windows-msvc -fms-extensions -fms-compatibility (clang-cl's dialect,
          MSVC 13.10 compatibility version), -c: what a clang build keeping MSVC's ABI needs. Its objects feed
          the link probe.
  gnu     --target=i686-unknown-linux-gnu -fms-extensions, -std=gnu++17, syntax only: the MSVC-only
          constructs that -fms-compatibility was hiding (two-phase lookup, missing typename, ...) and the
          Itanium-ABI / non-Windows differences.
  gnu64   the same for x86_64: what additionally breaks with 8-byte pointers (pointer <-> int casts, ...).
          The silent layout half of the 64-bit gap (char _pad[N], 4-byte offsets) is sized by the scans.
  All three carry the native build's flags (NATIVE / X87 below: include/compat/native.h force-included,
  -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks, x87 math on 32-bit, -fcheck-new off MS).
  *-poc   (not run by default) the three above on build/clang-probe/poc/, a patched copy of the snapshot: the
          2026-10-17 proof of concept of fix 1, which tools/gen_tree.py (tree_prelude.h, size_t spelling) and
          tools/gen_headers.py now do in the tree itself.

The link probe's undefined symbols before binding; tools/native_link.py binds them by address (fix 5a) and
reports what is left with the same groups (Grouper below).

The compiler is Homebrew LLVM (/opt/homebrew/opt/llvm/bin/clang++) if present, else `clang++` on PATH.
At most --jobs (default 4) compiler processes run at once.
"""
import argparse
import collections
import concurrent.futures
import csv
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "build/clang-probe")
SNAP = os.path.join(OUT, "snap")
CACHE = os.path.join(OUT, "cache")
LLVM = "/opt/homebrew/opt/llvm/bin"


def tool(name):
    p = os.path.join(LLVM, name)
    return p if os.path.exists(p) else shutil.which(name)


COMMON = ["-fno-color-diagnostics", "-fno-caret-diagnostics", "-fdiagnostics-show-option", "-ferror-limit=0",
          "-fexceptions", "-fcxx-exceptions", "-Wno-unused-value", "-Wno-unused-private-field",
          # warnings that point at behaviour clang may change (UB it exploits, lost bits)
          "-Wreturn-type", "-Wuninitialized", "-Wshift-overflow", "-Wnull-dereference", "-Wint-to-pointer-cast",
          "-Wpointer-to-int-cast", "-Wdangling", "-Wtautological-undefined-compare"]
# The native build's flags (docs/native-build.md fix 1), on every configuration: the compatibility header, no
# strict aliasing (`*(T*)&x` punning everywhere), wrapping signed overflow and kept null checks (lifted code
# relies on both), and on 32-bit x87 math (what the `volatile` rounding pins and the replay checkpoints
# assume; clang refuses -mfpmath=387 while SSE is enabled, hence -mno-sse). Non-MS targets null-check every
# `new` (-fcheck-new) because tree_prelude.h drops the `throw()` of operator new there.
# MSVC 7.1's dialect where clang has a switch for it (docs/native-build.md "After fix 4"): wchar_t is not a
# keyword (/Zc:wchar_t-, MSVC 7.1's default: sources `typedef unsigned short wchar_t;`; clang-cl /Zc:wchar_t-),
# `and`/`or`/`not` are identifiers (a stub's `virtual void or();`), `case 0xce85a963:` on an int converts as
# MSVC does instead of being a narrowing error, and `&T()` (the address of a temporary, which lives to the end
# of the full expression as under MSVC) is accepted.
DIALECT = ["-Xclang", "-fno-wchar", "-fno-operator-names", "-Wno-c++11-narrowing", "-Wno-address-of-temporary"]
NATIVE = ["-include", "compat/native.h", "-fno-strict-aliasing", "-fwrapv", "-fno-delete-null-pointer-checks"] + DIALECT
X87 = ["-mno-sse", "-mfpmath=387"]
CONFIGS = {
    "msvc": dict(flags=["--target=i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility",
                        "-fms-compatibility-version=13.10", "-std=c++14", "-O0", "-c"] + NATIVE + X87, obj=True),
    "gnu": dict(flags=["--target=i686-unknown-linux-gnu", "-fms-extensions", "-std=gnu++17", "-fsyntax-only"]
                + NATIVE + X87 + ["-fcheck-new"], obj=False),
    "gnu64": dict(flags=["--target=x86_64-unknown-linux-gnu", "-fms-extensions", "-std=gnu++17",
                         "-fsyntax-only"] + NATIVE + ["-fcheck-new"], obj=False),
}
# Proof-of-concept fixes (build/clang-probe/poc/, a patched copy of the snapshot; nothing in the repo changes):
#   compat.h, force-included: size_t, the placement operator new, type_info (what MSVC predeclares or <new> /
#   <typeinfo> would bring); include/gen/global.h: `enum script_state;` gets an underlying type; every
#   `operator new/delete(..., unsigned int ...)` declaration in the tree spells size_t (gen_tree's job).
POC = os.path.join(OUT, "poc")
COMPAT_H = """// GENERATED by tools/clang_probe.py: proof-of-concept native compatibility header (force-included)
#ifndef CLANG_PROBE_COMPAT_H
#define CLANG_PROBE_COMPAT_H
#if !defined(_MSC_VER)
typedef __SIZE_TYPE__ size_t;
#endif
#if defined(_MSC_VER)
class type_info;
namespace std { using ::type_info; }
#else
namespace std { class type_info; }
#endif
#endif
"""
for _c in ("msvc", "gnu", "gnu64"):
    CONFIGS[_c + "-poc"] = dict(CONFIGS[_c], root="poc", flags=CONFIGS[_c]["flags"] + ["-include", os.path.join(POC, "compat.h")],
                                obj=False)
    CONFIGS[_c + "-poc"]["flags"] = [f for f in CONFIGS[_c + "-poc"]["flags"] if f != "-c"] + ["-fsyntax-only"]
SIZE_T_RX = re.compile(r"\btypedef\s+unsigned(?:\s+int)?\s+size_t\s*;")
NEW_RX = re.compile(r"\b(operator\s+(?:new|delete)(?:\s*\[\s*\])?\s*\([^()]*?)\bunsigned(?:\s+int)?\b")


def make_poc():
    if os.path.exists(POC):
        shutil.rmtree(POC)
    os.makedirs(POC)
    with open(os.path.join(POC, "compat.h"), "w") as f:
        f.write(COMPAT_H)
    shutil.copytree(os.path.join(SNAP, "repo-include"), os.path.join(POC, "repo-include"))
    g = os.path.join(POC, "repo-include/gen/global.h")
    t = open(g).read()
    open(g, "w").write(re.sub(r"\benum (\w+);", r"enum \1 : int;", t))
    for sub in ("src", "include"):
        for dp, dns, fns in os.walk(os.path.join(SNAP, sub)):
            for fn in fns:
                src = os.path.join(dp, fn)
                dst = os.path.join(POC, os.path.relpath(src, SNAP))
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                t = open(src, encoding="latin1").read()
                t2 = SIZE_T_RX.sub("/* size_t: compat.h */", t)
                while True:
                    t3 = NEW_RX.sub(r"\1size_t", t2)
                    if t3 == t2:
                        break
                    t2 = t3
                open(dst, "w", encoding="latin1").write(t2)


DIAG_RE = re.compile(r"^(.*?):(\d+):(\d+): (fatal error|error|warning): (.*?)(?: \[([-\w,=#]+)\])?$")


# ---------------------------------------------------------------------------------------------
# Snapshot
def snapshot():
    tree = os.path.join(ROOT, "build/tree")
    if not os.path.exists(os.path.join(tree, "report.json")):
        sys.exit("build/tree/ has no report.json: run tools/build_tree.py first")
    if os.path.exists(SNAP):
        shutil.rmtree(SNAP)
    os.makedirs(SNAP)
    for sub in ("src", "include"):
        shutil.copytree(os.path.join(tree, sub), os.path.join(SNAP, sub))
    for fn in ("manifest.json", "report.json", "state.json"):
        shutil.copy2(os.path.join(tree, fn), os.path.join(SNAP, fn))
    shutil.copytree(os.path.join(ROOT, "include"), os.path.join(SNAP, "repo-include"))
    data = os.path.join(ROOT, "build/data/src")
    if os.path.isdir(data):
        shutil.copytree(data, os.path.join(SNAP, "data/src"))


def include_digest(root=SNAP):
    h = hashlib.sha1()
    for base in ("include", "repo-include"):
        for dp, dns, fns in sorted(os.walk(os.path.join(root, base))):
            dns.sort()
            for fn in sorted(fns):
                if fn.endswith(".h"):
                    p = os.path.join(dp, fn)
                    h.update(os.path.relpath(p, root).encode())
                    h.update(open(p, "rb").read())
    return h.hexdigest()


# ---------------------------------------------------------------------------------------------
# Compiling
def compile_one(cfg, rel, digest, clang):
    """Compile snap/<rel> under configuration cfg (cached). Returns the result dict."""
    spec = CONFIGS[cfg]
    base = os.path.join(OUT, spec["root"]) if spec.get("root") else SNAP
    src = os.path.join(base, rel)
    text = open(src, "rb").read()
    flags = spec["flags"] + COMMON
    key = hashlib.sha1(text + digest.encode() + repr(flags).encode() + clang.encode()).hexdigest()[:20]
    d = os.path.join(CACHE, cfg)
    os.makedirs(d, exist_ok=True)
    res_p = os.path.join(d, key + ".json")
    if os.path.exists(res_p):
        r = json.load(open(res_p))
        if not spec["obj"] or r["rc"] != 0 or os.path.exists(r["obj"]):
            return r
    obj = os.path.join(d, key + ".obj")
    cmd = [clang] + flags + ["-I" + os.path.join(base, "include"), "-I" + os.path.join(base, "repo-include"), src]
    if spec["obj"]:
        cmd += ["-o", obj + ".tmp"]
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", timeout=900)
        rc, out = p.returncode, p.stderr
    except subprocess.TimeoutExpired:
        rc, out = -1, "%s:1:1: fatal error: clang timed out" % src
    if spec["obj"] and rc == 0:
        os.replace(obj + ".tmp", obj)
    elif os.path.exists(obj + ".tmp"):
        os.unlink(obj + ".tmp")
    diags = []
    for line in out.splitlines():
        m = DIAG_RE.match(line)
        if m:
            f = os.path.relpath(m.group(1), base) if m.group(1).startswith(base) else m.group(1)
            diags.append([f, int(m.group(2)), m.group(4), m.group(5), m.group(6) or ""])
    r = {"tu": rel, "rc": rc, "diags": diags, "obj": obj if spec["obj"] and rc == 0 else None}
    if rc != 0 and not any(x[2] != "warning" for x in diags):
        r["raw"] = out[-2000:]
    with open(res_p, "w") as f:
        json.dump(r, f)
    return r


def tu_list():
    m = json.load(open(os.path.join(SNAP, "manifest.json")))
    return [t["path"] for t in m["tus"]]


def data_tus():
    base = os.path.join(SNAP, "data/src")
    out = []
    for dp, dns, fns in os.walk(base):
        for fn in fns:
            if fn.endswith(".cpp"):
                out.append(os.path.relpath(os.path.join(dp, fn), SNAP))
    return sorted(out)


def compile_all(cfg, paths, jobs, clang, digest):
    results = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        futs = {ex.submit(compile_one, cfg, p, digest, clang): p for p in paths}
        for i, f in enumerate(concurrent.futures.as_completed(futs), 1):
            results[futs[f]] = f.result()
            if i % 500 == 0 and sys.stderr.isatty():
                print("  %s: %d/%d" % (cfg, i, len(paths)), file=sys.stderr, flush=True)
    return results


# ---------------------------------------------------------------------------------------------
# Classification
# (category, config filter or None, severity: e/w, regex on the message). First match wins.
RULES = [
    # declarations the merge leaves inconsistent
    ("extern-c-redeclared", "e", r"^conflicting types for|with C language linkage conflicts with declaration|"
                                 r"^redeclaration of .* with a different type|has a different language linkage"),
    ("calling-convention-redeclared", "e", r"here was previously declared"),
    ("duplicate-definition", "e", r"^redefinition of"),
    # MSVC-isms
    ("enum-forward-declaration", "e", r"forward references to '.*' types"),
    ("msvc-template-spec-syntax", "e", r"template specialization requires 'template<>'"),
    ("dependent-base-lookup", "e", r"^unknown type name 'Fn'|^no matching constructor for initialization of '(Closure|Method)|"
                                   r"cannot initialize .* with an (rvalue|expression) of type '?Closure"),
    ("size_t-not-predeclared", "e", r"^unknown type name 'size_t'"),
    ("size_t-typedef-32bit", "e", r"typedef redefinition with different types \('unsigned int' vs 'unsigned long'\)"),
    ("placement-new-undeclared", "e", r"non-allocating placement new expression|takes type size_t"),
    ("exception-spec-mismatch", "e", r"exception specification"),
    ("typeid-needs-typeinfo", "e", r"include <typeinfo>"),
    ("msvc-for-scope", "e", r"^use of undeclared identifier '[ijk]'"),
    ("case-narrowing", "e", r"^case value evaluates to"),
    ("goto-over-initialization", "e", r"cannot jump from this goto"),
    ("register-keyword", "e", r"'register' storage class"),
    ("type-defined-in-return-type", "e", r"cannot be defined in the result type"),
    ("address-of-temporary", "e", r"taking the address of a temporary"),
    ("other-error", "e", r""),
    # warnings that matter
    ("64bit-pointer-int-cast", "w", r"cast to smaller integer type|from smaller integer type"),
    ("ub-null-this-or-reference-check", "w", r"cannot be null in well-defined C\+\+ code|"
                                            r"will always evaluate to|address of .* (not )?equal to a null pointer"),
    ("ub-missing-return", "w", r"does not return a value"),
    ("ub-uninitialized", "w", r"is uninitialized when used"),
    ("ub-array-bounds", "w", r"past the end of the array"),
    ("ub-unsequenced", "w", r"unsequenced modification"),
    ("ub-pure-virtual-in-ctor", "w", r"call to pure virtual member function"),
    ("ub-vptr-memaccess", "w", r"vtable pointer will be overwritten|non-trivially copyable type"),
    ("calling-convention-cast", "w", r"incompatible calling conventions"),
    ("alloc-size", "w", r"allocation of insufficient size"),
    ("undefined-internal", "w", r"has internal linkage but is not defined"),
    ("format-string", "w", r"^format specifies type"),
    ("writable-strings", "w", r"conversion from string literal"),
    ("ms-ext-explicit-ctor-call", "w", r"explicit constructor calls are a Microsoft extension"),
    ("ms-ext-template-lookup", "w", r"dependent bases of class templates is a Microsoft extension"),
    ("ms-ext-goto", "w", r"goto statement to its label is a Microsoft extension"),
    ("ms-ext-enum-forward", "w", r"forward references to .* types are a Microsoft extension"),
    ("ms-ext-exception-spec", "w", r"exception specification"),
    ("ms-ext-other", "w", r"Microsoft extension"),
    ("ignored-calling-convention", "w", r"calling convention is not supported for this target"),
    ("ignored-declspec", "w", r"__declspec attribute .* is not supported"),
    ("other-warning", "w", r""),
]
RULES = [(c, sev, re.compile(rx)) for c, sev, rx in RULES]
NOISE = {"ignored-calling-convention", "ignored-declspec", "other-warning", "format-string", "writable-strings"}

# what each category is and how it gets fixed (docs/native-build.md has the long form)
FIXES = {
    "extern-c-redeclared": ("gen_tree", "wrapped sources (namespace fn_<addr>) redeclare the same extern \"C\" name "
                            "or global with another type; MSVC 7.1 accepts that across namespaces, clang does not"),
    "calling-convention-redeclared": ("gen_tree", "same, the declarations differ in calling convention"),
    "duplicate-definition": ("sources", "the same extern \"C\" function defined by two clone sources "
                             "(donor names) in one TU"),
    "enum-forward-declaration": ("include/gen", "`enum script_state;` without an underlying type in gen/global.h"),
    "msvc-template-spec-syntax": ("sources", "explicit specialization of a template member without `template <>`"),
    "dependent-base-lookup": ("sources", "unqualified use of a dependent base's typedef (`Fn`) in Closure/Method "
                              "stubs: two-phase lookup"),
    "size_t-not-predeclared": ("compat header", "`size_t` used without a declaration (MSVC predeclares it)"),
    "size_t-typedef-32bit": ("gen_tree", "sources' own `typedef unsigned int size_t;` (hoisted into common.h)"),
    "placement-new-undeclared": ("compat header", "placement/global operator new declared with `unsigned int` "
                                 "or not at all"),
    "exception-spec-mismatch": ("compat header", "operator new/delete declared with and without `throw()`"),
    "typeid-needs-typeinfo": ("compat header", "`typeid` without <typeinfo>"),
    "msvc-for-scope": ("sources", "a for-loop variable used after the loop (/Zc:forScope-)"),
    "case-narrowing": ("sources", "`case 0xce85a963:` on an `int` switch (C++11 narrowing)"),
    "goto-over-initialization": ("sources", "goto past a variable's initialization (asm-shaped control flow)"),
    "register-keyword": ("sources", "`register` (removed in C++17)"),
    "type-defined-in-return-type": ("sources", "a struct defined in a function's return type"),
    "address-of-temporary": ("sources", "`&T()` (MSVC extension)"),
}


def classify(sev, msg):
    s = "w" if sev == "warning" else "e"
    for cat, csev, rx in RULES:
        if csev == s and rx.search(msg):
            return cat
    return "other-error" if s == "e" else "other-warning"


class Manifest:
    def __init__(self):
        m = json.load(open(os.path.join(SNAP, "manifest.json")))
        self.tus = {t["path"]: t for t in m["tus"]}
        self.verified = {}          # addr -> (tu path, kind, mode)
        for t in m["tus"]:
            for b in t["blocks"]:
                self.verified[int(b["addr"], 16)] = (t["path"], b["kind"], b["mode"], b["src"])

    def producer(self, f, line):
        """(producer family, source file or None) for a diagnostic location."""
        if f.startswith("repo-include/gen/"):
            return "include/gen", f[len("repo-"):]
        if f.startswith("repo-include/decls/data/"):
            return "include/decls/data", f[len("repo-"):]
        if f.startswith("repo-include/"):
            return "include/decls", f[len("repo-"):]
        if f.startswith("include/"):
            return "tree header (gen_tree hoist)", "build/tree/" + f
        t = self.tus.get(f)
        if t is None:
            return "other", f
        for b in t["blocks"]:
            lo, hi = b["lines"]
            if lo <= line <= hi:
                return "%s %s" % (b["kind"], b["mode"]), b["src"]
        return "TU declarations (gen_tree merge)", None


def analyse(results, man, tus):
    out = {}
    for cfg, res in results.items():
        cats = collections.defaultdict(lambda: {"occurrences": 0, "sites": set(), "tus": set(), "sources": set(),
                                                "producers": collections.Counter(), "examples": []})
        failing = {}
        for p in tus:
            r = res[p]
            tucats = set()
            for f, line, sev, msg, opt in r["diags"]:
                cat = classify(sev, msg)
                c = cats[cat]
                c["occurrences"] += 1
                site = (f, line)
                if site not in c["sites"]:
                    c["sites"].add(site)
                    prod, src = man.producer(f, line)
                    c["producers"][prod] += 1
                    if src and src.startswith(("matches/", "equivalent/")):
                        c["sources"].add(src)
                    if len(c["examples"]) < 4:
                        c["examples"].append({"at": "%s:%d" % (f, line), "producer": prod, "source": src,
                                              "message": msg})
                c["tus"].add(p)
                if sev != "warning":
                    tucats.add(cat)
            if r["rc"] != 0:
                failing[p] = sorted(tucats) or ["no-diagnostic"]
        sole = collections.Counter(v[0] for v in failing.values() if len(v) == 1)
        any_ = collections.Counter(c for v in failing.values() for c in v)
        layers = collections.defaultdict(lambda: [0, 0])
        for p in tus:
            lay = man.tus[p]["layer"]
            layers[lay][1] += 1
            layers[lay][0] += res[p]["rc"] == 0
        out[cfg] = {
            "tus": len(tus),
            "tus_compiling": len(tus) - len(failing),
            "by_layer": {k: {"compiling": v[0], "tus": v[1]} for k, v in sorted(layers.items())},
            "failing_tus_by_category": dict(any_.most_common()),
            "failing_tus_with_only_this_category": dict(sole.most_common()),
            "categories": {k: {"occurrences": v["occurrences"], "sites": len(v["sites"]), "tus": len(v["tus"]),
                               "sources": len(v["sources"]), "producers": dict(v["producers"].most_common()),
                               "examples": v["examples"]}
                           for k, v in sorted(cats.items(), key=lambda kv: -len(kv[1]["sites"]))},
            "failing": failing,
        }
    return out


# ---------------------------------------------------------------------------------------------
# Source scans (things no diagnostic reports: ABI and layout assumptions, UB the optimizer may exploit)
SCANS = [
    ("vptr-store", r"\*\s*\(\s*(?:void|int|unsigned int|unsigned)\s*\*\*?\s*\)\s*\(?\s*this\s*\)?\s*=|"
                   r"\b\w*vptr\w*\s*=[^=]|\b\w*vtbl\w*\s*=[^=]|\bvtable\w*\s*=[^=]",
     "hand-written vftable pointer stores (`*(void**)this = &g_vftable_x`, `m_vptr = ...`)"),
    ("vftable-symbol", r"\bg_vftable\w*|\bvftable_\w+|\w*Vtable_[0-9a-f]+\b",
     "references to vftables by symbol (the Xbox's own vftable, resolved only by address)"),
    ("absolute-address-cast", r"\(\s*[\w:]+(?:\s*\*)+\s*\)\s*0x(?:00)?(?:[1-3][0-9a-f]{5}|[45][0-9a-f]{5})\b",
     "integer literals in the XBE's code/data range cast to pointers"),
    ("function-pointer-from-int", r"\(\s*\w[\w\s\*]*\(\s*(?:__\w+\s*)?\*\s*\)\s*\([^)]*\)\s*\)\s*0x[0-9a-f]{5,}",
     "function pointers made from integers"),
    ("type-pun-cast", r"\(\s*\*\s*\(\s*[\w:]+(?:\s+[\w:]+)*\s*\*\s*\)\s*&",
     "`*(T*)&x` type punning (strict aliasing): -fno-strict-aliasing"),
    ("explicit-padding", r"\bchar\s+_?pad\w*\s*\[",
     "explicit `char pad[N]` layout (assumes 32-bit pointers and MSVC packing)"),
    ("stub-virtual", r"\bvirtual\b(?!\s*~)", "virtual members declared in TU-local stub classes (slot order is the "
                                             "MS ABI's: an Itanium target reorders/doubles destructor slots)"),
    ("stub-virtual-dtor", r"\bvirtual\s*~", "virtual destructors in TU-local stubs (1 slot in MS ABI, 2 in Itanium)"),
    ("manual-virtual-call", r"\b\w*(?:vptr|vtbl|vtable|vft)\w*\s*(?:\[|->\s*\w+\s*\()|"
                            r"\(\s*\*\s*\(\s*\w+\s*\*\*\*?\s*\)\s*\w+\s*\)\s*\[",
     "virtual calls through a hand-written vftable (`vptr[5]`, `(*(void***)p)[5]`)"),
    ("ms-int64", r"\b__int64\b", "`__int64`"),
    ("ms-calling-convention", r"\b__(?:thiscall|fastcall|stdcall)\b", "explicit calling conventions"),
    ("ms-declspec", r"__declspec\s*\(", "`__declspec(...)`"),
    ("inline-asm", r"\b__asm\b|\b_asm\b|\basm\s*\(", "inline assembly"),
    ("volatile", r"\bvolatile\b", "`volatile` (x87 rounding pins in lifted code)"),
    ("goto", r"\bgoto\b", "`goto`"),
    ("stack-cookie", r"__security_check_cookie|__security_cookie", "/GS stack cookie calls written out"),
    ("rtdynamiccast-by-address", r"\bFUN_00344e74\b", "`__RTDynamicCast` called by address with RTTI descriptors"),
    ("seh", r"\b__try\b|\b__except\b|\b__finally\b", "structured exception handling"),
]
SCANS = [(k, re.compile(rx), d) for k, rx, d in SCANS]


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return "\n".join(l.split("//")[0] for l in text.splitlines())


def scans(man, tus):
    res = {k: {"what": d, "occurrences": 0, "tus": 0, "sources": set(), "example": None} for k, _, d in SCANS}
    for p in tus:
        lines = open(os.path.join(SNAP, p), errors="replace").read().splitlines()
        seen = set()
        for i, raw in enumerate(lines, 1):
            line = raw.split("//")[0]
            for k, rx, _ in SCANS:
                n = len(rx.findall(line))
                if n:
                    r = res[k]
                    r["occurrences"] += n
                    if k not in seen:
                        r["tus"] += 1
                        seen.add(k)
                    prod, src = man.producer(p, i)
                    if src:
                        r["sources"].add(src)
                    if r["example"] is None:
                        r["example"] = "%s:%d: %s" % (p, i, line.strip()[:120])
    for r in res.values():
        r["sources"] = len(r["sources"])
    # include/gen layout: explicit pads and 4-byte-pointer fields
    gen = os.path.join(SNAP, "repo-include/gen")
    pads = ptrs = 0
    for fn in os.listdir(gen):
        if fn.endswith(".h"):
            t = open(os.path.join(gen, fn)).read()
            pads += len(re.findall(r"char _pad_\w+\[", t))
            ptrs += len(re.findall(r"^\s+\w[\w:<>, ]*\*\s*f_[0-9a-f]+;", t, flags=re.M))
    res["include-gen-layout"] = {"what": "include/gen: `char _pad_XX[N]` gaps and pointer-typed `f_XX` fields at "
                                         "32-bit offsets", "pads": pads, "pointer_fields": ptrs}
    return res


# ---------------------------------------------------------------------------------------------
# Link probe
LIB_SPANS = [(0x208b9c, 0x212bb0), (0x3440e0, 0x356bf0), (0x35a7b0, 0x35be88), (0x364840, 0x3f2be0)]
CRT_NAMES = set("""memcpy memset memmove memcmp strlen strcpy strncpy strcat strcmp strncmp stricmp _stricmp strnicmp
_strnicmp strchr strrchr strstr strtok sprintf _snprintf vsprintf _vsnprintf sscanf printf atoi atof atol strtol strtoul
strtod toupper tolower isspace isdigit isalpha malloc free calloc realloc fopen fclose fread fwrite fseek ftell fprintf
fputs sqrt sqrtf sin sinf cos cosf tan tanf atan atanf atan2 atan2f asin asinf acos acosf exp expf log logf log10 pow
powf fabs fabsf floor floorf ceil ceilf fmod fmodf ldexp frexp modf _isnan _finite _ftol _ftol2 _CIcos _CIsin _CIsqrt
_CIatan2 _CIacos _CIasin _CIpow _CIfmod _CIexp _CIlog _alldiv _allmul _allrem _aulldiv _aullrem _allshl _allshr
_aullshr __fltused _fltused _purecall __purecall atexit _atexit _onexit rand srand qsort bsearch abs labs time clock
_chkstk __chkstk _except_handler3 __CxxFrameHandler __CxxFrameHandler3 _CxxThrowException __CxxThrowException
__security_check_cookie __security_cookie ___security_cookie __RTDynamicCast ___RTDynamicCast __RTtypeid
__RTCastToVoid __ehvec_ctor __ehvec_dtor _wcslen wcslen wcscpy _itoa itoa _ltoa _ultoa __ceil_default""".split())
PLATFORM_RX = re.compile(r"^(D3D|Direct3D|IDirect3D|XG|DirectSound|IDirectSound|DSound|CDirectSound|Bink|XInput|"
                         r"XGet|XSet|XLaunch|XMount|XUnmount|XFind|XCreate|XDelete|XCalculate|XInit|XOpen|XQuery|XAuto|"
                         r"XapiGet|XDevice|Nt|Rtl|Ke|Ex[A-Z]|Hal|Mm|Ob|Io|Avp|Xe|"
                         r"CreateFile|ReadFile|WriteFile|CloseHandle|SetFilePointer|GetFileSize|CreateThread|"
                         r"CreateSemaphore|ReleaseSemaphore|WaitFor|Sleep|CreateFiber|SwitchToFiber|ConvertThreadToFiber|"
                         r"DeleteFiber|CreateEvent|SetEvent|ResetEvent|QueryPerformance|GetTickCount|GetLocalTime|"
                         r"GlobalMemoryStatus|HeapAlloc|HeapFree|HeapCreate|HeapSize|OutputDebugString|InitializeCriticalSection|"
                         r"EnterCriticalSection|LeaveCriticalSection|DeleteCriticalSection|ResumeThread|SuspendThread|"
                         r"GetCurrentThread|SetThreadPriority|ExitThread|GetLastError|GetOverlappedResult|"
                         r"CreateDirectory|FindFirstFile|FindNextFile|FindClose|DeleteFile|GetDiskFreeSpace|"
                         r"MoveFile|GetFileAttributes|VirtualAlloc|VirtualFree|SetVerticalBlankCallback)")
ADDR_RX = re.compile(r"(?:^|[^0-9A-Za-z])(FUN|DAT|thunk_FUN|PTR|LAB|g|s|flt|dbl|fltTbl|tbl|ptrTbl|unk|struct|zero)_"
                     r"(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")


def nm(objs):
    """{obj: (defined set, undefined set)} via llvm-nm, batched."""
    out = {}
    exe = tool("llvm-nm")
    for i in range(0, len(objs), 200):
        batch = objs[i:i + 200]
        p = subprocess.run([exe, "--no-sort"] + batch, capture_output=True, text=True, errors="replace")
        cur = None
        for line in p.stdout.splitlines():
            if line.endswith(":") and line[:-1] in batch:
                cur = line[:-1]
                out[cur] = (set(), set())
                continue
            if not line.strip() or cur is None:
                continue
            parts = line.split()
            if len(parts) == 2 and parts[0] == "U":
                out[cur][1].add(parts[1])
            elif len(parts) == 3 and parts[1] in "TDBRCVW":      # external definitions only (lowercase = local)
                out[cur][0].add(parts[2])
        if len(batch) == 1 and batch[0] not in out:
            out[batch[0]] = (set(), set())
    return out


def undname(names):
    exe = tool("llvm-undname")
    names = list(names)
    if not exe or not names:
        return {n: n for n in names}
    p = subprocess.run([exe], input="\n".join(names) + "\n", capture_output=True, text=True, errors="replace")
    outs = [l for l in p.stdout.splitlines()]
    res = {}
    # llvm-undname echoes each input line followed by its demangling
    it = iter(outs)
    for line in it:
        if line in names and line not in res:
            try:
                res[line] = next(it)
            except StopIteration:
                res[line] = line
    for n in names:
        res.setdefault(n, n)
    return res


G_CRT = "CRT / C++ runtime"
G_PLAT = "platform import (XDK / kernel / D3D / DSound / XPP / Bink)"
G_LIBADDR = "library code by address (CRT/XAPI span, unnamed)"
G_BIND = "function: verified and compiled, referenced under another symbol (bind by address)"
G_FAIL = "function: verified, but its TU fails under clang"
G_UNVER = "function: not yet verified"
G_STUB = "function by invented/stub name, no address in the symbol (bound by relocation only)"
G_VT = "vftable / RTTI by address (hand-written vptr stores, RTTI descriptors)"
G_DCPP = "data: emitted item referenced under a C++ (namespaced/typed) name"
G_DLIB = "data: library (CRT/XDK) data"
G_DOUT = "data: not an emitted item (outside the inventory / interior)"


class Grouper:
    """The link probe's groups for undefined symbols (also used by tools/native_link.py)."""

    def __init__(self, man, ok_tus):
        self.man, self.ok_tus = man, ok_tus
        funcs = {}
        with open(os.path.join(ROOT, "build/functions.csv")) as f:
            for r in csv.DictReader(f):
                funcs[int(r["address"], 16)] = r["name"]
        self.by_name = collections.defaultdict(list)
        for a, n in funcs.items():
            self.by_name[n].append(a)
        self.plat = {}
        pc = os.path.join(ROOT, "build/port/platform_calls.json")
        if os.path.exists(pc):
            for k, v in json.load(open(pc))["targets"].items():
                crt = v["subsystem"].startswith(("CRT", "C++"))
                self.plat[int(v["address"], 16)] = "crt" if crt else "platform"
                self.plat[k.split("!")[-1]] = "crt" if crt else "platform"
        self.inv = {}
        dj = os.path.join(ROOT, "config/data.json")
        if os.path.exists(dj):
            for it in json.load(open(dj))["items"]:
                self.inv[int(it["addr"], 16)] = it
        self.inv_addrs = sorted(self.inv)

    def data_item(self, a):
        import bisect
        i = bisect.bisect_right(self.inv_addrs, a) - 1
        if i >= 0:
            it = self.inv[self.inv_addrs[i]]
            if a < self.inv_addrs[i] + it["size"] + it.get("pad", 0):
                return it
        return None

    @staticmethod
    def base_name(s, d):
        if not s.startswith("?"):
            b = s[1:] if s.startswith(("_", "@")) else s
            return re.sub(r"@\d+$", "", b)
        q = re.search(r"([\w:<>~,` ]+?)\(", d)
        qn = q.group(1).split()[-1] if q else s
        return re.sub(r"^fn_[0-9a-f]{8}::", "", qn)

    def func_group(self, a):
        if any(lo <= a < hi for lo, hi in LIB_SPANS):
            return {"platform": G_PLAT, "crt": G_CRT}.get(self.plat.get(a), G_LIBADDR)
        if a in self.man.verified:
            return G_FAIL if self.man.verified[a][0] not in self.ok_tus else G_BIND
        return G_UNVER

    def group(self, s, d):
        """(group, address match or None) of one undefined symbol s (demangled d)."""
        b = self.base_name(s, d)
        short = b.split("::")[-1]
        m = ADDR_RX.search(s if s.startswith("?") else "_" + s.lstrip("_@"))
        plat = self.plat
        if short in CRT_NAMES or "_" + short in CRT_NAMES or plat.get(short) == "crt" or s.startswith((
                "??2@", "??3@", "??_U@", "??_V@", "??_7type_info", "??_Etype_info", "?terminate@@", "??1type_info")):
            g = G_CRT
        elif plat.get(short) == "platform" or (PLATFORM_RX.match(short) and not m):
            g = G_PLAT
        elif re.search(r"vftable|Vtable|vtbl", s, re.I) and not (m and m.group(1) in ("FUN", "thunk_FUN")):
            g = G_VT
        elif m and m.group(1) in ("FUN", "thunk_FUN", "LAB"):
            g = self.func_group(int(m.group(2), 16))
        elif m:
            it = self.data_item(int(m.group(2), 16))
            if it is None:
                g = G_DOUT
            elif it["kind"].startswith(("vtable", "rtti")):
                g = G_VT
            elif (it.get("object") or "").startswith("library/") or it["kind"] in ("kernel_thunks", "library_section"):
                g = G_DLIB
            elif s.startswith("?"):
                g = G_DCPP
            else:
                g = G_DOUT
        else:
            hit = self.by_name.get(b)
            if hit:
                g = self.func_group(next((a for a in hit if a in self.man.verified), hit[0]))
            else:
                g = G_STUB
        return g, m


def group_undefined(undef, refs, man, ok_tus, dem=None):
    """{symbol: group} for undefined symbols."""
    gr = Grouper(man, ok_tus)
    dem = dem or undname(sorted(undef))
    return {s: gr.group(s, dem.get(s, s))[0] for s in undef}


def link_probe(results, man, tus):
    res = results.get("msvc")
    if not res:
        return None
    objs = {p: r["obj"] for p, r in res.items() if r.get("obj")}
    syms = nm(sorted(objs.values()))
    defined = set()
    for d, u in syms.values():
        defined |= d
    refs = collections.Counter()
    for d, u in syms.values():
        for s in u:
            refs[s] += 1
    undef = {s for s in refs if s not in defined and not s.startswith(("@feat", "__imp_"))}
    ok_tus = {p for p in tus if res[p]["rc"] == 0}
    dem = undname(sorted(undef))
    gr = Grouper(man, ok_tus)
    groups = collections.defaultdict(lambda: {"symbols": 0, "references": 0, "examples": []})
    rows = []
    bind_why = collections.Counter()
    bind_named = 0
    def_addrs = {m.group(2).lower() for x in defined for m in [ADDR_RX.search(x if x.startswith("?") else "_" + x.lstrip("_@"))]
                 if m and m.group(1) in ("FUN", "thunk_FUN")}
    for s in sorted(undef):
        d = dem[s]
        g, m = gr.group(s, d)
        G = groups[g]
        G["symbols"] += 1
        if m:
            G.setdefault("addresses", set()).add(m.group(2).lower())
        if g == G_BIND:
            why = ("declared inside a wrapped namespace fn_<addr>" if re.search(r"@fn_00[0-9a-f]{6}@", s) else
                   "C linkage, defined with C++ linkage or another name" if not s.startswith("?") else
                   "free C++ function, signature or linkage differs" if re.match(r"\?[^@?]+@@[YJ]", s) else
                   "declared as a member of a caller's stub class")
            bind_why[why] += 1
            if m and (m.group(2).lower() in def_addrs):
                bind_named += 1
        G["references"] += refs[s]
        if re.search(r"@fn_00[0-9a-f]{6}@", s):
            G["in_wrapped_namespace"] = G.get("in_wrapped_namespace", 0) + 1
        if len(G["examples"]) < 6:
            G["examples"].append(d if d != s else s)
        rows.append((g, refs[s], s, d))
    with open(os.path.join(OUT, "undefined.txt"), "w") as f:
        for g, n, s, d in sorted(rows):
            f.write("%s\t%d\t%s\t%s\n" % (g, n, s, d))
    data_ok = sum(1 for p, r in res.items() if p.startswith("data/") and r["rc"] == 0)
    data_n = sum(1 for p in res if p.startswith("data/"))
    return {"objects": len(objs), "code_tus": len(ok_tus), "data_tus": "%d / %d" % (data_ok, data_n),
            "defined_symbols": len(defined), "undefined_symbols": len(undef),
            "undefined_references": sum(refs[s] for s in undef),
            "bind_by_address": {"why": dict(bind_why.most_common()),
                                "address_name_also_defined_under_an_address_name": bind_named},
            "groups": dict(sorted(((k, dict(v, addresses=len(v.get("addresses", ())))) for k, v in groups.items()),
                                  key=lambda kv: -kv[1]["symbols"]))}


def jsonable(o):
    if isinstance(o, set):
        return sorted(o)
    raise TypeError(type(o))


def summary(rep):
    print("clang: %s" % rep["clang"])
    for cfg, r in rep["configs"].items():
        print("\n== %s: %d / %d TUs compile (%s)" % (cfg, r["tus_compiling"], r["tus"],
              ", ".join("%s %d/%d" % (k, v["compiling"], v["tus"]) for k, v in r["by_layer"].items())))
        print("  %-34s %6s %6s %5s %5s %5s  %s" % ("category", "occ", "sites", "TUs", "fail", "only", "producers"))
        for k, v in r["categories"].items():
            if k in NOISE and cfg != "gnu64":
                continue
            print("  %-34s %6d %6d %5d %5d %5d  %s" % (
                k, v["occurrences"], v["sites"], v["tus"], r["failing_tus_by_category"].get(k, 0),
                r["failing_tus_with_only_this_category"].get(k, 0),
                ", ".join("%s %d" % kv for kv in list(v["producers"].items())[:3])))
    lp = rep.get("link_probe")
    if lp:
        print("\n== link probe (msvc objects: %d code TUs, data TUs %s): %d undefined symbols, %d references" % (
            lp["code_tus"], lp["data_tus"], lp["undefined_symbols"], lp["undefined_references"]))
        print("  %-86s %7s %7s %7s %6s" % ("group", "symbols", "refs", "in fn_", "addrs"))
        for k, v in lp["groups"].items():
            print("  %-86s %7d %7d %7d %6d" % (k, v["symbols"], v["references"], v.get("in_wrapped_namespace", 0),
                                              v["addresses"]))
        print("  bind by address: %s; %d also defined under an address name" % (
            lp["bind_by_address"]["why"], lp["bind_by_address"]["address_name_also_defined_under_an_address_name"]))
    print("\nscans:")
    for k, v in rep["scans"].items():
        if "occurrences" in v:
            print("  %-26s %6d in %4d TUs, %5d sources" % (k, v["occurrences"], v["tus"], v["sources"]))
        else:
            print("  %-26s %s" % (k, {a: b for a, b in v.items() if a != "what"}))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--snapshot", action="store_true")
    ap.add_argument("--configs", default="msvc,gnu,gnu64",
                    help="also msvc-poc,gnu-poc,gnu64-poc (the 2026-10-17 proof of concept; fix 1 is in the tree now)")
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--only")
    a = ap.parse_args(argv)
    clang = tool("clang++")
    cfgs = a.configs.split(",")
    if a.snapshot or not os.path.exists(os.path.join(SNAP, "manifest.json")):
        snapshot()
    if any(CONFIGS[c].get("root") for c in cfgs) and (a.snapshot or not os.path.exists(os.path.join(POC, "compat.h"))):
        make_poc()
    digests = {None: include_digest(SNAP)}
    if os.path.exists(os.path.join(POC, "compat.h")):
        digests["poc"] = include_digest(POC) + hashlib.sha1(COMPAT_H.encode()).hexdigest()

    def digest(cfg):
        return digests[CONFIGS[cfg].get("root")]
    if a.only:
        for cfg in cfgs:
            r = compile_one(cfg, a.only, digest(cfg), clang)
            print("== %s rc=%d" % (cfg, r["rc"]))
            for d in r["diags"]:
                print("  %s:%d: %s: %s [%s]" % tuple(d))
        return
    tus = tu_list()
    results = {}
    for cfg in cfgs:
        paths = tus + (data_tus() if CONFIGS[cfg]["obj"] else [])
        results[cfg] = compile_all(cfg, paths, a.jobs, clang, digest(cfg))
        ok = sum(1 for p in tus if results[cfg][p]["rc"] == 0)
        print("%s: %d / %d TUs compile" % (cfg, ok, len(tus)), flush=True)
    man = Manifest()
    rep = {"clang": subprocess.run([clang, "--version"], capture_output=True, text=True).stdout.splitlines()[0],
           "flags": {k: v["flags"] + COMMON for k, v in CONFIGS.items() if k in results},
           "snapshot": {"tree_report": {k: json.load(open(os.path.join(SNAP, "report.json")))["generator"][k]
                                        for k in ("tu_files", "verified_functions", "modes")}},
           "configs": analyse(results, man, tus),
           "scans": scans(man, tus),
           "link_probe": link_probe(results, man, tus)}
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1, default=jsonable)
    summary(rep)


if __name__ == "__main__":
    main()
