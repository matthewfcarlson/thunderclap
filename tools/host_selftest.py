#!/usr/bin/env python3
"""host_selftest.py: the checker's per-host verdict check (integ3, hostcheck).

`equiv.py --selftest` runs config/equiv-selftest.json's cases at a work-counted budget and compares each run's summary
(verdict, inputs, coverage, statuses) with the recorded one. Since the work clock (equiv.py "workclock") a host's speed
no longer changes what a check reaches, so every host must reproduce the record exactly; one that doesn't computes
something else (a Python, Unicorn, clang or input drift) and must not take proof jobs.

  host_selftest.py submit [--hosts mac1,mac2,...]   one pinned selftest job per queue host (the queue's own checker
                                                   and config at the job's base commit); ids -> build/jobs/selftest.ids
  host_selftest.py apply [--dry-run]               read the finished jobs; a host that failed loses the `equiv` cap in
                                                   build/jobs/hosts.json (the daemon reloads caps without a restart) and
                                                   is listed in build/jobs/selftest.json; one that passes again gets it back.
                                                   It changes nothing else in hosts.json; each change is logged in
                                                   build/jobs/daemon.log (tell the lead)
  host_selftest.py status                          the last results

The lane that lands a checker commit (equiv.py, equiv64.py, wine_gate, tree_tu proof paths, config/equiv-selftest.json)
runs `submit`, then `apply` once the jobs finish; also after a host's Python / Unicorn / clang changes."""
import argparse
import json
import os
import subprocess
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
JOBS = os.environ.get("JOBQ_DIR") or os.path.join(ROOT, "build/jobs")
IDS = os.path.join(JOBS, "selftest.ids")
STATE = os.path.join(JOBS, "selftest.json")
HOSTS = os.environ.get("JOBQ_HOSTS") or os.path.join(JOBS, "hosts.json")
DLOG = os.path.join(JOBS, "daemon.log")


def _log(msg):
    """every cap change goes into the daemon's log too (lead's condition for apply editing hosts.json)"""
    line = "%s host_selftest: %s" % (time.strftime("%H:%M:%S"), msg)
    print(line)
    with open(DLOG, "a") as f:
        f.write(line + "\n")
CMD = "mkdir -p jobsrc; build/venv/bin/python tools/equiv.py --selftest > jobsrc/selftest.json 2>jobsrc/selftest.err; exit 0"


def _hosts():
    return json.load(open(HOSTS))["hosts"]


def submit(hosts=None):
    names = hosts or [h["name"] for h in _hosts() if not h.get("local") and
                      ("equiv" in h.get("caps", []) or h.get("selftest_quarantined"))]
    out = []
    for n in names:
        # (needs any: a quarantined host has no `equiv` cap left, and the selftest is what gives it back)
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", "selftest",
                            "--needs", "any", "--host", n, "--prio", "5", "--limit", "5400",
                            "--out", "jobsrc/selftest.json", "--", "sh", "-c", CMD],
                           cwd=ROOT, capture_output=True, text=True)
        jid = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else ""
        if not jid.isdigit():
            raise SystemExit("submit for %s failed: %s" % (n, (r.stderr or r.stdout)[-300:]))
        out.append((n, int(jid)))
        print(n, jid)
    with open(IDS, "w") as f:
        for n, j in out:
            f.write("%s %d\n" % (n, j))


def _result(jid):
    p = os.path.join(JOBS, "out", str(jid), "jobsrc", "selftest.json")
    try:
        return json.load(open(p))
    except (OSError, ValueError):
        return None


def apply(dry_run=False):
    rows = [l.split() for l in open(IDS) if l.strip()]
    st = json.load(open(STATE)) if os.path.exists(STATE) else {}
    hosts = json.load(open(HOSTS))
    by = {h["name"]: h for h in hosts["hosts"]}
    changed = False
    for n, jid in rows:
        r = _result(jid)
        if r is None:
            print("%s: job %s has no result yet (or crashed): nothing changed" % (n, jid))
            continue
        ok = bool(r.get("ok"))
        st[n] = {"ok": ok, "job": int(jid), "checker": r.get("checker"), "at": time.strftime("%Y-%m-%dT%H:%M:%S"),
                 "diffs": [{"case": d["case"], "want": d["want"], "got": d["got"]} for d in r.get("diffs", [])][:6]}
        h = by.get(n)
        if h is None:
            continue
        caps = h.setdefault("caps", [])
        if not ok and "equiv" in caps:
            caps.remove("equiv")
            h["selftest_quarantined"] = {"job": int(jid), "cases": [d["case"] for d in r.get("diffs", [])]}
            changed = True
            _log("%s: selftest FAILED (job %s; %s): `equiv` cap removed" % (n, jid, ", ".join(h["selftest_quarantined"]["cases"])))
        elif ok and h.get("selftest_quarantined"):
            if "equiv" not in caps:
                caps.insert(0, "equiv")
            h.pop("selftest_quarantined")
            changed = True
            _log("%s: selftest passes again (job %s): `equiv` cap restored" % (n, jid))
        else:
            print("%s: selftest %s" % (n, "ok" if ok else "FAILED (already quarantined)"))
    if dry_run:
        return st
    with open(STATE + ".tmp", "w") as f:
        json.dump(st, f, indent=1, sort_keys=True)
    os.replace(STATE + ".tmp", STATE)
    if changed:
        with open(HOSTS + ".tmp", "w") as f:
            json.dump(hosts, f, indent=1)
            f.write("\n")
        os.replace(HOSTS + ".tmp", HOSTS)
    return st


def main(argv):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = p.add_subparsers(dest="cmd", required=True)
    s = sp.add_parser("submit")
    s.add_argument("--hosts")
    a_ = sp.add_parser("apply")
    a_.add_argument("--dry-run", action="store_true")
    sp.add_parser("status")
    a = p.parse_args(argv)
    if a.cmd == "submit":
        submit(a.hosts.split(",") if a.hosts else None)
    elif a.cmd == "apply":
        apply(a.dry_run)
    else:
        print(json.dumps(json.load(open(STATE)) if os.path.exists(STATE) else {}, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
