"""eaxcand.py EAX.TSV: from eaxscan.py's findings, the void blocks that leave a value in eax (eaxscan.cands) and the
callers that read it, one row per block (HULK_PORT_ABI candidates; the runtime list comes from wasm_port.py's
HULK_WASM_DEBUG_VOIDRET packer)."""
import sys, os, collections
sys.path.insert(0, os.path.dirname(__file__))
import eaxscan
c, B = eaxscan.cands()
rows = [l.rstrip("\n").split("\t") for l in open(sys.argv[1])]
hit = collections.defaultdict(list)
for r in rows:
    if "or eax, 0xffffffff" in r[6]:
        continue
    if r[0] == "direct":
        hit[int(r[1], 16)].append(r[4] + " " + r[6])
    else:
        for t in r[3].split():
            if int(t, 16) in c:
                hit[int(t, 16)].append(r[4] + " " + r[1] + " " + r[6])
print("void blocks leaving eax: %d; with a reading caller: %d" % (len(c), len(hit)), file=sys.stderr)
for a in sorted(hit):
    print("%s\t%s\t%s\t%s\t%d sites\t%s" % (hex(a), B[a][2], B[a][1], ",".join(c.get(a, ["-"])), len(hit[a]), "; ".join(hit[a][:3])))
