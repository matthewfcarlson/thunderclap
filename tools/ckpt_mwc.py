#!/usr/bin/env python3
"""Draw distance between two states of the particle generators (ckpt2; docs/checkpoints.md "The particle tag").

  build/venv/bin/python tools/ckpt_mwc.py Z1 W1 Z2 W2 [--max N]

The particle tag's moving words (probe v3 field dump: particle[6..7] the plane / sphere generator at 0x554bfc,
particle[8..9] the sprite emitter at 0x554c04) are Marsaglia multiply-with-carry generators stepped by 0x143100:
z = (z & 0xffff) * 0x9069 + (z >> 16), w = (w & 0xffff) * 0x4650 + (w >> 16). Prints the number of draws from the
first state to the second (or from the second to the first), or that neither is reached within N draws: two runs on
the same stream are a few draws apart, unrelated states are not reached at all. Diagnosis only: it never changes a
verdict (a differing particle hash stays a difference).
"""
import argparse
import sys


def step(z, w):
    return ((z & 0xffff) * 0x9069 + (z >> 16)) & 0xffffffff, ((w & 0xffff) * 0x4650 + (w >> 16)) & 0xffffffff


def distance(a, b, limit):
    """k >= 0 with step^k(a) == b, or None"""
    z, w = a
    for k in range(limit):
        if (z, w) == b:
            return k
        z, w = step(z, w)
    return None


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for n in ("z1", "w1", "z2", "w2"):
        ap.add_argument(n, type=lambda x: int(x, 16))
    ap.add_argument("--max", type=int, default=5_000_000)
    a = ap.parse_args(argv)
    f = distance((a.z1, a.w1), (a.z2, a.w2), a.max)
    if f is not None:
        print("second = first + %d draws" % f)
        return 0
    r = distance((a.z2, a.w2), (a.z1, a.w1), a.max)
    if r is not None:
        print("first = second + %d draws" % r)
        return 0
    print("not on one stream within %d draws" % a.max)
    return 1


if __name__ == "__main__":
    sys.exit(main())
