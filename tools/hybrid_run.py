#!/usr/bin/env python3
"""Disc image + xemu driver for the hybrid build (docs/hybrid-build.md).

  tools/hybrid_run.py iso                     # once: pack build/hybrid/hulk-hybrid.iso from isos/extracted
  tools/hybrid_run.py install XBE             # write a (padded) XBE into the packed image, in place
  tools/hybrid_run.py boot [--seconds 90] [--interval 10] [--until-title] [--tag NAME] [--gdb]
                                              # run xemu headless-ish, screenshot over QMP, quit
  tools/hybrid_run.py run XBE ...             # install + boot

The image is packed once with a default.xbe padded to patch_xbe.PAD_SIZE bytes, so every later build only
rewrites those bytes (no 2.3 GB repack). Data files are hard links into isos/extracted (no copy, never
written). xemu runs with a copy of the user's config (build/hybrid/xemu.toml) pointing at the user's own
BIOS/MCPX/HDD in build/xemu/Xbox-Emulator-Files, with -snapshot so the HDD image is never written.
"""
import argparse
import json
import os
import re
import shutil
import socket
import struct
import subprocess
import sys
import time
import tomllib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from patch_xbe import OUT_DIR, PAD_SIZE, ROOT, XBE_PATH  # noqa: E402

EXTRACTED = os.path.join(ROOT, "isos/extracted")
STAGE = os.path.join(OUT_DIR, "disc")
XEMU = "/Applications/xemu.app/Contents/MacOS/xemu"
USER_CFG = os.path.expanduser("~/Library/Application Support/xemu/xemu/xemu.toml")
FILES = os.path.join(ROOT, "build/xemu/Xbox-Emulator-Files")
# Several xemu can run side by side (e.g. parallel trace captures): HULK_XEMU_INSTANCE=N gives instance N its own
# disc image (an APFS clone of instance 0's, made on first use), config, EEPROM copy, QMP socket and GDB port
# (1234 + N). Instance 0 keeps the plain names. Each instance installs its own XBE into its own image.
INSTANCE = int(os.environ.get("HULK_XEMU_INSTANCE", "0"))
_SFX = "-%d" % INSTANCE if INSTANCE else ""
BASE_ISO = os.path.join(OUT_DIR, "hulk-hybrid.iso")
ISO = os.path.join(OUT_DIR, "hulk-hybrid%s.iso" % _SFX)
CFG = os.path.join(OUT_DIR, "xemu%s.toml" % _SFX)
QMP = os.path.join(OUT_DIR, "qmp%s.sock" % _SFX)
SHOTS = os.path.join(OUT_DIR, "shots")
GDB_PORT = 1234 + INSTANCE
# HULK_XEMU_DISPLAY: extra -display argument (e.g. "none"); see docs/hybrid-build.md for what works headless
DISPLAY = os.environ.get("HULK_XEMU_DISPLAY")


def ensure_instance_iso():
    """Instance N > 0: clone instance 0's packed image (copy-on-write on APFS, so instant and space-free)."""
    if INSTANCE and not os.path.exists(ISO):
        r = subprocess.run(["cp", "-c", BASE_ISO, ISO])
        if r.returncode:
            shutil.copy(BASE_ISO, ISO)
        shutil.copy(BASE_ISO + ".json", ISO + ".json")


# ---------------------------------------------------------------------------------------------
# Disc image
def pack_iso():
    if os.path.isdir(STAGE):
        shutil.rmtree(STAGE)
    os.makedirs(STAGE)
    for dirpath, _, files in os.walk(EXTRACTED):
        rel = os.path.relpath(dirpath, EXTRACTED)
        os.makedirs(os.path.join(STAGE, rel), exist_ok=True)
        for f in files:
            src, dst = os.path.join(dirpath, f), os.path.join(STAGE, rel, f)
            if rel == "." and f == "default.xbe":
                data = open(src, "rb").read()
                open(dst, "wb").write(data + b"\0" * (PAD_SIZE - len(data)))
            else:
                os.link(src, dst)
    if os.path.exists(ISO):
        os.unlink(ISO)
    subprocess.run(["xdvdfs", "pack", STAGE, ISO], check=True)
    off, size = find_file(ISO, "default.xbe")
    assert size == PAD_SIZE, size
    json.dump({"xbe_offset": off, "xbe_size": size}, open(ISO + ".json", "w"))
    print("packed %s; default.xbe at %#x (%d bytes)" % (ISO, off, size))


def find_file(iso, name):
    """(byte offset, size) of a root-directory file in an XDVDFS image."""
    with open(iso, "rb") as f:
        f.seek(32 * 2048)
        vd = f.read(2048)
        assert vd[:20] == b"MICROSOFT*XBOX*MEDIA", "not an XDVDFS image"
        root_sec, root_size = struct.unpack_from("<II", vd, 20)
        f.seek(root_sec * 2048)
        table = f.read(root_size)

    def walk(o):
        if o == 0xFFFF * 4 or o + 14 > len(table):
            return None
        left, right, sec, size, attr, nlen = struct.unpack_from("<HHIIBB", table, o)
        if left == 0xFFFF and right == 0xFFFF and sec == 0xFFFFFFFF:
            return None
        n = table[o + 14:o + 14 + nlen].decode("latin1")
        if n.lower() == name.lower():
            return sec * 2048, size
        for nxt in (left, right):
            if nxt and nxt != 0xFFFF:
                r = walk(nxt * 4)
                if r:
                    return r
        return None
    r = walk(0)
    if r is None:
        raise FileNotFoundError(name)
    return r


def install(xbe):
    ensure_instance_iso()
    meta = json.load(open(ISO + ".json"))
    data = open(xbe, "rb").read()
    if len(data) > meta["xbe_size"]:
        raise SystemExit("%s is %d bytes; the image reserves %d (repack with a larger PAD_SIZE)"
                         % (xbe, len(data), meta["xbe_size"]))
    data += b"\0" * (meta["xbe_size"] - len(data))
    with open(ISO, "r+b") as f:
        f.seek(meta["xbe_offset"])
        f.write(data)
    print("installed %s into %s" % (os.path.relpath(xbe, ROOT), os.path.relpath(ISO, ROOT)))


# ---------------------------------------------------------------------------------------------
# xemu
def _toml_value(v):
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return repr(v)
    if isinstance(v, str):
        return "'%s'" % v if "'" not in v else json.dumps(v)
    raise TypeError(v)


def _toml_dump(d, prefix=""):
    out, subs = [], []
    for k, v in d.items():
        if isinstance(v, dict):
            subs.append((k, v))
        else:
            out.append("%s = %s" % (k, _toml_value(v)))
    text = ""
    if out:
        text += ("[%s]\n" % prefix if prefix else "") + "\n".join(out) + "\n\n"
    for k, v in subs:
        text += _toml_dump(v, "%s.%s" % (prefix, k) if prefix else k)
    return text


def write_config(pad="keyboard"):
    """Copy the user's xemu.toml (never modified) and point it at build/ files. pad: what port 1 is bound to
    ("keyboard", or a gamepad's SDL GUID as xemu writes it; None keeps the user's own binding)."""
    cfg = tomllib.load(open(USER_CFG, "rb")) if os.path.exists(USER_CFG) else {}
    files = cfg.setdefault("sys", {}).setdefault("files", {})
    files["bootrom_path"] = os.path.join(FILES, "mcpx/mcpx_1.0.bin")
    files["flashrom_path"] = os.path.join(FILES, "bios/Complex_4627.bin")
    files["hdd_path"] = os.path.join(FILES, "hdd/xbox_hdd.qcow2")
    eeprom = os.path.join(OUT_DIR, "eeprom%s.bin" % _SFX)
    user_eeprom = files.get("eeprom_path")
    if not os.path.exists(eeprom) and user_eeprom and os.path.exists(user_eeprom):
        shutil.copy(user_eeprom, eeprom)
    files["eeprom_path"] = eeprom
    files["dvd_path"] = ISO
    cfg.setdefault("general", {})["show_welcome"] = False
    cfg["general"]["skip_boot_anim"] = True
    cfg.setdefault("net", {})["enable"] = False
    if os.environ.get("HULK_XEMU_SCALE"):       # render scale (experiments: a slower host)
        cfg.setdefault("display", {}).setdefault("quality", {})["surface_scale"] = int(os.environ["HULK_XEMU_SCALE"])
    # a pad in port 1 (the keyboard), so the game opens a controller; hooks.cpp replays input into it
    bind = cfg.setdefault("input", {}).setdefault("bindings", {})
    bind["port1_driver"] = "usb-xbox-gamepad"
    if pad is not None or "port1" not in bind:
        bind["port1"] = pad or "keyboard"
    open(CFG, "w").write(_toml_dump(cfg))
    return CFG


class Qmp:
    def __init__(self, path, timeout=30):
        t0 = time.time()
        while True:
            try:
                self.s = socket.socket(socket.AF_UNIX)
                self.s.connect(path)
                break
            except OSError:
                if time.time() - t0 > timeout:
                    raise
                time.sleep(0.5)
        self.s.settimeout(timeout)          # a wedged monitor raises instead of hanging the harness
        self.f = self.s.makefile("rwb")
        json.loads(self.f.readline())
        self.cmd("qmp_capabilities")

    def cmd(self, name, **args):
        self.f.write(json.dumps({"execute": name, "arguments": args}).encode() + b"\n")
        self.f.flush()
        while True:
            r = json.loads(self.f.readline())
            if "event" in r:
                continue
            if "error" in r:
                raise RuntimeError(r["error"])
            return r.get("return")


def png_write(path, w, h, rgb):
    import zlib
    raw = b"".join(b"\0" + rgb[y * w * 3:(y + 1) * w * 3] for y in range(h))

    def chunk(t, d):
        return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xFFFFFFFF)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
                           + chunk(b"IDAT", zlib.compress(raw, 1)) + chunk(b"IEND", b""))


class Xemu:
    """A running xemu with QMP. Reads guest memory through the HMP monitor (x / xp / pmemsave)."""

    def __init__(self, tag="run", gdb=False, extra=(), pad="keyboard"):
        ensure_instance_iso()
        write_config(pad)
        if os.path.exists(QMP):
            os.unlink(QMP)
        self.outdir = os.path.join(SHOTS, tag)
        os.makedirs(self.outdir, exist_ok=True)
        cmd = [XEMU, "-config_path", CFG, "-dvd_path", ISO, "-snapshot",
               "-qmp", "unix:%s,server,nowait" % QMP] + (["-gdb", "tcp::%d" % GDB_PORT] if gdb else []) \
            + (["-display", DISPLAY] if DISPLAY else []) + list(extra)
        self.log = open(os.path.join(self.outdir, "xemu.log"), "w")
        env = dict(os.environ)
        if not env.get("HULK_XEMU_SOUND"):      # muted unless asked for (SDL's null audio device)
            env.setdefault("SDL_AUDIODRIVER", "dummy")
        self.p = subprocess.Popen(cmd, stdout=self.log, stderr=subprocess.STDOUT, env=env)
        self.t0 = time.time()
        self.q = Qmp(QMP)

    def hmp(self, line):
        return self.q.cmd("human-monitor-command", **{"command-line": line})

    def alive(self):
        return self.p.poll() is None

    def u32(self, va):
        """A guest virtual dword (current page tables; the XBE image is mapped in every context)."""
        out = self.hmp("x /1wx %#x" % va)
        try:
            return int(out.split()[1], 16)
        except (IndexError, ValueError):
            return None

    def read(self, va, n):
        """Guest virtual bytes via memsave."""
        path = os.path.join(self.outdir, ".mem")
        self.q.cmd("memsave", val=va, size=n, filename=path)
        return open(path, "rb").read()

    def eip(self):
        m = re.search(r"EIP=([0-9a-f]+)", self.hmp("info registers"))
        return int(m.group(1), 16) if m else None

    def screenshot(self, path, w=640, h=480):
        """The scan-out buffer (NV_PCRTC_START) from guest RAM, X8R8G8B8, as PNG. Returns a content hash."""
        start = int(self.hmp("xp /1wx 0xfd600800").split()[1], 16) & 0x03FFFFFF     # 64 MB of RAM
        raw_path = os.path.join(self.outdir, ".fb")
        self.q.cmd("pmemsave", val=start, size=w * h * 4, filename=raw_path)
        raw = open(raw_path, "rb").read()
        rgb = bytearray(w * h * 3)
        rgb[0::3], rgb[1::3], rgb[2::3] = raw[2::4], raw[1::4], raw[0::4]
        png_write(path, w, h, bytes(rgb))
        import hashlib
        return hashlib.sha1(raw).hexdigest()[:12]

    def close(self):
        try:
            self.q.cmd("quit")
        except Exception:
            pass
        try:
            self.p.wait(timeout=15)
        except subprocess.TimeoutExpired:
            self.p.kill()
            self.p.wait()


BOOT_STEP = 0x49FB40        # g_BootSequenceStep (docs/subsystems.md section 4)
CTL_FIELDS = ("magic", "flags", "dt_us", "frame", "now_lo", "now_hi", "ckpt_interval", "ckpt_count",
              "replay_count", "replay_pos", "record_count", "polls", "nregions")


def read_hybrid(x, man, full=False):
    """g_hybrid (hybrid/hooks.cpp) from the running game: header fields, plus checkpoints and recorded
    input when full."""
    base = man["g_hybrid"]
    lay = man["g_hybrid_layout"]
    hdr = struct.unpack("<%dI" % len(CTL_FIELDS), x.read(base, 4 * len(CTL_FIELDS)))
    st = dict(zip(CTL_FIELDS, hdr))
    if "ext" in lay:
        ef = lay["ext_fields"]
        st.update(zip(ef, struct.unpack("<%dI" % len(ef), x.read(base + lay["ext"], 4 * len(ef)))))
    if "ext2" in lay:
        ef = lay["ext2_fields"]
        st.update(zip(ef, struct.unpack("<%dI" % len(ef), x.read(base + lay["ext2"], 4 * len(ef)))))
    if full:
        n = min(st["ckpt_count"], lay["ckpt_ring"])
        raw = x.read(base + lay["ckpt"], 8 * lay["ckpt_ring"])
        ck = [struct.unpack_from("<II", raw, 8 * i) for i in range(lay["ckpt_ring"])]
        start = st["ckpt_count"] - n
        st["checkpoints"] = [ck[(start + i) % lay["ckpt_ring"]] for i in range(n)]
        nrec = min(st["record_count"], lay["input_max"])
        rec_raw = x.read(base + lay["record"], lay["pad_bytes"] * lay["input_max"]) if nrec else b""
        if "wide" in lay:
            raw = x.read(base + lay["wide"], 16 + 4 * (lay["wide_pages"] // 32) + 8 * lay["wide_pages"])
            lo, hi, snap_frame, snap_taken = struct.unpack_from("<4I", raw, 0)
            o = 16 + 4 * (lay["wide_pages"] // 32)
            npages = min((hi - lo + 0xFFF) // 0x1000, lay["wide_pages"]) if hi > lo else 0
            st["wide"] = {"lo": lo, "snap_taken": snap_taken,
                          "pages": list(struct.unpack_from("<%dI" % npages, raw, o)),
                          "snap": list(struct.unpack_from("<%dI" % npages, raw, o + 4 * lay["wide_pages"]))}
        st["record"] = []                   # the newest nrec entries of the ring, oldest first
        for i in range(st["record_count"] - nrec, st["record_count"]):
            f, b, *rest = struct.unpack_from("<IH8B4hH", rec_raw, lay["pad_bytes"] * (i % lay["input_max"]))
            st["record"].append([f, b, list(rest[:8]), list(rest[8:12])])
    return st


def boot(seconds=90, interval=10, tag="run", gdb=False, extra=(), until_title=False, coverage=None, manifest=None,
         retries=2, shots=True):
    """boot_once, retried when xemu itself crashes (a host signal, seen in ~1 of 10 launches on macOS)."""
    for attempt in range(retries + 1):
        rep = boot_once(seconds, interval, tag, gdb, extra, until_title, coverage, manifest, shots)
        crashed = [smp for smp in rep["samples"] if (smp.get("exited") or 0) < 0]
        if not crashed:
            break
        print("  xemu crashed (signal %d); retrying" % -crashed[0]["exited"], file=sys.stderr)
        rep["xemu_crashes"] = attempt + 1
    return rep


def boot_once(seconds=90, interval=10, tag="run", gdb=False, extra=(), until_title=False, coverage=None,
              manifest=None, shots=True):
    """Boot the image and sample it every `interval` s: screenshot, boot step, EIP.

    Returns a report dict; "title" is true once g_BootSequenceStep is 0 (it starts at 1, counts
    up through the intro movies and drops to 0 on the press-start screen); "frozen" when the last three screenshots are identical.
    shots=False skips the screenshots: the framebuffer pmemsave during the new-game load is what wedges the monitor."""
    cov = None
    if coverage:
        from xemu_gdb import Coverage, Gdb
        x = Xemu(tag, True, list(extra) + ["-S"])
        cov = Coverage(Gdb(), coverage, x.t0)
        cov.start()
    else:
        x = Xemu(tag, gdb, extra)
    samples = []
    hyb = None
    try:
        while time.time() - x.t0 < seconds:
            time.sleep(max(0.0, interval - (time.time() - x.t0) % interval))
            if not x.alive():
                samples.append({"t": round(time.time() - x.t0), "exited": x.p.returncode})
                break
            t = round(time.time() - x.t0)
            path = os.path.join(x.outdir, "%03ds.png" % t)
            try:
                s = {"t": t, "step": x.u32(BOOT_STEP), "eip": "%#x" % (x.eip() or 0)}
                if shots:
                    s.update(fb=x.screenshot(path), png=os.path.relpath(path, ROOT))
                if manifest and manifest.get("g_hybrid"):
                    try:
                        hyb = read_hybrid(x, manifest, full=True)   # every sample: survives a later hang
                        s["frame"], s["ckpts"], s["polls"] = hyb["frame"], hyb["ckpt_count"], hyb["polls"]
                    except RuntimeError as e:                     # image not mapped yet (still booting)
                        s["hybrid_error"] = str(e)
            except (OSError, ValueError, IndexError) as e:      # socket timeout: the monitor stopped answering
                samples.append({"t": t, "monitor_error": repr(e)})
                print("  %4ds monitor error: %r" % (t, e), file=sys.stderr)
                break
            samples.append(s)
            print("  %(t)4ds step=%(step)s eip=%(eip)s fb=%(fb)s" % dict(s, fb=s.get("fb"))
                  + (" frame=%(frame)d ckpts=%(ckpts)d polls=%(polls)d" % s if "frame" in s else ""), file=sys.stderr)
            if until_title and s["step"] == 6 and len(samples) >= 2 and samples[-2].get("step") == 6:
                break
    finally:
        if cov:
            cov.stop()
            cov.join(timeout=10)
            cov.g.close()
        x.close()
    fbs = [s.get("fb") for s in samples if "fb" in s and s.get("step") != 0]
    rep = {"tag": tag, "samples": samples,
           "title": any(s.get("step") == 0 for s in samples),
           "frozen": len(fbs) >= 3 and len(set(fbs[-3:])) == 1,
           "exited": any("exited" in s for s in samples),
           "monitor_error": any("monitor_error" in s for s in samples)}
    if hyb is not None:
        rep["hybrid"] = hyb
    if cov:
        rep["coverage"] = {"patched": len(cov.addrs), "hit": len(cov.hits), "error": cov.error,
                           "hits": {"%#x" % a: t for a, t in sorted(cov.hits.items())}}
    json.dump(rep, open(os.path.join(x.outdir, "report.json"), "w"), indent=1)
    return rep


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("iso")
    i = sub.add_parser("install")
    i.add_argument("xbe")
    for name in ("boot", "run"):
        b = sub.add_parser(name)
        if name == "run":
            b.add_argument("xbe")
        b.add_argument("--seconds", type=float, default=90)
        b.add_argument("--interval", type=float, default=10)
        b.add_argument("--until-title", action="store_true")
        b.add_argument("--tag", default="run")
        b.add_argument("--gdb", action="store_true")
        b.add_argument("--coverage", action="store_true", help="count which patched functions run (gdb breakpoints)")
        b.add_argument("--manifest", help="the build's manifest JSON (default: next to XBE for run)")
    a = ap.parse_args(argv)
    if a.cmd == "iso":
        pack_iso()
    elif a.cmd == "install":
        install(a.xbe)
    else:
        if a.cmd == "run":
            install(a.xbe)
        mpath = a.manifest or (os.path.splitext(a.xbe)[0] + ".json" if a.cmd == "run" else None)
        man = json.load(open(mpath)) if mpath and os.path.exists(mpath) else None
        cov = [f["ours"] for f in man["functions"]] if a.coverage and man else None
        rep = boot(a.seconds, a.interval, a.tag, a.gdb, until_title=a.until_title, coverage=cov, manifest=man)
        summary = {k: v for k, v in rep.items() if k not in ("samples", "hybrid")}
        if "hybrid" in rep:
            summary["hybrid"] = {k: v for k, v in rep["hybrid"].items() if k not in ("checkpoints", "record")}
        if "coverage" in summary:
            summary["coverage"] = {k: v for k, v in summary["coverage"].items() if k != "hits"}
        print(json.dumps(summary))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
