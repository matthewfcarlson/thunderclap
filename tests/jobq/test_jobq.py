"""Unit tests for tools/jobq.py: guard, host choice, state machine, and a local-only daemon round trip.

  python3 -m unittest tests.jobq.test_jobq     (from the repo root; uses a throwaway queue directory)
"""
import json
import os
import sys
import tempfile
import threading
import time
import unittest

TMP = tempfile.mkdtemp(prefix="jobq-test-")
os.environ["JOBQ_DIR"] = TMP
os.environ["JOBQ_NO_DAEMON"] = "1"
os.environ["JOBQ_IDLE_EXIT"] = "3600"
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import jobq  # noqa: E402


def mkhost(name, caps, cap=4, pref=0, local=False, used=0, xemu=0):
    h = jobq.Host({"name": name, "local": local, "caps": caps, "slots": cap, "pref": pref, "routes": [["x"]]})
    h.cap, h.used, h.ready, h.xemu_used = cap, used, True, xemu
    return h


def job(needs="any", slots=1, tried=(), cmd="echo"):
    return {"needs": needs, "slots": slots, "tried": json.dumps(list(tried)), "cmd": json.dumps([cmd])}


class Guard(unittest.TestCase):
    def test_xemu_needs_snapshot(self):
        self.assertIsNotNone(jobq.guard(["xemu", "-dvd_path", "x"]))
        self.assertIsNotNone(jobq.guard(["python", "run.py"], "xemu"))
        self.assertIsNone(jobq.guard(["xemu", "-snapshot"]))
        self.assertIsNone(jobq.guard(["python", "run.py", "-snapshot"], "xemu"))

    def test_forbidden(self):
        for f in jobq.FORBIDDEN:
            self.assertIsNotNone(jobq.guard(["x", "-snapshot", f]), f)
        self.assertIsNone(jobq.guard(["python", "tools/equiv.py"]))

    def test_submit_refuses(self):
        with self.assertRaises(SystemExit):
            jobq.make_job("t", ["xemu", "-drive-mirror"], "xemu")


class Choose(unittest.TestCase):
    def setUp(self):
        self.m2 = mkhost("m2", ["equiv", "xemu"], 4)
        self.m1 = mkhost("m1", ["equiv"], 4)
        self.lo = mkhost("lo", ["equiv", "wine"], 3, 90, True)
        self.hs = [self.m2, self.m1, self.lo]

    def test_prefers_remote_then_balances(self):
        self.m2.used = 2
        self.assertIs(jobq.choose_host(job("equiv"), self.hs), self.m1)
        self.m1.used = 3
        self.assertIs(jobq.choose_host(job("equiv"), self.hs), self.m2)

    def test_laptop_last(self):
        self.m1.used = self.m2.used = 4
        self.assertIs(jobq.choose_host(job("equiv"), self.hs), self.lo)

    def test_wine_only_local(self):
        self.assertIs(jobq.choose_host(job("wine"), self.hs), self.lo)
        self.lo.used = 3
        self.assertIsNone(jobq.choose_host(job("wine"), self.hs))

    def test_xemu_one_at_a_time_never_local(self):
        self.assertIs(jobq.choose_host(job("xemu"), self.hs), self.m2)
        self.m2.xemu_used = 1
        self.assertIsNone(jobq.choose_host(job("xemu"), self.hs))
        self.lo.caps.add("xemu")
        self.assertIsNone(jobq.choose_host(job("xemu"), self.hs))

    def test_tried_host_avoided(self):
        self.assertIs(jobq.choose_host(job("equiv", tried=["m2"]), self.hs), self.m1)
        self.assertIs(jobq.choose_host(job("equiv", tried=["m2", "m1"]), self.hs[:2]), self.m2)

    def test_down_and_big_jobs(self):
        self.m1.down_until = time.time() + 99
        self.assertIs(jobq.choose_host(job("equiv"), self.hs), self.m2)
        self.assertIs(jobq.choose_host(job("equiv", slots=9), [self.m2]), self.m2)   # idle host takes a big job
        self.m2.used = 1
        self.assertIsNone(jobq.choose_host(job("equiv", slots=9), [self.m2]))


    def test_blocked_hosts_and_reservation(self):
        self.assertIsNone(jobq.choose_host(job("equiv"), [self.m2], blocked={"m2"}))
        self.assertIs(jobq.choose_host(job("equiv"), self.hs, blocked={"m2"}), self.m1)
        self.m2.used = 3
        big = job("equiv", slots=4)
        self.assertIsNone(jobq.choose_host(big, [self.m2]))                     # does not fit now
        self.assertTrue(self.m2.eligible(big, time.time(), capacity=False))     # but could once jobs finish: reserve m2
        self.assertFalse(self.lo.eligible(big, time.time(), capacity=False))    # the laptop never takes big jobs
        self.assertFalse(self.m1.eligible(job("xemu", slots=4), time.time(), capacity=False))


class Parse(unittest.TestCase):
    def test_ids(self):
        self.assertEqual(jobq.parse_ids(["3", "5-7", "9,10"]), [3, 5, 6, 7, 9, 10])


class StateMachine(unittest.TestCase):
    def test_requeue_then_gaveup(self):
        jid = jobq.insert_jobs([jobq.make_job("t", ["true"], attempts=2)])[0]
        d = jobq.Daemon([])
        c = jobq.conn()
        row = c.execute("SELECT * FROM jobs WHERE id=?", (jid,)).fetchone()
        h = mkhost("h", ["equiv"])
        self.assertTrue(d.claim(c, row, h))
        self.assertFalse(d.claim(c, row, h))          # already running
        d.requeue_or_giveup(jid, "ssh")
        self.assertEqual(c.execute("SELECT state FROM jobs WHERE id=?", (jid,)).fetchone()[0], "queued")
        d.claim(c, c.execute("SELECT * FROM jobs WHERE id=?", (jid,)).fetchone(), h)
        d.requeue_or_giveup(jid, "ssh")
        r = c.execute("SELECT state,reason,tried FROM jobs WHERE id=?", (jid,)).fetchone()
        self.assertEqual((r[0], r[1], json.loads(r[2])), ("gaveup", "ssh", ["h", "h"]))


class Fairness(unittest.TestCase):
    """A submitter with a long queue can't hide or starve a later submitter."""

    def test_later_submitter_gets_slots(self):
        old = jobq.PER_NAME_HEAD
        jobq.PER_NAME_HEAD = 5                     # the long queue is far deeper than the per-name head
        try:
            big = jobq.insert_jobs([jobq.make_job("fair-big", ["true"]) for _ in range(30)])
            small = jobq.insert_jobs([jobq.make_job("fair-small", ["true"]) for _ in range(2)])
            d = jobq.Daemon([mkhost("h", ["equiv"], cap=4)])
            d.run_job = lambda h, job: None        # claim only, don't run
            c = jobq.conn()
            d.dispatch(c)
            st = {r["name"]: r["n"] for r in c.execute(
                "SELECT name,count(*) n FROM jobs WHERE state='running' AND name LIKE 'fair-%' GROUP BY name")}
            self.assertEqual(st.get("fair-small"), 2)   # both small jobs start despite 30 older big ones
            self.assertEqual(st.get("fair-big"), 2)     # and the big submitter fills the rest, nothing idle
        finally:
            jobq.PER_NAME_HEAD = old
            c = jobq.conn()
            with c:
                c.execute("UPDATE jobs SET state='cancelled' WHERE name LIKE 'fair-%'")


class Lending(unittest.TestCase):
    """Reserved slots a big job leaves idle (load well below `used`) go to 1-slot jobs, within the core count."""

    def test_idle_reserved_slots_lent(self):
        h = mkhost("h", ["equiv"], cap=8, used=8)          # an 8-slot build holds the host...
        h.load, h.ncpu = 1.0, 16                            # ...but is in a one-core phase
        h.lend_budget = max(0, min(int(h.used - h.load) - 1, h.ncpu - 1 - int(h.load)))
        self.assertEqual(h.lend_budget, 6)
        self.assertTrue(h.eligible(job(slots=1), time.time()))
        self.assertFalse(h.eligible(job(slots=2), time.time()))   # only 1-slot jobs borrow
        h.lend_budget = 0
        self.assertFalse(h.eligible(job(slots=1), time.time()))   # nothing idle: no loan

    def test_held_host_lends_only_idle_slots(self):
        h = mkhost("h", ["equiv"], cap=16, used=8)         # a build runs; a queued big job holds the host
        h.load, h.ncpu = 1.0, 16
        h.lend_budget = 0
        self.assertIsNone(jobq.choose_host(job(slots=1), [h], blocked={"h"}))   # free slots stay for the big job
        h.lend_budget = 6
        self.assertIs(jobq.choose_host(job(slots=1), [h], blocked={"h"}), h)    # but idle reserved slots are lent
        self.assertIsNone(jobq.choose_host(job(slots=2), [h], blocked={"h"}))

    def test_busy_host_lends_nothing(self):
        h = mkhost("h", ["equiv"], cap=8, used=8)
        h.load, h.ncpu = 7.5, 8                             # the reserved slots really are busy
        self.assertEqual(max(0, min(int(h.used - h.load) - 1, h.ncpu - 1 - int(h.load))), 0)


class Affinity(unittest.TestCase):
    """jq3: a job with an affinity host waits for it until affinity_until, then goes anywhere (the affinity host first)."""

    def setUp(self):
        self.m2 = mkhost("m2", ["msvc"], 16)
        self.m1 = mkhost("m1", ["msvc"], 8)

    def aj(self, until, slots=8):
        j = job("msvc", slots=slots)
        j.update(affinity="m2", affinity_until=until)
        return j

    def test_waits_for_affinity_host(self):
        now = time.time()
        self.m2.used = 16
        self.assertIsNone(jobq.choose_host(self.aj(now + 60), [self.m2, self.m1], now))      # m1 is free but must not take it
        self.assertIs(jobq.choose_host(self.aj(now - 1), [self.m2, self.m1], now), self.m1)   # after the wait: anywhere
        self.m2.used = 0
        self.m1.used = 0
        self.assertIs(jobq.choose_host(self.aj(now - 1), [self.m1, self.m2], now), self.m2)   # the affinity host still first
        self.assertIs(jobq.choose_host(self.aj(now + 60), [self.m1, self.m2], now), self.m2)

    def test_unpinned_goes_where_there_is_room(self):
        self.m2.used = 12
        self.assertIs(jobq.choose_host(job("msvc", slots=8), [self.m2, self.m1]), self.m1)
        self.m1.used = 8
        self.assertIsNone(jobq.choose_host(job("msvc", slots=8), [self.m2, self.m1]))
        self.assertFalse(self.m1.eligible(self.aj(time.time() + 60), time.time(), capacity=False))   # only m2 is held for it
        self.assertTrue(self.m2.eligible(self.aj(time.time() + 60), time.time(), capacity=False))

    def test_make_job_fields(self):
        j = jobq.make_job("t", ["true"], affinity="m2", affinity_wait=100, prep=["python", "x", "{host}"])
        self.assertEqual(j["affinity"], "m2")
        self.assertAlmostEqual(j["affinity_until"], time.time() + 100, delta=5)
        self.assertEqual(json.loads(j["prep"]), ["python", "x", "{host}"])
        self.assertIsNone(jobq.make_job("t", ["true"])["affinity_until"])


class SlotRelease(unittest.TestCase):
    """jq3: a running job that declares fewer slots (RUNDIR/.jq-slots, read by `probe slots`) gives the rest back."""

    def test_apply_slots_lowers_only(self):
        h = mkhost("h", ["msvc"], 16)
        d = jobq.Daemon([h])
        jid = jobq.insert_jobs([jobq.make_job("t-slots", ["true"], slots=8)])[0]
        h.used = 9
        d.cur[jid] = (h, 8)
        h.run_slots = {"%d-a1" % jid: 1, "999999-a1": 1, "junk": 3}
        d.apply_slots(h)
        self.assertEqual((h.used, d.cur[jid][1]), (2, 1))
        c = jobq.conn()
        self.assertEqual(c.execute("SELECT slots_now FROM jobs WHERE id=?", (jid,)).fetchone()[0], 1)
        h.run_slots = {"%d-a1" % jid: 4}                       # never raised again
        d.apply_slots(h)
        self.assertEqual((h.used, d.cur[jid][1]), (2, 1))

    def test_probe_reads_run_slots(self):
        run = os.path.join(os.path.expanduser("~/hulk-jobs/run"), "jq3test-%d-a1" % os.getpid())
        os.makedirs(run, exist_ok=True)
        try:
            open(os.path.join(run, ".jq-slots"), "w").write("1\n")
            h = jobq.Host({"name": "local", "local": True, "slots": 2, "caps": ["equiv"]})
            h.route = []
            seen = []
            h.on_slots = lambda x: seen.append(dict(x.run_slots))
            self.assertTrue(h.probe())
            self.assertEqual(seen[0].get(os.path.basename(run)), 1)
        finally:
            import shutil
            shutil.rmtree(run, ignore_errors=True)


class NewHost(unittest.TestCase):
    """jq3: a host added to hosts.json joins a running daemon (no restart, so no running job is lost)."""

    def test_reload_adds_host(self):
        p = os.path.join(TMP, "hosts-new.json")
        json.dump({"hosts": [{"name": "old", "routes": [["x"]], "caps": ["equiv"]},
                             {"name": "new", "routes": [["y"]], "caps": ["equiv", "wine"], "slots": 24, "python": "/v/python"}]}, open(p, "w"))
        os.environ["JOBQ_HOSTS"] = p
        try:
            d = jobq.Daemon([jobq.Host({"name": "old", "routes": [["x"]], "caps": ["equiv"]})])
            d.reload_caps()
            self.assertEqual([h.name for h in d.hosts], ["old", "new"])
            n = d.hosts[1]
            self.assertEqual((n.slots_cfg, n.down_until, n.python, n.ready), (24, 1, "/v/python", False))
            self.assertIn("/v/python ", n.argv(["probe"], ["u@h"])[-1])
            d2 = jobq.Daemon([jobq.Host({"name": "old", "routes": [["x"]], "caps": ["equiv"]})], only=["old"])
            d2.reload_caps()
            self.assertEqual([h.name for h in d2.hosts], ["old"])
        finally:
            del os.environ["JOBQ_HOSTS"]


class RoundTrip(unittest.TestCase):
    """A real daemon with the local host only: success, failure exit, overlay file, output fetch, timeout retry, cancel."""

    @classmethod
    def setUpClass(cls):
        hosts = [jobq.Host({"name": "local", "local": True, "slots": 2, "caps": ["equiv"], "pref": 90})]
        cls.d = jobq.Daemon(hosts)
        threading.Thread(target=cls.d.loop, daemon=True).start()

    def wait(self, jid, t=90):
        c = jobq.conn()
        end = time.time() + t
        while time.time() < end:
            r = c.execute("SELECT * FROM jobs WHERE id=?", (jid,)).fetchone()
            if r["state"] in jobq.TERMINAL:
                return r
            time.sleep(0.3)
        self.fail("job %d did not finish" % jid)

    def sub(self, cmd, **kw):
        files = kw.pop("files", {})
        return jobq.insert_jobs([jobq.make_job("t", cmd, files=files, commit=jobq.head_commit(), **kw)])[0]

    def test_ok_and_fail(self):
        self.assertEqual(self.wait(self.sub(["true"]))["state"], "done")
        r = self.wait(self.sub(["sh", "-c", "exit 3"]))
        self.assertEqual((r["state"], r["exit_code"]), ("failed", 3))

    def test_overlay_and_outputs(self):
        src = os.path.join(TMP, "ov.txt")
        open(src, "w").write("hello overlay\n")
        files = {"ov/in.txt": [jobq.store_file(src), 0o644]}
        jid = self.sub(["sh", "-c", "mkdir -p o && cat ov/in.txt > o/out.txt; echo log-line"], files=files, outs=["o/out.txt"])
        r = self.wait(jid)
        self.assertEqual(r["state"], "done")
        self.assertEqual(open(os.path.join(jobq.OUT, str(jid), "o/out.txt")).read(), "hello overlay\n")
        self.assertIn("log-line", open(os.path.join(jobq.OUT, str(jid), "log")).read())

    def test_timeout_then_retry_succeeds(self):
        jid = self.sub(["sh", "-c", 'test "$JOBQ_ATTEMPT" -gt 1 || sleep 60'], limit=3)
        r = self.wait(jid)
        self.assertEqual((r["state"], r["attempts"]), ("done", 2))

    def test_timeout_gives_up(self):
        r = self.wait(self.sub(["sleep", "60"], limit=2, attempts=2))
        self.assertEqual((r["state"], r["attempts"]), ("gaveup", 2))
        self.assertIn("wall-clock", r["reason"])

    def test_prep_runs_before_and_failure_retries(self):
        mark = os.path.join(TMP, "prep-mark")
        jid = self.sub(["true"], prep=["sh", "-c", 'echo "$0" > %s' % mark, "{host}"])
        self.assertEqual(self.wait(jid)["state"], "done")
        self.assertEqual(open(mark).read().strip(), "local")
        r = self.wait(self.sub(["true"], prep=["sh", "-c", "exit 2"], attempts=2))
        self.assertEqual((r["state"], r["attempts"]), ("gaveup", 2))
        self.assertIn("prep", r["reason"])

    def test_slots_file_released_while_running(self):
        jid = self.sub(["sh", "-c", 'echo 1 > "$JOBQ_RUN_DIR/.jq-slots"; sleep 4'], slots=2)
        c = jobq.conn()
        while c.execute("SELECT state FROM jobs WHERE id=?", (jid,)).fetchone()[0] != "running":
            time.sleep(0.2)
        time.sleep(1)
        h = self.d.hosts[0]
        h.probe()
        self.assertEqual(c.execute("SELECT slots_now FROM jobs WHERE id=?", (jid,)).fetchone()[0], 1)
        self.assertEqual(self.wait(jid)["state"], "done")
        time.sleep(0.5)
        self.assertEqual(h.used, 0)

    def test_cancel_running(self):
        jid = self.sub(["sleep", "60"])
        c = jobq.conn()
        while c.execute("SELECT state FROM jobs WHERE id=?", (jid,)).fetchone()[0] != "running":
            time.sleep(0.2)
        with c:
            c.execute("UPDATE jobs SET cancel=1 WHERE id=?", (jid,))
        self.assertEqual(self.wait(jid)["state"], "cancelled")


if __name__ == "__main__":
    unittest.main()
