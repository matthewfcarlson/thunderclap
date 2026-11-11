// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188ab0..0x00188d30 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f393ec31 {
#define TREE_TU_END }
namespace fn_f393ec31 {} using namespace fn_f393ec31;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f393ec31 {
struct RefCounted_188ab0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419678[];
class PropAddToCollisionAction_188ab0 {
  public:
    PropAddToCollisionAction_188ab0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188ab0* m_20;
};
class Params_188b00 {
  public:
    int x;
};
extern Params_188b00 hulk_at_00494b44;
extern Params_188b00 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_188b00*, Params_188b00*, int);
class Object_188b00 {
  public:
    int Init_00183ca0(hulkfight::motion::PropSetStateByIndexTrack*, hulk_intptr);
};
extern "C" Object_188b00* __cdecl FUN_0008d690(int);
struct RefCounted_188b50 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419694[];
class PropSetStateByIndexAction_188b50 {
  public:
    PropSetStateByIndexAction_188b50* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188b50* m_20;
};
class Params_188ba0 {
  public:
    int x;
};
extern Params_188ba0 TypeA_188ba0;
extern Params_188ba0 TypeB_188ba0;
int __cdecl Check(void*, int, Params_188ba0*, Params_188ba0*, int);
struct PropSetStateByNameAction_nv_188ba0 {
    int Init_00183db0(hulkfight::motion::PropSetStateByNameTrack*, hulk_intptr);
};
hulkfight::motion::PropSetStateByNameAction* __cdecl Alloc_0008d690(int);
struct RefCounted_188bf0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004196b0[];
class PropSetStateByNameAction_188bf0 {
  public:
    PropSetStateByNameAction_188bf0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188bf0* m_20;
};
struct RefCounted_188c90 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004196cc[];
class PropSpawnAction_188c90 {
  public:
    PropSpawnAction_188c90* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188c90* m_20;
};


// 0x00188ab0 hulkfight::motion::PropAddToCollisionAction::vfunc_2 (71 B): matches/0x00188ab0.cpp
// sym: ?vfunc_2@PropAddToCollisionAction_188ab0@fn_f393ec31@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropAddToCollisionAction_188ab0* PropAddToCollisionAction_188ab0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419678;
    RefCounted_188ab0* q = *(RefCounted_188ab0* volatile*)&m_20;
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

} // namespace fn_f393ec31

// 0x00188b00 hulkfight::motion::PropSetStateByIndexTrack::vfunc_10 (70 B): matches/0x00188b00.cpp
// sym: ?vfunc_10@PropSetStateByIndexTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropSetStateByIndexTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        Object_188b00* p = FUN_0008d690(0x24);
        if (p)
            return p->Init_00183ca0(this, c);
    }
    return 0;
}

namespace fn_f393ec31 {

// 0x00188b50 hulkfight::motion::PropSetStateByIndexAction::vfunc_2 (71 B): matches/0x00188b50.cpp
// sym: ?vfunc_2@PropSetStateByIndexAction_188b50@fn_f393ec31@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropSetStateByIndexAction_188b50* PropSetStateByIndexAction_188b50::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419694;
    RefCounted_188b50* q = *(RefCounted_188b50* volatile*)&m_20;
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

} // namespace fn_f393ec31

// 0x00188ba0 hulkfight::motion::PropSetStateByNameTrack::vfunc_10 (70 B): matches/0x00188ba0.cpp
// sym: ?vfunc_10@PropSetStateByNameTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropSetStateByNameTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188ba0, &TypeB_188ba0, 0);
    if (result) {
        hulkfight::motion::PropSetStateByNameAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((PropSetStateByNameAction_nv_188ba0*)(((hulkfight::motion::PropSetStateByNameAction*)(p))))->Init_00183db0(this, c);
    }
    return 0;
}

namespace fn_f393ec31 {

// 0x00188bf0 hulkfight::motion::PropSetStateByNameAction::vfunc_2 (71 B): matches/0x00188bf0.cpp
// sym: ?vfunc_2@PropSetStateByNameAction_188bf0@fn_f393ec31@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropSetStateByNameAction_188bf0* PropSetStateByNameAction_188bf0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004196b0;
    RefCounted_188bf0* q = *(RefCounted_188bf0* volatile*)&m_20;
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


// 0x00188c90 hulkfight::motion::PropSpawnAction::vfunc_2 (71 B): matches/0x00188c90.cpp
// sym: ?vfunc_2@PropSpawnAction_188c90@fn_f393ec31@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropSpawnAction_188c90* PropSpawnAction_188c90::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004196cc;
    RefCounted_188c90* q = *(RefCounted_188c90* volatile*)&m_20;
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

} // namespace fn_f393ec31
