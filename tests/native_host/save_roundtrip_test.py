#!/usr/bin/env python3
"""The native save round trip (drive1, D141) on arm64 macOS: the image writes a save through the game's own path and
reads it back (src/platform/sdl/host/save_selftest.cpp, the entry hook on 0x0008c470 in native_hooks.h).

  build/venv/bin/python tests/native_host/save_roundtrip_test.py --binary PATH/hulk-mac [--data isos/extracted]

PATH is a native_mac.py link (`link --ld`). The image starts as usual; right after CMemoryCardManager mounts U: it
saves 0xbe8 bytes as "SELFTEST" (CMemoryCardManager::FUN_0008cbe0: the InstanceDrive's save open, core::File's write
and commit, XboxSaveDrive's signed blocks), loads the first save back (FUN_0008ca70: the save enumeration, the open,
core::File's read, the signature check), compares and exits. The test passes when the image exits 0 with
"save-selftest: ok" and the save backend holds the save (the hard disk's U: is HULK_UDATA_DIR: <title id>/save.dat). It needs the player's extracted disc
(the start-up reads it) and start-up to reach the mount natively (2026-11-19: HEAD stops earlier, at CGame's script
registrations; drive1 ran it on a private kit with find1's start-up patches, docs/native-build.md "drive1 D141").
"""
import argparse
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", required=True)
    ap.add_argument("--data", default=os.path.join(ROOT, "isos/extracted"))
    ap.add_argument("--timeout", type=int, default=120)
    ap.add_argument("--strict-missing", action="store_true",
                    help="stop at the first unbound name (default: HULK_NATIVE_MISSING=continue, as start-up still has some)")
    a = ap.parse_args()
    with tempfile.TemporaryDirectory(prefix="hulk-save-") as tmp:
        dirs = {k: os.path.join(tmp, k) for k in ("save", "tdata", "udata")}
        for d in dirs.values():
            os.makedirs(d)
        env = dict(os.environ, HULK_SAVE_SELFTEST="1", HULK_DATA_DIR=a.data, HULK_SAVE_DIR=dirs["save"],
                   HULK_TDATA_DIR=dirs["tdata"], HULK_UDATA_DIR=dirs["udata"], SDL_AUDIO_DRIVER="dummy",
                   HULK_TRACE_FILE=os.path.join(tmp, "trace.txt"))
        if not a.strict_missing:
            env["HULK_NATIVE_MISSING"] = "continue"
        try:
            p = subprocess.run([a.binary], env=env, capture_output=True, text=True, timeout=a.timeout)
        except subprocess.TimeoutExpired:
            print("FAIL: the image did not exit in %d s (start-up did not reach the U: mount?)" % a.timeout)
            return 1
        lines = [l for l in (p.stderr + p.stdout).splitlines() if l.startswith("save-selftest:")]
        for l in lines:
            print(l)
        files = []
        for base, _d, fs in os.walk(dirs["udata"]):
            files += [os.path.relpath(os.path.join(base, f), dirs["udata"]) for f in fs if f == "save.dat"]
        print("save files: %s" % (", ".join(sorted(files)) or "none"))
        if p.returncode != 0 or "save-selftest: ok" not in lines or not files:
            if not lines:
                trace = os.path.join(tmp, "trace.txt")
                tail = open(trace).read().splitlines()[-8:] if os.path.exists(trace) else []
                print("no self-test line: start-up stopped before the mount?\n  " + "\n  ".join(tail))
            print("FAIL (exit %d)" % p.returncode)
            return 1
        print("ok")
        return 0


if __name__ == "__main__":
    sys.exit(main())
