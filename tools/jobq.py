#!/usr/bin/env python3
"""Shared job queue and scheduler: heavy compute spread over this machine and the remote Macs (docs/compute.md).

  jobq.py submit --name AGENT [--needs equiv|msvc|clang|wine|xemu|any] [--files PATH|SRC=DEST ...] [--dirty]
                 [--out PATH ...] [--limit S] [--slots N] [--attempts N] [--prio N] -- CMD...      prints the job id
  jobq.py submit-many FILE [same options]   FILE: jsonl ({"cmd": [...], "files": [...], "out": [...], ...}) or one
                                            shell command per line; prints one id per line
  jobq.py wait ID|A-B|--name AGENT [--timeout S]   exit 0 when all are done, 1 when any failed/gave up, 2 on timeout
  jobq.py status [--name AGENT] [--all]   |  result ID [--json]  |  cancel ID... | --name AGENT
  jobq.py hosts | daemon | ensure | gc | init-hosts

A job runs on a host with the needed capability in a fresh clone of "git archive HEAD tools include tests config"
plus the job's overlay files (uncommitted sources; --dirty overlays every modified/untracked file of those
directories). build/, isos/, matches/, equivalent/ ... are symlinks to the host's own checkout. The command's
output, the --out paths and the exit code come back to build/jobs/out/ID/. State and hosts: build/jobs/.
"""
import argparse
import fcntl
import hashlib
import io
import json
import os
import shlex
import shutil
import sqlite3
import subprocess
import sys
import tarfile
import threading
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
JOBS = os.environ.get("JOBQ_DIR") or os.path.join(ROOT, "build/jobs")
DB = os.path.join(JOBS, "queue.sqlite")
OUT = os.path.join(JOBS, "out")
STORE = os.path.join(JOBS, "store")
CACHE = os.path.join(JOBS, "cache")
LOCK = os.path.join(JOBS, "daemon.lock")
PIDF = os.path.join(JOBS, "daemon.pid")
DLOG = os.path.join(JOBS, "daemon.log")
HOSTS_STATE = os.path.join(JOBS, "hosts-state.json")
BASE_PATHS = ["tools", "include", "tests", "config"]
NEEDS = ["any", "equiv", "msvc", "clang", "wine", "xemu"]
TERMINAL = ("done", "failed", "gaveup", "cancelled")
SSH = ["ssh", "-o", "ConnectTimeout=20", "-o", "ServerAliveInterval=20", "-o", "ServerAliveCountMax=3",
       "-o", "BatchMode=yes"]
RUNNER_SRC = os.path.join(ROOT, "tools/jobq_run.py")
IDLE_EXIT = int(os.environ.get("JOBQ_IDLE_EXIT", "900"))
KEEP_BASES = 4
FORBIDDEN = ("drive-backup", "blockdev-backup", "blockdev-create", "drive-mirror", "Application Support/xemu")

SCHEMA = """
CREATE TABLE IF NOT EXISTS jobs (
  id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, cmd TEXT NOT NULL, needs TEXT NOT NULL DEFAULT 'any',
  files TEXT NOT NULL DEFAULT '{}', outs TEXT NOT NULL DEFAULT '[]', base_commit TEXT, base_paths TEXT,
  limit_s INTEGER NOT NULL DEFAULT 1800, slots INTEGER NOT NULL DEFAULT 1, prio INTEGER NOT NULL DEFAULT 0,
  attempts INTEGER NOT NULL DEFAULT 0, max_attempts INTEGER NOT NULL DEFAULT 3, state TEXT NOT NULL DEFAULT 'queued',
  host TEXT, tried TEXT NOT NULL DEFAULT '[]', submitted REAL, started REAL, finished REAL, exit_code INTEGER,
  reason TEXT, wall REAL, pin TEXT, cancel INTEGER NOT NULL DEFAULT 0, out_dir TEXT, log_path TEXT);
CREATE INDEX IF NOT EXISTS jobs_state ON jobs(state, id);
CREATE INDEX IF NOT EXISTS jobs_name ON jobs(name, id);
"""


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, file=sys.stderr, flush=True)


def conn():
    os.makedirs(JOBS, exist_ok=True)
    c = sqlite3.connect(DB, timeout=60)
    c.row_factory = sqlite3.Row
    c.execute("PRAGMA journal_mode=WAL")
    c.execute("PRAGMA synchronous=NORMAL")
    c.executescript(SCHEMA)
    try:
        c.execute("ALTER TABLE jobs ADD COLUMN pin TEXT")
    except sqlite3.OperationalError:
        pass
    return c


# ---------------------------------------------------------------------------------------------------- safety

def guard(argv, needs="any"):
    """Reason to refuse a command, or None. xemu only ever runs with -snapshot, never on this machine, and never
    with an operation that writes the disk image or touches the user's xemu settings."""
    s = " ".join(argv).lower()
    for f in FORBIDDEN:
        if f.lower() in s:
            return "forbidden xemu operation %r" % f
    if needs == "xemu" or "xemu" in s:
        if "-snapshot" not in argv:
            return "xemu jobs must pass -snapshot as its own argument"
    return None


# ---------------------------------------------------------------------------------------------------- overlay files

def _walk(path):
    if os.path.isdir(path):
        for d, dirs, fs in os.walk(path):
            dirs[:] = [x for x in dirs if x not in ("__pycache__", ".git")]
            for f in fs:
                if f != ".DS_Store" and not f.endswith(".pyc"):
                    yield os.path.join(d, f)
    elif os.path.exists(path):
        yield path


def store_file(src):
    h = hashlib.sha1()
    with open(src, "rb") as f:
        data = f.read()
    h.update(data)
    sha = h.hexdigest()
    os.makedirs(STORE, exist_ok=True)
    dst = os.path.join(STORE, sha)
    if not os.path.exists(dst):
        tmp = "%s.%d" % (dst, os.getpid())
        with open(tmp, "wb") as f:
            f.write(data)
        os.replace(tmp, dst)
    return sha


def collect_files(specs, dirty=False, base_paths=BASE_PATHS):
    """Snapshot working-tree files into the content store: {dest relative to the workspace: [sha, mode]}."""
    files = {}
    for sp in specs or []:
        src, _, dest = sp.partition("=")
        srcp = src if os.path.isabs(src) else os.path.join(os.getcwd(), src)
        if not os.path.exists(srcp):
            srcp = os.path.join(ROOT, src)
        if not os.path.exists(srcp):
            raise SystemExit("--files: %s does not exist" % src)
        for f in _walk(srcp):
            if dest:
                rel = dest if not os.path.isdir(srcp) else os.path.join(dest, os.path.relpath(f, srcp))
            else:
                rel = os.path.relpath(os.path.realpath(f) if not f.startswith(ROOT) else f, ROOT)
                if rel.startswith(".."):
                    raise SystemExit("--files: %s is outside the checkout (use SRC=DEST)" % f)
            files[rel] = [store_file(f), os.stat(f).st_mode & 0o777]
    if dirty:
        out = subprocess.run(["git", "status", "--porcelain", "-uall", "--"] + base_paths, cwd=ROOT,
                             capture_output=True, text=True).stdout
        for l in out.splitlines():
            st, path = l[:2], l[3:].split(" -> ")[-1].strip('"')
            if "D" in st or path.endswith(".pyc") or "__pycache__" in path:
                continue
            f = os.path.join(ROOT, path)
            if os.path.isfile(f) and os.path.getsize(f) <= 8 << 20:
                files[path] = [store_file(f), os.stat(f).st_mode & 0o777]
    return files


def payload_tar(files):
    """Overlay files as an uncompressed tar (empty bytes when there are none)."""
    if not files:
        return b""
    buf = io.BytesIO()
    with tarfile.open(fileobj=buf, mode="w") as t:
        for rel, (sha, mode) in sorted(files.items()):
            p = os.path.join(STORE, sha)
            ti = tarfile.TarInfo(rel)
            ti.size, ti.mode, ti.mtime = os.path.getsize(p), mode or 0o644, 0
            with open(p, "rb") as f:
                t.addfile(ti, f)
    return buf.getvalue()


def base_key(commit, paths):
    out = subprocess.run(["git", "ls-tree", commit, "--"] + list(paths), cwd=ROOT, capture_output=True, text=True,
                         check=True).stdout
    return hashlib.sha1(out.encode()).hexdigest()[:16]


def base_tar(commit, paths, key):
    p = os.path.join(CACHE, "base-%s.tgz" % key)
    if not os.path.exists(p):
        os.makedirs(CACHE, exist_ok=True)
        tmp = p + ".%d" % os.getpid()
        subprocess.run("git archive %s %s | gzip -1 > %s" % (commit, " ".join(map(shlex.quote, paths)), tmp),
                       shell=True, cwd=ROOT, check=True)
        os.replace(tmp, p)
        old = sorted((os.path.join(CACHE, n) for n in os.listdir(CACHE) if n.startswith("base-")),
                     key=os.path.getmtime, reverse=True)
        for o in old[KEEP_BASES:]:
            try:
                os.unlink(o)
            except OSError:
                pass
    os.utime(p)
    return p


# ---------------------------------------------------------------------------------------------------- submit & CLI

def head_commit():
    return subprocess.run(["git", "rev-parse", "HEAD"], cwd=ROOT, capture_output=True, text=True,
                          check=True).stdout.strip()


def make_job(name, cmd, needs="any", files=None, outs=None, limit=1800, slots=1, attempts=3, prio=0,
             commit=None, paths=None, pin=None):
    if needs not in NEEDS:
        raise SystemExit("--needs must be one of %s" % ", ".join(NEEDS))
    if not cmd:
        raise SystemExit("no command")
    why = guard(cmd, needs)
    if why:
        raise SystemExit("refused: " + why)
    return dict(name=name, cmd=json.dumps(cmd), needs=needs, files=json.dumps(files or {}),
                outs=json.dumps(outs or []), limit_s=int(limit), slots=max(1, int(slots)),
                max_attempts=max(1, int(attempts)), prio=int(prio), base_commit=commit,
                base_paths=json.dumps(paths or BASE_PATHS), submitted=time.time(), pin=pin)


def insert_jobs(jobs):
    ids = []
    c = conn()
    with c:
        for j in jobs:
            cols = ",".join(j)
            cur = c.execute("INSERT INTO jobs (%s) VALUES (%s)" % (cols, ",".join("?" * len(j))), list(j.values()))
            ids.append(cur.lastrowid)
    c.close()
    return ids


def submit_jobs(jobs, ensure_daemon=True):
    ids = insert_jobs(jobs)
    if ensure_daemon and not os.environ.get("JOBQ_NO_DAEMON"):
        ensure()
    return ids


def split_dashdash(argv):
    if "--" in argv:
        i = argv.index("--")
        return argv[:i], argv[i + 1:]
    return argv, []


def add_job_opts(p):
    p.add_argument("--name", required=True, help="submitter (agent) name")
    p.add_argument("--needs", default="any", choices=NEEDS)
    p.add_argument("--files", nargs="*", default=[], help="working-tree files/dirs to overlay (PATH or SRC=DEST)")
    p.add_argument("--dirty", action="store_true", help="overlay every modified/untracked file under tools include tests config")
    p.add_argument("--out", nargs="*", default=[], help="paths (relative to the workspace) to fetch")
    p.add_argument("--limit", type=int, default=1800, help="wall-clock seconds per attempt")
    p.add_argument("--slots", type=int, default=1, help="cpu slots the job uses on a host")
    p.add_argument("--attempts", type=int, default=3)
    p.add_argument("--prio", type=int, default=0)
    p.add_argument("--host", help="run only on this host (debugging)")
    p.add_argument("--base", nargs="*", default=BASE_PATHS, help="tracked paths of the base workspace")


def cmd_submit(a, cmd):
    commit = head_commit()
    files = collect_files(a.files, a.dirty, a.base)
    j = make_job(a.name, cmd, a.needs, files, a.out, a.limit, a.slots, a.attempts, a.prio, commit, a.base, a.host)
    print(submit_jobs([j])[0])
    return 0


def cmd_submit_many(a, _cmd):
    commit = head_commit()
    base_files = collect_files(a.files, a.dirty, a.base)
    jobs = []
    for l in open(a.file):
        l = l.strip()
        if not l or l.startswith("#"):
            continue
        if l.startswith("{"):
            d = json.loads(l)
            cmd = d["cmd"] if isinstance(d["cmd"], list) else shlex.split(d["cmd"])
            f = dict(base_files)
            f.update(collect_files(d.get("files"), False, a.base))
            jobs.append(make_job(d.get("name", a.name), cmd, d.get("needs", a.needs), f, d.get("out", a.out),
                                 d.get("limit", a.limit), d.get("slots", a.slots), d.get("attempts", a.attempts),
                                 d.get("prio", a.prio), commit, a.base))
        else:
            jobs.append(make_job(a.name, shlex.split(l), a.needs, base_files, a.out, a.limit, a.slots, a.attempts,
                                 a.prio, commit, a.base))
    for i in submit_jobs(jobs):
        print(i)
    return 0


def parse_ids(specs):
    ids = []
    for s in specs:
        for part in s.split(","):
            if "-" in part:
                lo, hi = part.split("-")
                ids += range(int(lo), int(hi) + 1)
            elif part:
                ids.append(int(part))
    return ids


def select_ids(c, a):
    ids = parse_ids(getattr(a, "ids", []) or [])
    if getattr(a, "name", None):
        ids += [r[0] for r in c.execute("SELECT id FROM jobs WHERE name=? AND state NOT IN %s" % str(TERMINAL), (a.name,))]
    return sorted(set(ids))


def cmd_wait(a, _c):
    c = conn()
    ids = select_ids(c, a)
    if not ids:
        print("nothing to wait for")
        return 0
    t0, pending, last, bad = time.time(), set(ids), 0, 0
    while pending:
        rows = c.execute("SELECT id,state,exit_code,host,reason FROM jobs WHERE id IN (%s)" % ",".join(map(str, sorted(pending)))).fetchall()
        for r in rows:
            if r["state"] in TERMINAL:
                pending.discard(r["id"])
                bad += r["state"] != "done"
                if not a.quiet:
                    print("%d %s exit=%s host=%s%s" % (r["id"], r["state"], r["exit_code"], r["host"],
                                                       " (%s)" % r["reason"] if r["reason"] else ""), flush=True)
        if not pending:
            break
        if a.timeout and time.time() - t0 > a.timeout:
            print("timeout, %d still pending" % len(pending), file=sys.stderr)
            return 2
        if not os.environ.get("JOBQ_NO_DAEMON") and time.time() - last > 30:
            ensure()
            last = time.time()
        time.sleep(1)
    return 1 if bad else 0


def fmt_age(t):
    return "-" if not t else "%ds" % (time.time() - t)


def cmd_status(a, _c):
    c = conn()
    q = "SELECT name,state,count(*) n FROM jobs %s GROUP BY name,state ORDER BY name"
    rows = c.execute(q % ("WHERE name=?" if a.name else ""), (a.name,) if a.name else ()).fetchall()
    by = {}
    for r in rows:
        by.setdefault(r["name"], {})[r["state"]] = r["n"]
    for n, d in by.items():
        if a.all or any(s not in TERMINAL for s in d):
            print("%-14s %s" % (n, "  ".join("%s=%d" % kv for kv in sorted(d.items()))))
    if not by:
        print("no jobs")
    run = c.execute("SELECT id,name,host,started,attempts,cmd FROM jobs WHERE state='running'" +
                    (" AND name=?" if a.name else "") + " ORDER BY started LIMIT 40", (a.name,) if a.name else ()).fetchall()
    for r in run:
        print("  running %d %s on %s for %s (attempt %d): %s" % (r["id"], r["name"], r["host"], fmt_age(r["started"]),
                                                                 r["attempts"], " ".join(json.loads(r["cmd"]))[:80]))
    print_hosts()
    return 0


def print_hosts():
    try:
        st = json.load(open(HOSTS_STATE))
    except (OSError, ValueError):
        print("daemon: not running (no host state)")
        return
    age = time.time() - st["time"]
    print("daemon: %s" % ("running" if daemon_running() else "NOT running") + ", state %ds old" % age)
    for h in st["hosts"]:
        print("  %-8s %s/%s slots busy (config %s, load %.1f/%d cpu) done=%d failed=%d%s"
              % (h["name"], h["used"], h["cap"], h["cfg"], h["load"], h["ncpu"], h["ok"], h["bad"],
                 " DOWN" if h["down"] else ""))


def cmd_result(a, _c):
    c = conn()
    r = c.execute("SELECT * FROM jobs WHERE id=?", (a.id,)).fetchone()
    if not r:
        print("no such job", file=sys.stderr)
        return 3
    d = dict(r)
    od = os.path.join(OUT, str(r["id"]))
    d["outputs"] = sorted(os.path.relpath(os.path.join(dp, f), ROOT) for dp, _, fs in os.walk(od) for f in fs) if os.path.isdir(od) else []
    d["log"] = os.path.relpath(os.path.join(od, "log"), ROOT) if os.path.exists(os.path.join(od, "log")) else None
    if a.json:
        print(json.dumps(d))
    else:
        print("job %d %s exit=%s host=%s attempts=%d wall=%s%s" % (r["id"], r["state"], r["exit_code"], r["host"],
              r["attempts"], r["wall"], " reason=%s" % r["reason"] if r["reason"] else ""))
        print("log: %s" % d["log"])
        for o in d["outputs"]:
            if not o.endswith("/log"):
                print("output: %s" % o)
    return 0 if r["state"] == "done" else 1


def cmd_cancel(a, _c):
    c = conn()
    ids = select_ids(c, a)
    with c:
        for i in ids:
            c.execute("UPDATE jobs SET cancel=1 WHERE id=? AND state IN ('queued','running')", (i,))
            c.execute("UPDATE jobs SET state='cancelled', finished=?, reason='cancelled' WHERE id=? AND state='queued'",
                      (time.time(), i))
    print("cancelled %d job(s)" % len(ids))
    return 0


def cmd_gc(a, _c):
    c = conn()
    cutoff = time.time() - a.days * 86400
    rows = c.execute("SELECT id FROM jobs WHERE state IN %s AND finished<?" % str(TERMINAL), (cutoff,)).fetchall()
    for r in rows:
        shutil.rmtree(os.path.join(OUT, str(r["id"])), ignore_errors=True)
    used = set()
    for r in c.execute("SELECT files FROM jobs WHERE state IN ('queued','running') OR finished>=?", (cutoff,)):
        used |= {v[0] for v in json.loads(r["files"]).values()}
    n = 0
    if os.path.isdir(STORE):
        for f in os.listdir(STORE):
            if f not in used and os.path.getmtime(os.path.join(STORE, f)) < cutoff:
                os.unlink(os.path.join(STORE, f))
                n += 1
    with c:
        c.execute("DELETE FROM jobs WHERE state IN %s AND finished<?" % str(TERMINAL), (cutoff,))
    print("removed %d old job(s), %d stored file(s)" % (len(rows), n))
    return 0


# ---------------------------------------------------------------------------------------------------- hosts

def load_hosts():
    path = os.environ.get("JOBQ_HOSTS") or os.path.join(JOBS, "hosts.json")
    if not os.path.exists(path):
        src = os.path.join(ROOT, "build/agent-tools/hosts.json")
        hs = []
        if os.path.exists(src):
            for h in json.load(open(src))["hosts"]:
                h = dict(h)
                h.setdefault("caps", ["equiv", "msvc", "clang"])
                h.setdefault("pref", 0)
                h.setdefault("path", ["~/llvm/bin"])
                hs.append(h)
        hs.append({"name": "local", "local": True, "slots": 3, "pref": 90,
                   "caps": ["equiv", "msvc", "clang", "wine"], "path": ["/opt/homebrew/opt/llvm/bin"]})
        os.makedirs(JOBS, exist_ok=True)
        json.dump({"hosts": hs}, open(path, "w"), indent=1)
    return json.load(open(path))["hosts"]


class Host:
    def __init__(self, cfg):
        self.cfg = cfg
        self.name = cfg["name"]
        self.local = bool(cfg.get("local"))
        self.caps = set(cfg.get("caps", []))
        self.pref = cfg.get("pref", 90 if self.local else 0)
        self.slots_cfg = cfg.get("slots", 3 if self.local else 8)
        self.min_slots = 1 if self.local else 2
        self.xemu_max = cfg.get("xemu_max", 1) if "xemu" in self.caps else 0
        self.dir = cfg.get("dir", "hulk-permute")
        self.paths = cfg.get("path", [])
        self.route = None
        self.cap = self.slots_cfg
        self.used = 0
        self.xemu_used = 0
        self.load, self.ncpu = 0.0, 1
        self.fails = 0
        self.down_until = 0
        self.ok = self.bad = 0
        self.bases = set()
        self.lock = threading.Lock()      # serialises shipping a base tree
        self.next_probe = 0
        self.ready = False

    @property
    def home(self):
        return ROOT if self.local else "~/" + self.dir

    def argv(self, args, route=None):
        """Command line that runs jobq_run.py with ARGS on this host."""
        if self.local:
            return [sys.executable, RUNNER_SRC] + args
        remote = 'python3 "$HOME/hulk-jobs/jobq_run.py" ' + " ".join(shlex.quote(x) for x in args)
        return SSH + (route or self.route) + [remote]

    def call(self, args, stdin=None, timeout=120, route=None):
        return subprocess.run(self.argv(args, route), input=stdin, capture_output=True, timeout=timeout)

    def connect(self):
        """Pick a working route, install the runner, read the load. False when unreachable."""
        if self.local:
            self.route = []
        else:
            src = open(RUNNER_SRC, "rb").read()
            for r in self.cfg["routes"]:
                try:
                    p = subprocess.run(SSH + r + ['mkdir -p "$HOME/hulk-jobs" && cat > "$HOME/hulk-jobs/jobq_run.py.new" && '
                                                  'mv "$HOME/hulk-jobs/jobq_run.py.new" "$HOME/hulk-jobs/jobq_run.py"'],
                                       input=src, capture_output=True, timeout=90)
                except subprocess.TimeoutExpired:
                    continue
                if p.returncode == 0:
                    self.route = r
                    break
            else:
                return False
        return self.probe()

    def probe(self):
        try:
            p = self.call(["probe"], timeout=60)
        except subprocess.TimeoutExpired:
            return False
        if p.returncode:
            return False
        load, ncpu = p.stdout.split()
        self.load, self.ncpu = float(load), int(ncpu)
        foreign = max(0.0, self.load - 0.9 * self.used)
        self.cap = max(self.min_slots, min(self.slots_cfg, int(self.ncpu - foreign) + 2))
        self.next_probe = time.time() + 30
        self.ready = True
        return True

    def eligible(self, job, now):
        if now < self.down_until or not self.ready:
            return False
        needs = job["needs"]
        if job.get("pin") if isinstance(job, dict) else job["pin"]:
            if job["pin"] != self.name:
                return False
        if needs != "any" and needs not in self.caps:
            return False
        if needs == "xemu" or "xemu" in job["cmd"].lower():
            if self.local or self.xemu_used >= self.xemu_max:
                return False
        return self.cap - self.used >= job["slots"] or (self.used == 0 and self.cap > 0)


def choose_host(job, hosts, now=None):
    """The host a queued job should go to, or None: untried hosts first, then lowest preference value (remotes before
    the laptop), then the least loaded in proportion to its slots."""
    now = now or time.time()
    tried = json.loads(job["tried"]) if isinstance(job["tried"], str) else job["tried"]
    best, bk = None, None
    for h in hosts:
        if h.eligible(job, now):
            k = (h.name in tried, h.pref, h.used / max(1, h.cap))
            if bk is None or k < bk:
                best, bk = h, k
    return best


# ---------------------------------------------------------------------------------------------------- daemon

class Infra(Exception):
    """The attempt failed for a reason that is not the command's (ssh drop, timeout, missing tools): retry elsewhere."""


class Daemon:
    def __init__(self, hosts):
        self.hosts = hosts
        self.live = {}           # job id -> cancel Event
        self.lock = threading.Lock()
        self.idle_since = time.time()
        self.last_gc = 0

    # --- state transitions (DB) ---
    def claim(self, c, job, h):
        with c:
            tried = json.loads(job["tried"]) + [h.name]
            cur = c.execute("UPDATE jobs SET state='running', host=?, attempts=attempts+1, started=?, tried=?, reason=NULL "
                            "WHERE id=? AND state='queued'", (h.name, time.time(), json.dumps(tried), job["id"]))
        return cur.rowcount == 1

    def finish(self, jid, state, code, wall, reason, host):
        c = conn()
        with c:
            c.execute("UPDATE jobs SET state=?, exit_code=?, wall=?, reason=?, finished=?, host=? WHERE id=?",
                      (state, code, wall, reason, time.time(), host, jid))
        c.close()

    def requeue_or_giveup(self, jid, reason):
        c = conn()
        with c:
            r = c.execute("SELECT attempts,max_attempts FROM jobs WHERE id=?", (jid,)).fetchone()
            if r["attempts"] >= r["max_attempts"]:
                c.execute("UPDATE jobs SET state='gaveup', reason=?, finished=? WHERE id=?", (reason, time.time(), jid))
            else:
                c.execute("UPDATE jobs SET state='queued', reason=? WHERE id=?", (reason, jid))
        c.close()

    # --- one attempt ---
    def ensure_base(self, h, commit, paths, key):
        with h.lock:
            if key in h.bases:
                return
            p = h.call(["has", key], timeout=60)
            if p.returncode == 0 and b"ready" in p.stdout:
                h.bases.add(key)
                return
            tgz = base_tar(commit, paths, key)
            with open(tgz, "rb") as f:
                p = h.call(["unpack", key, h.home], stdin=f.read(), timeout=600)
            if p.returncode:
                raise Infra("shipping the base tree failed: " + p.stderr.decode()[-200:])
            h.bases.add(key)
            log("%s: base tree %s installed" % (h.name, key))

    def attempt(self, h, job, cancel):
        jid, att = job["id"], job["attempts"] + 1
        runid = "%d-a%d" % (jid, att)
        od = os.path.join(OUT, str(jid))
        os.makedirs(od, exist_ok=True)
        cmd, outs = json.loads(job["cmd"]), json.loads(job["outs"])
        why = guard(cmd, job["needs"])
        if why or ((job["needs"] == "xemu" or "xemu" in " ".join(cmd).lower()) and h.local):
            return "failed", 98, 0, why or "xemu never runs on the laptop"
        paths = json.loads(job["base_paths"] or "null") or BASE_PATHS
        commit = job["base_commit"] or head_commit()
        key = base_key(commit, paths)
        payload = payload_tar(json.loads(job["files"]))
        args = ["run", runid, key, h.home, str(job["limit_s"]), json.dumps(outs), str(att), h.name, str(jid),
                json.dumps(h.paths), "--"] + cmd
        res = os.path.join(od, ".result.tar")
        for rnd in range(3):
            self.ensure_base(h, commit, paths, key)
            t0 = time.time()
            with open(res, "wb") as rf:
                pr = subprocess.Popen(h.argv(args), stdin=subprocess.PIPE, stdout=rf, stderr=subprocess.PIPE)
                err = b""
                first = True
                try:
                    while True:
                        try:
                            _, err = pr.communicate(payload if first else None, timeout=2)
                            break
                        except subprocess.TimeoutExpired:
                            first = False
                            if cancel.is_set():
                                pr.kill()
                                pr.wait()
                                self.remote_kill(h, runid)
                                return "cancelled", None, time.time() - t0, "cancelled"
                            if time.time() - t0 > job["limit_s"] + 120:
                                pr.kill()
                                pr.wait()
                                raise Infra("no answer %ds after the limit" % 120)
                except BaseException:
                    if pr.poll() is None:
                        pr.kill()
                    raise
            if pr.returncode == 97:
                h.bases.discard(key)
                continue
            break
        else:
            raise Infra("base tree keeps disappearing")
        if pr.returncode == 98:
            return "failed", 98, 0, "guard: " + err.decode()[-100:].strip()
        meta = self.unpack_result(res, od, att)
        if meta is None:
            raise Infra("ssh/remote exit %d: %s" % (pr.returncode, err.decode(errors="replace")[-150:].strip()))
        if meta["timed_out"]:
            raise Infra("wall-clock limit %ds" % job["limit_s"])
        return ("done" if meta["code"] == 0 else "failed"), meta["code"], meta["wall"], None

    def unpack_result(self, res, od, att):
        try:
            with tarfile.open(res, "r:") as tf:
                names = tf.getnames()
                if ".jq/exit.json" not in names:
                    return None
                meta = json.load(tf.extractfile(".jq/exit.json"))
                for m in tf.getmembers():
                    n = os.path.normpath(m.name)
                    if n.startswith("/") or n.startswith("..") or n == ".jq/exit.json" or m.islnk():
                        continue
                    if n == ".jq/log":
                        with open(os.path.join(od, "log"), "wb") as f:
                            shutil.copyfileobj(tf.extractfile(m), f)
                        if meta["timed_out"]:
                            shutil.copyfile(os.path.join(od, "log"), os.path.join(od, "log.a%d" % att))
                        continue
                    try:
                        tf.extract(m, od, filter="data")
                    except TypeError:
                        tf.extract(m, od)
            os.unlink(res)
            return meta
        except (tarfile.TarError, EOFError, OSError, ValueError, KeyError):
            return None

    def remote_kill(self, h, runid):
        try:
            h.call(["kill", runid], timeout=60)
        except Exception:
            pass

    def run_job(self, h, job):
        jid = job["id"]
        cancel = self.live[jid]
        runid = "%d-a%d" % (jid, job["attempts"] + 1)
        t0 = time.time()
        try:
            state, code, wall, reason = self.attempt(h, job, cancel)
        except Infra as e:
            self.remote_kill(h, runid)
            reason = str(e)
            log("%s: job %d attempt failed (%s)" % (h.name, jid, reason))
            h.bad += 1
            if "ssh" in reason or "no answer" in reason or "shipping" in reason:
                h.fails += 1
                if h.fails >= 3:
                    h.down_until = time.time() + 120
                    h.fails, h.ready = 0, False
                    log("%s: marked down for 120s" % h.name)
            self.requeue_or_giveup(jid, reason)
        except Exception as e:      # a bug or an odd failure must not lose the job
            self.remote_kill(h, runid)
            log("%s: job %d internal error %r" % (h.name, jid, e))
            self.requeue_or_giveup(jid, "internal error %r" % (e,))
        else:
            h.fails = 0
            if state == "cancelled":
                self.finish(jid, "cancelled", None, wall, reason, h.name)
            else:
                h.ok += 1
                self.finish(jid, state, code, wall, reason, h.name)
        finally:
            with self.lock:
                h.used -= job["slots"]
                if job["needs"] == "xemu" or "xemu" in job["cmd"].lower():
                    h.xemu_used -= 1
                self.live.pop(jid, None)

    # --- main loop ---
    def dispatch(self, c):
        now = time.time()
        rows = c.execute("SELECT id,name,needs,slots,prio,tried,cmd,pin FROM jobs WHERE state='queued' ORDER BY prio DESC, id LIMIT 4000").fetchall()
        if not rows:
            return 0
        running = {}
        for r in c.execute("SELECT name,count(*) n FROM jobs WHERE state='running' GROUP BY name"):
            running[r["name"]] = r["n"]
        # fairness: the submitter with the fewest running jobs goes first, then the queue order
        order = sorted(range(len(rows)), key=lambda i: (-rows[i]["prio"], running.get(rows[i]["name"], 0), rows[i]["id"]))
        n = 0
        for i in order:
            r = rows[i]
            h = choose_host(r, self.hosts, now)
            if h is None:
                if all(x.cap - x.used <= 0 or now < x.down_until for x in self.hosts):
                    break
                continue
            job = c.execute("SELECT * FROM jobs WHERE id=?", (r["id"],)).fetchone()
            if not self.claim(c, job, h):
                continue
            job = dict(job)
            with self.lock:
                h.used += job["slots"]
                if job["needs"] == "xemu" or "xemu" in job["cmd"].lower():
                    h.xemu_used += 1
                self.live[job["id"]] = threading.Event()
            running[r["name"]] = running.get(r["name"], 0) + 1
            threading.Thread(target=self.run_job, args=(h, job), daemon=True).start()
            n += 1
        return n

    def write_state(self):
        st = {"time": time.time(), "hosts": [dict(name=h.name, used=h.used, cap=h.cap, cfg=h.slots_cfg, load=h.load,
              ncpu=h.ncpu, ok=h.ok, bad=h.bad, down=time.time() < h.down_until or not h.ready) for h in self.hosts]}
        tmp = HOSTS_STATE + ".tmp"
        with open(tmp, "w") as f:
            json.dump(st, f)
        os.replace(tmp, HOSTS_STATE)

    def recover(self, c):
        """Jobs left 'running' by a dead daemon go back to the queue; their remote leftovers are killed."""
        rows = c.execute("SELECT id,host,attempts FROM jobs WHERE state='running'").fetchall()
        for r in rows:
            h = next((x for x in self.hosts if x.name == r["host"]), None)
            if h and h.ready:
                self.remote_kill(h, "%d-a%d" % (r["id"], r["attempts"]))
            self.requeue_or_giveup(r["id"], "daemon restarted")
        if rows:
            log("recovered %d running job(s)" % len(rows))

    def loop(self):
        c = conn()
        for h in self.hosts:
            if not h.connect():
                h.down_until = time.time() + 60
                log("%s: unreachable" % h.name)
            else:
                log("%s: %d slots (config %d, load %.1f on %d cpus)" % (h.name, h.cap, h.slots_cfg, h.load, h.ncpu))
        self.recover(c)
        last_state = 0
        while True:
            now = time.time()
            for h in self.hosts:
                if h.down_until and now >= h.down_until:
                    h.down_until = 0
                    if not h.connect():
                        h.down_until = now + 120
                elif h.ready and now >= h.next_probe:
                    if not h.probe():
                        h.down_until = now + 60
                        h.ready = False
            for r in c.execute("SELECT id FROM jobs WHERE cancel=1 AND state='running'").fetchall():
                ev = self.live.get(r["id"])
                if ev:
                    ev.set()
            self.dispatch(c)
            if now - last_state > 5:
                self.write_state()
                last_state = now
            n = c.execute("SELECT count(*) FROM jobs WHERE state IN ('queued','running')").fetchone()[0]
            if n or self.live:
                self.idle_since = now
            elif now - self.idle_since > IDLE_EXIT:
                log("idle for %ds, exiting" % IDLE_EXIT)
                return
            if now - self.last_gc > 3600:
                self.last_gc = now
                for h in self.hosts:
                    if h.ready:
                        try:
                            h.call(["gc", str(KEEP_BASES)], timeout=120)
                        except Exception:
                            pass
            time.sleep(1)


def daemon_running():
    try:
        fd = os.open(LOCK, os.O_RDWR | os.O_CREAT)
    except OSError:
        return False
    try:
        fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
        fcntl.flock(fd, fcntl.LOCK_UN)
        return False
    except OSError:
        return True
    finally:
        os.close(fd)


def ensure():
    if daemon_running():
        return False
    os.makedirs(JOBS, exist_ok=True)
    lf = open(DLOG, "ab")
    subprocess.Popen([sys.executable, os.path.abspath(__file__), "daemon"], stdin=subprocess.DEVNULL, stdout=lf, stderr=lf,
                     start_new_session=True, cwd=ROOT)
    for _ in range(50):
        time.sleep(0.1)
        if daemon_running():
            break
    return True


def cmd_daemon(a, _c):
    os.makedirs(JOBS, exist_ok=True)
    fd = os.open(LOCK, os.O_RDWR | os.O_CREAT)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        print("daemon already running")
        return 0
    open(PIDF, "w").write(str(os.getpid()))
    log("daemon started, pid %d" % os.getpid())
    hosts = [Host(h) for h in load_hosts() if not a.only or h["name"] in a.only.split(",")]
    Daemon(hosts).loop()
    return 0


def cmd_ensure(a, _c):
    print("started" if ensure() else "already running")
    return 0


def cmd_hosts(a, _c):
    print_hosts()
    return 0


def main():
    argv, cmd = split_dashdash(sys.argv[1:])
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="c", required=True)
    s = sub.add_parser("submit")
    add_job_opts(s)
    s = sub.add_parser("submit-many")
    s.add_argument("file")
    add_job_opts(s)
    s = sub.add_parser("wait")
    s.add_argument("ids", nargs="*")
    s.add_argument("--name")
    s.add_argument("--timeout", type=float)
    s.add_argument("--quiet", action="store_true")
    s = sub.add_parser("status")
    s.add_argument("--name")
    s.add_argument("--all", action="store_true")
    s = sub.add_parser("result")
    s.add_argument("id", type=int)
    s.add_argument("--json", action="store_true")
    s = sub.add_parser("cancel")
    s.add_argument("ids", nargs="*")
    s.add_argument("--name")
    s = sub.add_parser("gc")
    s.add_argument("--days", type=float, default=14)
    s = sub.add_parser("daemon")
    s.add_argument("--only")
    sub.add_parser("ensure")
    sub.add_parser("hosts")
    sub.add_parser("init-hosts")
    a = p.parse_args(argv)
    fn = {"submit": cmd_submit, "submit-many": cmd_submit_many, "wait": cmd_wait, "status": cmd_status,
          "result": cmd_result, "cancel": cmd_cancel, "gc": cmd_gc, "daemon": cmd_daemon, "ensure": cmd_ensure,
          "hosts": cmd_hosts, "init-hosts": lambda a, c: (load_hosts() and 0)}[a.c]
    return fn(a, cmd) or 0


if __name__ == "__main__":
    sys.exit(main())
