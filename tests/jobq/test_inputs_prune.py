"""wine_build_job.PRUNE_PY: the host-side prune of ~/hulk-jobs/nb/inputs-STAMP never removes a stamp a queued or
running job names, nor one a running job holds a lease on; otherwise it keeps the most recently used ones.

  python3 -m unittest tests.jobq.test_inputs_prune     (from the repo root)
"""
import os
import subprocess
import sys
import tempfile
import time
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import wine_build_job as nbj  # noqa: E402


class Prune(unittest.TestCase):
    def setUp(self):
        self.nb = tempfile.mkdtemp()
        now = time.time()
        for i in range(8):          # inputs-s0 the oldest ... inputs-s7 the newest
            p = os.path.join(self.nb, "inputs-s%d" % i)
            os.makedirs(p)
            open(os.path.join(p, ".complete"), "w").close()
            os.utime(p, (now - 1000 + i, now - 1000 + i))
        os.makedirs(os.path.join(self.nb, "inputs-s9.tmp"))       # a sync in progress
        os.makedirs(os.path.join(self.nb, "ws"))

    def prune(self, *protected, keep=4, lease_max=3600):
        r = subprocess.run([sys.executable, "-c", nbj.PRUNE_PY, self.nb, str(keep), str(lease_max)] + list(protected),
                           capture_output=True, text=True, check=True)
        return sorted(n for n in os.listdir(self.nb) if n.startswith("inputs-"))

    def test_keeps_newest(self):
        self.assertEqual(self.prune(), ["inputs-s4", "inputs-s5", "inputs-s6", "inputs-s7", "inputs-s9.tmp"])

    def test_referenced_stamps_survive(self):
        left = self.prune("s0", "s2")
        self.assertIn("inputs-s0", left)
        self.assertIn("inputs-s2", left)
        self.assertNotIn("inputs-s1", left)
        self.assertNotIn("inputs-s3", left)

    def test_leased_stamp_survives_until_the_lease_is_stale(self):
        lease = os.path.join(self.nb, "inputs-s1", ".lease-64000")
        open(lease, "w").close()
        d = os.path.join(self.nb, "inputs-s1")
        os.utime(d, (time.time() - 5000, time.time() - 5000))      # (the oldest by use: only the lease keeps it)
        self.assertIn("inputs-s1", self.prune())
        old = time.time() - 7200
        os.utime(lease, (old, old))
        self.assertNotIn("inputs-s1", self.prune())

    def test_use_refreshes(self):
        p = os.path.join(self.nb, "inputs-s0")
        os.utime(p)                 # wine_build_run touches the directory when a job starts
        self.assertIn("inputs-s0", self.prune())


if __name__ == "__main__":
    unittest.main()
