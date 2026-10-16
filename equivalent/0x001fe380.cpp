// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 39/46, incomplete)
// FUN_001fe380 @ 0x001fe380
struct V3 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
};

extern "C" void __cdecl FUN_001fd640(V3 *o, V3 *p, V3 *q, V3 *res);
extern int DAT_00425260[4];

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual V3 *v8(V3 *tmp);
    char pad[0x40 - 4];
};

struct List {
    int count;
    char *base;
};

struct Lists {
    List l[20];
};

struct Frame {
    int s0;
    V3 res;
    int n;
    int cnt;
    int idx;
    float best;
    union {
        V3 q;
        struct {
            int pad[2];
            V3 tmp;
        } tt;
    };
    int pad52;
    V3 p;
    V3 dd;
    V3 pts[160];
};

static float DistSq(const V3 &a, const V3 &b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return dz * dz + dy * dy + dx * dx;
}

class Finder {
public:
    char pad0[0x214];
    Lists *lists[64];
    char FUN_001fe380(V3 *o, V3 *out);
};

char Finder::FUN_001fe380(V3 *o, V3 *out)
{
    Frame f;
    f.n = 0;
    for (int *tp = DAT_00425260; tp < DAT_00425260 + 4; tp++) {
        int cls = *tp;
        for (int k = 0; k < 20; k++) {
            int count = lists[cls]->l[k].count;
            for (int i = 0; i < count; i++) {
                Obj *e = (Obj *)(lists[cls]->l[k].base + i * 0x40);
                if (e) {
                    if (f.n >= 160)
                        break;
                    V3 *r = e->v8(&f.tt.tmp);
                    f.pts[f.n].ix = r->ix;
                    f.pts[f.n].iy = r->iy;
                    f.pts[f.n].iz = r->iz;
                    f.n++;
                }
            }
        }
    }

    bool found = false;
    int n = f.n;
    if (n > 1) {
        float best = 3.4028235e38f;
        for (int i = 1; i < n; i++) {
            f.p.ix = f.pts[i - 1].ix;
            f.p.iy = f.pts[i - 1].iy;
            f.p.iz = f.pts[i - 1].iz;
            for (int j = i; j < n; j++) {
                f.q.ix = f.pts[j].ix;
                f.q.iy = f.pts[j].iy;
                f.q.iz = f.pts[j].iz;
                f.dd.ix = f.p.ix;
                f.dd.iy = f.p.iy;
                f.dd.iz = f.p.iz;
                if (!(DistSq(f.p, f.q) > 22500.0f)) {
                    f.res.x = 0.0f;
                    f.res.y = 0.0f;
                    f.res.z = 0.0f;
                    FUN_001fd640(o, &f.p, &f.q, &f.res);
                    int rx = f.res.ix, ry = f.res.iy, rz = f.res.iz;
                    V3 r;
                    r.ix = rx;
                    r.iy = ry;
                    r.iz = rz;
                    float d = DistSq(r, *o);
                    if (d < best) {
                        best = d;
                        found = true;
                        out->ix = rx;
                        out->iy = ry;
                        out->iz = rz;
                    }
                }
            }
        }
        if (found)
            return found;
    }

    float best = 3.4028235e38f;
    for (int i = 0; i < n; i++) {
        float d = DistSq(f.pts[i], *o);
        if (d < best) {
            best = d;
            out->ix = f.pts[i].ix;
            out->iy = f.pts[i].iy;
            out->iz = f.pts[i].iz;
            found = true;
        }
    }
    return found;
}
