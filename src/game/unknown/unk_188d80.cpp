// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188d80..0x00189050 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f437b5d0 {
#define TREE_TU_END }
namespace fn_f437b5d0 {} using namespace fn_f437b5d0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f437b5d0 {
class Params_188d80 {
  public:
    int x;
};
extern Params_188d80 TypeA_188d80;
extern Params_188d80 TypeB_188d80;
int __cdecl Check(void*, int, Params_188d80*, Params_188d80*, int);
class Object_188d80 {
  public:
    int Init(hulkfight::motion::PropDamageTrack*, hulk_intptr);
};
extern "C" Object_188d80* __cdecl FUN_0008d690(int);
struct RefCounted_188dd0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_188dd0[];
class PropDamageAction_188dd0 {
  public:
    PropDamageAction_188dd0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188dd0* m_20;
};
class Params_188e20 {
  public:
    int x;
};
extern Params_188e20 TypeA_188e20;
extern Params_188e20 TypeB_188e20;
int __cdecl Check(void*, int, Params_188e20*, Params_188e20*, int);
struct GrapplePropDamageAction_nv_188e20 {
    int Init(hulkfight::motion::GrapplePropDamageTrack*, hulk_intptr);
};
hulkfight::motion::GrapplePropDamageAction* __cdecl Alloc(int);
struct RefCounted_188e70 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_188e70[];
class GrapplePropDamageAction_188e70 {
  public:
    GrapplePropDamageAction_188e70* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188e70* m_20;
};
struct RefCounted_188f10 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_188f10[];
class PropDestroyAction_188f10 {
  public:
    PropDestroyAction_188f10* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188f10* m_20;
};
struct RefCounted_188fb0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_188fb0[];
class PropThrowAction_188fb0 {
  public:
    PropThrowAction_188fb0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188fb0* m_20;
};

} // namespace fn_f437b5d0

// 0x00188d80 hulkfight::motion::PropDamageTrack::vfunc_10 (70 B): matches/0x00188d80.cpp
// sym: ?vfunc_10@PropDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188d80, &TypeB_188d80, 0);
    if (result) {
        Object_188d80* p = FUN_0008d690(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}

namespace fn_f437b5d0 {

// 0x00188dd0 hulkfight::motion::PropDamageAction::vfunc_2 (71 B): matches/0x00188dd0.cpp
// sym: ?vfunc_2@PropDamageAction_188dd0@fn_f437b5d0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropDamageAction_188dd0* PropDamageAction_188dd0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_188dd0;
    RefCounted_188dd0* q = *(RefCounted_188dd0* volatile*)&m_20;
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

} // namespace fn_f437b5d0

// 0x00188e20 hulkfight::motion::GrapplePropDamageTrack::vfunc_10 (70 B): matches/0x00188e20.cpp
// sym: ?vfunc_10@GrapplePropDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrapplePropDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188e20, &TypeB_188e20, 0);
    if (result) {
        hulkfight::motion::GrapplePropDamageAction* p = Alloc(0x24);
        if (p)
            return ((GrapplePropDamageAction_nv_188e20*)(((hulkfight::motion::GrapplePropDamageAction*)(p))))->Init(this, c);
    }
    return 0;
}

namespace fn_f437b5d0 {

// 0x00188e70 hulkfight::motion::GrapplePropDamageAction::vfunc_2 (71 B): matches/0x00188e70.cpp
// sym: ?vfunc_2@GrapplePropDamageAction_188e70@fn_f437b5d0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
GrapplePropDamageAction_188e70* GrapplePropDamageAction_188e70::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_188e70;
    RefCounted_188e70* q = *(RefCounted_188e70* volatile*)&m_20;
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


// 0x00188f10 hulkfight::motion::PropDestroyAction::vfunc_2 (71 B): matches/0x00188f10.cpp
// sym: ?vfunc_2@PropDestroyAction_188f10@fn_f437b5d0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropDestroyAction_188f10* PropDestroyAction_188f10::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_188f10;
    RefCounted_188f10* q = *(RefCounted_188f10* volatile*)&m_20;
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


// 0x00188fb0 hulkfight::motion::PropThrowAction::vfunc_2 (71 B): matches/0x00188fb0.cpp
// sym: ?vfunc_2@PropThrowAction_188fb0@fn_f437b5d0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropThrowAction_188fb0* PropThrowAction_188fb0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_188fb0;
    RefCounted_188fb0* q = *(RefCounted_188fb0* volatile*)&m_20;
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

} // namespace fn_f437b5d0
