// STATUS: equivalent (tools/equiv.py level 3: 3079 inputs, branch coverage 92/98, incomplete)
// COccupationAgent::vfunc_4 @ 0x00103c30
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" double sqrt(double);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

struct Vec3_103c30 {
    float x, y, z;
};

struct Key_103c30 {
    unsigned int lo, hi;
};

struct ScriptArgs {
    int tag;
    char text[10][0x40];
    int ints[10];
    char kinds[10];
    char pad2b6[2];
    void FUN_001d1630();
};

struct Script_103c30 {
    int FUN_001d3b00(const char* name, ScriptArgs args);
};
extern Script_103c30* __cdecl FUN_001d4c90();
extern unsigned __int64 __cdecl FUN_0027afb0(const char* s);


extern float __cdecl FUN_000964e0();
extern float __cdecl FUN_00083d90(float* v);
extern Vec3_103c30* __cdecl FUN_00083e00(Vec3_103c30* out, Vec3_103c30* in, float s);
extern float __cdecl FUN_00224f10(Vec3_103c30* v);
extern float __cdecl FUN_00224fc0(float a, float b);
extern void __cdecl FUN_00224d70(float angle, Vec3_103c30* out);

struct Vec3Ops_103c30 : Vec3_103c30 {
    float FUN_00018990();
    float FUN_0022d110();
    char FUN_0022d2b0(Vec3_103c30* other, float eps);
};

struct AnimReq {
    int size;
    int kind;
    int f08;
    int f0c;
    int f10;
    char name[0x40];
    int f54;
    int f58;
    int f5c;
    int f60;
    AnimReq* FUN_001ca110(int a, const char* nm, int b, int c, int d);
    AnimReq* FUN_001ca2e0(const char* nm, int a, int b, char c);
};

struct Locator {
    int first;
    char pad04[0x14];
    void* f18;
    int FUN_00059a50(Vec3_103c30* out);
};

struct NodeList_103c30 {
    char pad00[0x10];
    char* nodes;
    int count;
    Vec3_103c30* FUN_00106160(int idx);
};

struct Mode_103c30 {
    char pad00[0x14];
    int f14;
    unsigned __int64 FUN_000443c0();
};

struct Body_103c30 {
    char pad00[0x10];
    Locator* locator;
    char pad14[0x11c - 0x14];
    Mode_103c30* mode;
    char pad120[0x1ac4 - 0x120];
    Vec3_103c30 v1ac4;
    char pad1ad0[0x1d68 - 0x1ad0];
    unsigned __int64 f1d68;
    char pad1d70[0x1f70 - 0x1d70];
    int f1f70;
    char pad1f74[0x2064 - 0x1f74];
    Vec3_103c30 v2064;
    float f2070;
    Vec3_103c30 v2074;
    char pad2080[0x208c - 0x2080];
    Vec3Ops_103c30 v208c;
    char pad2098[0x22b0 - 0x2098];
    char f22b0;
    char* FUN_00036d00();
};

struct Obj60_103c30 {
    char pad00[0x40];
    Vec3_103c30 pos;
};

struct Part_103c30 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual Body_103c30* vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual int vfunc_9();
    char pad04[0x60 - 4];
    Obj60_103c30* f60;
    char pad64[0xe8 - 0x64];
    char flagE8;
    char flagE9;
};

struct Ident {
    int FUN_000897e0();
};
struct Obj54_103c30 {
    Ident* FUN_00086310();
};
struct Ctx_103c30 {
    char pad00[0x30];
    ScriptArgs* f30;
    char pad34[0x54 - 0x34];
    Obj54_103c30* f54;
};
struct Sink_103c30 {
    int FUN_001cbc20(AnimReq* r);
};
struct Ctx2_103c30 {
    char pad00[0x30];
    Sink_103c30* f30;
    char pad34[0x54 - 0x34];
    Obj54_103c30* f54;
};

class COccupationAgent;
class AgentSub_103c30 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(Ctx2_103c30* c, float dt, int a3);
    char pad04[0x89 - 4];
    char b89;
    void FUN_001048d0(COccupationAgent* owner);
    char FUN_00104920();
    void FUN_00104c60(Ctx2_103c30* c, Vec3_103c30* locPos, Vec3_103c30* nodePos, float f, unsigned char b, float g, int z);
};

class COccupationAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(Ctx2_103c30* c, float dt, int a3);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad04[4];
    float limit;
    char pad0c[0x58 - 0xc];
    Part_103c30* part;
    AgentSub_103c30* sub;
    NodeList_103c30* list;
    char name[0x40];
    char fa4;
    char fa5;
    char pada6[0xa8 - 0xa6];
    int fa8;
    int fac;
    int fb0;
    int iB4;
    int iB8;
    float fBC;
    unsigned char bC0;
    char padC1[3];
    float fC4;
    char bC8;
    char padC9[3];
    float fCC;
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    Vec3_103c30 vE0;
    float fEC;
    void FUN_000fc550(Ctx2_103c30* c, float dt, int a3);
    void FUN_00103a50();
    char FUN_001034e0();
};

void COccupationAgent::vfunc_4(Ctx2_103c30* a1, float a2, int a3)
{
    FUN_000fc550(a1, a2, a3);
    do {
        if (list == 0 && !fa5) {
            limit = 0.0f;
            break;
        }
        Body_103c30* b = part->vfunc_6();
        if (part != 0 && part->vfunc_9() == 4)
            break;
        sub->FUN_001048d0(this);
        if (b->mode->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc060)) {
            float t = fC4 - 10.0f;
            if (t < 0.0f)
                t = -t;
            if (t <= 1e-05f)
                fC4 = 1.0f;
        }
        Vec3_103c30 v;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        b->locator->FUN_00059a50(&v);
        if (iB8 == -1) {
            Part_103c30* p = part;
            if (p->flagE9) {
                p->flagE8 = 0;
                b->f22b0 = 0;
            }
            break;
        }
        b->f22b0 = sub->FUN_00104920();
        if (!sub->FUN_00104920() && !fa5) {
            FUN_00103a50();
            Vec3_103c30 tmp = *list->FUN_00106160(iB8);
            sub->FUN_00104c60(a1, &v, &tmp, fBC, bC0, fC4, 0);
            if (!sub->FUN_00104920()) {
                fD4 = 0.0f;
                fD0 = 0.0f;
                fCC = 0.0f;
                fDC = 0.0f;
                fEC = 0.0f;
                fD8 = 0.0f;
                break;
            }
        }
        if (b->mode != 0 && b->mode->f14 != 0 && !part->flagE8)
            break;
        sub->vfunc_4(a1, a2, a3);
        if (sub->b89 == 1) {
            char oldA4 = fa4;
            iB4 = iB8;
            fa4 = 0;
            fD4 = 0.0f;
            fD0 = 0.0f;
            fCC = 0.0f;
            fD8 = 0.0f;
            fDC = 0.0f;
            fEC = 0.0f;
            if (a2 > 0.0f) {
                Sink_103c30* snk = a1->f30;
                if (snk != 0) {
                    AnimReq req;
                    int locId = *(int*)part->vfunc_6()->locator;
                    if (!fa5) {
                        req.FUN_001ca2e0(name, locId, iB4, oldA4);
                    } else {
                        req.FUN_001ca110(locId, name, fa8, fac, fb0);
                    }
                    snk->FUN_001cbc20(&req);
                }
                Script_103c30* dbg = FUN_001d4c90();
                if (dbg != 0) {
                    char buf1[0x100];
                    strncpy(buf1, name, 0x100);
                    buf1[0xff] = 0;
                    ScriptArgs args;
                    args.FUN_001d1630();
                    args.tag = 1;
                    strncpy(args.text[0], part->vfunc_6()->FUN_00036d00(), 0x40);
                    args.text[0][0x3f] = 0;
                    int r = dbg->FUN_001d3b00(buf1, args);
                    if (!fa5) {
                        if (list == 0)
                            break;
                        if (r == 0) {
                            if (!a1->f54->FUN_00086310()->FUN_000897e0()) {
                                if (!FUN_001034e0())
                                    break;
                            }
                        } else {
                            unsigned __int64 id = b->f1d68;
                            if (id == FUN_0027afb0("CSM"))
                                b->f1f70 = 1;
                        }
                    }
                }
            }
            if (!fa5 && iB4 != iB8 && iB8 != -1) {
                Vec3_103c30 tmp = *list->FUN_00106160(iB8);
                sub->FUN_00104c60(a1, &v, &tmp, fBC, bC0, fC4, 0);
                sub->vfunc_4(a1, a2, a3);
            }
        }
        if (bC8 == 1) {
            Obj60_103c30* o = part->f60;
            if (o != 0) {
                Vec3_103c30 w = o->pos;
                Vec3_103c30 u;
                u.x = 0.0f;
                u.y = 0.0f;
                u.z = 0.0f;
                part->vfunc_6()->locator->FUN_00059a50(&u);
                w.x = w.x - u.x;
                w.y = w.y - u.y;
                w.z = w.z - u.z;
                if (sqrt(w.z * w.z + w.y * w.y + w.x * w.x) > 0.1f) {
                    ((Vec3Ops_103c30*)&w)->FUN_0022d110();
                    Vec3_103c30* dst = &part->vfunc_6()->v2074;
                    dst->x = w.x;
                    dst->y = w.y;
                    dst->z = w.z;
                }
            }
        } else {
            if (!(DAT_004e0aa8 & 1)) {
                DAT_004e0aa8 |= 1;
                (*(Vec3_103c30*)&DAT_004e0a9c).x = 0.0f;
                (*(Vec3_103c30*)&DAT_004e0a9c).y = 0.0f;
                (*(Vec3_103c30*)&DAT_004e0a9c).z = 0.0f;
            }
            if (DAT_004a1c44 && list != 0 && iB8 < list->count - 1 && iB8 >= 0 &&
                b->v208c.FUN_0022d2b0(((Vec3_103c30*)&DAT_004e0a9c), 1e-05f)) {
                Vec3_103c30 u2;
                u2.x = 0.0f;
                u2.y = 0.0f;
                u2.z = 0.0f;
                b->locator->FUN_00059a50(&u2);
                float r = (*(float*)&DAT_004a1c40);
                Vec3_103c30 cur;
                cur.x = u2.x;
                cur.z = u2.z;
                cur.y = 0.0f;
                Vec3_103c30* p = list->FUN_00106160(iB8);
                int idx = iB8;
                Vec3_103c30 nxt;
                Vec3_103c30 R;
                R.x = p->x;
                R.z = p->z;
                R.y = 0.0f;
                nxt.x = R.x;
                nxt.y = R.y;
                nxt.z = p->z;
                Vec3Ops_103c30 out;
                bool exact = false;
                Vec3Ops_103c30 d;
                if (r > 0.0f) {
                    for (;;) {
                        d.x = nxt.x - cur.x;
                        d.y = nxt.y - cur.y;
                        d.z = nxt.z - cur.z;
                        float seg = d.FUN_00018990();
                        r = r - seg;
                        if (!(r > 0.0f)) {
                            d.x = nxt.x - cur.x;
                            d.y = nxt.y - cur.y;
                            d.z = nxt.z - cur.z;
                            d.FUN_0022d110();
                            Vec3_103c30* sc = FUN_00083e00(&nxt, &d, seg + r);
                            R.x = cur.x + sc->x;
                            out.x = R.x - u2.x;
                            out.y = 0.0f;
                            out.z = (cur.z + sc->z) - u2.z;
                            exact = true;
                            break;
                        }
                        if (!(idx < list->count - 1))
                            break;
                        cur = nxt;
                        idx++;
                        nxt = *list->FUN_00106160(idx);
                    }
                }
                if (!exact) {
                    out.x = R.x - u2.x;
                    out.y = 0.0f;
                    out.z = R.z - u2.z;
                }
                out.FUN_0022d110();
                b->v2074.x = out.x;
                b->v2074.y = out.y;
                b->v2074.z = out.z;
            }
        }
        if (b->mode->f14 != 5)
            break;
        if (fEC > 0.0f) {
            b->v2064.x = vE0.x;
            b->v2064.y = vE0.y;
            b->v2064.z = vE0.z;
            b->v2064.x = b->v2064.x * -1.0f;
            b->v2064.y = b->v2064.y * -1.0f;
            b->v2064.z = b->v2064.z * -1.0f;
            b->v2074.x = b->v2064.x;
            b->v2074.y = b->v2064.y;
            b->v2074.z = b->v2064.z;
            b->f2070 = 1.0f;
            fEC = fEC - a2;
        }
        if (fDC > 0.0f) {
            b->v2064.x = vE0.x;
            b->v2064.y = vE0.y;
            b->v2064.z = vE0.z;
            b->v2074.x = vE0.x;
            b->v2074.y = vE0.y;
            b->v2074.z = vE0.z;
            b->v2074.x = b->v2074.x * -1.0f;
            b->v2074.y = b->v2074.y * -1.0f;
            b->v2074.z = b->v2074.z * -1.0f;
            b->f2070 = 1.0f;
            fDC = fDC - a2;
            if (fDC < 0.0f)
                fEC = FUN_000964e0() * 1.5f;
        } else {
            Vec3_103c30 u3;
            u3.x = 0.0f;
            u3.y = 0.0f;
            u3.z = 0.0f;
            b->locator->FUN_00059a50(&u3);
            if (sqrt((u3.z - fD4) * (u3.z - fD4) + (u3.y - fD0) * (u3.y - fD0) + (u3.x - fCC) * (u3.x - fCC)) < 1.0f) {
                fD8 = a2 + fD8;
                if (fD8 > 1.0f) {
                    Vec3Ops_103c30 t3;
                    t3.x = b->v1ac4.x;
                    t3.y = b->v1ac4.y;
                    t3.z = b->v1ac4.z;
                    Vec3_103c30 z3;
                    z3.x = 0.0f;
                    z3.y = 0.0f;
                    z3.z = 0.0f;
                    if (!t3.FUN_0022d2b0(&z3, 1e-05f)) {
                        fD4 = 0.0f;
                        fD0 = 0.0f;
                        fCC = 0.0f;
                        fD8 = 0.0f;
                        fDC = FUN_000964e0() + 0.5f;
                        float A = FUN_00224f10(&t3);
                        float B = FUN_00224f10(&b->v2064);
                        float C = FUN_00224fc0(B, A);
                        vE0.x = (*(float*)&DAT_004a1c58);
                        vE0.y = (*(float*)&DAT_004a1c5c);
                        vE0.z = (*(float*)&DAT_004a1c60);
                        FUN_00224d70(A - FUN_00083d90(&C) * 1.57079637f, &vE0);
                    }
                }
            } else {
                fCC = u3.x;
                fD0 = u3.y;
                fD4 = u3.z;
                fD8 = 0.0f;
            }
        }
    } while (0);
}
