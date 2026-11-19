"""tools/vcall_scan.py's solver (integ3 chk3): the row-echelon solver `_solve` gives exactly the feasible values of the
brute force it replaced (`_solve_brute`, kept as the oracle), on random small systems and on the stack-depth systems of
a sample of the XBE's functions (skipped without isos/extracted/default.xbe and build/functions.csv).

  build/venv/bin/python -m unittest tests/test_vcall_scan.py
"""
import os
import random
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import vcall_scan as vs  # noqa: E402

HAVE_XBE = all(os.path.exists(os.path.join(ROOT, p)) for p in ("isos/extracted/default.xbe", "build/functions.csv"))


def _random_system(rng):
    """Variables with pop-like domains (0, 4, .., 4k), equalities `const + sum coef*v == 0` built around a hidden
    assignment (so most systems have a solution; some get an off-by-4 constant and have none)."""
    nv = rng.randint(1, 6)
    used = list(range(nv))
    doms = [list(range(0, 4 * rng.randint(0, 4) + 1, 4)) for _ in used]
    hidden = {v: rng.choice(doms[v]) for v in used}
    cons = []
    for _ in range(rng.randint(0, 4)):
        vs_ = rng.sample(used, rng.randint(1, nv))
        terms = {v: rng.choice((-2, -1, 1, 1, 2)) for v in vs_}
        const = -sum(c * hidden[v] for v, c in terms.items())
        if rng.random() < 0.15:
            const += 4
        cons.append((const, tuple(sorted(terms.items()))))
    if rng.random() < 0.1:
        cons.append((rng.choice((0, 4)), ()))
    return used, doms, cons


class SolverOracle(unittest.TestCase):
    def test_random_systems(self):
        rng = random.Random(126)
        n_sol = 0
        for _ in range(3000):
            used, doms, cons = _random_system(rng)
            b = vs._solve_brute(used, doms, cons)
            s = vs._solve(used, doms, cons)
            self.assertEqual(b, s, (used, doms, cons))
            n_sol += b is not None
        self.assertGreater(n_sol, 1000)         # the sample holds solvable systems, not only empty ones

    @unittest.skipUnless(HAVE_XBE, "needs isos/extracted/default.xbe and build/functions.csv")
    def test_xbe_functions(self):
        o = vs.Original()
        rng = random.Random(7)
        funcs = sorted(o.funcs)
        rng.shuffle(funcs)
        checked = 0
        for va in funcs[:4000]:
            o.last_system = None
            o.model(va)
            if not o.last_system:
                continue
            used, doms, cons = o.last_system
            n = 1
            for d in doms:
                n *= len(d)
            if n > 200000:
                continue
            self.assertEqual(vs._solve_brute(used, doms, cons), vs._solve(used, doms, cons), hex(va))
            checked += 1
        self.assertGreater(checked, 100)


if __name__ == "__main__":
    unittest.main()
