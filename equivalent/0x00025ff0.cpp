// STATUS: equivalent (tools/equiv.py level 3: 230 inputs, branch coverage 123/146, incomplete)
// FUN_00025ff0 @ 0x00025ff0
extern "C" double __cdecl sqrt(double);

struct V3_25ff0 {
    float x, y, z;
    float FUN_000111f0();
};
struct V4_25ff0 { float x, y, z, w; };

struct Mat_25ff0 {
    float m[16];
    void FUN_0022c2b0(const V4_25ff0 *in, V3_25ff0 *out);
};

struct Query_25ff0 {
    float f[5];
};

struct Pos10_25ff0 {
    void FUN_00059a50(V3_25ff0 *out);
};

struct Sink_25ff0 {
    char FUN_001c4010(Query_25ff0 *q);
    V3_25ff0 *FUN_001c39d0();
    Mat_25ff0 *FUN_001c3990();
};
Sink_25ff0 *FUN_001c3d90();

class Selector_25ff0;
struct Gadget11c {
    char pad00[0x10];
    char b10;
};
struct Gadget1ca0 {
    char pad00[0xe8];
    char be8;
};

struct Entity;

struct Entity {
    char pad00[0x10];
    Pos10_25ff0 *f10;
    char pad14[0x11c - 0x14];
    Gadget11c *f11c;
    char pad120[0x12c - 0x120];
    int f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Entity *f334;
    Entity *f338;
    char pad33c[0x1ca0 - 0x33c];
    Gadget1ca0 *f1ca0;
    char pad1ca4[0x1d04 - 0x1ca4];
    char b1d04;
    char pad1d05[0x1f50 - 0x1d05];
    char b1f50;
    char pad1f51[0x20b0 - 0x1f51];
    int f20b0;
    void FUN_000359e0(Query_25ff0 *q);
};

struct EntityTable {
    char pad00[0x44];
    struct Lookup_25ff0 *f44;
};
struct Lookup_25ff0 {
    Entity *FUN_00059c10(int id);
};

struct Frame_25ff0 {
    int k;                  // 0x00
    int i;                  // 0x04
    int q;                  // 0x08
    int m;                  // 0x0c
    float s;                // 0x10
    V3_25ff0 d;                   // 0x14
    union {
        V4_25ff0 vt;              // 0x20
        Query_25ff0 qe;           // 0x20..0x33
    };
    float pY, pZ;           // 0x34, 0x38 (P.x is qe.f[4])
    int u;                  // 0x3c
    Selector_25ff0 *savedThis;    // 0x40
    V3_25ff0 zeroV;               // 0x44
    int t50, t54, t58;      // 0x50
    Sink_25ff0 *sink;             // 0x5c
    float S1[16];           // 0x60
    Query_25ff0 q0;               // 0xa0..0xb3, q0.f[4] is the first word of mat / L2
    char matRest[0xf0 - 0xb4];
    int L1[12];             // 0xf0
    char tail[0x130 - 0x120];
};

class Selector_25ff0 {
public:
    EntityTable *tbl;
    char pad04[8];
    int count;
    int ids[16];
    char enabled;
    char pad51[3];
    int flags[16];
    float score[16];
    int lim1;
    int lim2;
    int lim3;
    char pade0[0x124 - 0xe0];
    Entity *me;

    char FUN_00024300(Entity *e);
    void Update(float unusedA, float dt);
};

void Selector_25ff0::Update(float unusedA, float dt)
{
    if (!enabled) {
        for (int i = 0; i < count; i++) {
            flags[i] = 3;
            score[i] = dt + score[i];
        }
        return;
    }

    Frame_25ff0 f;
    Mat_25ff0 *mat = (Mat_25ff0 *)&f.q0.f[4];
    int *L2 = (int *)&f.q0.f[4];
    f.savedThis = this;
    f.zeroV.x = 0;
    f.zeroV.y = 0;
    f.zeroV.z = 0;
    f.sink = FUN_001c3d90();
    float r;
    if (me != 0) {
        me->FUN_000359e0(&f.q0);
        f.q0.f[3] = f.q0.f[3] * 0.5f;
        if (f.sink->FUN_001c4010(&f.q0)) {
            V3_25ff0 pos;
            pos.x = 0;
            pos.y = 0;
            pos.z = 0;
            me->f10->FUN_00059a50(&pos);
            V3_25ff0 *c = f.sink->FUN_001c39d0();
            f.d.x = pos.x - c->x;
            f.d.y = pos.y - c->y;
            f.d.z = pos.z - c->z;
            *mat = *f.sink->FUN_001c3990();
            r = (float)(sqrt((double)(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x)) * 0.5f);
        } else {
            *mat = *f.sink->FUN_001c3990();
            r = 10.0f;
        }
    } else {
        *mat = *f.sink->FUN_001c3990();
        r = 10.0f;
    }
    f.vt.x = 0;
    f.vt.y = 0;
    f.vt.z = r;
    f.vt.w = 0;
    mat->FUN_0022c2b0(&f.vt, &f.zeroV);

    f.k = 0;
    f.m = 0;
    f.u = 0;
    for (f.i = 0; f.i < count; f.i++) {
        Entity *es = tbl->f44->FUN_00059c10(ids[f.i]);
        float sc = dt + score[f.i];
        bool had4 = (flags[f.i] & 4) != 0;
        score[f.i] = sc;
        if (had4) {
            flags[f.i] = 3;
            continue;
        }
        flags[f.i] = 0;
        if (es == me) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        Gadget11c *g = es->f11c;
        if (es->b1f50) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (es->f1ca0 && es->f1ca0->be8) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (es->b1d04) {
            f.k++;
            flags[f.i] = 3;
            continue;
        }
        if (me) {
            if (es->f12c == me->f328 || es == me->f334 || es == me->f338) {
                f.k++;
                flags[f.i] = 3;
                continue;
            }
        }
        f.qe.f[3] = 1.0f;
        es->FUN_000359e0(&f.qe);
        f.qe.f[3] = f.qe.f[3] * 0.75f;
        if (!f.sink->FUN_001c4010(&f.qe)) {
            f.s = score[f.i];
            int pos = 0;
            while (pos < f.u && !(f.s > score[L2[pos]]))
                pos++;
            for (int e = f.u; e > pos; e--)
                L2[e] = L2[e - 1];
            L2[pos] = f.i;
            f.u++;
            continue;
        }
        flags[f.i] |= 2;
        if (g && g->b10) {
            flags[f.i] |= 1;
            f.k++;
            continue;
        }
        if (FUN_00024300(es)) {
            flags[f.i] |= 1;
            continue;
        }
        if (es->f20b0 != 0) {
            f.L1[f.m] = f.i;
            f.S1[f.m] = 3.4028235e+38f;
            f.m++;
            continue;
        }
        V3_25ff0 *P = (V3_25ff0 *)&f.qe.f[4];
        P->x = 0;
        P->y = 0;
        P->z = 0;
        es->f10->FUN_00059a50(P);
        f.d.x = P->x - f.zeroV.x;
        f.d.y = P->y - f.zeroV.y;
        f.d.z = P->z - f.zeroV.z;
        float x = f.d.FUN_000111f0();
        if (f.qe.f[3] > 0.0f)
            x = x / (f.qe.f[3] * f.qe.f[3]);
        int pos = 0;
        while (pos < f.m && !(x < f.S1[pos]))
            pos++;
        for (int e = f.m; e > pos; e--) {
            f.L1[e] = f.L1[e - 1];
            f.S1[e] = f.S1[e - 1];
        }
        f.S1[pos] = x;
        f.L1[pos] = f.i;
        f.m++;
    }

    int n1 = lim1 - f.k;
    if (n1 > 0) {
        if (n1 > f.m)
            n1 = f.m;
        for (int j = 0; j < n1; j++)
            flags[f.L1[j]] |= 1;
    } else {
        n1 = 0;
    }
    if (f.m - n1 > 0) {
        int q2 = lim2;
        if (q2 <= 0) {
            int rem = f.m - n1;
            q2 = rem % 2 + rem / 2;
        }
        int *L3 = (int *)f.S1;
        int cnt = 0;
        for (int j = n1; j < f.m; j++) {
            int id = f.L1[j];
            float s = score[id];
            int pos = 0;
            while (pos < cnt && !(s > score[L3[pos]]))
                pos++;
            for (int e = cnt; e > pos; e--)
                L3[e] = L3[e - 1];
            L3[pos] = id;
            cnt++;
        }
        if (q2 > cnt)
            q2 = cnt;
        for (int j = 0; j < q2; j++)
            flags[L3[j]] |= 1;
    }

    int n3 = lim3;
    if (n3 < 1)
        n3 = 1;
    if (n3 > f.u)
        n3 = f.u;
    for (int j = 0; j < n3; j++)
        flags[L2[j]] |= 1;
}
