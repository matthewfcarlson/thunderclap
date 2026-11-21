#!/usr/bin/env python3
"""The ledger kind `ckpt` (ckpt2, D162/D163 piece 4; rev5 ADOPT; docs/checkpoints.md "The rule"): record the blocks a
checkpoint validation vouches for in config/ckpt-ledger.jsonl (append-only, merge=union). A line satisfies only the Wine
mode of its block for its wine code hash; tools/tree_tu.py re-checks R2 and R4 whenever it reads a line
(ckpt_line_accepts) and counts it only in materialize's D126 gate, verify's proof status and `hash --proven`'s pin
(never as an equiv proof: not for --from-ledger, carry, post contracts, the x64 gate or the unproven ratchet).

  # after a pair (control + proof Wine builds linked with HULK_WINE_NOICF=1, the proof image fetched), the proof
  # image's coverage replay of every manifest reference, ckpt_validate.py blocks and gate:
  build/venv/bin/python tools/ckpt_ledger.py record --blocks BLOCKS.json --gate GATE.json \
      --proof-tree PROOF_WORKSPACE --proof-job PROOF_JOB --coverage-job play3=COVER_JOB [--addr 0x...] [--dry-run]
  build/venv/bin/python tools/ckpt_ledger.py show [--addr 0x...]      # each line and whether it is accepted now

record refuses unless: the gate report is ok on every manifest reference, names this proof job and the manifest's
current commit; the blocks report's proof image is the proof job's (image.sha256); the function is eligible (R4 none,
R2 ok) and its tree block equivalent; the proof workspace's sources (src/, include/) hash as the proof job's
sources.json.gz says (so the code hash computed there is the image's); the recording tree's block has that same wine
code hash now; and no pause is open (config/ckpt-pause.jsonl). The changed blocks' window bitmaps go into the line, so
R2 is recomputed at read time on any host; the validation's reports are copied to build/ckpt/validations/ID/ (local
audit material, never committed) and their hash recorded. A line vouches for its block's own code at that commit;
callees are validated on their own.
"""
import argparse
import datetime
import gzip
import hashlib
import json
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

VALIDATOR_FILES = ("tools/ckpt_validate.py", "tools/ckpt_refs.py", "tools/ckpt_ledger.py", "tools/cover.py")


def validator_digest(root=ROOT):
    """sha256 over the image-time validator's files (revoke --kind ckpt --validator DIGEST revokes every line recorded
    under it)"""
    h = hashlib.sha256()
    for rel in VALIDATOR_FILES:
        p = os.path.join(root, rel)
        h.update(rel.encode() + b"\0")
        if os.path.exists(p):
            with open(p, "rb") as f:
                h.update(hashlib.sha256(f.read()).digest())
    return h.hexdigest()[:20]


def sha1_file(p):
    with open(p, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def sha256_file(p):
    with open(p, "rb") as f:
        return hashlib.sha256(f.read()).hexdigest()


def job_dir(job):
    return os.path.join(ROOT, "build/jobs/out", str(job), "nb-out")


def summary(job):
    p = os.path.join(job_dir(job), "summary.json")
    return json.load(open(p)) if os.path.exists(p) else None


def landing_baseline(tree):
    import tree_tu
    return tree_tu.load_unproven_baseline(os.path.join(tree, "config", "unproven-baseline.json"))


def manifest_commit(root=ROOT):
    return subprocess.run(["git", "-C", root, "log", "-1", "--format=%H", "--", "config/ckpt-refs.json"],
                          capture_output=True, text=True).stdout.strip() or None


def source_mismatch(proof_tree, sources):
    """[path] of the proof workspace's src/ and include/ files whose content differs from the proof job's sources map
    (or that the workspace lacks)"""
    bad = []
    for rel, h in sorted(sources.items()):
        if not rel.startswith(("src/", "include/")):
            continue
        p = os.path.join(proof_tree, rel)
        if not os.path.exists(p) or sha1_file(p) != h:
            bad.append(rel)
    return bad


def wine_code(tree, tu, addr):
    """(kind, wine code hash) of block ADDR of TU in the tree at TREE, as tree_tu's check computes it"""
    import tree_tu
    p = os.path.join(tree, tu)
    recs = tree_tu.check_tu(p)
    tree_tu.with_wine(p, recs)
    r = next((x for x in recs if x["addr"] == addr), None)
    return (r.get("kind"), r.get("wine_code_hash")) if r else (None, None)


def refuse(why):
    sys.exit("ckpt_ledger record: REFUSED: %s" % why)


def cmd_record(a):
    import ckpt_refs
    import ckpt_validate
    import tree_tu
    if tree_tu.ckpt_open_pause():
        refuse("a pause is open (config/ckpt-pause.jsonl): no new ckpt line until the user lifts it")
    import ckpt_audit
    miss = ckpt_audit.audit_missing()
    if miss:
        refuse("the weekly audit is not done: %s" % miss)
    m = ckpt_refs.load()
    names = sorted(e["name"] for e in m["references"])
    gate = json.load(open(a.gate))
    blocks = json.load(open(a.blocks))
    if not gate.get("ok"):
        refuse("the gate report is not ok")
    if sorted(gate.get("references", {})) != names:
        refuse("the gate covers %s, the manifest lists %s" % (sorted(gate.get("references", {})), names))
    for name, g in gate["references"].items():
        if not g.get("ok") or str(g.get("proof")) != str(a.proof_job):
            refuse("gate %s: ok %s, proof %s (this proof job is %s)" % (name, g.get("ok"), g.get("proof"), a.proof_job))
    mc = manifest_commit()
    if gate.get("manifest_commit") != mc:
        refuse("the gate ran against manifest commit %s, the manifest is at %s" % (gate.get("manifest_commit"), mc))
    covj = dict(c.partition("=")[::2] for c in a.coverage_job)
    if sorted(covj) != names:
        refuse("--coverage-job for %s, the manifest lists %s" % (sorted(covj), names))
    jd = job_dir(a.proof_job)
    want = {}
    for l in open(os.path.join(jd, "image.sha256")):
        w = l.split()
        if len(w) == 2:
            want[w[1]] = w[0]
    img = os.path.join(blocks["proof"], "hulk-strict.exe")
    if want.get("hulk-strict.exe") != sha1_file(img):
        refuse("the blocks report's proof image is not the proof job's image")
    # (rev5) one image: the pair is linked without ICF (the image the block diff reads), and every coverage replay ran
    # exactly that image (`cover` writes the sha1 of the image it ran) and gave the hit file the blocks report read
    ctl_job = str(next(iter(gate["references"].values()))["control"])
    for j in (a.proof_job, ctl_job):
        sm = summary(j)
        if sm is None or sm.get("link_noicf") is not True:
            refuse("job %s was not linked with HULK_WINE_NOICF=1 (summary link_noicf %s)" % (
                j, None if sm is None else sm.get("link_noicf")))
        # (rev5) only the proof may be a proof-workspace build (HULK_CKPT_WORKSPACE=1); nothing else switched
        if sm.get("off") and not (j == a.proof_job and sm["off"] == {"HULK_CKPT_WORKSPACE": "1"}):
            refuse("job %s was built with development switches %s" % (j, sm["off"]))
    for name, cj in covj.items():
        cd = os.path.join(ROOT, "build/jobs/out", str(cj), "wine-out")
        try:
            ran = open(os.path.join(cd, "image.sha1")).read().split()[0]
        except (OSError, IndexError):
            ran = None
        if ran != want.get("hulk-strict.exe"):
            refuse("coverage job %s ran image %s, the proof job's is %s" % (cj, ran, want.get("hulk-strict.exe")))
        cv = os.path.join(cd, "trace.txt.cov")
        bc = (blocks.get("covers") or {}).get(name) or {}
        if not os.path.exists(cv) or bc.get("sha256") != sha256_file(cv):
            refuse("the blocks report's coverage of %s is not coverage job %s's hit file" % (name, cj))
    with gzip.open(os.path.join(jd, "sources.json.gz"), "rt") as f:
        sources = json.load(f)
    bad = source_mismatch(a.proof_tree, sources)
    if bad:
        refuse("the proof workspace is not the proof job's source (%d file(s), first %s)" % (len(bad), bad[0]))
    addrs = {"0x%08x" % int(x, 16) for x in a.addr} if a.addr else None
    fns = [f for f in blocks["functions"] if addrs is None or f["addr"] in addrs]
    if addrs and {f["addr"] for f in fns} != addrs:
        refuse("not in the blocks report: %s" % sorted(addrs - {f["addr"] for f in fns}))
    vid = "%s-%s" % (a.proof_job, datetime.datetime.now().strftime("%Y%m%d%H%M%S"))
    vdir = os.path.join(ROOT, "build/ckpt/validations", vid)
    host = gate.get("host")
    lines = []
    now = datetime.datetime.now().isoformat(timespec="seconds")
    vd = validator_digest()
    for f in fns:
        if not f.get("eligible") or f.get("r4") is not None or not f.get("r2"):
            refuse("%s is not eligible (%s)" % (f["addr"], f.get("r4") or "R2 %s" % f.get("r2_windows")))
        if not f.get("r2_hits"):
            refuse("%s: the blocks report has no window bitmaps (ckpt_validate.py before piece 4)" % f["addr"])
        kind, code = wine_code(a.proof_tree, f["tu"], f["addr"])
        if kind != "equivalent" or not code:
            refuse("%s: a %s block in the proof workspace (wine code %s)" % (f["addr"], kind, code))
        kind2, code2 = wine_code(a.tree, f["tu"], f["addr"])
        lb = landing_baseline(a.tree)
        if tree_tu.workspace_accepts(lb):
            refuse("the landing tree's unproven baseline holds workspace accepts %s" % tree_tu.workspace_accepts(lb)[:5])
        if ((lb.get("blocks", {}).get(f["addr"], {}).get("modes") or {}).get("wine") or {}).get("code") == code2:
            refuse("%s: the landing tree's unproven baseline lists its wine code (the ckpt line must be the only "
                   "exemption)" % f["addr"])
        if kind2 != "equivalent" or code2 != code:
            refuse("%s: the recording tree's block is %s with wine code %s, the proof's is %s" % (
                f["addr"], kind2, code2, code))
        ae = ckpt_validate.allow_entry(f["tu"])
        if ae is None or f.get("allow") != {"entry": ae[0], "tags": list(ae[1])}:
            refuse("%s: the allowlist entry is %s now, the report says %s" % (f["addr"], ae, f.get("allow")))
        refs = {}
        for name, h in f["r2_hits"].items():
            ent = next(e for e in m["references"] if e["name"] == name)
            refs[name] = {"recording_sha256": ent["recording_sha256"], "ref_sha256": ent["ref_sha256"],
                          "probe": ent["probe"], "epoch": h["epoch"], "blocks": h["blocks"]}
        e = {"kind": "ckpt", "addr": f["addr"], "mode": "wine", "code": code, "tu": f["tu"], "allow": f["allow"],
             "refs": refs, "min_windows": ckpt_validate.MIN_WINDOWS, "validator": vd, "host": host,
             "manifest_commit": mc,
             "commit": subprocess.run(["git", "-C", a.tree, "rev-parse", "HEAD"], capture_output=True,
                                      text=True).stdout.strip() or None,
             "jobs": {"control": ctl_job, "proof": str(a.proof_job), "coverage": covj},
             "image_sha256": sha256_file(img),
             "gate": {n: g["gate"] for n, g in gate["references"].items()},
             "control_diverged": {n: g.get("control_diverged") for n, g in gate["references"].items()},
             "particle_frames": {n: g.get("particle_frames") for n, g in gate["references"].items()},
             "evidence": {"path": os.path.relpath(vdir, ROOT)}, "date": now, "by": "ckpt_ledger record"}
        why = tree_tu.ckpt_line_accepts(e, f["tu"], kind2, code2, manifest=m)
        if why is not None:
            refuse("%s: the line would not be accepted when read (%s)" % (f["addr"], why))
        lines.append(e)
    if not lines:
        refuse("no function to record")
    if a.dry_run:
        for e in lines:
            print(json.dumps(e, sort_keys=True))
        return 0
    os.makedirs(vdir, exist_ok=True)
    shutil.copy(a.blocks, os.path.join(vdir, "blocks.json"))
    shutil.copy(a.gate, os.path.join(vdir, "gate.json"))
    ev = hashlib.sha256(open(os.path.join(vdir, "blocks.json"), "rb").read() +
                        open(os.path.join(vdir, "gate.json"), "rb").read()).hexdigest()
    with open(a.ledger or tree_tu.CKPT_LEDGER, "a") as out:
        for e in lines:
            e["evidence"]["sha256"] = ev
            out.write(json.dumps(e, sort_keys=True) + "\n")
            print("recorded ckpt %s %s wine %s (%s)" % (e["addr"], e["tu"], e["code"], tree_tu.ckpt_line_key(e)))
    return 0


def cmd_cover(a):
    """submit the coverage replay of a proof job's fetched image for one manifest reference: every basic-block leader
    armed (cover.py list --bb) with window bitmaps (HULK_COVER_EPOCH), the sha1 of the image it ran in
    wine-out/image.sha1 (record checks it against the proof job's)"""
    import ckpt_refs
    ent = next((e for e in ckpt_refs.verify() if e["name"] == a.ref), None)
    if ent is None:
        sys.exit("cover: %s is not a manifest reference" % a.ref)
    img = os.path.join(job_dir(a.proof_job), "image")
    if not os.path.exists(os.path.join(img, "hulk-strict.exe")):
        sys.exit("cover: no fetched image for job %s (submit the proof with --fetch image)" % a.proof_job)
    sm = summary(a.proof_job) or {}
    if sm.get("link_noicf") is not True:
        sys.exit("cover: job %s was not linked with HULK_WINE_NOICF=1" % a.proof_job)
    out = os.path.join(ROOT, "build/ckpt/validations", "cover-%s" % a.proof_job)
    os.makedirs(out, exist_ok=True)
    lst = os.path.join(out, "cover.lst")
    if not os.path.exists(lst):
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/cover.py"), "list", os.path.join(img, "hulk-strict.map"),
                        "--bb", "--exe", os.path.join(img, "hulk-strict.exe"), "--out", lst], check=True)
    import wine_replay_job
    files = ["%s=wine-img/%s" % (os.path.join(img, f), f) for f in wine_replay_job.DLLS] + [
        "%s=wine-img/rec.hrp" % os.path.join(ROOT, ent["recording"]), "%s=wine-img/cover.lst" % lst,
        "tools/wine_replay_job.py", "tools/wine_run.py"]
    cmd = ("mkdir -p wine-out && shasum wine-img/hulk-strict.exe > wine-out/image.sha1 && "
           "build/venv/bin/python tools/wine_replay_job.py run --timeout %d --frames %d "
           "--env 'HULK_COVER=..\\wine-img\\cover.lst' --env HULK_COVER_EPOCH=%d") % (a.timeout, a.frames, a.epoch)
    argv = [sys.executable, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", a.name, "--needs", "wine",
            "--limit", str(a.timeout + 600), "--attempts", "1", "--out", "wine-out", "--files"] + files
    if a.host:
        argv += ["--host", a.host]
    argv += ["--", "sh", "-c", cmd]
    r = subprocess.run(argv, capture_output=True, text=True)
    if r.returncode:
        sys.exit(r.stderr or r.stdout)
    print(r.stdout.strip())
    return 0


def cmd_show(a):
    import tree_tu
    addrs = {"0x%08x" % int(x, 16) for x in a.addr} if a.addr else None
    for e in tree_tu.ckpt_lines(a.ledger):
        if addrs and e["addr"] not in addrs:
            continue
        kind, code = wine_code(ROOT, e["tu"], e["addr"]) if a.check else (None, None)
        why = tree_tu.ckpt_line_accepts(e, e["tu"], kind, code) if a.check else "(not checked: --check)"
        print("%s %s %s %s %s: %s" % (tree_tu.ckpt_line_key(e), e["addr"], e["tu"], e["code"], e["date"],
                                     "accepted" if why is None else why))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ledger", help="(tests) another ckpt ledger file")
    sp = ap.add_subparsers(dest="cmd", required=True)
    r = sp.add_parser("record")
    r.add_argument("--blocks", required=True, help="ckpt_validate.py blocks --json")
    r.add_argument("--gate", required=True, help="ckpt_validate.py gate --json")
    r.add_argument("--proof-tree", required=True, help="the proof job's workspace (its sources)")
    r.add_argument("--proof-job", required=True)
    r.add_argument("--coverage-job", action="append", default=[], help="NAME=JOB, every manifest reference")
    r.add_argument("--tree", default=ROOT, help="the tree the line lands in (default: this checkout)")
    r.add_argument("--addr", action="append")
    r.add_argument("--dry-run", action="store_true")
    c = sp.add_parser("cover", help="submit the proof image's coverage replay of one manifest reference")
    c.add_argument("--proof-job", required=True)
    c.add_argument("--ref", default="play3")
    c.add_argument("--name", required=True)
    c.add_argument("--host")
    c.add_argument("--frames", type=int, default=60000)
    c.add_argument("--timeout", type=int, default=8400)
    c.add_argument("--epoch", type=int, default=300)
    s = sp.add_parser("show")
    s.add_argument("--addr", action="append")
    s.add_argument("--check", action="store_true", help="compute each block's current wine code and re-check the line")
    a = ap.parse_args()
    return {"record": cmd_record, "cover": cmd_cover, "show": cmd_show}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
