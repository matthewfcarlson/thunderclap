// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001133f0..0x00113d50 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f054a7c3 {
#define TREE_TU_END }
namespace fn_f054a7c3 {} using namespace fn_f054a7c3;
#include "game/unknown.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f054a7c3 {
struct RefCounted_1133f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040ddc0[];
class SemaphoreWaitAction_1133f0 {
  public:
    SemaphoreWaitAction_1133f0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1133f0* m_20;
};
class Params_113440 {
  public:
    int x;
};
extern Params_113440 hulk_at_00494b44;
extern Params_113440 hulk_at_00494b60;
class Object_113440 {
  public:
    int Init_0010f9d0(hulkfight::ai::SemaphoreClearTrack*, hulk_intptr);
};
Object_113440* __cdecl Alloc_0008d690(int);
struct RefCounted_113490 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dddc[];
class SemaphoreClearAction_113490 {
  public:
    SemaphoreClearAction_113490* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113490* m_20;
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
class AllocObj_1134e0 {
  public:
    int init_0010fa60(hulkfight::ai::KeywordWaitTrack*, hulk_intptr);
};
struct RefCounted_113530 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040ddf8[];
class KeywordWaitAction_113530 {
  public:
    KeywordWaitAction_113530* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113530* m_20;
};
class Caster_1136e0 {
  public:
    virtual bool Fnf_001113e0(void*);
};
void other_002343e0(void*, Caster_1136e0*);
class Caster_113900 {
  public:
    virtual bool cast_00110f60(void*);
};
class Obj {
  public:
    void apply_00236760(void*);
    int Get_00236760(void*);
};
extern "C" void* find(const char*, Caster_113900*);
class Caster_1139f0 {
  public:
    virtual bool cast_001111e0(void*);
};
extern void* lookup_002343e0(const char*, Caster_1139f0*);
class Caster {
  public:
    virtual bool cast_001113e0(void*);
};
extern "C" void* Find(const char*, Caster*);


// 0x001133f0 hulkfight::ai::SemaphoreWaitAction::vfunc_2 (71 B): matches/0x001133f0.cpp
// sym: ?vfunc_2@SemaphoreWaitAction_1133f0@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SemaphoreWaitAction_1133f0* SemaphoreWaitAction_1133f0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040ddc0;
    RefCounted_1133f0* q = *(RefCounted_1133f0* volatile*)&m_20;
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

} // namespace fn_f054a7c3

// 0x00113440 hulkfight::ai::SemaphoreClearTrack::vfunc_10 (70 B): matches/0x00113440.cpp
// sym: ?vfunc_10@SemaphoreClearTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::ai::SemaphoreClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_113440* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_0010f9d0(this, c);
    }
    return 0;
}

namespace fn_f054a7c3 {

// 0x00113490 hulkfight::ai::SemaphoreClearAction::vfunc_2 (71 B): matches/0x00113490.cpp
// sym: ?vfunc_2@SemaphoreClearAction_113490@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SemaphoreClearAction_113490* SemaphoreClearAction_113490::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dddc;
    RefCounted_113490* q = *(RefCounted_113490* volatile*)&m_20;
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

} // namespace fn_f054a7c3

// 0x001134e0 hulkfight::ai::KeywordWaitTrack::vfunc_10 (70 B): matches/0x001134e0.cpp
// sym: ?vfunc_10@KeywordWaitTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::KeywordWaitTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_1134e0* p = (AllocObj_1134e0*)FUN_0008d690(0x2c);
        if (p)
            return p->init_0010fa60(this, c);
    }
    return 0;
}

namespace fn_f054a7c3 {

// 0x00113530 hulkfight::ai::KeywordWaitAction::vfunc_2 (71 B): matches/0x00113530.cpp
// sym: ?vfunc_2@KeywordWaitAction_113530@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
KeywordWaitAction_113530* KeywordWaitAction_113530::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040ddf8;
    RefCounted_113530* q = *(RefCounted_113530* volatile*)&m_20;
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


// 0x001136e0 FUN_001136e0 (27 B): matches/0x001136e0.cpp
// sym: ?target@fn_f054a7c3@@YAXPAX@Z
void target(void* p) {
    Caster_1136e0 c;
    other_002343e0(p, &c);
}

} // namespace fn_f054a7c3

// 0x001138a0 FUN_001138a0 (38 B): matches/0x001138a0.cpp [wrapped: conflict: Find]
// sym: _FUN_001138a0
namespace fn_001138a0 {
class Caster_1138a0 {
  public:
    virtual bool Cast_00110e60(void*);
};
class Target {
  public:
    void Apply_00236760(void*);
};
void* __cdecl Find_002343e0(void*, Caster_1138a0*);
extern "C" void FUN_001138a0(Target* target, void* value) {
    Caster_1138a0 caster;
    target->Apply_00236760(Find_002343e0(value, &caster));
}
} // namespace fn_001138a0


// 0x001138d0 FUN_001138d0 (38 B): matches/0x001138d0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_001138d0@@YAXPAVObject@1@PAX@Z
namespace fn_001138d0 {
class Caster {
  public:
    virtual bool Dummy_00110f00(void*);
};
extern "C++" void* __cdecl Lookup_002343e0(void*, Caster*);
class Object {
  public:
    void Set_00236760(void*);
};
void __cdecl Target(Object* obj, void* name) {
    Caster caster;
    void* p = Lookup_002343e0(name, &caster);
    obj->Set_00236760(p);
}
} // namespace fn_001138d0

namespace fn_f054a7c3 {

// 0x00113900 FUN_00113900 (38 B): matches/0x00113900.cpp
// sym: _FUN_00113900
extern "C" void FUN_00113900(Obj* obj, const char* name) {
    Caster_113900 caster;
    void* p = find(name, &caster);
    obj->apply_00236760(p);
}

} // namespace fn_f054a7c3

// 0x00113930 FUN_00113930 (38 B): matches/0x00113930.cpp [wrapped: conflict: Find]
// sym: _FUN_00113930
namespace fn_00113930 {
class Caster_113930 {
  public:
    virtual bool Cast_00110fc0(void*);
};
void* __cdecl Find_002343e0(void*, Caster_113930*);
class Obj {
  public:
    void Apply_00236760(void*);
};
extern "C" void __cdecl FUN_00113930(Obj* obj, void* item) {
    Caster_113930 caster;
    void* p = Find_002343e0(item, &caster);
    obj->Apply_00236760(p);
}
} // namespace fn_00113930


// 0x00113990 FUN_00113990 (38 B): matches/0x00113990.cpp [wrapped: conflict: Find; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00113990
namespace fn_00113990 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual void dummy();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {};
} // namespace fight
namespace hulkfight {
namespace ai {
class PropsToChuckCondition;
}
} // namespace hulkfight
class Owner {
  public:
    void Set_00236760(void*);
};
void* Find_002343e0(const char*, fight::ConditionFactoryCaster*);
extern "C" void FUN_00113990(Owner* owner, const char* name) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition> caster;
    owner->Set_00236760(Find_002343e0(name, &caster));
}
} // namespace fn_00113990

namespace fn_f054a7c3 {

// 0x001139f0 FUN_001139f0 (38 B): matches/0x001139f0.cpp
// sym: _FUN_001139f0
extern "C" void FUN_001139f0(Obj* obj, const char* name) {
    Caster_1139f0 caster;
    void* p = lookup_002343e0(name, &caster);
    obj->apply_00236760(p);
}

} // namespace fn_f054a7c3

// 0x00113a20 FUN_00113a20 (38 B): matches/0x00113a20.cpp [wrapped: conflict: find]
// sym: _FUN_00113a20
namespace fn_00113a20 {
class Caster {
  public:
    virtual bool Cast_00111240(void*);
};
extern "C++" void* __cdecl find_002343e0(void*, Caster*);
class Factory {
  public:
    void apply_00236760(void*);
};
extern "C" void __cdecl FUN_00113a20(Factory* f, void* p) {
    Caster caster;
    f->apply_00236760(find_002343e0(p, &caster));
}
} // namespace fn_00113a20


// 0x00113a50 FUN_00113a50 (38 B): matches/0x00113a50.cpp [wrapped: conflict: Function]
// sym: ?Function@fn_00113a50@@YAXPAVFactory@1@PBD@Z
namespace fn_00113a50 {
class Caster {
  public:
    virtual bool Cast_001112e0(void*);
};
class Factory {
  public:
    void Add_00236760(void*);
};
extern "C++" void* Find_002343e0(const char*, Caster*);
void Function(Factory* factory, const char* name) {
    Caster c;
    factory->Add_00236760(Find_002343e0(name, &c));
}
} // namespace fn_00113a50


// 0x00113a80 FUN_00113a80 (38 B): matches/0x00113a80.cpp [wrapped: conflict: Find]
// sym: _FUN_00113a80
namespace fn_00113a80 {
class Caster {
  public:
    virtual bool Cast_00111360(void*);
};
class Obj {
  public:
    void Set_00236760(void*);
};
void* Find_002343e0(int, Caster*);
extern "C" void FUN_00113a80(Obj* obj, hulk_intptr id) {
    Caster caster;
    obj->Set_00236760(Find_002343e0(id, &caster));
}
} // namespace fn_00113a80

namespace fn_f054a7c3 {

// 0x00113ab0 FUN_00113ab0 (38 B): matches/0x00113ab0.cpp
// sym: _FUN_00113ab0
extern "C" int FUN_00113ab0(Obj* obj, const char* name) {
    Caster caster;
    return obj->Get_00236760(Find(name, &caster));
}

} // namespace fn_f054a7c3

// 0x00113ae0 FUN_00113ae0 (38 B): matches/0x00113ae0.cpp [wrapped: conflict: Lookup; fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00113ae0
namespace fn_00113ae0 {
namespace hulkfight {
namespace ai {
class PropsToSuckCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class Obj {
  public:
    void Do_00236760(void*);
};
extern "C++" void* Lookup_002343e0(void*, fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>*);
extern "C" void FUN_00113ae0(Obj* obj, void* b) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition> caster;
    obj->Do_00236760(Lookup_002343e0(b, &caster));
}
} // namespace fn_00113ae0


// 0x00113b10 FUN_00113b10 (38 B): matches/0x00113b10.cpp [wrapped: conflict: Find]
// sym: _FUN_00113b10
namespace fn_00113b10 {
class Caster {
  public:
    virtual bool dummy_00111540(void*);
};
class Owner {
  public:
    void Fn_00236760(void*);
};
void* __cdecl Find_002343e0(void*, Caster*);
extern "C" void __cdecl FUN_00113b10(Owner* o, void* key) {
    Caster c;
    void* p = Find_002343e0(key, &c);
    o->Fn_00236760(p);
}
} // namespace fn_00113b10


// 0x00113b40 FUN_00113b40 (38 B): matches/0x00113b40.cpp [wrapped: conflict: lookup]
// sym: _FUN_00113b40
namespace fn_00113b40 {
class Caster {
  public:
    virtual bool cast_001115c0(void*);
};
class Factory {
  public:
    void use_00236760(void*);
};
extern "C++" void* __cdecl lookup_002343e0(const char*, Caster*);
extern "C" void __cdecl FUN_00113b40(Factory* f, const char* name) {
    Caster c;
    void* p = lookup_002343e0(name, &c);
    f->use_00236760(p);
}
} // namespace fn_00113b40


// 0x00113b70 FUN_00113b70 (38 B): matches/0x00113b70.cpp [wrapped: conflict: Find]
// sym: _FUN_00113b70
namespace fn_00113b70 {
class Caster_113b70 {
  public:
    virtual void Cast();
};
class SpecificCaster : public Caster_113b70 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set_00236760(void*);
};
void* __cdecl Find_002343e0(void*, Caster_113b70*);
extern "C" void __cdecl FUN_00113b70(Owner* owner, void* key) {
    SpecificCaster caster;
    owner->Set_00236760(Find_002343e0(key, &caster));
}
} // namespace fn_00113b70


// 0x00113ba0 FUN_00113ba0 (38 B): matches/0x00113ba0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_00113ba0@@YAXPAUOwner@1@PBD@Z
namespace fn_00113ba0 {
struct Caster {
    virtual bool Cast_00111680(void*);
};
struct Owner {
    void Apply_002367c0(void*);
};
extern "C++" void* __cdecl Find_00236ac0(const char*, Caster*);
void __cdecl Target(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find_00236ac0(name, &caster);
    owner->Apply_002367c0(p);
}
} // namespace fn_00113ba0


// 0x00113bd0 FUN_00113bd0 (38 B): matches/0x00113bd0.cpp [wrapped: conflict: Find]
// sym: _FUN_00113bd0
namespace fn_00113bd0 {
class Caster_113bd0 {
  public:
    virtual bool Cast_00111720(void*);
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern void* __cdecl Find_00236ac0(void*, Caster_113bd0*);
extern "C" void FUN_00113bd0(Obj* obj, void* arg) {
    Caster_113bd0 caster;
    obj->Apply_002367c0(Find_00236ac0(arg, &caster));
}
} // namespace fn_00113bd0


// 0x00113c30 FUN_00113c30 (38 B): matches/0x00113c30.cpp [wrapped: conflict: find]
// sym: _FUN_00113c30
namespace fn_00113c30 {
class Caster {
  public:
    virtual bool cast_00111800(void*);
};
class Obj {
  public:
    void set_002367c0(void*);
};
extern void* find_00236ac0(const char*, Caster*);
extern "C" void FUN_00113c30(Obj* obj, const char* name) {
    Caster c;
    void* p = find_00236ac0(name, &c);
    obj->set_002367c0(p);
}
} // namespace fn_00113c30


// 0x00113c60 FUN_00113c60 (38 B): matches/0x00113c60.cpp [wrapped: conflict: find]
// sym: _FUN_00113c60
namespace fn_00113c60 {
class Caster {
  public:
    virtual bool cast_00111880(void*);
};
class Owner {
  public:
    void use_002367c0(void*);
};
void* find_00236ac0(void*, Caster*);
extern "C" void FUN_00113c60(Owner* owner, void* value) {
    Caster caster;
    void* p = find_00236ac0(value, &caster);
    owner->use_002367c0(p);
}
} // namespace fn_00113c60


// 0x00113c90 FUN_00113c90 (38 B): matches/0x00113c90.cpp [wrapped: conflict: Find]
// sym: _FUN_00113c90
namespace fn_00113c90 {
class Caster {
  public:
    virtual bool Cast_00111920(void*);
};
void* __cdecl Find_00236ac0(void*, Caster*);
class Owner {
  public:
    void* Get_002367c0(void*);
};
extern "C" void* __cdecl FUN_00113c90(Owner* owner, void* p) {
    Caster caster;
    void* x = Find_00236ac0(p, &caster);
    return owner->Get_002367c0(x);
}
} // namespace fn_00113c90


// 0x00113cc0 FUN_00113cc0 (38 B): matches/0x00113cc0.cpp [wrapped: conflict: lookup]
// sym: _FUN_00113cc0
namespace fn_00113cc0 {
class Caster {
  public:
    virtual bool Fnf_001119a0(void*);
};
class Obj {
  public:
    void take_002367c0(void*);
};
extern "C++" void* lookup_00236ac0(void*, Caster*);
extern "C" void FUN_00113cc0(Obj* obj, void* name) {
    Caster caster;
    obj->take_002367c0(lookup_00236ac0(name, &caster));
}
} // namespace fn_00113cc0


// 0x00113cf0 FUN_00113cf0 (38 B): matches/0x00113cf0.cpp [wrapped: conflict: Find]
// sym: _FUN_00113cf0
namespace fn_00113cf0 {
class Caster {
  public:
    virtual bool cast_00111a40(void*);
};
class Token {};
class Factory {
  public:
    void Set_002367c0(Token*);
};
Token* Find_00236ac0(void*, Caster*);
extern "C" void FUN_00113cf0(Factory* f, void* p) {
    Caster c;
    f->Set_002367c0(Find_00236ac0(p, &c));
}
} // namespace fn_00113cf0


// 0x00113d20 FUN_00113d20 (38 B): matches/0x00113d20.cpp [wrapped: conflict: Find]
// sym: _FUN_00113d20
namespace fn_00113d20 {
class Caster {
  public:
    virtual bool Cast_00111ac0(void*);
};
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C++" void* __cdecl Find_00236ac0(void*, Caster*);
extern "C" void FUN_00113d20(Owner* owner, void* track) {
    Caster caster;
    owner->Add_002367c0(Find_00236ac0(track, &caster));
}
} // namespace fn_00113d20

