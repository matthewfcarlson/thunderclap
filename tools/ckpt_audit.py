#!/usr/bin/env python3
"""The weekly audit of `ckpt` ledger lines (ckpt2, D162 safeguard 2, piece 5; docs/checkpoints.md "The audit").

  build/venv/bin/python tools/ckpt_audit.py sample [--week 2026-W47]     # which lines this week's audit takes (no jobs)
  build/venv/bin/python tools/ckpt_audit.py submit [--week 2026-W47] --name ME   # records the sample, submits the proofs
  build/venv/bin/python tools/ckpt_audit.py judge [--week 2026-W47]      # after the jobs: pass / fail / inconclusive
  build/venv/bin/python tools/ckpt_audit.py status                       # open pauses and the audits so far
  build/venv/bin/python tools/ckpt_audit.py lift PAUSE_ID --decision D170 --why TEXT    # only on the user's decision

The population is every ckpt line recorded before the week starts (Monday 00:00) that tree_tu.ckpt_line_accepts at
HEAD (the block's committed wine code is the line's, R2/R4 hold now, not revoked). It is stratified by the line's
allowlist entry and from each stratum ceil(5%) of the lines are drawn, seeded by sha256 of the week id, so anyone can
recompute the sample. Each sampled block gets a full proof at HEAD (queue jobs, no overlays): equiv.py at 3,000 inputs
in MSVC, --wine and --x64. A mode fails when its run is a `fail` (a difference found; for --x64 one the x64 baseline does
not list for that block); a run that neither fails nor proves (short, unsupported, cut) is inconclusive and is
resubmitted by the next `submit` of the same week. Any failure revokes that block's ckpt lines (tree_tu.py revoke
--kind ckpt, D154) and appends a pause record to config/ckpt-pause.jsonl: no new ckpt line is recorded or accepted
from then until the user lifts it (`lift`, naming the decision); lines recorded before the pause keep counting.
config/ckpt-audit.jsonl (append-only, merge=union) keeps every sample and verdict; the jobs and reports live under
build/ckpt/audit/WEEK/ (local).
"""
import argparse
import datetime
import hashlib
import json
import math
import os
import random
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

AUDIT = os.path.join(ROOT, "config", "ckpt-audit.jsonl")
FRACTION = 0.05
INPUTS = 3000
MODES = ("msvc", "wine", "x64")
WEEK = re.compile(r"^(\d{4})-W(\d{2})$")


def this_week(now=None):
    y, w, _d = (now or datetime.date.today()).isocalendar()
    return "%04d-W%02d" % (y, w)


def week_start(week):
    m = WEEK.match(week)
    if not m:
        sys.exit("a week is YYYY-Www (ISO), not %r" % week)
    return datetime.datetime.combine(datetime.date.fromisocalendar(int(m.group(1)), int(m.group(2)), 1),
                                     datetime.time()).isoformat(timespec="seconds")


def seed_of(week):
    return int(hashlib.sha256(("ckpt-audit:" + week).encode()).hexdigest()[:16], 16)


def order(lines, week):
    """{entry: [line]}: each allowlist entry's lines in the week's seeded order (a generator seeded from the week id
    shuffles the lines sorted by key: the same order wherever it is computed). The sample is the first
    ceil(fraction * n) of each; a sampled line that stops counting is replaced by the next one that still counts (rev5)."""
    import tree_tu
    rng = random.Random(seed_of(week))
    strata = {}
    for e in sorted(lines, key=tree_tu.ckpt_line_key):
        strata.setdefault((e.get("allow") or {}).get("entry") or "?", []).append(e)
    out = {}
    for name in sorted(strata):
        pop = list(strata[name])
        rng.shuffle(pop)
        out[name] = pop
    return out


def draw(lines, week, fraction=FRACTION):
    """{entry: [line]}: per allowlist entry the first ceil(fraction * n) lines of the week's order"""
    return {name: pop[:math.ceil(fraction * len(pop))] for name, pop in order(lines, week).items()}


def current_codes(lines, tree):
    """{(tu, addr): (kind, wine code hash, msvc code hash)} of the lines' blocks in TREE"""
    import tree_tu
    out = {}
    for tu in sorted({e["tu"] for e in lines}):
        p = os.path.join(tree, tu)
        if not os.path.exists(p):
            continue
        recs = tree_tu.check_tu(p)
        tree_tu.with_wine(p, recs)
        for r in recs:
            out[(tu, r["addr"])] = (r.get("kind"), r.get("wine_code_hash"), r.get("code_hash"))
    return out


def population(week, tree, lines=None, codes=None):
    """the live lines recorded before WEEK starts, accepted now in TREE"""
    import tree_tu
    start = week_start(week)
    lines = [e for e in (lines if lines is not None else tree_tu.ckpt_lines()) if (e.get("date") or "") < start]
    codes = codes if codes is not None else current_codes(lines, tree)
    out = []
    for e in lines:
        kind, wh, _mh = codes.get((e["tu"], e["addr"]), (None, None, None))
        if tree_tu.ckpt_line_accepts(e, e["tu"], kind, wh) is None:
            out.append(e)
    return out, codes


def head_tree(week):
    """a snapshot of HEAD's tree (the jobs run at HEAD; the shared checkout may hold others' edits)"""
    head = subprocess.run(["git", "-C", ROOT, "rev-parse", "HEAD"], capture_output=True, text=True).stdout.strip()
    d = os.path.join(ROOT, "build/ckpt/audit", week, "tree-" + head[:12])
    if not os.path.exists(d):
        os.makedirs(d + ".new", exist_ok=True)
        subprocess.run("git -C %s archive %s src include config | tar -x -C %s" % (ROOT, head, d + ".new"), shell=True,
                       check=True)
        os.rename(d + ".new", d)
    return head, d


def records(path=None):
    path = path or AUDIT
    out = []
    if os.path.exists(path):
        with open(path) as f:
            for l in f:
                if l.strip().startswith("{"):
                    out.append(json.loads(l))
    return out


def append(rec, path=None):
    with open(path or AUDIT, "a") as f:
        f.write(json.dumps(rec, sort_keys=True) + "\n")


def cmd_sample(a, quiet=False):
    import tree_tu
    head, tree = head_tree(a.week)
    pop, codes = population(a.week, tree)
    od = order(pop, a.week)
    s = {name: es[:math.ceil(FRACTION * len(es))] for name, es in od.items()}
    sample = [slot(e, codes, name) for name, es in sorted(s.items()) for e in es]
    rec = {"kind": "sample", "week": a.week, "seed": "%x" % seed_of(a.week), "head": head, "fraction": FRACTION,
           "order": {name: [tree_tu.ckpt_line_key(e) for e in es] for name, es in od.items()},
           "population": {name: sum(1 for e in pop if (e.get("allow") or {}).get("entry") == name)
                          for name in sorted({(e.get("allow") or {}).get("entry") for e in pop})},
           "sample": sample}
    if not quiet:
        print(json.dumps(rec, indent=1))
    return rec


def slot(e, codes, entry):
    import tree_tu
    return {"key": tree_tu.ckpt_line_key(e), "addr": e["addr"], "tu": e["tu"], "code": e["code"],
            "msvc_code": codes[(e["tu"], e["addr"])][2], "entry": entry}


def current_sample(week):
    """(the sample record, its slots with the recorded replacements applied)"""
    rec = next((r for r in reversed(records()) if r.get("kind") == "sample" and r.get("week") == week), None)
    if rec is None:
        return None, []
    slots = list(rec["sample"])
    for r in records():
        if r.get("kind") == "replace" and r.get("week") == week:
            slots = [r["new"] if x["key"] == r["old"] else x for x in slots]
    return rec, slots


def replace_dead(rec, slots, week, tree):
    """(rev5) a slot whose line no longer counts at HEAD (and has no verdict yet) takes the next line of its stratum's
    seeded order that still counts and is not sampled; the replacement and the reason are recorded"""
    import tree_tu
    lines = {tree_tu.ckpt_line_key(e): e for e in tree_tu.ckpt_lines()}
    judged = {v["key"] for v in verdicts(week)}
    pop, codes = population(week, tree, lines=list(lines.values()))
    live = {tree_tu.ckpt_line_key(e) for e in pop}
    out = []
    for x in slots:
        if x["key"] in live or x["key"] in judged:
            out.append(x)
            continue
        taken = {y["key"] for y in slots} | {y["key"] for y in out}
        nxt = next((k for k in rec["order"].get(x["entry"], []) if k in live and k not in taken), None)
        new = slot(lines[nxt], codes, x["entry"]) if nxt else None
        r = {"kind": "replace", "week": week, "old": x["key"], "new": new,
             "why": "the line no longer counts at HEAD (%s)" % ("code, R2/R4 or revocation"),
             "date": datetime.datetime.now().isoformat(timespec="seconds")}
        if new is None:
            r["why"] += "; no counting line left in %s" % x["entry"]
        append(r)
        print("audit %s: %s %s replaced by %s" % (week, x["addr"], x["key"][:10], new and new["addr"]))
        if new is not None:
            out.append(new)
    return out


def job_cmd(s, mode):
    flag = {"msvc": "", "wine": " --wine", "x64": " --x64"}[mode]
    return ("mkdir -p audit && build/venv/bin/python tools/equiv.py %s %s%s --json --inputs %d > audit/%s.json"
            % (s["tu"], s["addr"], flag, INPUTS, mode))


def cmd_submit(a):
    import tree_tu
    rec, slots = current_sample(a.week)
    if rec is None:
        rec = cmd_sample(a, quiet=True)
        append(dict(rec, date=datetime.datetime.now().isoformat(timespec="seconds")))
        rec, slots = current_sample(a.week)
    else:
        _h, tree = head_tree(a.week)
        slots = replace_dead(rec, slots, a.week, tree)
    d = os.path.join(ROOT, "build/ckpt/audit", a.week)
    os.makedirs(d, exist_ok=True)
    jp = os.path.join(d, "jobs.json")
    jobs = json.load(open(jp)) if os.path.exists(jp) else {}
    done = {(v["key"], v["mode"]) for v in verdicts(a.week) if v["verdict"] in ("pass", "fail")}
    head = subprocess.run(["git", "-C", ROOT, "rev-parse", "HEAD"], capture_output=True, text=True).stdout.strip()
    if head != rec["head"]:
        print("note: HEAD %s is not the sample's %s: the jobs run at HEAD and judge checks the code they ran" % (
            head[:12], rec["head"][:12]))
    n = 0
    for s in slots:
        for mode in MODES:
            k = "%s %s" % (s["key"], mode)
            if (s["key"], mode) in done or (k in jobs and not a.resubmit):
                continue
            argv = [sys.executable, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", a.name, "--needs", "equiv",
                    "--limit", str(a.limit), "--attempts", "2", "--out", "audit", "--", "sh", "-c", job_cmd(s, mode)]
            r = subprocess.run(argv, capture_output=True, text=True)
            if r.returncode:
                sys.exit(r.stderr or r.stdout)
            jobs[k] = r.stdout.strip().split()[-1]
            n += 1
    json.dump(jobs, open(jp, "w"), indent=1)
    print("audit %s: %d line(s) sampled, %d job(s) submitted (%s)" % (a.week, len(slots), n, jp))
    return 0


def verdicts(week):
    return [r for r in records() if r.get("kind") == "verdict" and r.get("week") == week]


def judge_one(rep, mode, s, x64_base):
    """('pass' | 'fail' | 'inconclusive', why) of one audit run"""
    import tree_tu
    if rep is None:
        return "inconclusive", "no report"
    tc = rep.get("tree_code") or {}
    if mode == "x64":
        import x64_gate
        cls, gate = x64_gate.classify(rep)
        if cls == "equivalent":
            return "pass", cls
        if cls.startswith("fail:") or cls == "compile_error":
            listed = (x64_base.get("blocks") or {}).get(s["addr"])
            if gate and listed and gate.split("/")[0] in (listed if isinstance(listed, list) else [listed]):
                return "pass", "%s (listed in the x64 baseline)" % cls
            return "fail", cls
        return "inconclusive", cls
    code = s["code"] if mode == "wine" else s.get("msvc_code")
    ok, why = tree_tu.proves(rep, mode, code)
    if ok:
        return "pass", why
    if tc.get(mode) not in (None, code):
        return "inconclusive", "the run checked other code (%s, sampled %s)" % (tc.get(mode), code)
    if rep.get("status") == "fail":
        return "fail", (rep.get("first_diff") or "fail")[:300]
    return "inconclusive", why


def cmd_judge(a):
    import tree_tu
    import x64_gate
    rec, slots = current_sample(a.week)
    if rec is None:
        sys.exit("judge: no sample recorded for %s (submit first)" % a.week)
    jp = os.path.join(ROOT, "build/ckpt/audit", a.week, "jobs.json")
    jobs = json.load(open(jp)) if os.path.exists(jp) else {}
    have = {(v["key"], v["mode"]) for v in verdicts(a.week) if v["verdict"] in ("pass", "fail")}
    base = x64_gate.load_baseline()
    failed = []
    now = datetime.datetime.now().isoformat(timespec="seconds")
    for s in slots:
        for mode in MODES:
            if (s["key"], mode) in have:
                continue
            j = jobs.get("%s %s" % (s["key"], mode))
            p = os.path.join(ROOT, "build/jobs/out", str(j), "audit", "%s.json" % mode) if j else None
            rep = None
            if p and os.path.exists(p):
                try:
                    rep = json.load(open(p))
                except ValueError:
                    rep = None
            v, why = judge_one(rep, mode, s, base)
            print("%s %s %-5s %-12s %s" % (s["addr"], s["key"][:10], mode, v, why[:120]))
            if v == "inconclusive":
                continue
            append({"kind": "verdict", "week": a.week, "key": s["key"], "addr": s["addr"], "mode": mode, "verdict": v,
                    "why": why[:300], "job": j, "date": now})
            if v == "fail":
                failed.append((s, mode, why))
                if mode == "msvc":
                    # (rev5) ckpt never covers msvc: an equiv proof of this code was wrong or the checker changed. A
                    # D154 revocation candidate for the lead, never revoked here
                    append({"kind": "equiv_suspect", "week": a.week, "addr": s["addr"], "mode": "msvc",
                            "code": s.get("msvc_code"), "job": j, "why": why[:300], "date": now})
                    print("EQUIV SUSPECT: %s msvc code %s failed at 3,000 inputs (job %s): a D154 revocation "
                          "candidate for the lead (tree_tu.py revoke %s --mode msvc)" % (
                              s["addr"], s.get("msvc_code"), j, s["addr"]))
                elif mode == "x64":
                    append({"kind": "x64_report", "week": a.week, "addr": s["addr"], "job": j, "why": why[:300],
                            "date": now})
                    print("X64: %s fails --x64 (%s): for the x64 baseline (x64_gate.py accept) or a fix" % (
                        s["addr"], why[:120]))
    for s, mode, why in failed:
        why_ = "D162 audit %s: %s %s failed (%s)" % (a.week, s["addr"], mode, why[:160])
        live = [e for e in tree_tu.ckpt_lines() if e["addr"] == s["addr"] and
                tree_tu.ckpt_line_key(e) not in tree_tu.revoked_lines()]
        if live:
            tree_tu.main(["revoke", s["addr"], "--mode", "wine", "--kind", "ckpt", "--why", why_])
        pause = {"pause": "audit-%s-%s-%s" % (a.week, s["addr"], mode), "week": a.week, "addr": s["addr"],
                 "mode": mode, "why": why_, "date": now, "by": "ckpt_audit"}
        with open(tree_tu.CKPT_PAUSE, "a") as f:
            f.write(json.dumps(pause, sort_keys=True) + "\n")
        print("PAUSED: %s (no new ckpt line until the user lifts it: ckpt_audit.py lift %s --decision D...)" % (
            why_, pause["pause"]))
    left = sum(1 for s in slots for m in MODES if (s["key"], m) not in
               {(v["key"], v["mode"]) for v in verdicts(a.week) if v["verdict"] in ("pass", "fail")})
    print("audit %s: %d failure(s); %d run(s) still open (inconclusive or pending: submit --resubmit)" % (
        a.week, len(failed), left))
    return 1 if failed else 0


def previous_week(now=None):
    d = (now or datetime.date.today()) - datetime.timedelta(days=7)
    return this_week(d)


def audit_missing(now=None, lines=None):
    """(rev5) why the previous week's audit is not done, or None: when a ckpt line existed before that week began, the
    week needs a sample record whose every slot has a pass/fail verdict in every mode (ckpt_ledger.py record refuses
    otherwise, so a skipped audit stops new ckpt lines as a pause does)"""
    import tree_tu
    wk = previous_week(now)
    start = week_start(wk)
    if not any((e.get("date") or "") < start for e in (lines if lines is not None else tree_tu.ckpt_lines())):
        return None
    rec, slots = current_sample(wk)
    if rec is None:
        return "no audit sample for %s (ckpt_audit.py submit --week %s)" % (wk, wk)
    done = {(v["key"], v["mode"]) for v in verdicts(wk) if v["verdict"] in ("pass", "fail")}
    open_ = [(s["addr"], m) for s in slots for m in MODES if (s["key"], m) not in done]
    if open_:
        return "the %s audit has %d run(s) without a verdict (first %s %s; ckpt_audit.py judge --week %s)" % (
            wk, len(open_), open_[0][0], open_[0][1], wk)
    return None


def cmd_lift(a):
    import tree_tu
    if not re.match(r"^D\d+[a-z]?$", a.decision or ""):
        sys.exit("lift: --decision names the user's decision (D<number>)")
    open_ = {r["pause"] for r in records(tree_tu.CKPT_PAUSE) if r.get("pause")} - \
        {r["lift"] for r in records(tree_tu.CKPT_PAUSE) if r.get("lift")}
    if a.pause not in open_:
        sys.exit("lift: %s is not an open pause (open: %s)" % (a.pause, sorted(open_)))
    rec = {"lift": a.pause, "decision": a.decision, "why": a.why.strip(), "by": "user",
           "date": datetime.datetime.now().isoformat(timespec="seconds")}
    with open(tree_tu.CKPT_PAUSE, "a") as f:
        f.write(json.dumps(rec, sort_keys=True) + "\n")
    print("lifted", a.pause, "by", a.decision)
    return 0


def cmd_status(a):
    import tree_tu
    ps = records(tree_tu.CKPT_PAUSE)
    lifted = {r["lift"] for r in ps if r.get("lift")}
    for r in ps:
        if r.get("pause"):
            print("pause %s %s: %s (%s)" % (r["pause"], "lifted" if r["pause"] in lifted else "OPEN", r.get("why"),
                                            r.get("date")))
    for r in records():
        if r.get("kind") == "sample":
            vs = verdicts(r["week"])
            print("audit %s: population %s, sampled %d, verdicts %d (%d fail)" % (
                r["week"], r.get("population"), len(r["sample"]), len(vs), sum(v["verdict"] == "fail" for v in vs)))
        elif r.get("kind") in ("equiv_suspect", "x64_report"):
            print("%s %s %s: %s (job %s)" % (r["kind"], r["week"], r["addr"], r.get("why"), r.get("job")))
    print("ckpt lines: %d" % len(tree_tu.ckpt_lines()))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    for n in ("sample", "submit", "judge"):
        p = sp.add_parser(n)
        p.add_argument("--week", default=this_week())
        if n == "submit":
            p.add_argument("--name", required=True)
            p.add_argument("--limit", type=int, default=14400)
            p.add_argument("--resubmit", action="store_true", help="submit again the runs with no pass/fail verdict")
    p = sp.add_parser("lift")
    p.add_argument("pause")
    p.add_argument("--decision", required=True)
    p.add_argument("--why", required=True)
    sp.add_parser("status")
    a = ap.parse_args(argv)
    return {"sample": lambda a: cmd_sample(a) and 0, "submit": cmd_submit, "judge": cmd_judge, "lift": cmd_lift,
            "status": cmd_status}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
