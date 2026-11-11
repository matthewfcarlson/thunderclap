// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001571a0..0x001575f0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f3c596a7 {
#define TREE_TU_END }
namespace fn_f3c596a7 {} using namespace fn_f3c596a7;
#include "game/unknown.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f3c596a7 {
typedef unsigned int u32_1571a0;
extern int hulk_at_00494b44, hulk_at_00494b60;
struct Result_1571a0 {
    u32_1571a0 setup_00151bc0(hulkfight::motion::HitPushbackTrack*, hulk_uintptr);
};
extern Result_1571a0* alloc_0008d690(int);
extern int hulk_at_0041460c;
class RefObj_1571f0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class HitPushbackAction_1571f0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1571f0* m2;
    RefObj_1571f0* m3;
    void* vfunc_2(unsigned char flag);
};
typedef unsigned int u32_157250;
struct Created_157250 {
    int init_00151de0(hulkfight::motion::HitFloatTrack*, u32_157250);
};
extern void* __cdecl alloc(hulk_uintptr);
extern const int typeA_157250;
extern const int typeB_157250;
extern int hulk_at_00414628;
class RefObj_1572a0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class HitFloatAction_1572a0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1572a0* m2;
    RefObj_1572a0* m3;
    void* vfunc_2(unsigned char flag);
};
class Params_157300 {
  public:
    int x;
};
extern Params_157300 TypeA_157300;
extern Params_157300 TypeB_157300;
class Object_157300 {
  public:
    int Init_00151e90(hulkfight::motion::HitDamageTrack*, hulk_intptr);
};
Object_157300* __cdecl Alloc_0008d690(int);
struct RefCounted_157350 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00414644[];
class HitDamageAction_157350 {
  public:
    HitDamageAction_157350* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_157350* m_20;
};
extern void* hulk_at_00414660[];
class Ref_1573f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1573f0 {
  public:
    void* vptr;
};
class HitThrowAction_1573f0 : public Action_1573f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1573f0* m20;
    Ref_1573f0* m24;
    Ref_1573f0* m28;
    HitThrowAction_1573f0* f2(unsigned char flags);
};
extern int hulk_at_0041467c;
class RefObj_1574a0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class HitOrientToPushbackAction_1574a0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1574a0* m2;
    RefObj_1574a0* m3;
    void* vfunc_2(unsigned char flag);
};
struct RefCounted_157550 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00414698[];
class HealthAction_157550 {
  public:
    HealthAction_157550* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_157550* m_20;
};

} // namespace fn_f3c596a7

// 0x001571a0 hulkfight::motion::HitPushbackTrack::vfunc_10 (70 B): matches/0x001571a0.cpp
// sym: ?vfunc_10@HitPushbackTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::HitPushbackTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1571a0 a = (u32_1571a0)__p0; u32_1571a0 b = (u32_1571a0)__p1; hulk_uintptr c = (u32_1571a0)__p2;

    if (check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        Result_1571a0* p = alloc_0008d690(0x44);
        if (p)
            return (int)(p->setup_00151bc0(this, c));
    }
    return (int)(0);
}

namespace fn_f3c596a7 {

// 0x001571f0 hulkfight::motion::HitPushbackAction::vfunc_2 (90 B): matches/0x001571f0.cpp
// sym: ?vfunc_2@HitPushbackAction_1571f0@fn_f3c596a7@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* HitPushbackAction_1571f0::vfunc_2(unsigned char flag) {
    volatile HitPushbackAction_1571f0* self = this;
    self->mVptr = &hulk_at_0041460c;
    RefObj_1571f0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1571f0* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        operator_delete(this);
    return this;
}

} // namespace fn_f3c596a7

// 0x00157250 hulkfight::motion::HitFloatTrack::vfunc_10 (70 B): matches/0x00157250.cpp
// sym: ?vfunc_10@HitFloatTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00138c50 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitFloatTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_157250 a = (u32_157250)__p0; u32_157250 b = (u32_157250)__p1; u32_157250 c = (u32_157250)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(c), 0, (void*)(&typeA_157250), (void*)(&typeB_157250), 0))) {
        Created_157250* p = (Created_157250*)alloc_0008d690(0x38);
        if (p)
            return p->init_00151de0(this, c);
    }
    return 0;
}

namespace fn_f3c596a7 {

// 0x001572a0 hulkfight::motion::HitFloatAction::vfunc_2 (90 B): matches/0x001572a0.cpp
// sym: ?vfunc_2@HitFloatAction_1572a0@fn_f3c596a7@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* HitFloatAction_1572a0::vfunc_2(unsigned char flag) {
    volatile HitFloatAction_1572a0* self = this;
    self->mVptr = &hulk_at_00414628;
    RefObj_1572a0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1572a0* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        operator_delete(this);
    return this;
}

} // namespace fn_f3c596a7

// 0x00157300 hulkfight::motion::HitDamageTrack::vfunc_10 (70 B): matches/0x00157300.cpp
// sym: ?vfunc_10@HitDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&TypeA_157300), (void*)(&TypeB_157300), 0));
    if (result) {
        Object_157300* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_00151e90(this, c);
    }
    return 0;
}

namespace fn_f3c596a7 {

// 0x00157350 hulkfight::motion::HitDamageAction::vfunc_2 (71 B): matches/0x00157350.cpp
// sym: ?vfunc_2@HitDamageAction_157350@fn_f3c596a7@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HitDamageAction_157350* HitDamageAction_157350::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00414644;
    RefCounted_157350* q = *(RefCounted_157350* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x001573f0 hulkfight::motion::HitThrowAction::vfunc_2 (95 B): matches/0x001573f0.cpp
// sym: ?f2@HitThrowAction_1573f0@fn_f3c596a7@@QAEPAV12@E@Z
HitThrowAction_1573f0* HitThrowAction_1573f0::f2(unsigned char flags) {
    vptr = hulk_at_00414660;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1573f0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x001574a0 hulkfight::motion::HitOrientToPushbackAction::vfunc_2 (90 B): matches/0x001574a0.cpp
// sym: ?vfunc_2@HitOrientToPushbackAction_1574a0@fn_f3c596a7@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* HitOrientToPushbackAction_1574a0::vfunc_2(unsigned char flag) {
    volatile HitOrientToPushbackAction_1574a0* self = this;
    self->mVptr = &hulk_at_0041467c;
    RefObj_1574a0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1574a0* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        operator_delete(this);
    return this;
}


// 0x00157550 hulkfight::motion::HealthAction::vfunc_2 (71 B): matches/0x00157550.cpp
// sym: ?vfunc_2@HealthAction_157550@fn_f3c596a7@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HealthAction_157550* HealthAction_157550::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00414698;
    RefCounted_157550* q = *(RefCounted_157550* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_f3c596a7
