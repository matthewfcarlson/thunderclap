// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8600..0x000e8a10 (kind game, layer game, confidence medium), dominant class FEPoseAnimation
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f477ab1c {
#define TREE_TU_END }
namespace fn_f477ab1c {} using namespace fn_f477ab1c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f477ab1c {
struct Source {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
};
struct Evaluator { float FUN_000dfbf0(int); };
struct Entry { float factor; char unused[12]; };
struct Target {
    Evaluator** functions;
    char unused[4];
    Entry entries[8];
    int selected;
    hulk_freg FUN_000e8600(int parameter, int index);
};
extern const float limit = -1.0f;
extern void* hulk_at_0040bfc0[];
} // namespace fn_f477ab1c
void operator delete[](void*);
namespace fn_f477ab1c {
class Ref_e86f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEAnimation_e86f0 {
  public:
    void* vptr;
    void* m4;
    int m8;
    Ref_e86f0* mc;
    ~FEAnimation_e86f0();
};
struct Ref_e8980 {
    virtual void a();
    virtual void release();
};
struct FEBillboardAnimation_e8980 {
    int* vptr;
    unsigned int resource;
    char pad[4];
    Ref_e8980* child;
    void cleanup();
};
extern "C" char DAT_0040c3d0[];
class Ref_e89e0 {
  public:
    virtual void f();
    virtual void g();
};
class FEPoseAnimation_e89e0 {
  public:
    void Done_000e8730();
};


// 0x000e8600 FUN_000e8600 (69 B): equivalent/0x000e8600.cpp
// sym: ?FUN_000e8600@Target@fn_f477ab1c@@QAEMHH@Z @ea85b3045feb @w5b262aed9caf
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_000e8600 @ 0x000e8600
hulk_freg Target::FUN_000e8600(int parameter, int index) {
    Evaluator* evaluator = functions[9 + index];
    Entry* entry = &entries[selected];
    Source* source = (Source*)functions[9];
    float divisor = source->slot7();
    float ratio = (*(float*)&DAT_0040cc38) / divisor;
    float value = evaluator->FUN_000dfbf0(parameter);
    return value * entry->factor * ratio;
}

} // namespace fn_f477ab1c

// 0x000e8650 FUN_000e8650 (73 B): matches/0x000e8650.cpp
// sym: ?FUN_000e8650@Obj_e8650@owners@@QAEXM@Z
void owners::Obj_e8650::FUN_000e8650(float x) {
    a = x;
    if (x > -1.0f && b > -1.0f) {
        int v = x <= b ? 1 : 0;
        flag = v;
    }
}


// 0x000e86a0 FUN_000e86a0 (73 B): matches/0x000e86a0.cpp
// sym: ?FUN_000e86a0@Obj_e86a0@owners@@QAEXM@Z
void owners::Obj_e86a0::FUN_000e86a0(float x) {
    input = x;
    if (value > limit && x > limit) {
        int r;
        if (value <= x)
            r = 1;
        else
            r = 0;
        flag = (unsigned char)r;
    }
}

namespace fn_f477ab1c {

// 0x000e86f0 FUN_000e86f0 (53 B): matches/0x000e86f0.cpp
// sym: ??1FEAnimation_e86f0@fn_f477ab1c@@QAE@XZ
FEAnimation_e86f0::~FEAnimation_e86f0() {
    vptr = hulk_at_0040bfc0;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m4) {
        operator delete[](m4);
        m4 = 0;
    }
}

} // namespace fn_f477ab1c

// 0x000e8730 FUN_000e8730 (85 B): matches/0x000e8730.cpp [wrapped: conflict: operatordelete[]]
// sym: ??1FEPoseAnimation_e8730@fn_000e8730@@QAE@XZ
namespace fn_000e8730 {
extern "C" void _ReadWriteBarrier();
extern void* DAT_0040c390[];
extern void* DAT_0040bfc0[];
class Ref_e8730 {
  public:
    virtual void F0();
    virtual void Release();
};

class FEPoseAnimation_e8730 {
  public:
    void* vptr;
    char* m4;
    char p[4];
    Ref_e8730* mc;
    char p2[0x50];
    Ref_e8730* m60;
    ~FEPoseAnimation_e8730();
};
FEPoseAnimation_e8730::~FEPoseAnimation_e8730() {
    vptr = DAT_0040c390;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    vptr = DAT_0040bfc0;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m4) {
        operator delete[](m4);
        m4 = 0;
    }
}
} // namespace fn_000e8730


// 0x000e8790 FEPoseAnimation::vfunc_2 (488 B): equivalent/0x000e8790.cpp [wrapped: conflict: FEPoseAnimation; Target]
// sym: ?vfunc_2@FEPoseAnimation@fn_000e8790@@UAEXXZ @190cd907599b @w44b46e78f592
namespace fn_000e8790 {
// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 38/38)
// FEPoseAnimation::vfunc_2 @ 0x000e8790
extern float (__cdecl *DAT_004de948)();

class Elem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float x);
    virtual float v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
};

struct ElemList {
    char pad0[0x24];
    Elem **begin;
    Elem **end;
};

struct Holder {
    char pad0[0x48];
    ElemList *list;
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float x, int y);
    char pad4[0x44];
    ElemList *list;
    void FUN_002998d0(int x);
};

struct Target {
    char pad0[0x38];
    int state;
    float f3c;
    char pad40[4];
    float f44;
    float f48;
    char pad4c[5];
    char flag51;
};

class FEPoseAnimation {
public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2();
    char pad4[0x4];
    char pad8[4];
    Owner *owner;
    Target *target;
    char pad14[0x58 - 0x14];
    int reverse;
    char done;
};

void FEPoseAnimation::vfunc_2()
{
    if (done)
        return;
    Target *t = target;
    done = 1;
    if (!t)
        return;
    if (t->state != 2)
        return;
    if (!owner)
        return;
    owner->v6(DAT_004de948() * ((reverse == 0) ? 1 : -1) * 1000.0f, 0);
    owner->FUN_002998d0(0);
    ElemList *l = owner->list;
    if ((char)(l->end - l->begin) == 0)
        return;
    Elem *e = *l->begin;
    if (!e)
        return;
    if (reverse == 0) {
        if (!e->v22()) {
            if (!(target->f44 > -1.0f))
                return;
            float lim = target->f44;
            if (!(e->v13() >= lim))
                return;
        }
        Target *a = target;
        if (a->flag51) {
            if (a->f48 > -1.0f)
                e->v12(a->f48);
            else
                e->v12(a->f3c);
            e->v6(0, 1);
            return;
        }
        a->state = 1;
        a = target;
        if (!(a->f48 > -1.0f))
            return;
        e->v12(a->f48);
        e->v6(0, 1);
        return;
    }
    if (e->v13() <= 0.0f) {
    } else {
        if (!(target->f44 > -1.0f))
            return;
        float lim = target->f44;
        if (!(e->v13() <= lim))
            return;
    }
    Target *a = target;
    if (a->flag51) {
        if (a->f48 > -1.0f)
            e->v12(a->f48);
        else
            e->v12(a->f3c);
        e->v6(0, 1);
        return;
    }
    a->state = 1;
}
} // namespace fn_000e8790

namespace fn_f477ab1c {

// 0x000e8980 FUN_000e8980 (78 B): matches/0x000e8980.cpp
// sym: ?cleanup@FEBillboardAnimation_e8980@fn_f477ab1c@@QAEXXZ
void FEBillboardAnimation_e8980::cleanup() {
    vptr = &billboardVtable;
    Ref_e8980* volatile* pc = &child;
    Ref_e8980* c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    vptr = &animationVtable;
    c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    if (resource) {
        thunk(resource);
        resource = 0;
    }
}


// 0x000e89d0 FEBillboardAnimation::vfunc_3 (1 B): matches/0x000e89d0.cpp
// sym: ?FUN_000e89d0@fn_f477ab1c@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e89d0() {}

} // namespace fn_f477ab1c

// 0x000e89e0 FUN_000e89e0 (36 B): matches/0x000e89e0.cpp
// sym: ?FUN_000e89e0@FEParticleAnimation@@QAEXXZ
void FEParticleAnimation::FUN_000e89e0() {
    *(int* volatile*)this = (int*)((hulk_intptr)DAT_0040c3d0);
    Ref_e89e0* r = (*(Ref_e89e0 *volatile *)&this->f_64);
    if (r) {
        r->g();
        (*(Ref_e89e0 *volatile *)&this->f_64) = 0;
    }
    ((FEPoseAnimation_e89e0*)this)->Done_000e8730();
}

