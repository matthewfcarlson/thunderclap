#!/usr/bin/env python3
"""Work-queue dispatcher for remote equivalence checks (used by promote-remote.sh).

Usage: tools/promote_dispatch.py NAME LIST OUT.jsonl --hosts hosts.json [--status FILE] [options]
LIST has one "0xADDR path/to/source.cpp" per line. Small batches are handed to whichever remote host has free
slots, so faster hosts take more work. A batch whose remote run dies, whose ssh drops, that yields no result
line, or that exceeds its wall-clock limit goes back on the queue (preferably to another host); a function that
completes with any status other than "error" is a result, not a retry.

hosts.json (kept out of version control; it holds user and host names):
  {"hosts": [{"name": "h1", "slots": 14, "dir": "checkout-dir-in-remote-home",
              "routes": [["user@host"], ["-J", "user@jump", "user@host"]]}]}
Routes are tried in order (ssh arguments ending in the target). Each host needs build/venv and the data files
already in <dir>; tools/ and include/ from git HEAD are shipped once per host per run.
"""
import argparse, io, json, math, os, re, subprocess, sys, tarfile, tempfile, threading, time

SSH = ["ssh", "-o", "ConnectTimeout=20", "-o", "ServerAliveInterval=20", "-o", "ServerAliveCountMax=3",
       "-o", "BatchMode=yes"]


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, file=sys.stderr, flush=True)


class Host:
    def __init__(self, cfg, adapt):
        self.name, self.dir = cfg["name"], cfg.get("dir", "hulk-permute")
        self.routes, self.cfg_slots, self.adapt = cfg["routes"], cfg["slots"], adapt
        self.route = None
        self.slots = 0
        self.used = 0
        self.fails = 0
        self.down_until = 0
        self.done = 0          # functions with a result from this host
        self.batches_ok = 0
        self.batches_bad = 0
        self.ready = False

    def ssh(self, cmd, stdin=None, timeout=None, route=None):
        r = route or self.route
        return subprocess.run(SSH + r + [cmd], input=stdin, capture_output=True, timeout=timeout)

    def connect(self):
        """Pick the first route that answers; set load-adjusted slots. False when unreachable."""
        for r in self.routes:
            try:
                p = self.ssh("uptime; sysctl -n hw.ncpu", route=r, timeout=60)
            except subprocess.TimeoutExpired:
                continue
            if p.returncode:
                continue
            out = p.stdout.decode().split("\n")
            self.route = r
            self.slots = self.cfg_slots
            try:
                load = float(re.search(r"load averages?: ([\d.]+)", out[0]).group(1))
                ncpu = int(out[1])
                if self.adapt:
                    self.slots = max(2, min(self.cfg_slots, int(ncpu - load) + 2))
                log("%s: route %s, load %.1f on %d cpus, %d slots (config %d)"
                    % (self.name, " ".join(r), load, ncpu, self.slots, self.cfg_slots))
            except Exception:
                log("%s: route %s, %d slots" % (self.name, " ".join(r), self.slots))
            return True
        return False

    def prepare(self, tools_tar):
        p = self.ssh("cd ~/%s && tar xzf -" % self.dir, stdin=tools_tar, timeout=600)
        if p.returncode:
            log("%s: shipping tools failed: %s" % (self.name, p.stderr.decode()[-200:]))
            return False
        return True


class Batch:
    def __init__(self, bid, items):
        self.bid, self.items, self.attempts, self.tried = bid, items, 0, []


def limit_of(extra, margin):
    m = re.search(r"--time-budget\s+(\d+)", extra)
    return (int(m.group(1)) if m else 1800) + margin


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name"), ap.add_argument("list"), ap.add_argument("out")
    ap.add_argument("--hosts", required=True)
    ap.add_argument("--status")
    ap.add_argument("--inputs", type=int, default=3000)
    ap.add_argument("--extra", default="", help="extra equiv.py args, e.g. '--time-budget 600'")
    ap.add_argument("--batch", type=int, default=2, help="max functions per batch")
    ap.add_argument("--attempts", type=int, default=3)
    ap.add_argument("--margin", type=int, default=600, help="seconds added to the time budget for the wall-clock limit")
    ap.add_argument("--limit", type=int, help="wall-clock limit per batch in seconds (overrides budget+margin)")
    ap.add_argument("--only", help="comma-separated host names to use")
    ap.add_argument("--no-adapt", action="store_true", help="ignore load average when sizing slots")
    a = ap.parse_args()

    items = [tuple(l.split()[:2]) for l in open(a.list) if l.strip()]
    total = len(items)
    cfg = json.load(open(a.hosts))["hosts"]
    if a.only:
        cfg = [c for c in cfg if c["name"] in a.only.split(",")]
    hosts = [Host(c, not a.no_adapt) for c in cfg]
    limit = a.limit or limit_of(a.extra, a.margin)

    # tools/include from the committed tree, not the working tree
    ar = subprocess.run("git archive HEAD tools include | gzip -1", shell=True, capture_output=True,
                        cwd=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).stdout
    ok = []
    for h in hosts:
        if h.connect() and h.prepare(ar):
            h.ready = True
            ok.append(h)
        else:
            log("%s: unreachable, skipped" % h.name)
    if not ok:
        print("no host reachable")
        return 1
    hosts = ok

    lock = threading.Lock()
    queue = list(items)              # functions not yet batched
    retry = []                       # Batches to run again
    inflight = {}
    results = {}                     # addr -> record
    gaveup = {}                      # addr -> reason
    start = time.time()
    out = open(a.out, "w")
    counter = [0]

    def write_status(final=False):
        el = time.time() - start
        n = len(results)
        rem = total - n - len(gaveup)
        eta = "-" if not n else ("%dm" % round(el / n * rem / 60))
        lines = ["%s %s: %d/%d done, %d queued, %d in flight, %d gave up, elapsed %dm, ETA %s"
                 % (time.strftime("%H:%M:%S"), "FINISHED" if final else "running", n, total,
                    len(queue) + sum(len(b.items) for b in retry), sum(len(b.items) for b in inflight.values()),
                    len(gaveup), el // 60, eta)]
        for h in hosts:
            state = "down" if h.down_until > time.time() else "up"
            lines.append("  %s: %d done, %d/%d slots busy, %d batches ok / %d failed, %s"
                         % (h.name, h.done, h.used, h.slots, h.batches_ok, h.batches_bad, state))
        for ad, why in gaveup.items():
            lines.append("  GAVE UP %s: %s" % (ad, why))
        if a.status:
            with open(a.status + ".tmp", "w") as f:
                f.write("\n".join(lines) + "\n")
            os.replace(a.status + ".tmp", a.status)

    def run_batch(h, b):
        k = len(b.items)
        d = "rpb-%s-%s-a%d" % (a.name, b.bid, b.attempts)
        buf = io.BytesIO()
        with tarfile.open(fileobj=buf, mode="w:gz") as t:
            lst = "".join("%s %s/%s.cpp\n" % (ad, d, ad) for ad, _ in b.items).encode()
            ti = tarfile.TarInfo(d + "/list.txt"); ti.size = len(lst); t.addfile(ti, io.BytesIO(lst))
            for ad, src in b.items:
                data = open(src, "rb").read()
                ti = tarfile.TarInfo("%s/%s.cpp" % (d, ad)); ti.size = len(data); t.addfile(ti, io.BytesIO(data))
        cmd = ("cd ~/%s && tar xzf - && perl -e 'alarm shift; exec @ARGV' %d build/venv/bin/python "
               "tools/equiv_batch.py %s/list.txt %s/out.jsonl --jobs %d -- --inputs %d --max-inputs %d %s "
               ">%s/log 2>&1; cat %s/out.jsonl; rm -rf %s"
               % (h.dir, limit, d, d, k, a.inputs, a.inputs, a.extra, d, d, d))
        recs, why = [], None
        try:
            p = h.ssh(cmd, stdin=buf.getvalue(), timeout=limit + 60)
            if p.returncode:
                why = "ssh/remote exit %d %s" % (p.returncode, p.stderr.decode()[-120:].strip())
            for l in p.stdout.decode(errors="replace").splitlines():
                try:
                    recs.append(json.loads(l))
                except ValueError:
                    pass
        except subprocess.TimeoutExpired:
            why = "wall-clock limit %ds" % limit
        if why or len(recs) < k:
            # best effort: stop anything of ours still running for this batch, and drop its files
            try:
                h.ssh("pkill -f '[r]%s/'; rm -rf ~/%s/%s" % (d[1:], h.dir, d), timeout=60)
            except Exception:
                pass
        ssh_dead = bool(why) and "exit 255" in why
        with lock:
            del inflight[b.bid]
            h.used -= k
            good = {r["addr"]: r for r in recs if r.get("status") not in (None, "error")}
            srcs = dict(b.items)
            for ad, r in good.items():
                if ad in results or ad not in srcs:
                    continue
                r["src"], r["host"] = srcs[ad], h.name
                results[ad] = r
                out.write(json.dumps(r) + "\n"); out.flush()
                h.done += 1
            missing = [(ad, s) for ad, s in b.items if ad not in results]
            if missing:
                h.batches_bad += 1
                reason = why or "no usable result line"
                if ssh_dead:
                    h.fails += 1
                    if h.fails >= 3:
                        h.down_until = time.time() + 120
                        h.fails = 0
                        log("%s: marked down for 120s" % h.name)
                log("%s: batch %s failed (%s), %d to retry" % (h.name, b.bid, reason, len(missing)))
                for ad, s in missing:
                    counter[0] += 1
                    nb = Batch("r%d" % counter[0], [(ad, s)])
                    nb.attempts, nb.tried = b.attempts, list(b.tried)
                    if nb.attempts >= a.attempts:
                        gaveup[ad] = reason
                    else:
                        retry.append(nb)
            else:
                h.batches_ok += 1
                h.fails = 0

    def take(h, free):
        """Next batch for host h (called under lock) or None."""
        # retries first, preferring batches not yet tried on this host
        for pref in (True, False):
            for b in retry:
                if (not pref or h.name not in b.tried):
                    if pref is False and any(o is not h and o.down_until < time.time() and o.name not in b.tried
                                            for o in hosts) and h.name in b.tried and a.attempts > 1:
                        # another healthy host has not tried it yet; leave it for them
                        continue
                    retry.remove(b)
                    return b
        if queue:
            remaining = len(queue)
            n = 1 if remaining <= sum(x.slots for x in hosts) else a.batch
            n = max(1, min(n, free, remaining))
            counter[0] += 1
            b = Batch("b%d" % counter[0], queue[:n])
            del queue[:n]
            return b
        return None

    last = 0
    while True:
        with lock:
            now = time.time()
            for h in hosts:
                if h.down_until > now:
                    continue
                if h.down_until and h.down_until <= now:
                    h.down_until = 0
                    if not h.connect():
                        h.down_until = now + 120
                        continue
                while h.slots - h.used > 0:
                    b = take(h, h.slots - h.used)
                    if not b:
                        break
                    b.attempts += 1
                    b.tried.append(h.name)
                    h.used += len(b.items)
                    inflight[b.bid] = b
                    threading.Thread(target=run_batch, args=(h, b), daemon=True).start()
            finished = not queue and not retry and not inflight
        if now - last > 10 or finished:
            with lock:
                write_status(finished)
            last = now
        if finished:
            break
        time.sleep(1)

    out.close()
    print("checked on: %s (%s)" % (" ".join(h.name for h in hosts), ", ".join("%d on %s" % (h.done, h.name) for h in hosts)))
    if gaveup:
        print("unfinished (gave up after %d attempts): %s" % (a.attempts, sorted(gaveup)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
