// STATUS: equivalent (tools/equiv.py level 3: 795 inputs, branch coverage 37/38, incomplete)
// FUN_00280d90 @ 0x00280d90
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Vtx {
    V3 p;
    V3 n;
};

char FUN_00280840(const V3 *center, float radius, const Vtx *a, const Vtx *b, const Vtx *c);

static __forceinline void MidNormal(Vtx *m, const Vtx *a, const Vtx *b)
{
    m->n.x = (b->n.x - a->n.x) * 0.5f + a->n.x;
    m->n.y = (b->n.y - a->n.y) * 0.5f + a->n.y;
    m->n.z = (b->n.z - a->n.z) * 0.5f + a->n.z;
}

static __forceinline void MidPos(Vtx *m, const Vtx *a, const Vtx *b)
{
    m->p.x = (b->p.x - a->p.x) * 0.5f + a->p.x;
    m->p.y = (b->p.y - a->p.y) * 0.5f + a->p.y;
    m->p.z = (b->p.z - a->p.z) * 0.5f + a->p.z;
}

static __forceinline float EdgeLen(const Vtx *a, const Vtx *b)
{
    float dx = b->p.x - a->p.x;
    float dy = b->p.y - a->p.y;
    float dz = b->p.z - a->p.z;
    return (float)sqrt(dz * dz + dy * dy + dx * dx);
}

void FUN_00280d90(Vtx *verts, int n, int limit, int *outN, V3 center, float radius, float maxEdge)
{
    int pass = 8;
    do {
        int i = 0;
        int snap = n;
        Vtx *slot = verts;
        while (i < snap) {
            if (n >= limit - 9)
                break;
            Vtx t[3];
            t[0] = slot[0];
            t[1] = slot[1];
            t[2] = slot[2];
            if (!FUN_00280840(&center, radius, &t[0], &t[1], &t[2])) {
                slot[0] = verts[n - 3];
                slot[1] = verts[n - 2];
                slot[2] = verts[n - 1];
                n -= 3;
                snap -= 3;
            } else {
                float len[3];
                unsigned idx3 = 2;
                len[0] = EdgeLen(&t[0], &t[1]);
                len[1] = EdgeLen(&t[1], &t[2]);
                len[2] = EdgeLen(&t[2], &t[0]);
                unsigned big = 0;
                unsigned mid = 1;
                if (len[1] > len[0]) {
                    big = 1;
                    mid = 0;
                }
                if (len[2] > len[mid]) {
                    idx3 = mid;
                    mid = 2;
                }
                if (len[mid] > len[big]) {
                    unsigned tmp = big;
                    big = mid;
                    mid = tmp;
                }
                Vtx m[3];
                MidPos(&m[0], &t[0], &t[1]);
                MidNormal(&m[0], &t[0], &t[1]);
                m[0].n.FUN_0022d110();
                MidPos(&m[1], &t[1], &t[2]);
                MidNormal(&m[1], &t[1], &t[2]);
                m[1].n.FUN_0022d110();
                MidPos(&m[2], &t[2], &t[0]);
                MidNormal(&m[2], &t[2], &t[0]);
                m[2].n.FUN_0022d110();

                Vtx out[12];
                int count;
                if (!(len[big] > maxEdge)) {
                    out[0] = t[0];
                    out[1] = t[1];
                    out[2] = t[2];
                    count = 3;
                } else if (!(len[mid] > maxEdge)) {
                    unsigned e1 = (big + 1) % 3;
                    unsigned e2 = (big + 2) % 3;
                    out[0] = m[big];
                    out[1] = t[e2];
                    out[2] = t[big];
                    out[3] = m[big];
                    out[4] = t[e1];
                    out[5] = t[e2];
                    count = 6;
                } else if (!(len[idx3] > maxEdge)) {
                    out[0] = m[big];
                    out[1] = m[mid];
                    out[2] = t[big];
                    out[3] = m[big];
                    out[4] = t[mid];
                    out[5] = m[mid];
                    out[6] = t[idx3];
                    out[7] = t[(idx3 + 1) % 3];
                    out[8] = m[(idx3 + 2) % 3];
                    count = 9;
                } else {
                    out[0] = m[0];
                    out[1] = m[1];
                    out[2] = m[2];
                    out[3] = t[0];
                    out[4] = m[0];
                    out[5] = m[2];
                    out[6] = t[1];
                    out[7] = m[1];
                    out[8] = m[0];
                    out[9] = t[2];
                    out[10] = m[2];
                    out[11] = m[1];
                    count = 12;
                }

                int k = 0;
                if (count > 0) {
                    do {
                        if (!FUN_00280840(&center, radius, &out[k], &out[k + 1], &out[k + 2])) {
                            out[k] = out[count - 3];
                            out[k + 1] = out[count - 2];
                            out[k + 2] = out[count - 1];
                            count -= 3;
                            k -= 3;
                        }
                        k += 3;
                    } while (k < count);
                }

                if (count >= 3) {
                    slot[0] = out[0];
                    slot[1] = out[1];
                    slot[2] = out[2];
                }
                for (int j = 3; j < count; j++)
                    verts[n++] = out[j];
            }
            i += 3;
            slot += 3;
        }
        pass--;
    } while (pass != 0);
    *outN = n;
}
