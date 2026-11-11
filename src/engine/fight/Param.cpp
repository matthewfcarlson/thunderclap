// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234090..0x002343b0 (kind game, layer engine, confidence high), dominant class fight::Param
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f350f41f {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f350f41f {} using namespace fn_f350f41f;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f350f41f {
class Ref_234090 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_234090 {
  public:
    Ref_234090* mRef;
    bool Clear(Ref_234090*);
};
class A_234150 {
  public:
    virtual void f();
    virtual void g();
};
extern "C" int FUN_00267090(int);
class B_234150 {
  public:
    A_234150* a;
    int b;
};
extern void* hulk_at_00427958;
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
class Enumerator {
  public:
    virtual int Get(int index);
    int Count();
};
class Param;
class Item_2342b0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void Apply(Param*, int);
};
class Param {
  public:
    virtual Item_2342b0* Get(int);
    virtual void V1();
    virtual bool V2(int);
    virtual void V3();
    virtual void V4();
    virtual void V5();
};
typedef unsigned __int64 uint64;
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual bool slot13(); virtual uint64 slot14(); virtual void slot15();
 virtual void slot16(uint64 value); virtual void slot17();
};
namespace fight {
struct Param {
 virtual void FUN_00344f51();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual bool vfunc_3(unsigned int low, unsigned int high, unsigned int value, Source* source);
 virtual void vfunc_4(unsigned int value, Source* source);
 virtual void vfunc_5();
};
}


// 0x00234090 FUN_00234090 (26 B): matches/0x00234090.cpp
// sym: ?Clear@Owner_234090@fn_f350f41f@@QAE_NPAVRef_234090@2@@Z
bool Owner_234090::Clear(Ref_234090* unused) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    return true;
}


// 0x00234150 FUN_00234150 (34 B): matches/0x00234150.cpp
// sym: @FUN_00234150@4
extern "C" int __fastcall FUN_00234150(B_234150* p) {
    if (p->a)
        p->a->g();
    p->a = 0;
    return FUN_00267090(p->b);
}


// 0x00234210 FUN_00234210 (7 B): matches/0x00234210.cpp
// sym: @FUN_00234210@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_00234210(void* self) {
    *(void**)self = &hulk_at_00427958;
}


// 0x00234220 fight::Param::vfunc_5 (31 B): matches/0x00234220.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f350f41f@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00234240 FUN_00234240 (33 B): matches/0x00234240.cpp
// sym: ?Count@Enumerator@fn_f350f41f@@QAEHXZ
int Enumerator::Count() {
    int i = 0;
    while (Get(i) != 0)
        ++i;
    return i;
}


// 0x002342b0 fight::Param::vfunc_2 (63 B): matches/0x002342b0.cpp
// sym: ?V2@Param@fn_f350f41f@@UAE_NH@Z
bool Param::V2(int arg) {
    int n = 0;
    while (Get(n) != 0)
        ++n;
    --n;
    if (n >= 0) {
        do {
            Item_2342b0* p = Get(n);
            p->Apply(this, arg);
            --n;
        } while (n >= 0);
    }
    return true;
}


// 0x002342f0 fight::Param::vfunc_3 (83 B): equivalent/0x002342f0.cpp
// sym: ?vfunc_3@Param@fight@fn_f350f41f@@UAE_NIIIPAUSource@3@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::Param::vfunc_3 @ 0x002342f0
namespace fight {
bool Param::vfunc_3(unsigned int low, unsigned int high, unsigned int value, Source* source) {
 if (!source->slot13()) return false;
 uint64 id = source->slot14();
 if (id != ((uint64)high << 32 | low)) return false;
 source->slot16(id);
 vfunc_4(value, source);
 source->slot17();
 return true;
}
}

} // namespace fn_f350f41f

// 0x00234350 fight::Param::vfunc_4 (71 B): matches/0x00234350.cpp [wrapped: conflict: Param]
// sym: ?vfunc_4@Param@fn_00234350@@QAE_NHH@Z
namespace fn_00234350 {
class Param;
class Item_234350 {
  public:
    virtual void a(int);
    virtual void b();
    virtual bool c();
    virtual void d();
    virtual void e();
    virtual void f(Param*, int, int);
};
class Param {
  public:
    virtual Item_234350* Get(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    bool vfunc_4(int, int);
};
bool Param::vfunc_4(int p1, int p2) {
    int i = 0;
    Item_234350* x = Get(0);
    while (x) {
        if (!x->c())
            x->f(this, p1, p2);
        ++i;
        x = Get(i);
    }
    return true;
}
} // namespace fn_00234350

