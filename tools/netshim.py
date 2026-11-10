#!/usr/bin/env python3
"""A seeded network impairment proxy for UDP: delay, jitter, loss, reordering and duplication (docs/multiplayer.md
"Network impairment shim"). Every lockstep test goes through it.

  # two one-way links: packets sent to 127.0.0.1:42001 go to B (41002) and to 42002 go to A (41001)
  build/venv/bin/python tools/netshim.py run --link 42001:127.0.0.1:41002 --link 42002:127.0.0.1:41001 \
        --delay 120-200 --jitter 15 --dist pareto --loss 2 --reorder 1 --dup 0.5 --seed 7 [--log FILE] [--duration S]
  build/venv/bin/python tools/netshim.py selftest        # checks the impairments it applies, and the seed's replay

Model, per link (each direction is its own link with its own generator, seeded from --seed and the link's index):
  * base delay: one value per link drawn from --delay LO-HI ms (or a fixed --delay MS) at start; the 120-200 ms default is
    the design target's one-way latency.
  * jitter: per packet, added to the base. --dist normal (|N(0, J)|), pareto (heavy tail: scale J/2, alpha 2.5, capped at
    10*J; the usual Wi-Fi/cellular shape) or uniform (0..2J). Packets are delivered in send order (a FIFO link) unless
    reordering lets one overtake: the jitter alone never reorders.
  * reorder %: the packet skips the FIFO rule (it may arrive before earlier packets).
  * loss %: dropped (bursty with --burst P: after a loss the next packet is lost with probability P).
  * dup %: a second copy arrives 1-20 ms after the first.
The decisions (drop, delay, dup) are drawn per packet in arrival order from the link's generator, so the same seed and the
same packet sequence give the same decisions (`--log` records them; selftest checks it). Wall-clock delivery is as exact
as the host's timers (about 1 ms).
"""
import argparse
import heapq
import json
import os
import random
import select
import socket
import sys
import threading
import time


def parse_delay(s):
    if "-" in s:
        a, b = s.split("-", 1)
        return float(a), float(b)
    return float(s), float(s)


class Link:
    def __init__(self, idx, listen_port, dest, a, sock):
        self.idx = idx
        self.listen_port = listen_port
        self.dest = dest
        self.sock = sock
        self.rng = random.Random((a.seed << 8) ^ idx)
        lo, hi = parse_delay(a.delay)
        self.base = self.rng.uniform(lo, hi)
        self.a = a
        self.last_due = 0.0          # FIFO: a packet is never due before the previous one
        self.lost_prev = False
        self.n = self.sent = self.dropped = self.dups = self.reordered = 0
        self.decisions = []          # (packet number, dropped, delay ms, dup ms or None, reordered)

    def jitter(self):
        j = self.a.jitter
        if j <= 0:
            return 0.0
        if self.a.dist == "normal":
            return abs(self.rng.gauss(0, j))
        if self.a.dist == "uniform":
            return self.rng.uniform(0, 2 * j)
        return min(10 * j, (j / 2) * (self.rng.paretovariate(2.5) - 1) * 2)

    def decide(self):
        """-> (drop, delay_ms, dup_ms or None, reorder) for the next packet"""
        a = self.a
        self.n += 1
        p_loss = a.burst if (self.lost_prev and a.burst > 0) else a.loss / 100.0
        drop = self.rng.random() < p_loss
        delay = self.base + self.jitter()
        reorder = self.rng.random() < a.reorder / 100.0
        dup = self.rng.uniform(1, 20) if self.rng.random() < a.dup / 100.0 else None
        self.lost_prev = drop
        if len(self.decisions) < 200000:
            self.decisions.append((self.n, drop, round(delay, 3), None if dup is None else round(dup, 3), reorder))
        return drop, delay, dup, reorder


def run(a, stop=None, ready=None):
    links, socks = [], []
    for i, spec in enumerate(a.link):
        lp, host, dp = spec.split(":")
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.bind((a.bind, int(lp)))
        s.setblocking(False)
        links.append(Link(i, int(lp), (host, int(dp)), a, s))
        socks.append(s)
    out = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    by_sock = {l.sock: l for l in links}
    heap = []                    # (due time, seq, payload, link)
    seq = 0
    t_end = time.monotonic() + a.duration if a.duration else None
    logf = open(a.log, "w") if a.log else None
    if logf:
        logf.write(json.dumps({"links": [{"idx": l.idx, "listen": l.listen_port, "dest": l.dest, "base_ms": round(l.base, 3)}
                                         for l in links], "args": {k: v for k, v in vars(a).items() if k != "func"}}) + "\n")
    if ready:
        ready.set()
    while not (stop and stop.is_set()) and not (t_end and time.monotonic() > t_end):
        now = time.monotonic()
        timeout = 0.05
        if heap:
            timeout = max(0.0, min(timeout, heap[0][0] - now))
        r, _, _ = select.select(socks, [], [], timeout)
        now = time.monotonic()
        for s in r:
            l = by_sock[s]
            while True:
                try:
                    data, _ = s.recvfrom(65536)
                except (BlockingIOError, OSError):
                    break
                drop, delay, dup, reorder = l.decide()
                if drop:
                    l.dropped += 1
                    continue
                due = now + delay / 1000.0
                if reorder:
                    l.reordered += 1
                else:
                    due = max(due, l.last_due)
                    l.last_due = due
                heapq.heappush(heap, (due, seq, data, l))
                seq += 1
                if dup is not None:
                    l.dups += 1
                    heapq.heappush(heap, (due + dup / 1000.0, seq, data, l))
                    seq += 1
        now = time.monotonic()
        while heap and heap[0][0] <= now:
            _, _, data, l = heapq.heappop(heap)
            try:
                out.sendto(data, l.dest)
                l.sent += 1
            except OSError:
                pass
    stats = [{"link": l.idx, "listen": l.listen_port, "base_ms": round(l.base, 3), "in": l.n, "out": l.sent,
              "dropped": l.dropped, "dups": l.dups, "reordered": l.reordered} for l in links]
    if logf:
        for l in links:
            for d in l.decisions:
                logf.write(json.dumps([l.idx] + list(d)) + "\n")
        logf.write(json.dumps({"stats": stats}) + "\n")
        logf.close()
    for s in socks:
        s.close()
    return stats, links


def add_model_args(p):
    p.add_argument("--delay", default="120-200", help="one-way base delay in ms: MS or LO-HI (one draw per link)")
    p.add_argument("--jitter", type=float, default=15.0, help="jitter scale in ms")
    p.add_argument("--dist", choices=["normal", "pareto", "uniform"], default="pareto")
    p.add_argument("--loss", type=float, default=0.0, help="loss %%")
    p.add_argument("--burst", type=float, default=0.0, help="P(loss | previous lost); 0: independent losses")
    p.add_argument("--reorder", type=float, default=0.0, help="%% of packets exempt from FIFO order")
    p.add_argument("--dup", type=float, default=0.0, help="duplicate %%")
    p.add_argument("--seed", type=int, default=1)


def cmd_run(a):
    import signal
    stop = threading.Event()
    signal.signal(signal.SIGTERM, lambda *_: stop.set())
    signal.signal(signal.SIGINT, lambda *_: stop.set())
    stats, _ = run(a, stop)
    print(json.dumps(stats))


def selftest(a):
    """Sends a numbered stream through one link and checks loss, delay, dup and order against the settings; then
    checks that the same seed draws the same decisions."""
    import types
    fails = []
    base_port = a.port

    def one(name, model, n=1500, gap=0.002):
        ns = types.SimpleNamespace(bind="127.0.0.1", link=["%d:127.0.0.1:%d" % (base_port, base_port + 1)], duration=0,
                                   log=None, **model)
        rx = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        rx.bind(("127.0.0.1", base_port + 1))
        rx.setblocking(False)
        stop, ready = threading.Event(), threading.Event()
        res = {}
        th = threading.Thread(target=lambda: res.update(r=run(ns, stop, ready)))
        th.start()
        ready.wait(5)
        tx = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        got, sent_at = [], {}
        t0 = time.monotonic()
        for i in range(n):
            sent_at[i] = time.monotonic()
            tx.sendto(i.to_bytes(4, "little"), ("127.0.0.1", base_port))
            time.sleep(gap)
            try:
                while True:
                    d, _ = rx.recvfrom(64)
                    got.append((int.from_bytes(d, "little"), time.monotonic()))
            except (BlockingIOError, socket.timeout):
                pass
        rx.settimeout(0.05)
        deadline = time.monotonic() + 1.5
        while time.monotonic() < deadline:
            try:
                d, _ = rx.recvfrom(64)
                got.append((int.from_bytes(d, "little"), time.monotonic()))
            except socket.timeout:
                pass
        stop.set()
        th.join()
        rx.close()
        tx.close()
        stats, links = res["r"]
        ids = [g[0] for g in got]
        uniq = set(ids)
        lat = sorted((t - sent_at[i]) * 1000 for i, t in got)
        inv = sum(1 for x, y in zip(ids, ids[1:]) if y < x)
        r = {"name": name, "sent": n, "received": len(ids), "unique": len(uniq), "loss_pct": round(100 * (n - len(uniq)) / n, 2),
             "dup": len(ids) - len(uniq), "inversions": inv, "base_ms": stats[0]["base_ms"],
             "lat_min": round(lat[0], 1) if lat else None, "lat_p50": round(lat[len(lat) // 2], 1) if lat else None,
             "lat_max": round(lat[-1], 1) if lat else None, "secs": round(time.monotonic() - t0, 1)}
        return r, links[0].decisions

    def check(cond, what):
        if not cond:
            fails.append(what)

    m0 = dict(delay="0", jitter=0, dist="normal", loss=0, burst=0, reorder=0, dup=0, seed=1)
    r, _ = one("clean", m0)
    print(json.dumps(r))
    check(r["unique"] == r["sent"] and r["dup"] == 0 and r["inversions"] == 0, "clean link must deliver all, in order")
    m1 = dict(delay="120-200", jitter=15, dist="pareto", loss=5, burst=0, reorder=0, dup=0, seed=3)
    r, d1 = one("delay+jitter+loss", m1)
    print(json.dumps(r))
    check(120 <= r["base_ms"] <= 200, "base delay inside 120-200")
    check(r["lat_min"] is not None and r["lat_min"] >= r["base_ms"] - 1, "no packet faster than the base delay")
    check(2.0 <= r["loss_pct"] <= 8.5, "loss near 5%% (got %s)" % r["loss_pct"])
    check(r["inversions"] == 0, "FIFO without --reorder")
    m2 = dict(delay="50", jitter=20, dist="uniform", loss=0, burst=0, reorder=10, dup=5, seed=5)
    r, _ = one("reorder+dup", m2)
    print(json.dumps(r))
    check(r["inversions"] > 0, "reordering produces inversions")
    check(2 <= 100 * r["dup"] / r["sent"] <= 9, "dup near 5%% (got %d)" % r["dup"])
    check(r["unique"] == r["sent"], "no loss configured")
    # the same seed and stream -> the same decisions
    r, d1b = one("delay+jitter+loss (again)", m1)
    check(d1 == d1b, "same seed, same decisions")
    print(json.dumps({"seeded_replay_identical": d1 == d1b, "decisions": len(d1)}))
    if fails:
        print("SELFTEST FAIL: " + "; ".join(fails))
        return 1
    print("SELFTEST ok")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    r = sp.add_parser("run")
    r.add_argument("--link", action="append", required=True, help="LISTENPORT:DESTHOST:DESTPORT (one direction)")
    r.add_argument("--bind", default="0.0.0.0")
    r.add_argument("--duration", type=float, default=0, help="seconds (0: until killed)")
    r.add_argument("--log", help="JSON lines: the links, every decision, the final counters")
    add_model_args(r)
    t = sp.add_parser("selftest")
    t.add_argument("--port", type=int, default=47100)
    a = ap.parse_args()
    if a.c == "run":
        cmd_run(a)
        return 0
    return selftest(a)


if __name__ == "__main__":
    sys.exit(main())
