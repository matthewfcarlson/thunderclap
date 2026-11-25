#!/usr/bin/env python3
"""The online co-op handshake's secrets (wnet2; docs/multiplayer.md 18.1): the app key and the disc spot table.

Both live in ONE untracked file at the checkout's root, netplay.local.json (gitignored; HULK_NETPLAY_CONFIG names
another, e.g. a test's under build/<lane>/), beside the Worker's address the lead keeps there:
    {"worker_url": "https://...", "app_key": "<64 hex>", "disc_spots": [{"f", "o", "n", "h"}, ...]}
The app builds (tools/wasm_app.py, wasm_android.py, wasm_linux.py, wasm_build_job.py) compile worker_url and app_key
into the runner (never module memory); disc_spots go only to the Worker (a secret), never into the app.

  build/venv/bin/python tools/netplay_keys.py init [--disc SRC] [--spots 15] [--new-key] [--new-spots]
        adds what the file lacks (merging: other fields stay; mode 0600) and prints the wrangler commands
  build/venv/bin/python tools/netplay_keys.py check SRC [SRC ...]
        every spot read from each disc source (the extracted folder, an .iso, a .hulkdisc pack) must hash as recorded
  build/venv/bin/python tools/netplay_keys.py secret APP_KEY|DISC_SPOTS
        writes one value to stdout, for a pipe into `npx wrangler secret put NAME` (never into a log)
  build/venv/bin/python tools/netplay_keys.py status
        what the file holds (no values)

Disc spots are (file, offset, length) inside the disc's file tree, read as files (run/disc.c's hdisc_* in the app;
tools/disc_pack.py's sources here), never raw image offsets, so a folder, a trimmed or Redump .iso and a disc pack
answer alike. Only default.xbe and the .rcf archives holding no Bink movie qualify: an AV1 pack (tools/disc_av1.py)
zeroes each movie past its first 64 KiB, and packs add only their own .hulk/ files. The spot table is derived from the
game: it stays in the untracked file and in the Worker's secret, never in the repository.
"""
import argparse
import hashlib
import json
import os
import secrets
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
DEFAULT_DISC = os.path.join(ROOT, "isos/extracted")
SPOT_MIN, SPOT_MAX = 4096, 65536


def config_path():
    return os.environ.get("HULK_NETPLAY_CONFIG") or os.path.join(ROOT, "netplay.local.json")


def load(path=None):
    """The config (a dict; {} when the file is missing)."""
    p = path or config_path()
    try:
        with open(p) as f:
            v = json.load(f)
    except FileNotFoundError:
        return {}
    if not isinstance(v, dict):
        raise SystemExit("%s: not a JSON object" % p)
    return v


def save(cfg, path=None):
    """Write CFG (merged over what the file holds now: fields another writer added stay), mode 0600."""
    p = path or config_path()
    cur = load(p)
    cur.update(cfg)
    tmp = p + ".tmp"
    fd = os.open(tmp, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
    with os.fdopen(fd, "w") as f:
        json.dump(cur, f, indent=1)
        f.write("\n")
    os.chmod(tmp, 0o600)
    os.replace(tmp, p)


def eligible(src):
    """{name: size} of the files every disc source holds byte-identical: default.xbe and the movie-free archives."""
    import disc_av1
    out = {}
    for name, size in sorted(src.files.items()):
        low = name.lower()
        if name.startswith(".hulk/") or "/" in name:
            continue
        if low == "default.xbe":
            out[name] = size
        elif low.endswith(".rcf") and size > SPOT_MAX and not disc_av1.rcf_movies(src, name):
            out[name] = size
    return out


def sample(src, n):
    files = eligible(src)
    if "default.xbe" not in {k.lower() for k in files}:
        raise SystemExit("no default.xbe in the disc source")
    names = sorted(files)
    total = sum(files.values())
    rng = secrets.SystemRandom()
    spots = []
    # default.xbe always once (the build itself), the rest weighted by size
    picks = [next(k for k in names if k.lower() == "default.xbe")]
    while len(picks) < n:
        x = rng.randrange(total)
        for k in names:
            if x < files[k]:
                picks.append(k)
                break
            x -= files[k]
    for name in picks:
        ln = rng.randrange(SPOT_MIN, SPOT_MAX + 1)
        off = rng.randrange(0, files[name] - ln)
        data = src.read(name, off, ln)
        if len(data) != ln:
            raise SystemExit("short read: %s @%d" % (name, off))
        spots.append({"f": name, "o": off, "n": ln, "h": hashlib.sha256(data).hexdigest()})
    return spots


def wrangler_lines():
    me = "build/venv/bin/python tools/netplay_keys.py"
    return ["%s secret APP_KEY | (cd net/worker && npx wrangler secret put APP_KEY)" % me,
            "%s secret DISC_SPOTS | (cd net/worker && npx wrangler secret put DISC_SPOTS)" % me,
            "(cd net/worker && npx wrangler deploy)"]


def cmd_init(a):
    import disc_pack
    cfg = load()
    add = {}
    if a.new_key or not cfg.get("app_key"):
        add["app_key"] = secrets.token_hex(32)
    if a.new_spots or not cfg.get("disc_spots"):
        src = disc_pack.open_source(a.disc)
        add["disc_spots"] = sample(src, a.spots)
    if add:
        save(add)
    cfg = load()
    print("%s: %s" % (config_path(), ", ".join("%s %s" % (k, "set" if k in add else "kept") for k in
                                               ("app_key", "disc_spots") if k in cfg)))
    if "worker_url" not in cfg:
        print("note: no worker_url yet (the lead adds the Worker's address)")
    print("\nFrom the checkout's root, set the Worker's secrets (values go through the pipe, never on screen), then redeploy:")
    for l in wrangler_lines():
        print("  " + l)
    print("\nA new app key needs the apps rebuilt (old builds are then refused); new spots need no rebuild.")
    return 0


def cmd_check(a):
    import disc_pack
    spots = load().get("disc_spots") or []
    if not spots:
        raise SystemExit("no disc_spots in %s (netplay_keys.py init)" % config_path())
    ok = True
    for path in a.src:
        src = disc_pack.open_source(path)
        bad = []
        names = {k.lower(): k for k in src.files}
        for i, s in enumerate(spots):
            name = names.get(s["f"].lower())
            data = src.read(name, s["o"], s["n"]) if name else b""
            if hashlib.sha256(data).hexdigest() != s["h"]:
                bad.append(i)
        print("%s (%s): %d/%d spots %s" % (path, src.kind, len(spots) - len(bad), len(spots),
                                          "agree" if not bad else "agree; DIFFER: %s" % bad))
        ok = ok and not bad
    return 0 if ok else 1


def cmd_secret(a):
    cfg = load()
    if a.name == "APP_KEY":
        v = cfg.get("app_key")
    else:
        v = json.dumps(cfg.get("disc_spots"), separators=(",", ":")) if cfg.get("disc_spots") else None
    if not v:
        raise SystemExit("%s: no %s (netplay_keys.py init)" % (config_path(), a.name))
    if sys.stdout.isatty():
        raise SystemExit("refused: %s goes into a pipe (| npx wrangler secret put %s), not onto the screen" % (a.name, a.name))
    sys.stdout.write(v)
    return 0


def cmd_status(a):
    cfg = load()
    p = config_path()
    mode = oct(os.stat(p).st_mode & 0o777) if os.path.exists(p) else "missing"
    print("%s (%s): worker_url %s, app_key %s, disc_spots %s" % (
        p, mode, "set" if cfg.get("worker_url") else "-", "set" if cfg.get("app_key") else "-",
        "%d" % len(cfg["disc_spots"]) if cfg.get("disc_spots") else "-"))
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)
    q = sub.add_parser("init")
    q.add_argument("--disc", default=DEFAULT_DISC, help="the disc: extracted folder, .iso or .hulkdisc")
    q.add_argument("--spots", type=int, default=15)
    q.add_argument("--new-key", action="store_true", help="replace the app key (every app must be rebuilt)")
    q.add_argument("--new-spots", action="store_true", help="sample a new spot table")
    q.set_defaults(fn=cmd_init)
    q = sub.add_parser("check")
    q.add_argument("src", nargs="+")
    q.set_defaults(fn=cmd_check)
    q = sub.add_parser("secret")
    q.add_argument("name", choices=["APP_KEY", "DISC_SPOTS"])
    q.set_defaults(fn=cmd_secret)
    q = sub.add_parser("status")
    q.set_defaults(fn=cmd_status)
    a = p.parse_args(argv)
    return a.fn(a)


if __name__ == "__main__":
    sys.exit(main())
