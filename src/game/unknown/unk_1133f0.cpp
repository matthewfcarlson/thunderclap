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

// ---- declarations shared by the functions below
namespace fn_f054a7c3 {
struct RefCounted_1133f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_1133f0[];
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
extern Params_113440 TypeA_113440;
extern Params_113440 TypeB_113440;
int __cdecl Check(void*, int, Params_113440*, Params_113440*, int);
class Object_113440 {
  public:
    int Init(hulkfight::ai::SemaphoreClearTrack*, hulk_intptr);
};
Object_113440* __cdecl Alloc(int);
struct RefCounted_113490 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_113490[];
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
    int init(hulkfight::ai::KeywordWaitTrack*, hulk_intptr);
};
struct RefCounted_113530 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_113530[];
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
    virtual void f();
};
void other(void*, Caster_1136e0*);
class Caster_113900 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
    int Get(void*);
};
extern "C" void* find(const char*, Caster_113900*);
class Caster_1139f0 {
  public:
    virtual void cast();
};
extern void* lookup(const char*, Caster_1139f0*);
class Caster {
  public:
    virtual void cast();
};
extern "C" void* Find(const char*, Caster*);


// 0x001133f0 hulkfight::ai::SemaphoreWaitAction::vfunc_2 (71 B): matches/0x001133f0.cpp
// sym: ?vfunc_2@SemaphoreWaitAction_1133f0@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SemaphoreWaitAction_1133f0* SemaphoreWaitAction_1133f0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1133f0;
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
    int result = Check((void*)c, 0, &TypeA_113440, &TypeB_113440, 0);
    if (result) {
        Object_113440* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}

namespace fn_f054a7c3 {

// 0x00113490 hulkfight::ai::SemaphoreClearAction::vfunc_2 (71 B): matches/0x00113490.cpp
// sym: ?vfunc_2@SemaphoreClearAction_113490@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SemaphoreClearAction_113490* SemaphoreClearAction_113490::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_113490;
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
            return p->init(this, c);
    }
    return 0;
}

namespace fn_f054a7c3 {

// 0x00113530 hulkfight::ai::KeywordWaitAction::vfunc_2 (71 B): matches/0x00113530.cpp
// sym: ?vfunc_2@KeywordWaitAction_113530@fn_f054a7c3@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
KeywordWaitAction_113530* KeywordWaitAction_113530::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_113530;
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
    other(p, &c);
}

} // namespace fn_f054a7c3

// 0x001138a0 FUN_001138a0 (38 B): matches/0x001138a0.cpp [wrapped: conflict: Find]
// sym: _FUN_001138a0
namespace fn_001138a0 {
class Caster_1138a0 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster_1138a0*);
extern "C" void FUN_001138a0(Target* target, void* value) {
    Caster_1138a0 caster;
    target->Apply(Find(value, &caster));
}
} // namespace fn_001138a0


// 0x001138d0 FUN_001138d0 (38 B): matches/0x001138d0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_001138d0@@YAXPAVObject@1@PAX@Z
namespace fn_001138d0 {
class Caster {
  public:
    virtual void Dummy();
};
extern "C++" __declspec(nothrow) void* __cdecl Lookup(void*, Caster*);
class Object {
  public:
    void Set(void*);
};
void __cdecl Target(Object* obj, void* name) {
    Caster caster;
    void* p = Lookup(name, &caster);
    obj->Set(p);
}
} // namespace fn_001138d0

namespace fn_f054a7c3 {

// 0x00113900 FUN_00113900 (38 B): matches/0x00113900.cpp
// sym: _FUN_00113900
extern "C" void FUN_00113900(Obj* obj, const char* name) {
    Caster_113900 caster;
    void* p = find(name, &caster);
    obj->apply(p);
}

} // namespace fn_f054a7c3

// 0x00113930 FUN_00113930 (38 B): matches/0x00113930.cpp [wrapped: conflict: Find]
// sym: _FUN_00113930
namespace fn_00113930 {
class Caster_113930 {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster_113930*);
class Obj {
  public:
    void Apply(void*);
};
extern "C" void __cdecl FUN_00113930(Obj* obj, void* item) {
    Caster_113930 caster;
    void* p = Find(item, &caster);
    obj->Apply(p);
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
    void Set(void*);
};
void* Find(const char*, fight::ConditionFactoryCaster*);
extern "C" void FUN_00113990(Owner* owner, const char* name) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition> caster;
    owner->Set(Find(name, &caster));
}
} // namespace fn_00113990

namespace fn_f054a7c3 {

// 0x001139f0 FUN_001139f0 (38 B): matches/0x001139f0.cpp
// sym: _FUN_001139f0
extern "C" void FUN_001139f0(Obj* obj, const char* name) {
    Caster_1139f0 caster;
    void* p = lookup(name, &caster);
    obj->apply(p);
}

} // namespace fn_f054a7c3

// 0x00113a20 FUN_00113a20 (38 B): matches/0x00113a20.cpp [wrapped: conflict: find]
// sym: _FUN_00113a20
namespace fn_00113a20 {
class Caster {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* __cdecl find(void*, Caster*);
class Factory {
  public:
    void apply(void*);
};
extern "C" void __cdecl FUN_00113a20(Factory* f, void* p) {
    Caster caster;
    f->apply(find(p, &caster));
}
} // namespace fn_00113a20


// 0x00113a50 FUN_00113a50 (38 B): matches/0x00113a50.cpp [wrapped: conflict: Function]
// sym: ?Function@fn_00113a50@@YAXPAVFactory@1@PBD@Z
namespace fn_00113a50 {
class Caster {
  public:
    virtual void Cast();
};
class Factory {
  public:
    void Add(void*);
};
extern "C++" __declspec(nothrow) void* Find(const char*, Caster*);
void Function(Factory* factory, const char* name) {
    Caster c;
    factory->Add(Find(name, &c));
}
} // namespace fn_00113a50


// 0x00113a80 FUN_00113a80 (38 B): matches/0x00113a80.cpp [wrapped: conflict: Find]
// sym: _FUN_00113a80
namespace fn_00113a80 {
class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* Find(int, Caster*);
extern "C" void FUN_00113a80(Obj* obj, hulk_intptr id) {
    Caster caster;
    obj->Set(Find(id, &caster));
}
} // namespace fn_00113a80

namespace fn_f054a7c3 {

// 0x00113ab0 FUN_00113ab0 (38 B): matches/0x00113ab0.cpp
// sym: _FUN_00113ab0
extern "C" int FUN_00113ab0(Obj* obj, const char* name) {
    Caster caster;
    return obj->Get(Find(name, &caster));
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
    void Do(void*);
};
extern "C++" __declspec(nothrow) void* Lookup(void*, fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>*);
extern "C" void FUN_00113ae0(Obj* obj, void* b) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition> caster;
    obj->Do(Lookup(b, &caster));
}
} // namespace fn_00113ae0


// 0x00113b10 FUN_00113b10 (38 B): matches/0x00113b10.cpp [wrapped: conflict: Find]
// sym: _FUN_00113b10
namespace fn_00113b10 {
class Caster {
  public:
    virtual void dummy();
};
class Owner {
  public:
    void Fn(void*);
};
void* __cdecl Find(void*, Caster*);
extern "C" void __cdecl FUN_00113b10(Owner* o, void* key) {
    Caster c;
    void* p = Find(key, &c);
    o->Fn(p);
}
} // namespace fn_00113b10


// 0x00113b40 FUN_00113b40 (38 B): matches/0x00113b40.cpp [wrapped: conflict: lookup]
// sym: _FUN_00113b40
namespace fn_00113b40 {
class Caster {
  public:
    virtual void cast();
};
class Factory {
  public:
    void use(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl lookup(const char*, Caster*);
extern "C" void __cdecl FUN_00113b40(Factory* f, const char* name) {
    Caster c;
    void* p = lookup(name, &c);
    f->use(p);
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
    void Set(void*);
};
void* __cdecl Find(void*, Caster_113b70*);
extern "C" void __cdecl FUN_00113b70(Owner* owner, void* key) {
    SpecificCaster caster;
    owner->Set(Find(key, &caster));
}
} // namespace fn_00113b70


// 0x00113ba0 FUN_00113ba0 (38 B): matches/0x00113ba0.cpp [wrapped: conflict: Target]
// sym: ?Target@fn_00113ba0@@YAXPAUOwner@1@PBD@Z
namespace fn_00113ba0 {
struct Caster {
    virtual void Cast();
};
struct Owner {
    void Apply(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find(const char*, Caster*);
void __cdecl Target(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Apply(p);
}
} // namespace fn_00113ba0


// 0x00113bd0 FUN_00113bd0 (38 B): matches/0x00113bd0.cpp [wrapped: conflict: Find]
// sym: _FUN_00113bd0
namespace fn_00113bd0 {
class Caster_113bd0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* __cdecl Find(void*, Caster_113bd0*);
extern "C" void FUN_00113bd0(Obj* obj, void* arg) {
    Caster_113bd0 caster;
    obj->Apply(Find(arg, &caster));
}
} // namespace fn_00113bd0


// 0x00113c30 FUN_00113c30 (38 B): matches/0x00113c30.cpp [wrapped: conflict: find]
// sym: _FUN_00113c30
namespace fn_00113c30 {
class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern void* find(const char*, Caster*);
extern "C" void FUN_00113c30(Obj* obj, const char* name) {
    Caster c;
    void* p = find(name, &c);
    obj->set(p);
}
} // namespace fn_00113c30


// 0x00113c60 FUN_00113c60 (38 B): matches/0x00113c60.cpp [wrapped: conflict: find]
// sym: _FUN_00113c60
namespace fn_00113c60 {
class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void use(void*);
};
void* find(void*, Caster*);
extern "C" void FUN_00113c60(Owner* owner, void* value) {
    Caster caster;
    void* p = find(value, &caster);
    owner->use(p);
}
} // namespace fn_00113c60


// 0x00113c90 FUN_00113c90 (38 B): matches/0x00113c90.cpp [wrapped: conflict: Find]
// sym: _FUN_00113c90
namespace fn_00113c90 {
class Caster {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster*);
class Owner {
  public:
    void* Get(void*);
};
extern "C" void* __cdecl FUN_00113c90(Owner* owner, void* p) {
    Caster caster;
    void* x = Find(p, &caster);
    return owner->Get(x);
}
} // namespace fn_00113c90


// 0x00113cc0 FUN_00113cc0 (38 B): matches/0x00113cc0.cpp [wrapped: conflict: lookup]
// sym: _FUN_00113cc0
namespace fn_00113cc0 {
class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void take(void*);
};
extern "C++" __declspec(nothrow) void* lookup(void*, Caster*);
extern "C" void FUN_00113cc0(Obj* obj, void* name) {
    Caster caster;
    obj->take(lookup(name, &caster));
}
} // namespace fn_00113cc0


// 0x00113cf0 FUN_00113cf0 (38 B): matches/0x00113cf0.cpp [wrapped: conflict: Find]
// sym: _FUN_00113cf0
namespace fn_00113cf0 {
class Caster {
  public:
    virtual void cast();
};
class Token {};
class Factory {
  public:
    void Set(Token*);
};
Token* Find(void*, Caster*);
extern "C" void FUN_00113cf0(Factory* f, void* p) {
    Caster c;
    f->Set(Find(p, &c));
}
} // namespace fn_00113cf0


// 0x00113d20 FUN_00113d20 (38 B): matches/0x00113d20.cpp [wrapped: conflict: Find]
// sym: _FUN_00113d20
namespace fn_00113d20 {
class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find(void*, Caster*);
extern "C" void FUN_00113d20(Owner* owner, void* track) {
    Caster caster;
    owner->Add(Find(track, &caster));
}
} // namespace fn_00113d20

