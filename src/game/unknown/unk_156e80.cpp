// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00156e80..0x00157150 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f203b23d {
#define TREE_TU_END }
namespace fn_f203b23d {} using namespace fn_f203b23d;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f203b23d {
extern int g_vftable_156e80;
class RefObj_156e80 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class GroundSlideAction_156e80 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_156e80* m2;
    RefObj_156e80* m3;
    void* vfunc_2(unsigned char flag);
};
class Params_156ee0 {
  public:
    int x;
};
extern Params_156ee0 TypeA_156ee0;
extern Params_156ee0 TypeB_156ee0;
int __cdecl Check(void*, int, Params_156ee0*, Params_156ee0*, int);
class Object_156ee0 {
  public:
    int Init(hulkfight::motion::HitPauseTrack*, hulk_intptr);
};
Object_156ee0* __cdecl Alloc(int);
struct RefCounted_156f30 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_156f30[];
class HitPauseAction_156f30 {
  public:
    HitPauseAction_156f30* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_156f30* m_20;
};
typedef unsigned int u32_156f80;
struct Helper_156f80 {
    int run(hulkfight::motion::HitReactionTrack*, u32_156f80);
};
extern int __cdecl FUN_00344e74(u32_156f80, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_156f80[];
extern const char RTTI2_156f80[];
typedef unsigned int u32_156ff0;
struct Helper_156ff0 {
    int run(hulkfight::motion::HitReactionFloatTrack*, u32_156ff0);
};
extern int __cdecl FUN_00344e74(u32_156ff0, int, const void*, const void*, int);
extern const char RTTI1_156ff0[];
extern const char RTTI2_156ff0[];
struct RefCounted_1570b0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_1570b0[];
class HitPushbackAddAction_1570b0 {
  public:
    HitPushbackAddAction_1570b0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1570b0* m_20;
};


// 0x00156e80 hulkfight::motion::GroundSlideAction::vfunc_2 (90 B): matches/0x00156e80.cpp
// sym: ?vfunc_2@GroundSlideAction_156e80@fn_f203b23d@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* GroundSlideAction_156e80::vfunc_2(unsigned char flag) {
    volatile GroundSlideAction_156e80* self = this;
    self->mVptr = &g_vftable_156e80;
    RefObj_156e80* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_156e80* t2 = self->m2;
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

} // namespace fn_f203b23d

// 0x00156ee0 hulkfight::motion::HitPauseTrack::vfunc_10 (70 B): matches/0x00156ee0.cpp
// sym: ?vfunc_10@HitPauseTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPauseTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_156ee0, &TypeB_156ee0, 0);
    if (result) {
        Object_156ee0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}

namespace fn_f203b23d {

// 0x00156f30 hulkfight::motion::HitPauseAction::vfunc_2 (71 B): matches/0x00156f30.cpp
// sym: ?vfunc_2@HitPauseAction_156f30@fn_f203b23d@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HitPauseAction_156f30* HitPauseAction_156f30::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_156f30;
    RefCounted_156f30* q = *(RefCounted_156f30* volatile*)&m_20;
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

} // namespace fn_f203b23d

// 0x00156f80 hulkfight::motion::HitReactionTrack::vfunc_10 (70 B): matches/0x00156f80.cpp
// sym: ?vfunc_10@HitReactionTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001421d0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitReactionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_156f80 a = (u32_156f80)__p0; u32_156f80 b = (u32_156f80)__p1; u32_156f80 c = (u32_156f80)__p2;

    if (FUN_00344e74(c, 0, RTTI1_156f80, RTTI2_156f80, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_156f80*)p)->run(this, c);
    }
    return 0;
}


// 0x00156fd0 hulkfight::motion::HitReactionAction::vfunc_2 (30 B): matches/0x00156fd0.cpp
// sym: ??_GHitReactionAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::HitReactionAction::~HitReactionAction() {}


// 0x00156ff0 hulkfight::motion::HitReactionFloatTrack::vfunc_10 (70 B): matches/0x00156ff0.cpp
// sym: ?vfunc_10@HitReactionFloatTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001421d0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitReactionFloatTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_156ff0 a = (u32_156ff0)__p0; u32_156ff0 b = (u32_156ff0)__p1; u32_156ff0 c = (u32_156ff0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_156ff0, RTTI2_156ff0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_156ff0*)p)->run(this, c);
    }
    return 0;
}


// 0x00157040 hulkfight::motion::HitReactionFloatAction::vfunc_2 (30 B): matches/0x00157040.cpp
// sym: ??_GHitReactionFloatAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::HitReactionFloatAction::~HitReactionFloatAction() {}

namespace fn_f203b23d {

// 0x001570b0 hulkfight::motion::HitPushbackAddAction::vfunc_2 (71 B): matches/0x001570b0.cpp
// sym: ?vfunc_2@HitPushbackAddAction_1570b0@fn_f203b23d@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HitPushbackAddAction_1570b0* HitPushbackAddAction_1570b0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1570b0;
    RefCounted_1570b0* q = *(RefCounted_1570b0* volatile*)&m_20;
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

} // namespace fn_f203b23d
