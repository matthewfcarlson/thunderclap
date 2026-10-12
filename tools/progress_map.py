#!/usr/bin/env python3
"""Map of game code by verification status: one box per function, area proportional to its bytes,
laid out in address order (left to right, top to bottom), so neighbouring boxes are neighbouring code.

Writes docs/progress-map.svg (light and dark via prefers-color-scheme), used by the README. The layout is
an ordered strip treemap (Bederson et al.): rows fill left to right, each row takes items in address order
for as long as that improves the row's average aspect ratio, so boxes stay close to square.

Usage: tools/progress_map.py [OUT.svg]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from packet import Db  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
W, H = 1200, 640          # plot area
COLS = 16                 # equal-byte address columns
PAD_TOP, PAD_BOTTOM = 80, 24


def strip(values, x, y, w, h):
    """Ordered strip treemap: rows across the full width, in input order; values sum to w*h."""
    out, i, n = [], 0, len(values)
    def avg(row):
        s = sum(row)
        rh = s / w
        return sum(max(rh / (v / rh), (v / rh) / rh) for v in row) / len(row)
    while i < n:
        row = [values[i]]
        i += 1
        while i < n and avg(row + [values[i]]) <= avg(row):
            row.append(values[i])
            i += 1
        rh = sum(row) / w
        cx = x
        for v in row:
            out.append((cx, y, v / rh, rh))
            cx += v / rh
        y += rh
    return out


def main():
    out = sys.argv[1] if len(sys.argv) > 1 and sys.argv[1].endswith(".svg") else os.path.join(ROOT, "docs/progress-map.svg")
    db = Db()
    has = lambda d, a: os.path.exists(os.path.join(ROOT, d, "0x%08x.cpp" % a))
    groups = {"matched": [], "equivalent": [], "unverified": []}
    funcs = []
    for r in db.funcs.values():
        if not db.is_game(r):
            continue
        a, n = int(r["address"], 16), int(r["size"])
        k = "matched" if has("matches", a) else "equivalent" if has("equivalent", a) else "unverified"
        groups[k].append(n)
        funcs.append((a, n, k))
    funcs.sort()
    total = sum(n for _, n, _ in funcs)
    order = ["matched", "equivalent", "unverified"]
    # Equal-byte columns read top to bottom, left to right; within a column, an ordered strip layout.
    scale = W * H / total
    rects, ticks, i, x0 = [], [], 0, 0.0
    for c in range(COLS):
        want = total * (c + 1) / COLS
        j, acc = i, sum(n for _, n, _ in funcs[:i])
        while j < len(funcs) and (acc + funcs[j][1] <= want or j == i or c == COLS - 1):
            acc += funcs[j][1]
            j += 1
        col = funcs[i:j]
        if not col:
            continue
        vals = [n * scale for _, n, _ in col]
        colw = sum(vals) / H      # whole functions per column, so widths differ slightly; heights don't
        for (a, n, k), (x, y, w, h) in zip(col, strip(vals, x0, PAD_TOP, colw, H)):
            rects.append('<rect class="%s" x="%.1f" y="%.1f" width="%.1f" height="%.1f"/>' % (k[0], x, y, w, h))
        ticks.append('<text class="t3" x="%.1f" y="%d">0x%x</text>' % (x0 + 1, PAD_TOP - 4, col[0][0]))
        x0 += colw
        i = j
    pct = {k: 100 * sum(groups[k]) / total for k in order}
    count = {k: len(groups[k]) for k in order}
    legend = []
    for i, (k, label) in enumerate((("matched", "Byte-matched"), ("equivalent", "Proven equivalent"),
                                    ("unverified", "Not yet verified"))):
        lx = i * W // 3
        legend.append('<rect class="%s" x="%d" y="34" width="12" height="12" rx="2"/>' % (k[0], lx))
        text = "%s: %.1f%% of bytes, %s functions" % (label, pct[k], format(count[k], ","))
        legend.append('<text class="t2" x="%d" y="45">%s</text>' % (lx + 18, text))
    svg = f'''<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {W} {PAD_TOP + H + PAD_BOTTOM}" width="{W}" height="{PAD_TOP + H + PAD_BOTTOM}" role="img" aria-label="Treemap of game code: {pct['matched']:.1f}% of bytes byte-matched, {pct['equivalent']:.1f}% proven equivalent, {pct['unverified']:.1f}% not yet verified">
<style>
svg {{ --bg:#fcfcfb; --ink:#0b0b0b; --ink2:#52514e; --m:#2a78d6; --e:#eb6834; --u:#e4e3df; --gap:#fcfcfb; }}
@media (prefers-color-scheme: dark) {{ svg {{ --bg:#1a1a19; --ink:#f0efec; --ink2:#c3c2b7; --m:#3987e5; --e:#d95926; --u:#3a3a37; --gap:#1a1a19; }} }}
.bg {{ fill: var(--bg); }}
.m {{ fill: var(--m); }} .e {{ fill: var(--e); }} .u {{ fill: var(--u); }}
g.boxes rect {{ stroke: var(--gap); stroke-width: 0.5; }}
.t1 {{ fill: var(--ink); font: 600 16px -apple-system, "Segoe UI", Helvetica, Arial, sans-serif; }}
.t2 {{ fill: var(--ink2); font: 13px -apple-system, "Segoe UI", Helvetica, Arial, sans-serif; }}
.t3 {{ fill: var(--ink2); font: 10px ui-monospace, Menlo, Consolas, monospace; }}
</style>
<rect class="bg" x="0" y="0" width="{W}" height="{PAD_TOP + H + PAD_BOTTOM}"/>
<text class="t1" x="0" y="20">Game code by address, one box per function (area = bytes): {pct['matched'] + pct['equivalent']:.1f}% verified</text>
{chr(10).join(legend)}
{chr(10).join(ticks)}
<g class="boxes">
{chr(10).join(rects)}
</g>
</svg>
'''
    open(out, "w").write(svg)
    print("%s: %d functions, %.1f KB" % (out, sum(count.values()), len(svg) / 1e3))


if __name__ == "__main__":
    main()
