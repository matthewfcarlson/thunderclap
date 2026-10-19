// STATUS: equivalent (tools/equiv.py level 3: 2665 inputs, branch coverage 120/122, incomplete)
// FUN_001b4d00 @ 0x001b4d00
extern "C" double __cdecl sqrt(double);
extern unsigned int DAT_004dc0e0;
extern unsigned int DAT_004dc0e4;
extern unsigned int DAT_004e21ec;

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3 *other, float eps);
};

extern V3 DAT_004e21e0;

void __cdecl FUN_002f1ce0(V3 *pos, void *thing, V3 *outDir, float *outDist);
void __cdecl FUN_00083e00(V3 *out, V3 *dir, float t);
struct ThisCall_00080cd0 {
    void FUN_00080cd0(V3 *d, int z);
};

struct Ent;
struct Obj;

struct HitInfo {
    char pad00[8];
    V3 pos08;
    char pad14[0x28 - 0x14];
    V3 neg28;
    char pad34[0x64 - 0x34];
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
    float f7c;
    char pad80[0x90 - 0x80];
    char b90;
    char pad91[0x98 - 0x91];
    void FUN_00059820();
    void FUN_00059300();
};

struct Chk {
    int FUN_001d5e80(int a);
};

struct Q70 {
    char pad00[0x98];
    V3 v98;
};

struct Sel20 {
    char FUN_00024300(Ent *e);
    char FUN_000242d0(Ent *e);
};

struct Obj54 {
    void FUN_000afea0(int a, float b, float c, float d);
};
struct Obj54h {
    Obj54 *FUN_00086330();
};

struct Ctx1f4 {
    char pad00[0x20];
    Sel20 *f20;
    char pad24[0x54 - 0x24];
    Obj54h *f54;
};

struct Gear11c {
    char pad00[0x1b0];
    int f1b0;
};

struct Ent {
    char pad00[8];
    unsigned int f8;
    unsigned int fc;
    int f10;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[0x64 - 0x44];
    V3 v64;
    char pad70[0xec - 0x70];
    Chk *fec;
    char pad_f0[0xfc - 0xf0];
    int ffc;
    char pad100[0x114 - 0x100];
    int f114;
    char pad118[0x11c - 0x118];
    Gear11c *f11c;
    char pad120[0x148 - 0x120];
    int f148;
    char pad14c[0x338 - 0x14c];
    int f338;
    char pad33c[0x1cef - 0x33c];
    unsigned char b1cef;
    char char_pad;
    char FUN_001d6980();
    void FUN_001d6ec0(int a, Obj *o, int c);
    char FUN_001d7300();
    void FUN_001d86d0(V3 *a, V3 *b);
    void FUN_000437a0(int a, HitInfo *h, int b, int c, int d);
    void FUN_00043ae0(int a, void *slot, float t, int b, float c, int d, int e, int f, int g);
    void FUN_00081420(HitInfo *h);
};

struct Obj {
    char pad00[8];
    Ent *f8;
    int fc;
    char pad10[0x18 - 0x10];
    Obj *f18;
    char pad1c[4];
    void *f20;
    char pad24[0x40 - 0x24];
    V3 v40;
    char pad4c[0x70 - 0x4c];
    Q70 *f70;
};

struct Slot {
    V3 pos;
    int fc;
    char pad10[0x138 - 0x10];
    char FUN_001b3440(int a);
    void FUN_001b3420();
    char FUN_001b32b0(Obj *o);
    char FUN_001b3670(V3 *v);
    void FUN_001b32e0(Obj *o);
    float FUN_001b3620(float d);
    Obj *FUN_001b3300();
    float FUN_001b35d0(float d);
    int FUN_001b3250(float d);
};

struct Vec {
    Obj **begin;
    Obj **end;
};

struct Mgr8 {
    Vec *FUN_002ed700();
};

class Combat {
public:
    char pad00[8];
    Mgr8 *f8;
    char padc[4];
    Slot slots[4];
    void FUN_001b4d00(Ctx1f4 *ctx, int arg2);
};

void Combat::FUN_001b4d00(Ctx1f4 *ctx, int arg2)
{
    for (int sn = 0; sn < 4; sn++) {
        Slot *slot = &slots[sn];
        if (!slot->FUN_001b3440(arg2)) {
            slot->FUN_001b3420();
            continue;
        }
        Vec *vec = f8->FUN_002ed700();
        for (unsigned int i = 0; i < (unsigned int)(vec->end - vec->begin); i++) {
            Obj *elem = vec->begin[i];
            Obj *obj = elem->f18;
            if (!obj)
                continue;
            int kind = obj->fc;
            if (kind != 5 && kind != 7 && kind != 1)
                continue;
            if (kind == 1) {
                if (obj->f8->f338 != 0)
                    continue;
            }
            if (slot->FUN_001b32b0(obj))
                continue;

            V3 posA;
            posA.x = 0;
            posA.y = 0;
            posA.z = 0;
            V3 dirB;
            dirB.x = 0;
            dirB.y = 0;
            dirB.z = 0;
            V3 posC;
            posC.x = 0;
            posC.y = 0;
            posC.z = 0;
            if (obj->f70)
                posA = obj->f70->v98;
            else
                posA = obj->v40;
            if (!slot->FUN_001b3670(&posA)) {
                if (obj->fc != 7)
                    continue;
                Ent *E7 = obj->f8;
                if (!E7)
                    continue;
                if (E7->f10 != 0 && E7->f10 != 1)
                    continue;
                V3 d;
                d.x = slot->pos.x - E7->v64.x;
                d.y = slot->pos.y - E7->v64.y;
                d.z = slot->pos.z - E7->v64.z;
                if (d.x * d.x + d.z * d.z + d.y * d.y < 500.0f)
                    ((ThisCall_00080cd0*)(this))->FUN_00080cd0(&d, 0);
                continue;
            }
            slot->FUN_001b32e0(obj);
            V3 sp = slot->pos;
            float maxDist = 32768.0f;
            Obj *el2 = vec->begin[i];
            if (el2->f20) {
                FUN_002f1ce0(&sp, el2->f20, &dirB, &maxDist);
                V3 zero2;
                zero2.x = 0;
                zero2.y = 0;
                zero2.z = 0;
                if (dirB.FUN_0022d2b0(&zero2, 1e-05f)) {
                    dirB.x = 0;
                    dirB.y = 1.0f;
                    dirB.z = 0;
                }
                if (!(0.03f < maxDist))
                    maxDist = 0.03f;
                double px = dirB.x * maxDist;
                float py = dirB.y * maxDist;
                float pz = dirB.z * maxDist;
                posC.x = (float)(px + sp.x);
                posC.y = sp.y + py;
                posC.z = sp.z + pz;
            } else {
                double dx = posA.x - sp.x;
                double dy = posA.y - sp.y;
                double dz = posA.z - sp.z;
                dirB.x = (float)dx;
                dirB.y = (float)dy;
                dirB.z = (float)dz;
                maxDist = (float)sqrt(dx * dx + dz * dz + dy * dy);
                dirB.FUN_0022d110();
            }

            float distF = slot->FUN_001b3620(maxDist);
            if (obj->fc == 5) {
                if (slot->fc == 4 || slot->fc == 5)
                    continue;
                Ent *E = obj->f8;
                int m = E->ffc;
                if (m == 2 || m == 3 || m == 1)
                    continue;
                if (E->FUN_001d6980())
                    continue;
                if (E->f148 != 0)
                    continue;
                int mode = E->fec->FUN_001d5e80(E->f40);
                if (mode == 3 || mode == 2)
                    continue;
                if (distF > 0.0f)
                    E->FUN_001d6ec0((int)distF, slot->FUN_001b3300(), 0);
                if (!E->FUN_001d7300())
                    continue;
                if (E->f114 != 0)
                    continue;
                if (obj->f70 == 0)
                    continue;
                float t = slot->FUN_001b35d0(maxDist);
                if (!(t > 0.0f))
                    continue;
                V3 dd = dirB;
                if (!(DAT_004e21ec & 1)) {
                    DAT_004e21ec |= 1;
                    DAT_004e21e0.x = 0;
                    DAT_004e21e0.y = -1.5f;
                    DAT_004e21e0.z = 0;
                }
                dd.x = dd.x + DAT_004e21e0.x;
                dd.y = dd.y + DAT_004e21e0.y;
                dd.z = dd.z + DAT_004e21e0.z;
                dd.FUN_0022d110();
                V3 out;
                FUN_00083e00(&out, &dd, t);
                V3 neg;
                neg.x = out.x * -1.0f;
                neg.y = out.y * -1.0f;
                neg.z = out.z * -1.0f;
                E->FUN_001d86d0(&neg, &posA);
            } else if (obj->fc == 1) {
                Ent *E = obj->f8;
                int sfc = slot->fc;
                bool isId = (E->f8 == DAT_004dc0e0 && E->fc == DAT_004dc0e4);
                bool is45 = (sfc == 4 || sfc == 5);
                if (isId) {
                    if (!is45)
                        continue;
                    HitInfo hi;
                    hi.FUN_00059820();
                    hi.neg28.x = dirB.x * -1.0f;
                    hi.neg28.y = dirB.y * -1.0f;
                    hi.neg28.z = dirB.z * -1.0f;
                    hi.b90 = 1;
                    float t = slot->FUN_001b35d0(maxDist);
                    if (t <= 1e-05f)
                        hi.f7c = 1.0f;
                    E->FUN_000437a0(0, &hi, 0, 0, 1);
                    hi.FUN_00059300();
                } else {
                    if (is45)
                        continue;
                    if (ctx->f20->FUN_00024300(E))
                        continue;
                    float t = slot->FUN_001b35d0(maxDist);
                    if (t <= 0.0f)
                        continue;
                    Obj *r = slot->FUN_001b3300();
                    if (r && r->fc == 1 && r->f8) {
                        if (r->f8->f11c->f1b0 == E->f11c->f1b0) {
                            if (E->b1cef == 0)
                                distF = distF * 0.1f;
                            else
                                distF = 0;
                        }
                    }
                    E->FUN_00043ae0(0, slot, t, 0, distF, 0, 0, 1, 0);
                    if (!ctx->f20->FUN_000242d0(E))
                        continue;
                    int rr = slot->FUN_001b3250(maxDist);
                    if (rr == 1 || slot->FUN_001b3250(maxDist) == 0)
                        ctx->f54->FUN_00086330()->FUN_000afea0(0, 90.0f, 90.0f, 0.4f);
                }
            } else if (obj->fc == 7) {
                Ent *E = obj->f8;
                if (!E)
                    continue;
                HitInfo hi;
                hi.FUN_00059820();
                hi.neg28.x = dirB.x * -1.0f;
                hi.neg28.y = dirB.y * -1.0f;
                hi.neg28.z = dirB.z * -1.0f;
                hi.pos08 = posC;
                hi.f64 = 30.0f;
                hi.f78 = 1.0f;
                hi.b90 = 1;
                E->FUN_00081420(&hi);
                hi.FUN_00059300();
            }
        }
    }
}
