// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00102a50..0x00103340 (kind game, layer game, confidence high), dominant class CMoveAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff1bac5e {
#define TREE_TU_END }
namespace fn_ff1bac5e {} using namespace fn_ff1bac5e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff1bac5e {
class Origin_102a50 {
  public:
    void Get(float*);
};
class Vec_102a50 {
  public:
    float x, y, z;
    float Normalize();
};
class Owner_102a50 {
  public:
    char pad[0x10];
    Origin_102a50* origin;
    float Scale();
};
class Helper_102b60 {
  public:
    float f(hulk_intptr, int);
};
extern volatile const float gZero_102b60;
struct Triple_102b90 {
    int a, b, c;
};
class Target_102b90 {
  public:
    char pad[0x5c];
    int x, y, z;
    char pad2[8];
    int value;
    unsigned char flag;
    void Set(Triple_102b90* p, int v, unsigned char f);
};
struct V3_102bf0 {
    float x, y, z;
};
struct Anchor_102bf0 {
    void FUN_00059a50(V3_102bf0 *out);
};
class Mover_102bf0 {
public:
    char pad00[0x10];
    Anchor_102bf0 *anchor;
    float FUN_000356b0();
};


// 0x00102a50 FUN_00102a50 (100 B): matches/0x00102a50.cpp
// sym: ?FUN_00102a50@fn_ff1bac5e@@YAXPAVOwner_102a50@1@PAMPAVVec_102a50@1@@Z
void FUN_00102a50(Owner_102a50* owner, float* src, Vec_102a50* dst) {
    float local[3];
    owner->origin->Get(local);
    dst->x = src[0] - local[0];
    dst->y = src[1] - local[1];
    dst->z = src[2] - local[2];
    dst->Normalize();
    float scale = owner->Scale();
    dst->x = scale * dst->x;
    dst->y = scale * dst->y;
    dst->z = scale * dst->z;
}

} // namespace fn_ff1bac5e

// 0x00102ac0 FUN_00102ac0 (82 B): matches/0x00102ac0.cpp [wrapped: conflict: CMoveAgent]
// sym: ??0CMoveAgent@fn_00102ac0@@QAE@PAX@Z
namespace fn_00102ac0 {
extern "C" char DAT_0040d418[];
class Obj_102ac0 {
  public:
    virtual void Init();
};
class CAvoidBehaviour_102ac0 {
  public:
    Obj_102ac0* Make();
};
struct CCharacterAgent_000fc760 {
    CCharacterAgent_000fc760(void*);
};
extern "C" void* FUN_0008d690(hulk_uintptr);
class CMoveAgent : public CCharacterAgent_000fc760 {
  public:
    char pad[0x68];
    Obj_102ac0* p;
    unsigned char b6c;
    char padx[3];
    float scale;
    unsigned char flag;
    unsigned char b75;
    unsigned char b76;
    CMoveAgent(void*);
};
CMoveAgent::CMoveAgent(void* arg) : CCharacterAgent_000fc760(arg) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0040d418);
    CAvoidBehaviour_102ac0* h = (CAvoidBehaviour_102ac0*)FUN_0008d690(0x38);
    Obj_102ac0* q;
    if (h)
        q = h->Make();
    else
        q = 0;
    p = q;
    q->Init();
    scale = 1.0f;
    flag = 1;
    b6c = 0;
    b75 = 0;
    b76 = 0;
}
} // namespace fn_00102ac0


// 0x00102b20 FUN_00102b20 (32 B): matches/0x00102b20.cpp [wrapped: conflict: CMoveAgent]
// sym: ??1CMoveAgent@fn_00102b20@@UAE@XZ
namespace fn_00102b20 {
class Ref_102b20 {
  public:
    virtual void a();
    virtual void Release();
};
class CMoveAgent {
  public:
    virtual ~CMoveAgent();
    void finish();
    char pad[0x64];
    Ref_102b20* member;
};
CMoveAgent::~CMoveAgent() {
    member->Release();
    member = 0;
    finish();
}
} // namespace fn_00102b20


// 0x00102b40 CMoveAgent::vfunc_9 (26 B): matches/0x00102b40.cpp
// sym: ?vfunc_9@CMoveAgent@@UAEXXZ
void CMoveAgent::vfunc_9() {
    *(int*)((char*)this + 8) = 0;
    *(unsigned int*)((char*)this + 0x70) = 0x3f800000;
    *((unsigned char*)this + 0x74) = 1;
    *((unsigned char*)this + 0x6c) = 0;
    *((unsigned char*)this + 0x75) = 0;
    *((unsigned char*)this + 0x76) = 0;
}


// 0x00102b60 CMoveAgent::vfunc_3 (39 B): matches/0x00102b60.cpp
// sym: ?vfunc_3@CMoveAgent@@UAEMHH@Z
hulk_freg CMoveAgent::vfunc_3(hulk_intptr x, int y) {
    ((Helper_102b60*)this)->f(x, y);
    float z = gZero_102b60;
    *(int*)((char*)this + 8) = 0;
    return z;
}

namespace fn_ff1bac5e {

// 0x00102b90 FUN_00102b90 (38 B): matches/0x00102b90.cpp
// sym: ?Set@Target_102b90@fn_ff1bac5e@@QAEXPAUTriple_102b90@2@HE@Z
void Target_102b90::Set(Triple_102b90* p, int v, unsigned char f) {
    x = p->a;
    y = p->b;
    z = p->c;
    value = v;
    flag = f;
}

} // namespace fn_ff1bac5e

// 0x00102bc0 CMoveAgent::vfunc_7 (44 B): equivalent/0x00102bc0.cpp [wrapped: conflict: CMoveAgent]
// sym: ?vfunc_7@CMoveAgent@fn_00102bc0@@UAEXD@Z
namespace fn_00102bc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CMoveAgent::vfunc_7 @ 0x00102bc0
struct MoveTarget {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void* slot6(const char*, int);
};
struct CMoveAgent {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(char); virtual void vfunc_8(void*); virtual void vfunc_9(); virtual void vfunc_10();
    char padding[0x58 - 4]; MoveTarget* moveTarget;
};
void CMoveAgent::vfunc_7(char enabled) {
    if (enabled)
        vfunc_8(moveTarget->slot6("move", -1));
}
} // namespace fn_00102bc0

namespace fn_ff1bac5e {

// 0x00102bf0 FUN_00102bf0 (155 B): equivalent/0x00102bf0.cpp
// sym: _FUN_00102bf0
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 2/2)
// FUN_00102bf0 @ 0x00102bf0
// FUN_00102bf0: out = (target - origin), clamped to a maximum length
extern "C" void __cdecl FUN_00102bf0(void *m, void *target, float speed, void * out_)
{
    V3_102bf0 * out = (V3_102bf0 *)out_;
    V3_102bf0 origin;
    ((Mover_102bf0 *)m)->anchor->FUN_00059a50(&origin);
    out->x = ((V3_102bf0 *)target)->x - origin.x;
    out->y = ((V3_102bf0 *)target)->y - origin.y;
    hulk_freg dz = ((V3_102bf0 *)target)->z - origin.z;      // the store of out->z leaves st0 unrounded for the length
    out->z = dz;
    double root = sqrt(out->x * out->x + out->y * out->y + dz * dz);
    hulk_freg len = (float)root;
    hulk_freg t = (float)(root / speed);
    hulk_freg limit = ((Mover_102bf0 *)m)->FUN_000356b0();
    hulk_freg clamped = (t < limit) ? t : limit;
    hulk_freg scale = clamped / len;
    out->x = scale * out->x;
    out->y = scale * out->y;
    out->z = scale * out->z;
}

} // namespace fn_ff1bac5e

// 0x00102cd0 CMoveAgent::vfunc_4 (1421 B): equivalent/0x00102cd0.cpp [wrapped: conflict: CMoveAgent]
// sym: ?F@CMoveAgent@fn_00102cd0@@QAEXPAVArg1_102cd0@2@HH@Z
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
namespace fn_00102cd0 {
// STATUS: equivalent (tools/equiv.py level 3: 19936 inputs, branch coverage 50/50)
// CMoveAgent::vfunc_4 @ 0x00102cd0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_102cd0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_102cd0* other, float eps);
    float FUN_00018990();
};

class Body_102cd0 {
public:
    void FUN_00059a50(V3_102cd0* out);
};

class Agent_102cd0 {
public:
    char pad00[0x10];
    Body_102cd0* body;
    char pad14[0x2064 - 0x14];
    V3_102cd0 dir;
    float speed;
    V3_102cd0 aim;
    void FUN_00035550(V3_102cd0* v);
};

class Obj60_102cd0 {
public:
    char pad00[0x10];
    Body_102cd0* body;
    char pad14[0x1ca0 - 0x14];
    char* link;
};

class Item_102cd0 {
public:
    char pad[0x40];
    float x;
    char pad2[4];
    float z;
};

class Sub58_102cd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Agent_102cd0* v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad04[0x60 - 4];
    Item_102cd0* item;
    char pad64[0xe8 - 0x64];
    char flagE8;
    int FUN_000fdc80();
    int FUN_000fdc40();
};

class Arg1_102cd0 {
public:
    char pad00[0x20];
    struct Gate_102cd0* gate;
};

struct Gate_102cd0 {
    char FUN_00024300(Agent_102cd0* a);
};

struct Env;
float FUN_0010ae50(Env* e, Agent_102cd0* a, float f, V3_102cd0* v1, V3_102cd0* v2, int zero, Obj60_102cd0** out);


#define DAT_004dd700 (*(Env* *)&::DAT_004dd700)

extern "C++" __declspec(nothrow) void __cdecl FUN_00102bf0(void *, void *, float, void *);
void FUN_00102a50(Agent_102cd0* a, V3_102cd0* pos, V3_102cd0* out);

class CMoveAgent {
public:
    char pad00[0x58];
    Sub58_102cd0* sub;
    V3_102cd0 pos;
    char pad68[4];
    char flag6c;
    char pad6d[3];
    float f70;
    char flag74;
    char flag75;
    char flag76;
    void FUN_000fc550(Arg1_102cd0* a, int b, int c);
    void F(Arg1_102cd0* a, int b, int c);
};

void CMoveAgent::F(Arg1_102cd0* a1, int a2, int a3)
{
    V3_102cd0 A, B, C, D, F, G, H, J, E, w;
    V3_102cd0 junk;
    Obj60_102cd0* obj;
    float len, t, thr;
    char ok;

    FUN_000fc550(a1, a2, a3);
    Agent_102cd0* ag = sub->v6();
    A.x = 0; A.y = 0; A.z = 0;
    B.x = 0; B.y = 0; B.z = 0;
    C.x = 0; C.y = 0; C.z = 0;
    D.x = 0; D.y = 0; D.z = 0;
    if (sub && sub->v9() == 4)
        return;
    if (flag74)
        FUN_00102bf0((Agent_102cd0 *)ag, (V3_102cd0 *)(&pos), 5.0f, (V3_102cd0 *)(&A));
    else
        FUN_00102a50(ag, &pos, &A);
    ok = a1->gate->FUN_00024300(ag);
    if (!ok)
        A.y = 0;
    len = (float)sqrt(A.z * A.z + A.x * A.x + A.y * A.y);
    A.FUN_0022d110();
    ag->body->FUN_00059a50(&junk);
    V3_102cd0 v80;
    v80.z = A.z;
    v80.x = A.x;
    v80.y = A.y;
    obj = 0;
    thr = 1.5f;
    if (!flag6c)
        thr = 0.99f;
    t = FUN_0010ae50(DAT_004dd700, ag, 1.5f, &v80, &B, 0, &obj);
    if (!(t < 0.0f) && !(t > thr) && !ok) {
        flag6c = 1;
    } else {
        flag6c = 0;
        B.z = 0;
        B.y = 0;
        B.x = 0;
    }
    flag76 = 0;
    int cnt80 = sub->FUN_000fdc80();
    int cnt40 = sub->FUN_000fdc40();
    if (cnt80 == cnt40) {
        E.x = 0; E.y = 0; E.z = 0;
        if (!B.FUN_0022d2b0(&E, 1.0e-5f)) {
            B.FUN_0022d110();
            F.x = A.x;
            F.y = 0;
            F.z = A.z;
            F.FUN_0022d110();
            if (F.z * B.z + F.x * B.x + B.y * F.y < -0.7f && t < 0.99f) {
                if (obj && obj->link && *(char**)(obj->link + 0x10c)) {
                    V3_102cd0* g = (V3_102cd0*)(*(char**)(obj->link + 0x10c) + 0x5c);
                    G = *g;
                    H.x = G.x - pos.x;
                    H.y = G.y - pos.y;
                    H.z = G.z - pos.z;
                    if (H.FUN_00018990() < 1.0f) {
                        obj->body->FUN_00059a50(&H);
                        ag->body->FUN_00059a50(&w);
                        F.x = G.x - H.x;
                        F.y = 0;
                        H.y = 0;
                        F.z = G.z - H.z;
                        H.x = pos.x - w.x;
                        H.z = pos.z - w.z;
                        hulk_freg lh = H.FUN_00018990();
                        hulk_freg lf = F.FUN_00018990();
                        if (lf < lh)
                            flag76 = 1;
                    }
                }
            } else {
                B.z = 0;
                B.y = 0;
                B.x = 0;
            }
        }
    }
    D.z = C.z + A.z;
    double sx = C.x + A.x;
    double sy = C.y + A.y;
    hulk_freg ty = B.y * 0.25f;
    hulk_freg tz = B.z * 0.25f;
    D.x = (float)(B.x * 0.25f + sx);
    D.y = (float)(ty + sy);
    D.z = tz + D.z;
    D.FUN_0022d110();
    if (flag76) {
        ag->speed = 0;
    } else if (sub->v9() >= 3 && !sub->flagE8) {
        ag->speed = 1.0f;
    } else if (len > f70) {
        ag->speed = f70;
    } else if (flag74) {
        ag->speed = len;
    } else {
        ag->speed = f70;
    }
    J.x = 0; J.y = 0; J.z = 0;
    if (D.FUN_0022d2b0(&J, 1.0e-5f)) {
        ag->FUN_00035550(&ag->aim);
    } else {
        Item_102cd0* item = sub->item;
        if (flag75 && item) {
            V3_102cd0 I;
            I.x = item->x;
            I.y = 0;
            I.z = item->z;
            ag->body->FUN_00059a50(&w);
            J.x = I.x - w.x;
            J.y = 0;
            J.z = I.z - w.z;
            J.FUN_0022d110();
            ag->aim.x = J.x;
            ag->aim.y = J.y;
            ag->aim.z = J.z;
        } else {
            ag->aim.x = A.x;
            ag->aim.y = A.y;
            ag->aim.z = A.z;
        }
    }
    ag->dir.x = D.x;
    ag->dir.y = D.y;
    ag->dir.z = D.z;
}
} // namespace fn_00102cd0
#undef DAT_004dd700

