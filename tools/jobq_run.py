#!/usr/bin/env python3
"""Host-side helper of tools/jobq.py (stdlib only, python 3.9 compatible). Runs on every host, including the laptop.

jobq.py copies this file to ~/hulk-jobs/jobq_run.py and calls it over ssh:
  has BH                      print "ready" if the base workspace BH is unpacked
  unpack BH HOME              stdin: tar.gz of the base tree -> ~/hulk-jobs/ws/base-BH (+ symlinks to HOME's build, isos...)
  run RUNID BH HOME LIMIT OUTS_JSON ATTEMPT HOST JOB PATHS_JSON -- CMD...
                              stdin: tar of overlay files. Clones the base into ~/hulk-jobs/run/RUNID, extracts the overlay,
                              runs CMD there (own process group, wall-clock LIMIT), then writes to stdout a tar with
                              .jq/exit.json, .jq/log and the OUTS paths, and removes the run directory.
  kill RUNID                  kill the run's process group and remove its directory
  gc KEEP                     keep the KEEP newest base workspaces; remove stale run directories
  probe                       print "load1 ncpu"
Exit status 97 from run: base workspace missing (the caller ships it and retries).
"""
import json
import os
import shutil
import signal
import subprocess
import sys
import tarfile
import time

JOBS = os.path.expanduser("~/hulk-jobs")
WS = os.path.join(JOBS, "ws")
RUN = os.path.join(JOBS, "run")
LINKS = ["build", "isos", "matches", "equivalent", "src", "config", "farm", "docs", "tools", "include", "tests"]
WHISKY = os.path.expanduser("~/Library/Application Support/com.isaacmarovitz.Whisky/Libraries/Wine/bin/wine64")
FORBIDDEN = ("drive-backup", "blockdev-backup", "blockdev-create", "drive-mirror", "Application Support/xemu")


def xemu_guard(argv):
    s = " ".join(argv)
    low = s.lower()
    if any(f.lower() in low for f in FORBIDDEN):
        return "forbidden xemu operation"
    if "xemu" in low and "-snapshot" not in argv:
        return "xemu without -snapshot"
    return None


def link_tree(root, home):
    """Symlink the directories not shipped in the base tree to the host's checkout."""
    for n in LINKS:
        d, t = os.path.join(root, n), os.path.join(home, n)
        if not os.path.lexists(d) and os.path.exists(t):
            os.symlink(t, d)


def clone(src, dst):
    for flags in ("-Rcp", "-Rp"):
        if subprocess.run(["cp", flags, src, dst], capture_output=True).returncode == 0:
            return
        shutil.rmtree(dst, ignore_errors=True)
    raise SystemExit("clone failed")


def safe_extract(tf, dest):
    for m in tf.getmembers():
        p = os.path.normpath(m.name)
        if p.startswith("/") or p.startswith(".."):
            raise SystemExit("unsafe path in archive: " + m.name)
        parts = p.split(os.sep)
        for i in range(1, len(parts)):      # never write through a symlinked directory (the host's shared checkout)
            if os.path.islink(os.path.join(dest, *parts[:i])):
                raise SystemExit("overlay path goes through a symlink: " + m.name)
        t = os.path.join(dest, p)
        if os.path.islink(t) or (os.path.isfile(t) and not m.isdir()):
            os.unlink(t)
    tf.extractall(dest)


def kill_group(pgid):
    for sig in (signal.SIGTERM, signal.SIGKILL):
        try:
            os.killpg(pgid, sig)
        except (ProcessLookupError, PermissionError):
            return
        time.sleep(1.5 if sig == signal.SIGTERM else 0)


def cmd_has(a):
    print("ready" if os.path.isdir(os.path.join(WS, "base-" + a[0])) else "none")


def cmd_unpack(a):
    bh, home = a
    home = os.path.expanduser(home)
    dst = os.path.join(WS, "base-" + bh)
    os.makedirs(WS, exist_ok=True)
    if os.path.isdir(dst):
        return
    tmp = "%s.tmp%d" % (dst, os.getpid())
    os.makedirs(tmp)
    with tarfile.open(fileobj=sys.stdin.buffer, mode="r|gz") as tf:
        for m in tf:
            p = os.path.normpath(m.name)
            if p.startswith("/") or p.startswith(".."):
                raise SystemExit("unsafe path")
            tf.extract(m, tmp)
    link_tree(tmp, home)
    try:
        os.rename(tmp, dst)
    except OSError:
        shutil.rmtree(tmp, ignore_errors=True)


def cmd_run(a):
    i = a.index("--")
    runid, bh, home, limit, outs, attempt, host, job, paths = a[:i]
    cmd = a[i + 1:]
    limit, outs, paths = int(limit), json.loads(outs), [os.path.expanduser(x) for x in json.loads(paths)]
    home = os.path.expanduser(home)
    payload = sys.stdin.buffer.read()
    base = os.path.join(WS, "base-" + bh)
    if not os.path.isdir(base):
        sys.exit(97)
    os.utime(base)
    why = xemu_guard(cmd)
    if why:
        sys.stderr.write(why + "\n")
        sys.exit(98)
    d = os.path.join(RUN, runid)
    os.makedirs(RUN, exist_ok=True)
    shutil.rmtree(d, ignore_errors=True)
    clone(base, d)
    if payload:
        import io
        with tarfile.open(fileobj=io.BytesIO(payload), mode="r:*") as tf:
            safe_extract(tf, d)
    env = dict(os.environ, JOBQ_JOB=job, JOBQ_ATTEMPT=attempt, JOBQ_HOST=host, JOBQ_RUN_DIR=d, JOBQ_HOME=home,
               PYTHONPYCACHEPREFIX=os.path.join(JOBS, "pyc"), PYTHONDONTWRITEBYTECODE="")
    env["PATH"] = os.pathsep.join(paths + [env.get("PATH", "")])
    cmd = list(cmd)
    if cmd[0] in ("python", "python3") and os.path.exists(os.path.join(d, "build/venv/bin/python")):
        cmd[0] = "build/venv/bin/python"
    elif cmd[0] in ("wine64", "wine"):
        cmd[0] = os.environ.get("WINE") or (WHISKY if os.path.exists(WHISKY) else os.path.expanduser("~/wine-whisky/Wine/bin/wine64"))
    logp = os.path.join(d, ".jq-log")
    t0, code, timed_out = time.time(), None, False
    with open(logp, "wb") as lg:
        try:
            p = subprocess.Popen(cmd, cwd=d, env=env, stdin=subprocess.DEVNULL, stdout=lg, stderr=subprocess.STDOUT,
                                 start_new_session=True)
            open(os.path.join(d, ".pgid"), "w").write(str(p.pid))
            try:
                code = p.wait(timeout=limit)
            except subprocess.TimeoutExpired:
                timed_out = True
                kill_group(p.pid)
                p.wait()
            else:
                try:
                    os.killpg(p.pid, signal.SIGKILL)    # orphans of the command
                except (ProcessLookupError, PermissionError):
                    pass
        except OSError as e:
            lg.write(("cannot start %r: %s\n" % (cmd[0], e)).encode())
            code = 127
    meta = json.dumps({"code": code, "timed_out": timed_out, "wall": round(time.time() - t0, 1), "host": host})
    with tarfile.open(fileobj=sys.stdout.buffer, mode="w|") as tf:
        mp = os.path.join(d, ".jq-exit")
        open(mp, "w").write(meta)
        tf.add(mp, ".jq/exit.json")
        tf.add(logp, ".jq/log")
        for o in outs:
            o = os.path.normpath(o)
            if o.startswith("/") or o.startswith(".."):
                continue
            if os.path.exists(os.path.join(d, o)):
                tf.add(os.path.join(d, o), o)
    sys.stdout.buffer.flush()
    shutil.rmtree(d, ignore_errors=True)


def cmd_kill(a):
    d = os.path.join(RUN, a[0])
    try:
        kill_group(int(open(os.path.join(d, ".pgid")).read()))
    except (OSError, ValueError):
        pass
    shutil.rmtree(d, ignore_errors=True)


def cmd_gc(a):
    keep = int(a[0])
    if os.path.isdir(WS):
        bases = sorted((os.path.join(WS, n) for n in os.listdir(WS)), key=os.path.getmtime, reverse=True)
        for p in bases[keep:]:
            shutil.rmtree(p, ignore_errors=True)
    if os.path.isdir(RUN):
        for n in os.listdir(RUN):
            p = os.path.join(RUN, n)
            if time.time() - os.path.getmtime(p) > 86400:
                cmd_kill([n])


def cmd_probe(a):
    print("%.2f %d" % (os.getloadavg()[0], os.cpu_count() or 1))


def main():
    c, a = sys.argv[1], sys.argv[2:]
    globals()["cmd_" + c](a)


if __name__ == "__main__":
    main()
