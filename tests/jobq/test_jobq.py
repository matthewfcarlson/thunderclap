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
