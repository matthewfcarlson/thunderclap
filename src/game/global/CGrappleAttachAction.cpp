// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00015370..0x000157c0 (kind game, layer game, confidence medium), dominant class CGrappleAttachAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f87e33ec {
#define TREE_TU_END }
namespace fn_f87e33ec {} using namespace fn_f87e33ec;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f87e33ec {
struct R5;
struct R4;
struct R2;
struct R1;
struct M_15370;
struct T2;
struct R3;
struct T2 {
    char pad[0x24];
    int f24;
    char pad2[0x12e0 - 0x28];
    int f12e0;
    int f12e4;
    int f12e8;
};
struct R3 {
    char pad[0x68];
    unsigned int f68;
};
struct R5 {
    R3* Fn_00059a40();
};
struct R4 {
    char pad[0x10];
    R5* f10;
};
struct R2 {
    char pad[0x338];
    R4* f338;
};
struct R1 {
    R2* Fn_00059a30();
};
struct M_15370 {
    R1* Fn_000592a0();
};
extern char hulk_at_0048d534[];
extern char hulk_at_0048d554[];
void* FUN_00344e74(void* e, int a, void* b, void* c, int d);
struct C_15440 {
    void run_00222b50(void*, int, float);
};
struct B_15440 {
    C_15440* getC_00059a40();
};
struct A_15440 {
};

} // namespace fn_f87e33ec

// 0x00015370 CGrappleLocoStrafe4Action::vfunc_7 (193 B): matches/0x00015370.cpp
// sym: ?vfunc_7@CGrappleLocoStrafe4Action@@UAE_NH@Z
bool CGrappleLocoStrafe4Action::vfunc_7(int arg) {
    if (!(*(T2 * *)&this->f_24))
        return false;
    R1* r1 = (*(M_15370 * *)&this->f_1c)->Fn_000592a0();
    R2* r2 = r1->Fn_00059a30();
    R4* r4 = r2->f338;
    if (!r4)
        return false;
    R3* r3 = r4->f10->Fn_00059a40();
    if (!r3)
        return false;
    for (unsigned int i = 0; i < r3->f68; i++) {
        void* e = ((void *)((owners::C_222e20 *)r3)->FUN_00222e20((unsigned)i));
        T2* p = (T2*)FUN_00344e74(e, 0, hulk_at_0048d534, hulk_at_0048d554, 0);
        if (p) {
            (*(T2 * *)&this->f_24)->f24 = p->f24;
            (*(T2 * *)&this->f_24)->f12e4 = p->f12e4;
            (*(T2 * *)&this->f_24)->f12e0 = p->f12e0;
            (*(T2 * *)&this->f_24)->f12e8 = p->f12e8;
            return true;
        }
    }
    return false;
}


// 0x00015440 CGrappleLocoStrafe4Action::vfunc_4 (49 B): matches/0x00015440.cpp
// sym: ?vfunc_4@CGrappleLocoStrafe4Action@@UAEXXZ
void CGrappleLocoStrafe4Action::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        B_15440* b = ((B_15440 *)((owners::Object_592a0 *)((*(A_15440 * *)&this->f_1c)))->FUN_000592a0());
        C_15440* c = b->getC_00059a40();
        if (c)
            c->run_00222b50((*(void * *)&this->f_24), 0, -1.0f);
    }
}


// 0x00015480 CGrappleAttachAction::vfunc_6 (827 B): equivalent/0x00015480.cpp [wrapped: conflict: CGrappleAttachAction]
// sym: ?vfunc_6@CGrappleAttachAction@fn_00015480@@UAEDH@Z @b94f9174b7a4 @wb9fc77d0d6c8
namespace fn_00015480 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 32/32)
// CGrappleAttachAction::vfunc_6 @ 0x00015480
struct Vec3_15480 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_00011160(float s, Vec3_15480* d);
};

struct Mat_15480 {
    float m[12];
    Vec3_15480 t;
    float w;
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022bc20(float a, float b, float c);
    void FUN_0022c120();
    void FUN_0022c2b0(Vec3_15480* in, Vec3_15480* out);
    void FUN_0022ca90(Mat_15480* a, Mat_15480* b);
};

struct JointFinder_15480 {
    unsigned int FUN_0027b200(int a, int b);
};

struct SkeletonData_15480 {
    char pad0[8];
    JointFinder_15480* finder;
    char pad0c[0x1c - 0xc];
    Mat_15480* mats;
};

struct Resource_15480 {
    char pad0[0x64];
    SkeletonData_15480* skeleton;
};

struct IdHolder_15480 {
    Resource_15480* FUN_00059a40();
};

struct Entity {
    char pad00[0x10];
    IdHolder_15480* idHolder;
    char pad14[0x12c - 0x14];
    int f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x330 - 0x32c];
    Entity* p330;
    Entity* link;
    Entity* p338;
    char pad33c[0x20a8 - 0x33c];
    int f20a8;
    void FUN_000393c0();
    void FUN_00035160(Mat_15480* out);
    void FUN_0003a680(Entity* target, int a, int b, int c, Mat_15480* m, float e5, float e6, float e7);
};

struct GrappleData_15480 {
    char pad0[0x10];
    int jointA;
    int jointB;
    int f18;
    int f1c;
    unsigned char useOffset;
    char pad21[3];
    Vec3_15480 offset;
    float f30;
    Vec3_15480 v34;
    int f40;
    int f44;
    Vec3_15480 v48;
    float f54;
    float f58;
    char b5c;
    char pad5d[3];
    float f60;
    float f64;
};

void* __fastcall FUN_000592a0(void* owner);
extern "C" Entity* __fastcall FUN_00059a30(void* x);
extern "C" hulk_freg __cdecl FUN_00224f10(Vec3_15480* v);

union SkelOrLen {
    SkeletonData_15480* skel;
    float len;
};

class CGrappleAttachAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void* owner;
    GrappleData_15480* data;
};

char CGrappleAttachAction::vfunc_6(int arg)
{
    struct Frame {
        float tmp;
        SkelOrLen u;
        Vec3_15480 d;
        unsigned int id;
        Vec3_15480 r;
        Vec3_15480 q;
        Mat_15480 A;
        Mat_15480 C;
        Mat_15480 B;
    } f;

    Entity* a = FUN_00059a30(FUN_000592a0(owner));
    Entity* b = a->link;
    if (b == 0) {
        b = a->p330;
        if (b == 0) {
            b = a->p338;
            if (b == 0)
                return 0;
        }
    }
    if (data->b5c) {
        Entity* t = a;
        a = b;
        b = t;
    }
    Resource_15480* res = a->idHolder->FUN_00059a40();
    a->link = b;
    a->FUN_0003a680(0, -1, 0, 0, 0, data->f60, 1.0f, data->f64);
    if (a->f20a8 >= 0 && a->f328 == b->f12c)
        a->FUN_000393c0();

    f.id = 0xffff;
    f.u.skel = 0;
    if (res != 0) {
        f.u.skel = res->skeleton;
        if (f.u.skel != 0)
            f.id = f.u.skel->finder->FUN_0027b200(data->jointA, data->jointB);
    }
    if (data->useOffset) {
        f.A.FUN_0022b980();
        f.d = data->offset;
        f.A.t = f.d;
        f.r.y = data->v34.y;
        f.A.FUN_0022bc20(data->v34.x, f.r.y + data->f30, data->v34.z);
    } else {
        if (f.id != 0xffff)
            f.B = f.u.skel->mats[f.id];
        else
            a->FUN_00035160(&f.B);
        f.B.FUN_0022c120();
        b->FUN_00035160(&f.C);
        if (f.u.skel != 0 && (data->f40 | data->f44) != 0) {
            unsigned int j = f.u.skel->finder->FUN_0027b200(data->f40, data->f44);
            if (j != 0xffff) {
                f.q = data->v48;
                f.u.skel->mats[j].FUN_0022c2b0(&f.q, &f.r);
                f.d.x = f.r.x - f.C.t.x;
                f.d.y = 0.0f;
                f.d.z = f.r.z - f.C.t.z;
                f.u.len = f.d.FUN_0022d110();
                if (f.u.len > data->f54) {
                    f.tmp = FUN_00224f10(&f.d);
                    f.C.FUN_0022ba70(f.tmp);
                }
                f.tmp = data->f58;
                if (f.tmp > 0.0f && f.u.len > f.tmp)
                    f.C.t.FUN_00011160(f.u.len - f.tmp, &f.d);
            }
        }
        f.A.FUN_0022ca90(&f.C, &f.B);
    }
    b->FUN_0003a680(a, f.id, data->f18, data->f1c, &f.A, data->f60, 1.0f, data->f64);
    b->link = 0;
    return 0;
}
} // namespace fn_00015480

