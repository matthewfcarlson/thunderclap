#!/usr/bin/env python3
"""Hybrid build: redirect original XBE functions to our compiled code (docs/hybrid-build.md).

  tools/patch_xbe.py [--matches N|all] [--equivalent] [--only 0xADDR,...] [--exclude FILE]
                     [--set FILE] [--out build/hybrid/default.xbe] [--jobs 8] [--empty-section]

Steps:
  1. compile each source (matches/0xADDR.cpp, equivalent/0xADDR.cpp) with MSVC 7.1; objects are cached
     in build/hybrid/obj/ by source hash;
  2. bind every symbol our object references to an original address, with tools/equiv.py's binding
     (explicit `// equiv-map:` > content > names > pairing with the original);
  3. classify: `identical` (linked at the original address, our bytes equal the original's), `local`
     (calls helpers defined in our own object), `equivalent` (from equivalent/); reject anything that would
     reach an unresolved symbol or a private copy of a writable global;
  4. lay every accepted object out in a new section `.hybrid` after the last section, link it there with
     equiv.Ours.link, and write `jmp ours` over each original entry;
  5. rebuild the header: insert one section header, append the section name and its page refcounts,
     recompute the image size and the section digests.

The output XBE is padded to a fixed size (--pad) so that tools/hybrid_run.py can rewrite it in place
inside the packed disc image. A manifest (*.json next to the XBE) lists every patched function.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import sys
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv  # noqa: E402
from compare import CompileError, DEFAULT_FLAGS, compile_obj, strip_padding  # noqa: E402

ROOT = equiv.ROOT
XBE_PATH = equiv.XBE_PATH
OUT_DIR = os.path.join(ROOT, "build/hybrid")
OBJ_DIR = os.path.join(OUT_DIR, "obj")
SEC_HDR = 56
SECTION_NAME = b".hybrid\0"
SEC_FLAGS = 0x7            # writable | preload | executable
PAD_SIZE = 16 << 20        # output XBE file size (see hybrid_run.py: in-place disc update)

# Compiler-generated EH helpers: always link our own copy (names like __ehhandler$?FUN_00123456@@...
# would otherwise bind by the address in the name to the function itself).
LOCAL_PREFIXES = ("__ehhandler$", "__ehfuncinfo$", "__unwindfunclet$", "__catch$", "__tryblocktable$",
                  "__unwindtable$", "__catchsym$", "$SG", "$L")


# ---------------------------------------------------------------------------------------------
# Sources
def source_set(kind):
    d = os.path.join(ROOT, kind)
    out = []
    for f in sorted(os.listdir(d)):
        m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", f)
        if m:
            out.append((int(m.group(1), 16), os.path.join(d, f)))
    return out


def annotations(src):
    explicit, convs = {}, []
    for line in open(src, errors="replace"):
        m = re.match(r"\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", line)
        if m:
            explicit.setdefault(m.group(1), int(m.group(2), 16))
        m = re.match(r"\s*//\s*equiv-conv:\s*(\S+)\s+(.+?)\s*$", line)
        if m:
            convs.append((m.group(1), m.group(2).split()))
    return explicit, convs


def cached_obj(src):
    """Compile src (cached by content + flags)."""
    os.makedirs(OBJ_DIR, exist_ok=True)
    h = hashlib.sha1(open(src, "rb").read() + repr(DEFAULT_FLAGS).encode()).hexdigest()[:16]
    path = os.path.join(OBJ_DIR, "%s-%s.obj" % (os.path.splitext(os.path.basename(src))[0], h))
    if not os.path.exists(path):
        tmp = path + ".d%d" % os.getpid()
        os.makedirs(tmp, exist_ok=True)
        try:
            o = compile_obj(src, DEFAULT_FLAGS, tmp)
            os.replace(o, path)
        finally:
            for f in os.listdir(tmp):
                os.unlink(os.path.join(tmp, f))
            os.rmdir(tmp)
    return path


# ---------------------------------------------------------------------------------------------
# Binding (worker side). Mirrors the first half of equiv.verify.
def _writable(sec):
    return bool(sec["flags"] & 0x80000000)


def prepare(job):
    addr, src, kind = job
    rec = {"addr": addr, "src": os.path.relpath(src, ROOT), "kind": kind}
    try:
        prog = equiv.Program.get()
        if addr not in prog.funcs:
            return dict(rec, status="reject", reason="not in functions.csv")
        size, tname = prog.funcs[addr]
        rec["name"] = tname
        if size < 5:
            return dict(rec, status="reject", reason="shorter than a jmp")
        explicit, convs = annotations(src)
        if convs:
            return dict(rec, status="reject", reason="equiv-conv (needs an adapter thunk)")
        try:
            obj_path = cached_obj(src)
        except CompileError as e:
            return dict(rec, status="reject", reason="compile error: " + str(e)[:200])
        obj = equiv.Obj(obj_path)
        target = prog.read(addr, size)
        fsym = equiv.pick_symbol(obj, addr, target)
        if fsym is None:
            return dict(rec, status="reject", reason="no function in object")
        ours = equiv.Ours(obj, fsym)
        oview = equiv.CodeView(prog.read, addr, (addr, addr + size), prog).build()
        orefs = equiv.original_refs(prog, oview, size)
        ours.link({})
        resolved, how, conflicts, exact = equiv.resolve_symbols(prog, ours, oview, orefs, explicit)
        for n in list(resolved):
            if n.startswith(LOCAL_PREFIXES) and n not in explicit:
                del resolved[n]
                how[n] = "local"
        ours_bytes = ours.bytes_at(addr, resolved)
        identical = ours_bytes == target or ours_bytes == strip_padding(target)
        # symbols reachable from our function, and how each one links
        reach = [s for _, s, _, _ in ours.relocs + ours.local_relocs() if s is not None]
        problems = []
        for s in reach:
            name, _, secnum, _, _ = s
            if name in resolved or s == fsym:
                continue
            if secnum <= 0:
                if name in equiv.INTRINSIC_NAMES:
                    problems.append("intrinsic %s not in the XBE" % name)
                else:
                    problems.append("unresolved %s" % name)
            elif _writable(obj.sections[secnum - 1]) and not name.startswith(("$SG", "??_C@")) \
                    and not (s[3] == 0x20):
                problems.append("private copy of writable %s" % name)
        rec.update(obj=obj_path, sym=fsym[0], symidx=[k for k, v in obj.syms.items() if v == fsym][0],
                   resolved=resolved, identical=identical,
                   how={n: h for n, h in how.items()},
                   local_funcs=sorted({s[0] for s in reach if s[2] > 0 and s[3] == 0x20 and s[0] not in resolved
                                       and s != fsym}))
        if conflicts:
            rec["conflicts"] = conflicts[:5]
        if problems:
            return dict(rec, status="reject", reason="; ".join(sorted(set(problems))[:4]))
        if kind == "matches":
            rec["class"] = "identical" if identical else "local"
        else:
            rec["class"] = "equivalent"
        rec["status"] = "ok"
        return rec
    except Exception as e:      # keep going: one bad source must not stop a build of thousands
        return dict(rec, status="reject", reason="error: %s: %s" % (type(e).__name__, e))


def check_extent(recs):
    """Reject functions whose functions.csv extent doesn't end in ret/jmp: a match compiled to that
    truncated extent (e.g. 0x27afb0, declared noreturn to stop before `add esp, 0Ch; ret`) would run off
    its end. Cheap, so it runs after the cache."""
    import capstone
    prog = equiv.Program.get()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for r in recs:
        if r.get("status") != "ok":
            continue
        size = prog.funcs[r["addr"]][0]
        ins = list(md.disasm(prog.read(r["addr"], size), r["addr"]))
        if not ins or ins[-1].mnemonic not in ("ret", "jmp", "int3") or sum(i.size for i in ins) != size:
            r["status"], r["reason"] = "reject", "extent: original does not end in ret/jmp (functions.csv size)"
    return recs


def _init_worker():
    equiv.Program.get()


def prepare_all(jobs, nproc=8, cache=None):
    """[(addr, src, kind)] -> records. `cache` is a dict keyed by (addr, src hash) reused between runs."""
    todo, out = [], {}
    keys = {}
    for j in jobs:
        k = "%08x:%s" % (j[0], hashlib.sha1(open(j[1], "rb").read()).hexdigest()[:16])
        keys[j] = k
        if cache is not None and k in cache:
            out[j] = cache[k]
        else:
            todo.append(j)
    if todo:
        with Pool(nproc, initializer=_init_worker) as pool:
            for i, r in enumerate(pool.imap(prepare, todo, chunksize=8)):
                j = todo[i]
                out[j] = r
                if cache is not None:
                    cache[keys[j]] = r
                if (i + 1) % 500 == 0:
                    print("  prepared %d/%d" % (i + 1, len(todo)), file=sys.stderr)
    return [out[j] for j in jobs]


def load_cache():
    p = os.path.join(OUT_DIR, "prepare-cache.json")
    try:
        return json.load(open(p))
    except (OSError, ValueError):
        return {}


def save_cache(c):
    os.makedirs(OUT_DIR, exist_ok=True)
    p = os.path.join(OUT_DIR, "prepare-cache.json")
    json.dump(c, open(p + ".tmp", "w"))
    os.replace(p + ".tmp", p)


# ---------------------------------------------------------------------------------------------
# XBE header surgery
class XbeImage:
    def __init__(self, data):
        self.d = bytearray(data)
        self.base, self.hdr_size, self.img_size = struct.unpack_from("<III", self.d, 0x104)
        self.nsec, self.sec_va = struct.unpack_from("<II", self.d, 0x11C)

    def off(self, va):
        return va - self.base

    def sections(self):
        out = []
        for i in range(self.nsec):
            o = self.off(self.sec_va) + i * SEC_HDR
            out.append((o,) + struct.unpack_from("<9I", self.d, o))
        return out

    def va_to_file(self, va):
        for o, fl, sva, vs, ra, rs, *_ in self.sections():
            if sva <= va < sva + rs:
                return ra + va - sva
        raise ValueError("VA %x not in a raw section" % va)

    def next_va(self):
        end = max(s[2] + s[3] for s in self.sections())
        return (end + 0xFFF) & ~0xFFF

    def add_section(self, name, data, flags=SEC_FLAGS):
        """Insert a section header after the table; append the name and two refcount words to the header."""
        d = self.d
        first_raw = min(s[4] for s in self.sections())
        ins = self.off(self.sec_va) + self.nsec * SEC_HDR       # end of the section table
        ins_va = self.base + ins
        hdr_end = self.hdr_size
        need = hdr_end + SEC_HDR + len(name) + 4
        if need > first_raw:
            raise ValueError("no room in the XBE header (%#x > %#x)" % (need, first_raw))

        def fix(v):
            return v + SEC_HDR if ins_va <= v < self.base + hdr_end else v
        # 1. pointers into the moved region
        for fo in (0x14C, 0x150, 0x154, 0x164, 0x168, 0x16C, 0x170):
            v, = struct.unpack_from("<I", d, fo)
            struct.pack_into("<I", d, fo, fix(v))
        for o, fl, sva, vs, ra, rs, nva, nrc, hp, tp in self.sections():
            struct.pack_into("<I", d, o + 20, fix(nva))
            struct.pack_into("<I", d, o + 28, fix(hp))
            struct.pack_into("<I", d, o + 32, fix(tp))
        # 2. shift [ins, hdr_end) up by one header
        d[ins + SEC_HDR:hdr_end + SEC_HDR] = d[ins:hdr_end]
        hdr_end += SEC_HDR
        name_va = self.base + hdr_end
        d[hdr_end:hdr_end + len(name)] = name
        hdr_end += len(name)
        hdr_end = (hdr_end + 1) & ~1
        rc_va = self.base + hdr_end
        d[hdr_end:hdr_end + 4] = b"\0\0\0\0"
        hdr_end += 4
        # 3. the new section: page-aligned VA after the last one, raw data at the end of the file
        va = self.next_va()
        raw = (len(d) + 0xFFF) & ~0xFFF
        d.extend(b"\0" * (raw - len(d)))
        d.extend(data)
        struct.pack_into("<9I", d, ins, flags, va, len(data), raw, len(data), name_va, 0, rc_va, rc_va + 2)
        d[ins + 36:ins + 56] = b"\0" * 20
        self.nsec += 1
        self.hdr_size = hdr_end
        self.img_size = max(self.img_size, ((va + len(data) + 0xFFF) & ~0xFFF) - self.base)
        struct.pack_into("<III", d, 0x108, self.hdr_size, self.img_size, struct.unpack_from("<I", d, 0x110)[0])
        struct.pack_into("<I", d, 0x11C, self.nsec)
        return va

    def fix_digests(self):
        for o, fl, sva, vs, ra, rs, *_ in self.sections():
            data = bytes(self.d[ra:ra + rs])
            self.d[o + 36:o + 56] = hashlib.sha1(struct.pack("<I", rs) + data).digest()

    def write(self, va, b):
        o = self.va_to_file(va)
        self.d[o:o + len(b)] = b


# ---------------------------------------------------------------------------------------------
# Test hooks (hybrid/hooks.cpp; docs/tasks/10-hybrid-test-plan.md deliverable 1)
HOOK_SRC = os.path.join(ROOT, "hybrid/hooks.cpp")
# (call site, original callee, our symbol): the call's rel32 is redirected to our function.
HOOK_CALLS = [
    (0x0008646E, 0x00267F40, "_hybrid_clock_tick"),          # GameClock::Update -> GetMicroseconds64
    (0x00087E40, 0x00267F40, "_hybrid_clock_now"),           # GameClock ctor    -> GetMicroseconds64
    (0x002685D9, 0x003EB91F, "_hybrid_xinput_get_state@8"),  # ControllerXBox::vfunc_17 -> XInputGetState
    (0x000876E5, 0x00086450, "_hybrid_game_tick"),           # CGame::Tick -> GameClock::Update (notes CGame)
    (0x0008763A, 0x0008DB00, "_hybrid_pump_services@0"),     # CGame::Tick -> PumpPlatformServices (iosync)
    (0x00273465, 0x0026DCE0, "_hybrid_drive_thread_start"),  # DriveThread ctor -> thread start (notes it)
    (0x00260AE2, 0x0034774C, "_hybrid_sound_rand"),          # audio sequencing -> CRT rand (sound-rng)
] + [(site, 0x000964D0, "_hybrid_sound_rng") for site in (   # sound code -> the game's MWC RNG (sound-rng)
    0x001EF2CA,     # 0x1ef2a0: caches it in 0x4e3758 for the sound manager
    0x001EFE8D,     # 0x1efe20
    0x001F7362,     # 0x1f7320 (voices)
    0x001F74B7,     # 0x1f7320
)] + [(site, 0x00354CD1, "_hybrid_qpc@4") for site in (       # QueryPerformanceCounter -> virtual clock (vclock)
    0x00267AA7,     # 0x267aa0 (seconds)
    0x00267F07,     # core::GetMicroseconds
    0x00267F47,     # core::GetMicroseconds64
    0x00267F87,     # core::GetMilliseconds (controller poll rate, timers, loading screens, FMV, sound)
    0x0026802C,     # core::TimerList::vfunc_5
    0x00292507,     # Pure3D timer
    0x003214D7,     # pure3d::d3dContext::vfunc_106
    0x003214EB,     # pure3d::d3dContext::vfunc_107
)]
SEED_SITE = (0x0008668E, 0x00267F00)                         # 0x86630: Seed(GetMicroseconds()) on new game
COOKIE_CHECK = 0x0034502E                                    # __security_check_cookie (__fastcall)
# With vclock the clock stands still between game-loop updates (loops outside it, like the loading screens, run a
# number of times that depends on the host's I/O). The pad poll's rate limit (ControllerSystemXBox::vfunc_12:
# `if (GetMilliseconds() - last < interval) return`) would then never pass in the PRESSSTART loop, so it goes:
# the pad is read on every call, which is once per frame in the game loop anyway.
VCLOCK_PATCHES = [(0x0026918B, b"\x72\x58", b"\x90\x90")]
# g_hybrid word indices (keep in sync with struct HybridCtl)
CTL = {"flags": 1, "dt_us": 2, "ckpt_interval": 6, "replay_count": 8, "nregions": 12}
CTL_REGIONS, CKPT_RING, INPUT_MAX, PAD_BYTES = 16, 4096, 8192, 24
CTL_CKPT = 16 * 4 + 8 * 8
CTL_REPLAY = CTL_CKPT + CKPT_RING * 8
CTL_RECORD = CTL_REPLAY + INPUT_MAX * PAD_BYTES
CTL_WIDE = CTL_RECORD + INPUT_MAX * PAD_BYTES        # wide_lo, wide_hi, snap_frame, snap_taken, mask[8], pages, snap
WIDE_PAGES = 256
CTL_EXT = CTL_WIDE + 16 + 4 * (WIDE_PAGES // 32) + 8 * WIDE_PAGES   # struct HybridCtl's extension fields
EXT_FIELDS = ("cgame", "main_thread", "game_state", "vt_lo", "vt_hi", "step_us", "extra_us", "max_extra_us",
              "vreads", "pre_step_us", "pre_us", "halt_frame", "halted", "ndrives", "drive0", "drive1", "drive2",
              "drive3", "io_waits", "io_timeouts", "io_timeout_ms", "replay_avail", "replay_starved", "snd_rng0", "snd_rng1", "snd_rng2", "snd_rng3", "snd_rand",
              "snd_rng_calls", "nskip")      # then skip[SKIP_MAX]
SKIP_MAX = 32
HF = {"fixed-dt": 1, "replay": 2, "record": 4, "ckpt": 8, "autostart": 16, "wide": 32, "pollkey": 64,
      "vclock": 128, "iosync": 256, "sound-rng": 512, "quant": 1024}


def link_hooks(base):
    """Link hybrid/hooks.cpp at base. Returns (image, {symbol: address})."""
    obj = equiv.Obj(cached_obj(HOOK_SRC))
    fsym = next(sy for sy in obj.syms.values() if sy[0] == "_hybrid_clock_tick")
    saved = equiv.OURS
    try:
        equiv.OURS = base
        ours = equiv.Ours(obj, fsym).link({})
    finally:
        equiv.OURS = saved
    if ours.poison:
        raise ValueError("hooks.cpp references unresolved symbols: %s" % sorted(ours.poison.values()))
    syms = {sy[0]: ours.sym_local_addr(sy) for sy in obj.syms.values()
            if sy[2] > 0 and sy[4] == 2 and ours.sym_local_addr(sy) is not None}
    return ours.image, syms


def pack_replay(entries):
    """[(frame, buttons, [8 analog], [4 thumbs])] -> bytes for g_hybrid.replay."""
    out = b""
    if len(entries) > INPUT_MAX:
        print("  replay: %d entries; the ring holds %d, the rest must be fed while the game runs"
              % (len(entries), INPUT_MAX), file=sys.stderr)
    for frame, buttons, analog, thumbs in entries[:INPUT_MAX]:
        out += struct.pack("<IH8B4hH", frame, buttons, *(list(analog) + [0] * 8)[:8], *(list(thumbs) + [0] * 4)[:4], 0)
    return out


# Behaviour changes behind flags (task 06 deliverable 3; docs/subsystems.md). {name: [(va, bytes)]}
TWEAKS = {
    # g_BootSequenceStep starts at 6: no dolby/marvel/radical/sierra/attract movies before the title
    "skip-intro": [(0x49FB40, struct.pack("<I", 6))],
    # CFMVManager::QueueMovie 0x1b7310 returns at once: no Bink movies at all (the game loop does not tick
    # while one plays, so frame-keyed input replays cannot get past them). Movies started another way (the
    # opening movie, 0x1b83c0 -> 0x1b7f40, which also hides the background level load) end at their first
    # render: FMV render 0x1b7d10 reads the movie's status (vfunc 0x30) as 0, "finished", and stops it. Without
    # this the loop spins unpaced in GS_FMV for as long as the movie plays in real time (thousands of updates).
    "no-fmv": [(0x1B7310, b"\xc2\x0c\x00"), (0x1B7D38, b"\x33\xc0\x90")],
}


# ---------------------------------------------------------------------------------------------
# Layout + link (main process)
def link_section(records, base, hooks=None):
    """Lay out the hooks object (optional) and every accepted function object from base.

    Returns (section bytes, {original addr: our entry VA}, {hook symbol: VA})."""
    image = bytearray()
    entries, hook_syms = {}, {}
    if hooks is not None or records:
        img, hook_syms = link_hooks(base)        # also holds shims our functions may need (see below)
        image.extend(img)
    saved = equiv.OURS
    try:
        for r in records:
            resolved = dict(r["resolved"])
            for n, a in resolved.items():
                if a == COOKIE_CHECK and not n.startswith("@"):     # declared __cdecl: shim it
                    resolved[n] = hook_syms["_hybrid_check_cookie_cdecl"]
                    r["cookie_shim"] = True
            cur = base + len(image)
            cur = (cur + 15) & ~15
            image.extend(b"\xcc" * (cur - base - len(image)))
            obj = equiv.Obj(r["obj"])
            fsym = obj.syms[r["symidx"]]
            equiv.OURS = cur
            ours = equiv.Ours(obj, fsym).link(resolved)
            entries[r["addr"]] = ours.func_addr
            image.extend(ours.image)
            r["ours"] = ours.func_addr
            r["ours_len"] = ours.func_len
    finally:
        equiv.OURS = saved
    return image, entries, hook_syms


def _redirect_in_copies(image, base, records, site, callee, replacement):
    """A hook site inside a function we replaced: apply the same change to our copy, at every
    `call callee` in it (byte-identical copies have it at the same offset; equivalent ones anywhere).
    replacement(call_va) -> 5 bytes. Returns the number of calls changed."""
    prog = equiv.Program.get()
    n = 0
    for r in records:
        size = prog.funcs.get(r["addr"], (0,))[0]
        if not (r["addr"] <= site < r["addr"] + size) or "ours" not in r:
            continue
        o0 = r["ours"] - base
        for o in range(o0, o0 + r["ours_len"] - 4):
            if image[o] == 0xE8:
                rel, = struct.unpack_from("<i", image, o + 1)
                if base + o + 5 + rel == callee:
                    image[o:o + 5] = replacement(base + o)
                    n += 1
    return n


def apply_hooks(x, image, base, syms, hooks, records=()):
    """Redirect the hook call sites (in the original and in our copies) and configure g_hybrid."""
    for site, callee, name in HOOK_CALLS:
        _redirect_in_copies(image, base, records, site, callee,
                            lambda va, t=syms[name]: b"\xe8" + struct.pack("<i", t - (va + 5)))
        o = x.va_to_file(site)
        rel, = struct.unpack_from("<i", x.d, o + 1)
        if x.d[o] != 0xE8 or site + 5 + rel != callee:
            raise ValueError("hook site %#x is not call %#x" % (site, callee))
        x.write(site + 1, struct.pack("<i", syms[name] - (site + 5)))
    if hooks.get("seed") is not None:
        site = SEED_SITE[0]
        o = x.va_to_file(site)
        rel, = struct.unpack_from("<i", x.d, o + 1)
        if x.d[o] != 0xE8 or site + 5 + rel != SEED_SITE[1]:
            raise ValueError("seed site %#x is not call %#x" % SEED_SITE)
        x.write(site, b"\xb8" + struct.pack("<I", hooks["seed"] & 0xFFFFFFFF))
        _redirect_in_copies(image, base, records, site, SEED_SITE[1],
                            lambda va: b"\xb8" + struct.pack("<I", hooks["seed"] & 0xFFFFFFFF))
    ctl = syms["_g_hybrid"] - base

    def put(idx, v):
        struct.pack_into("<I", image, ctl + 4 * idx, v & 0xFFFFFFFF)
    flags = 0
    for f in hooks.get("flags", ("fixed-dt", "ckpt")):
        flags |= HF[f]
    if hooks.get("replay"):
        flags |= HF["replay"]
        data = pack_replay(hooks["replay"])
        image[ctl + CTL_REPLAY:ctl + CTL_REPLAY + len(data)] = data
        # the rest of a long replay is fed into the ring while the game runs (hybrid_test.ReplayFeeder);
        # without a feeder the game waits at entry INPUT_MAX
        put(CTL["replay_count"], len(hooks["replay"]))
        struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("replay_avail"), len(data) // PAD_BYTES)
    put(CTL["flags"], flags)
    put(CTL["dt_us"], hooks.get("dt_us", 33333))
    put(CTL["ckpt_interval"], hooks.get("ckpt_interval", 30))
    struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("step_us"), hooks.get("step_us", 0))
    struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("halt_frame"), hooks.get("halt_frame", 0))
    struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("pre_step_us"), hooks.get("pre_step_us", 4000))
    struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("io_timeout_ms"), hooks.get("io_timeout_ms", 200))
    for i, w in enumerate((0x2F6B6F2A, 0x1F123BB5, 0, 0, 0x5EED)):           # sound-rng initial states
        struct.pack_into("<I", image, ctl + CTL_EXT + 4 * (EXT_FIELDS.index("snd_rng0") + i), w)
    skip = hooks.get("skip", [])[:SKIP_MAX]
    struct.pack_into("<I", image, ctl + CTL_EXT + 4 * EXT_FIELDS.index("nskip"), len(skip))
    for i, (a, n) in enumerate(skip):
        struct.pack_into("<II", image, ctl + CTL_EXT + 4 * len(EXT_FIELDS) + 8 * i, a, n)
    if "vclock" in hooks.get("flags", ()):
        for site, old, new in VCLOCK_PATCHES:
            if x.d[x.va_to_file(site):x.va_to_file(site) + len(old)] != old:
                raise ValueError("vclock patch site %#x changed" % site)
            x.write(site, new)
            for r in records:          # our copy of the function, if it's replaced: same offset when identical
                size = equiv.Program.get().funcs.get(r["addr"], (0,))[0]
                if "ours" in r and r["addr"] <= site < r["addr"] + size:
                    if r.get("class") != "identical":
                        raise ValueError("vclock patch %#x is inside replaced non-identical %#x" % (site, r["addr"]))
                    o = r["ours"] - base + (site - r["addr"])
                    image[o:o + len(new)] = new
    if hooks.get("snap_frame"):
        struct.pack_into("<I", image, ctl + CTL_WIDE + 8, hooks["snap_frame"])
    for i, w in enumerate(hooks.get("mask", [])[:WIDE_PAGES // 32]):
        struct.pack_into("<I", image, ctl + CTL_WIDE + 16 + 4 * i, w)
    regions = hooks.get("regions")
    if regions is not None:
        for i, (a, n) in enumerate(regions[:8]):
            struct.pack_into("<II", image, ctl + 4 * (CTL_REGIONS + 2 * i), a, n)
        put(CTL["nregions"], len(regions[:8]))


# ---------------------------------------------------------------------------------------------
# In-guest trace gate (tools/trace_gate.py; docs/tasks/ingame-trace.md). Every target function's entry becomes
# `jmp tramp_f`; the trampoline counts the call in a per-function entry and, when the host asked for this call
# (count >= next), stops at one shared gate address (the only permanent GDB breakpoint) with every register as
# it was at the function's entry. The host then co-simulates the call exactly as tools/trace_capture.py does
# and resumes the guest at the trampoline's copy of the displaced entry instructions.
#
#   header  (TRACE_HDR words): busy, gate_fn (the entry's address), gate_cont, gates, busy_skips
#   entry i (16 bytes): count, next (gate when count >= next; 0 = the next call, 0xffffffff = never),
#                       polls at the first call, frame at the first call
#   tramp_f: push entry_f; call common; <displaced instructions, relocated>; jmp f+len
TRACE_HDR = ("busy", "gate_fn", "gate_cont", "gates", "busy_skips")
TRACE_ENTRY = 16
NEVER = 0xFFFFFFFF


class _Asm:
    """A tiny x86 assembler: raw bytes plus rel8/rel32 fixups to labels."""

    def __init__(self, va):
        self.va, self.b, self.labels, self.fix = va, bytearray(), {}, []

    def here(self):
        return self.va + len(self.b)

    def label(self, name):
        self.labels[name] = self.here()

    def raw(self, *parts):
        for p in parts:
            self.b += p if isinstance(p, (bytes, bytearray)) else bytes([p])

    def u32(self, v):
        self.b += struct.pack("<I", v & 0xFFFFFFFF)

    def jcc8(self, op, name):
        self.raw(op, 0)
        self.fix.append((len(self.b) - 1, name, 1))

    def jcc32(self, op2, name):            # 0F op2 rel32
        self.raw(0x0F, op2)
        self.b += b"\0\0\0\0"
        self.fix.append((len(self.b) - 4, name, 4))

    def done(self):
        for o, name, n in self.fix:
            rel = self.labels[name] - (self.va + o + n)
            if n == 1:
                assert -128 <= rel < 128, name
                self.b[o] = rel & 0xFF
            else:
                struct.pack_into("<i", self.b, o, rel)
        return bytes(self.b)


def _trace_common(va, hdr, polls, frame):
    """The shared bookkeeping routine and the gate. Returns (bytes, gate VA). Stack at entry:
    [ret into tramp_f][entry_f][the function's return address]."""
    H = {k: hdr + 4 * i for i, k in enumerate(TRACE_HDR)}
    a = _Asm(va)
    a.raw(0x9C, 0x50, 0x52)                         # pushfd; push eax; push edx
    a.raw(b"\x8b\x54\x24\x10")                      # mov edx, [esp+16]     (entry_f)
    a.raw(b"\x8b\x02")                              # mov eax, [edx]        (count)
    a.raw(b"\x85\xc0")                              # test eax, eax
    a.jcc8(0x75, "counted")                         # jnz counted
    a.raw(0xA1); a.u32(polls)                       # mov eax, [g_hybrid.polls]
    a.raw(b"\x89\x42\x08")                          # mov [edx+8], eax
    a.raw(0xA1); a.u32(frame)                       # mov eax, [g_hybrid.frame]
    a.raw(b"\x89\x42\x0c")                          # mov [edx+12], eax
    a.raw(b"\x31\xc0")                              # xor eax, eax
    a.label("counted")
    a.raw(0x40)                                     # inc eax
    a.raw(b"\x89\x02")                              # mov [edx], eax
    a.raw(b"\x3b\x42\x04")                          # cmp eax, [edx+4]      (next)
    a.jcc8(0x72, "pass")                            # jb pass
    a.raw(0xB8); a.u32(1)                           # mov eax, 1
    a.raw(b"\x87\x05"); a.u32(H["busy"])            # xchg [busy], eax
    a.raw(b"\x85\xc0")                              # test eax, eax
    a.jcc8(0x75, "busy")                            # jnz busy: another gate is between taking and the host
    a.raw(b"\x8b\x44\x24\x10")                      # mov eax, [esp+16]     (entry_f)
    a.raw(0xA3); a.u32(H["gate_fn"])                # mov [gate_fn], eax
    a.raw(b"\x8b\x44\x24\x0c")                      # mov eax, [esp+12]     (the displaced code in tramp_f)
    a.raw(0xA3); a.u32(H["gate_cont"])              # mov [gate_cont], eax
    a.raw(b"\xff\x05"); a.u32(H["gates"])           # inc dword [gates]
    a.raw(0x5A, 0x58, 0x9D)                         # pop edx; pop eax; popfd
    a.raw(b"\x8d\x64\x24\x08")                      # lea esp, [esp+8]      (flags untouched)
    a.label("gate")                                 # every register as at the function's entry
    a.raw(0x90)                                     # nop   <- the host's breakpoint; it sets eip = gate_cont
    a.raw(b"\xc7\x05"); a.u32(H["busy"]); a.u32(0)  # (no host: carry on) mov dword [busy], 0
    a.raw(b"\xff\x25"); a.u32(H["gate_cont"])       # jmp dword [gate_cont]
    a.label("busy")
    a.raw(b"\xff\x05"); a.u32(H["busy_skips"])      # inc dword [busy_skips]
    a.label("pass")
    a.raw(0x5A, 0x58, 0x9D)                         # pop edx; pop eax; popfd
    a.raw(b"\xc2\x04\x00")                          # ret 4  -> the displaced code, entry_f popped
    return a.done(), a.labels["gate"]


def _displace(prog, f, patched):
    """Relocate the instructions covering f's first 5 bytes. Returns (length, relocate(va) -> bytes, ends) or a
    rejection string. ends: the copy ends in a transfer (no jmp back needed)."""
    size = prog.funcs.get(f, (0,))[0]
    if size < 5:
        return "shorter than a jmp"
    code = prog.read(f, 32)
    ins = []
    n = 0
    for ci in prog.md.disasm(code, f):
        ins.append(ci)
        n += ci.size
        if n >= 5:
            break
    if n < 5:
        return "undecodable entry"
    if n > size:
        return "entry instructions run past the function"
    hits = [p for p in patched if f <= p < f + n]
    if hits:
        return "entry bytes already patched (%#x)" % hits[0]
    view = equiv.CodeView(prog.read, f, (f, f + size), prog).build()
    for i in view.insns.values():
        if i.target is not None and f < i.target < f + n:
            return "branch at %#x into the entry bytes" % i.addr
        if f < i.addr < f + n and i.addr not in {c.address for c in ins}:
            return "instruction at %#x overlaps the entry bytes" % i.addr
    for tg in view.tables.values():
        if any(f < t < f + n for t in tg):
            return "jump table into the entry bytes"
    parts = []
    ends = False
    for k, ci in enumerate(ins):
        last = k == len(ins) - 1
        b = bytes(ci.bytes)
        mn = ci.mnemonic
        rel = mn in ("call", "jmp") or (mn.startswith("j") and mn not in ("jmp",))
        tgt = None
        if rel and len(ci.operands) == 1 and ci.operands[0].type == 2:     # an immediate: a relative branch
            tgt = ci.operands[0].imm & 0xFFFFFFFF
        if mn.startswith("loop") or mn in ("jecxz", "jcxz"):
            return "relative %s in the entry bytes" % mn
        if mn in ("int3", "hlt", "ud2", "int", "into", "iret", "iretd", "retf", "sysenter", "ljmp", "lcall"):
            return "%s in the entry bytes" % mn
        if mn in ("ret", "retn", "jmp") and not last:
            return "%s before the end of the entry bytes" % mn
        if mn == "call" and tgt is None:
            # (it would return into the copy, not to f+n where the co-simulation waits for it)
            return "indirect call in the entry bytes"
        if mn == "call":
            parts.append(("call", tgt, ci.address + ci.size))     # push the original return address; jmp
            ends = True
        elif mn == "jmp" and tgt is not None:
            parts.append(("jmp", tgt))
            ends = True
        elif tgt is not None:                                       # jcc
            cc = b[0] & 0x0F if b[0] != 0x0F else b[1] & 0x0F
            parts.append(("jcc", cc, tgt))
        else:
            parts.append(("raw", b))
            ends = ends or mn in ("ret", "retn", "jmp")

    def relocate(va):
        out = bytearray()
        for p in parts:
            here = va + len(out)
            if p[0] == "raw":
                out += p[1]
            elif p[0] == "call":
                out += b"\x68" + struct.pack("<I", p[2])
                out += b"\xe9" + struct.pack("<i", p[1] - (here + 10))
            elif p[0] == "jmp":
                out += b"\xe9" + struct.pack("<i", p[1] - (here + 5))
            else:
                out += bytes([0x0F, 0x80 | p[1]]) + struct.pack("<i", p[2] - (here + 6))
        if not ends:
            here = va + len(out)
            out += b"\xe9" + struct.pack("<i", (f + n) - (here + 5))
        return bytes(out)
    return n, relocate, ends


def trace_stubs(x, base, sec, g_hybrid, targets, nxt=0, original=None):
    """Append the trace gate (header, common routine, entry table, trampolines) to section image `sec` (at VA
    base) and point each target's entry at its trampoline in XBE image x. targets: [addr]. original: the
    unpatched XBE bytes (entries whose first bytes the build already changed are refused).
    Returns the manifest's "trace" dict."""
    prog = equiv.Program.get()
    patched = set()
    if original is not None:
        xo = XbeImage(original)
        for f in targets:
            try:
                a, b = x.d[x.va_to_file(f):x.va_to_file(f) + 16], xo.d[xo.va_to_file(f):xo.va_to_file(f) + 16]
            except ValueError:
                continue
            patched.update(f + i for i in range(16) if a[i] != b[i])
    plan, rejected = [], {}
    for f in sorted(set(targets)):
        r = _displace(prog, f, patched)
        if isinstance(r, str):
            rejected["0x%08x" % f] = r
        elif r is not None:
            plan.append((f,) + r)
    while len(sec) % 16:
        sec.append(0xCC)
    hdr = base + len(sec)
    sec.extend(b"\0" * (4 * len(TRACE_HDR) + 12))
    common_va = base + len(sec)
    polls, frame = g_hybrid + 4 * 11, g_hybrid + 4 * 3
    code, gate = _trace_common(common_va, hdr, polls, frame)
    sec.extend(code)
    while len(sec) % 16:
        sec.append(0xCC)
    table = base + len(sec)
    for _ in plan:
        sec.extend(struct.pack("<4I", 0, nxt, 0, 0))
    entries = []
    for i, (f, n, relocate, _ends) in enumerate(plan):
        ent = table + TRACE_ENTRY * i
        tva = base + len(sec)
        t = bytearray(b"\x68" + struct.pack("<I", ent) + b"\xe8" + struct.pack("<i", common_va - (tva + 10)))
        t += relocate(tva + len(t))
        sec.extend(t)
        x.write(f, b"\xe9" + struct.pack("<i", tva - (f + 5)))
        entries.append([f, n, tva])
    return {"hdr": hdr, "hdr_fields": list(TRACE_HDR), "common": common_va, "gate": gate, "table": table,
            "entry_bytes": TRACE_ENTRY, "functions": entries, "rejected": rejected, "next_init": nxt}


def build(records, out, pad=PAD_SIZE, empty_section=False, tweaks=(), hooks=None, trace=None):
    """hooks: None, or {"seed": int|None, "flags": [...], "dt_us": int, "ckpt_interval": int,
    "replay": [(frame, buttons, analog, thumbs)], "regions": [(addr, size)]}.
    trace: None, or {"targets": [addr], "next": initial `next` of every entry} (the in-guest trace gate,
    trace_stubs; needs hooks)."""
    data = open(XBE_PATH, "rb").read()
    x = XbeImage(data)
    for t in tweaks:
        for va, b in TWEAKS[t]:
            x.write(va, b)
    ok = [r for r in records if r.get("status") == "ok"]
    va = None
    hook_syms = {}
    if ok or empty_section or hooks is not None:
        va = x.next_va()
        sec, entries, hook_syms = link_section(ok, va, hooks)
        if hooks is not None:
            apply_hooks(x, sec, va, hook_syms, hooks, ok)
        tinfo = None
        if trace:
            tinfo = trace_stubs(x, va, sec, hook_syms["_g_hybrid"], [t for t in trace["targets"] if t not in entries],
                                trace.get("next", 0), data)
        got = x.add_section(SECTION_NAME, bytes(sec) or b"\xcc" * 16)
        assert got == va
        for a, e in entries.items():
            x.write(a, b"\xe9" + struct.pack("<i", e - (a + 5)))
    else:
        tinfo = None
    if ok or empty_section or tweaks or hooks is not None:
        x.fix_digests()
    d = bytes(x.d)
    if pad and len(d) < pad:
        d += b"\0" * (pad - len(d))
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    open(out, "wb").write(d)
    man = {"xbe": os.path.relpath(out, ROOT), "section_va": va, "patched": len(ok), "tweaks": list(tweaks),
           "hooks": None if hooks is None else {k: v for k, v in hooks.items() if k != "replay"},
           "g_hybrid": hook_syms.get("_g_hybrid"),
           "g_hybrid_layout": {"ckpt": CTL_CKPT, "ckpt_ring": CKPT_RING, "record": CTL_RECORD,
                               "input_max": INPUT_MAX, "pad_bytes": PAD_BYTES, "wide": CTL_WIDE,
                               "wide_pages": WIDE_PAGES, "ext": CTL_EXT, "ext_fields": list(EXT_FIELDS)},
           "functions": [{k: r.get(k) for k in ("addr", "name", "src", "class", "ours", "sym")} for r in ok]}
    if tinfo is not None:
        man["trace"] = tinfo
    json.dump(man, open(os.path.splitext(out)[0] + ".json", "w"), indent=1)
    return man


def select(args):
    jobs = []
    if args.matches:
        m = source_set("matches")
        if args.matches != "all":
            m = m[:int(args.matches)]
        jobs += [(a, s, "matches") for a, s in m]
    if args.equivalent:
        jobs += [(a, s, "equivalent") for a, s in source_set("equivalent")]
    if args.only:
        want = {int(x, 16) for x in args.only.split(",")}
        jobs = [j for j in jobs if j[0] in want]
    return jobs


DEFAULT_EXCLUDE = os.path.join(ROOT, "hybrid/exclude.txt")


def default_exclude():
    return read_addr_file(DEFAULT_EXCLUDE) if os.path.exists(DEFAULT_EXCLUDE) else set()


CONFIDENCE = os.path.join(ROOT, "build/equiv-confidence.json")


def tiers(path=None):
    """{addr: tier} from tools/equiv_confidence.py's file (0 mismatch .. 3 replay-verified); {} if absent."""
    path = path or CONFIDENCE
    if not os.path.exists(path):
        return {}
    doc = json.load(open(path))
    return {int(a, 16): r["tier"] for a, r in doc["functions"].items()}


def tier_filter(jobs, args):
    """Drop equivalent/ functions below --tier-min (missing from the confidence file: tier 1, fuzz only)."""
    if getattr(args, "tier_min", None) is None:
        return jobs
    t = tiers(getattr(args, "confidence", None))
    if not t:
        raise SystemExit("--tier-min needs %s (tools/equiv_confidence.py)" % os.path.relpath(
            getattr(args, "confidence", None) or CONFIDENCE, ROOT))
    return [j for j in jobs if j[2] != "equivalent" or t.get(j[0], 1) >= args.tier_min]


def add_tier_args(ap):
    ap.add_argument("--confidence", help="equivalence confidence file (default build/equiv-confidence.json)")
    ap.add_argument("--tier-min", type=int, help="only equivalent/ functions at this confidence tier or higher "
                    "(0 mismatch, 1 fuzz only, 2 replay agreed on a few calls, 3 replay-verified)")


def read_addr_file(path):
    out = set()
    for line in open(path):
        line = line.split("#")[0].strip()
        if line:
            out.add(int(line.split()[0], 16))
    return out


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--matches", help="N (first N by address) or all")
    ap.add_argument("--equivalent", action="store_true")
    ap.add_argument("--only", help="comma-separated addresses to keep")
    ap.add_argument("--set", help="file of addresses to patch (one per line); filters the selection")
    ap.add_argument("--exclude", help="file of addresses to leave alone")
    ap.add_argument("--no-default-exclude", action="store_true", help="also patch the functions in hybrid/exclude.txt")
    ap.add_argument("--classes", default="identical", help="comma list of identical,local,equivalent")
    ap.add_argument("--allow-chunked", action="store_true", help="also patch functions with several chunks")
    ap.add_argument("--out", default=os.path.join(OUT_DIR, "default.xbe"))
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--pad", type=int, default=PAD_SIZE)
    ap.add_argument("--empty-section", action="store_true", help="add the section even with nothing patched")
    ap.add_argument("--tweak", action="append", default=[], choices=sorted(TWEAKS),
                    help="behaviour change to apply (repeatable)")
    ap.add_argument("--hooks", action="store_true", help="link hybrid/hooks.cpp (fixed dt, checkpoints)")
    ap.add_argument("--seed", type=lambda v: int(v, 0), help="with --hooks: constant RNG seed for new games")
    ap.add_argument("--dt-us", type=int, default=33333)
    ap.add_argument("--ckpt-interval", type=int, default=30)
    ap.add_argument("--replay", help="with --hooks: input replay JSON ([[frame, buttons, [analog x8], [thumbs x4]], ...])")
    ap.add_argument("--record", action="store_true", help="with --hooks: log pad changes into g_hybrid.record")
    ap.add_argument("--no-fixed-dt", action="store_true")
    ap.add_argument("--report", help="write every record (incl. rejects) to this JSON file")
    add_tier_args(ap)
    args = ap.parse_args(argv)
    jobs = tier_filter(select(args), args)
    if args.set:
        keep = read_addr_file(args.set)
        jobs = [j for j in jobs if j[0] in keep]
    drop = read_addr_file(args.exclude) if args.exclude else set()
    if not args.no_default_exclude:
        drop |= default_exclude()
    jobs = [j for j in jobs if j[0] not in drop]
    cache = load_cache()
    recs = check_extent(prepare_all(jobs, args.jobs, cache))
    save_cache(cache)
    classes = set(args.classes.split(","))
    chunks = {}
    import csv
    for row in csv.DictReader(open(equiv.FUNCS_CSV)):
        chunks[int(row["address"], 16)] = int(row["chunks"] or 1)
    for r in recs:
        if r.get("status") != "ok":
            continue
        if r["class"] not in classes:
            r["status"], r["reason"] = "skip", "class %s not selected" % r["class"]
        elif chunks.get(r["addr"], 1) > 1 and not args.allow_chunked:
            r["status"], r["reason"] = "skip", "function has %d chunks" % chunks[r["addr"]]
    if args.report:
        json.dump(recs, open(args.report, "w"), indent=1, default=str)
    hooks = None
    if args.hooks:
        flags = ["ckpt"] + ([] if args.no_fixed_dt else ["fixed-dt"]) + (["record"] if args.record else []) \
            + (["autostart"] if args.replay else [])
        hooks = {"seed": args.seed, "flags": flags, "dt_us": args.dt_us, "ckpt_interval": args.ckpt_interval}
        if args.replay:
            hooks["replay"] = json.load(open(args.replay))
    man = build(recs, args.out, args.pad, args.empty_section, args.tweak, hooks)
    from collections import Counter
    c = Counter(r.get("class") if r.get("status") == "ok" else r.get("status") for r in recs)
    reasons = Counter(re.sub(r"\s.*", "", r.get("reason", "")) if r.get("status") != "ok" else "" for r in recs)
    print("patched %d functions -> %s (section at %s)" % (man["patched"], args.out,
                                                          "%#x" % man["section_va"] if man["section_va"] else "-"))
    print("  " + ", ".join("%s=%d" % kv for kv in sorted(c.items(), key=str)))
    print("  reasons: " + ", ".join("%s=%d" % kv for kv in reasons.most_common(8) if kv[0]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
