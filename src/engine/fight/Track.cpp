// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00236a90..0x00236e00 (kind game, layer engine, confidence high), dominant class fight::Track
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5a78e74 {
#define TREE_TU_END }
namespace fn_f5a78e74 {} using namespace fn_f5a78e74;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f5a78e74 {
typedef unsigned __int64 Key_236ac0;
extern "C" int __cdecl FUN_00238190(int);
extern "C" int __cdecl FUN_00266da0(hulk_intptr);
} // namespace fn_f5a78e74
extern "C" Key_236ac0 __cdecl FUN_002672f0(int, int, int);
namespace fn_f5a78e74 {
struct Node { char pad[16]; Node* next; int FUN_002367f0(Key_236ac0); };
struct List_236ac0 { Node* first; };
struct Visitor { virtual bool accept(int)=0; virtual int fallback(int)=0; };
class Ref_236b70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_236b70 {
  public:
    char pad[4];
    Ref_236b70* value;
    void Set(Ref_236b70* p);
};
class Param_236ba0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Param_236bb0 {
  public:
    virtual void f0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void f3();
    virtual void vfunc_4();
};
struct Sink_236bc0 {
    bool FUN_00232290(void *item);
};
struct Item_236bc0 {
    char pad00[0xc];
    unsigned int flags;
    float f10;
    float f14;
};
class Source_236bc0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual float v6();
    virtual float v7();
    virtual void v8(); virtual void v9();
    virtual Item_236bc0 *v10(int a, Sink_236bc0 *sink, int c);
    char pad04[4];
    unsigned int mode;
    bool FUN_00236bc0(int a, Sink_236bc0 *sink, int c);
};
} // namespace fn_f5a78e74
unsigned __int64 __cdecl FUN_002672f0(unsigned int name, int a, int b);
namespace fn_f5a78e74 {
class Param {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(unsigned __int64 id, int *out);
    virtual void vfunc_11(unsigned __int64 id, char *out);
    virtual void vfunc_12();
    virtual bool vfunc_13();
    virtual unsigned __int64 vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(unsigned __int64 id);
    virtual void vfunc_17();
};
union ParamArg_236c50 {
    Param *param;
    char flag;
};
class Track {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(unsigned __int64 id, int extra, ParamArg_236c50 arg);
    virtual void vfunc_4(int extra, Param *param);
    char pad04[4];
    int value;              // 0x8
};
extern void* Entity_236d10_vftable[];
class Entity_236d10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class TrackFactory_236d10 : public Entity_236d10 {
  public:
    TrackFactory_236d10* vfunc_5(signed char flags);
};
class Track_236d40 {
  public:
    virtual void f();
    int a;
    int b;
    Track_236d40();
};
class Ref_236d60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void Release(int);
};
class Param_236d60 {
  public:
    virtual void p();
};
extern "C" void __fastcall FUN_00234210(void* self);
class Track_236d60 : public Param_236d60 {
  public:
    virtual ~Track_236d60();
    Ref_236d60* mRef;
};

} // namespace fn_f5a78e74

// 0x00236a90 FUN_00236a90 (18 B): matches/0x00236a90.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0TrackFactory@fight@fn_00236a90@@QAE@XZ
namespace fn_00236a90 {
namespace fight {
class Base_236a90 {
  public:
    Base_236a90();
    virtual void V();
};
class TrackFactory : public Base_236a90 {
  public:
    TrackFactory();
    virtual void V();
};
void TrackFactory::V() {}
TrackFactory::TrackFactory() {}
} // namespace fight
} // namespace fn_00236a90

namespace fn_f5a78e74 {

// 0x00236ab0 FUN_00236ab0 (11 B): matches/0x00236ab0.cpp
// sym: ?FUN_00236ab0@fn_f5a78e74@@YIXPAVCEffectStopTrack@@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_00236ab0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_0027afd0(self);
}


// 0x00236ac0 FUN_00236ac0 (163 B): matches/0x00236ac0.cpp
// sym: ?target@fn_f5a78e74@@YAHHPAUVisitor@1@@Z
// FUN_00236ac0 @ 0x00236ac0
int __cdecl target(int value, Visitor* visitor) {
 int old = FUN_00266da0(FUN_00238190(0));
 List_236ac0* list = (*(List_236ac0**)&DAT_004e5af8);
 if (list) {
  Key_236ac0 key=FUN_002672f0(value,0,0);
  Node* node=list->first;
  while (node) {
   int result=node->FUN_002367f0(key);
   if(visitor->accept(result)) { FUN_00266da0(old); return result; }
   node=node->next;
  }
 }
 int result=visitor->fallback(value);
 FUN_00266da0(old);
 return result;
}


// 0x00236b70 FUN_00236b70 (39 B): matches/0x00236b70.cpp
// sym: ?Set@Owner_236b70@fn_f5a78e74@@QAEXPAVRef_236b70@2@@Z
// Same code shape as 0x002344a0 (propagated; names are from that function)
void Owner_236b70::Set(Ref_236b70* p) {
    if (value)
        value->f5(1);
    value = p;
}

} // namespace fn_f5a78e74

// 0x00236ba0 fight::Track::vfunc_8 (7 B): matches/0x00236ba0.cpp
// sym: ?vfunc_8@Track@fight@@UAEPAXPAX0@Z
void* fight::Track::vfunc_8(void* __p0, void* __p1) { hulk_intptr value = (hulk_intptr)__p0;

    return (void*)(value);
}


// 0x00236bb0 fight::Track::vfunc_9 (8 B): matches/0x00236bb0.cpp
// sym: ?vfunc_9@Track@fight@@UAEHHHH@Z
 // namespace fight
int fight::Track::vfunc_9(hulk_intptr , hulk_intptr , hulk_intptr ) {
    return 1;
}

namespace fn_f5a78e74 {

// 0x00236bc0 FUN_00236bc0 (136 B): equivalent/0x00236bc0.cpp
// sym: ?FUN_00236bc0@Source_236bc0@fn_f5a78e74@@QAE_NHPAUSink_236bc0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00236bc0 @ 0x00236bc0
bool Source_236bc0::FUN_00236bc0(int a, Sink_236bc0 *sink, int c)
{
    int saved = FUN_00266da0(FUN_00238190(3));
    Item_236bc0 *item = v10(a, sink, c);
    if (!item) {
        FUN_00266da0(saved);
        return false;
    }
    item->f10 = v6();
    item->f14 = v7();
    item->flags ^= (mode ^ item->flags) & 3;
    bool ok = sink->FUN_00232290(item);
    FUN_00266da0(saved);
    return ok;
}


// 0x00236c50 fight::Track::vfunc_3 (178 B): equivalent/0x00236c50.cpp
// sym: ?vfunc_3@Track@fn_f5a78e74@@UAE_N_KHTParamArg_236c50@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// fight::Track::vfunc_3 @ 0x00236c50
bool Track::vfunc_3(unsigned __int64 id, int extra, ParamArg_236c50 arg)
{
    Param *param = arg.param;
    int count;

    if (!param->vfunc_13())
        return false;
    unsigned __int64 key = param->vfunc_14();
    if (key != id)
        return false;

    param->vfunc_16(key);
    if (!param->vfunc_3()) {
        arg.flag = 0;
        param->vfunc_11(FUN_002672f0((*(hulk_uintptr*)&DAT_004ca290), 0, 0), &arg.flag);
    }
    count = 0;
    param->vfunc_10(FUN_002672f0((*(hulk_uintptr*)&DAT_004ca294), 0, 0), &count);
    value = count;
    vfunc_4(extra, param);
    param->vfunc_17();
    return true;
}


// 0x00236d10 fight::TrackFactory::vfunc_2 (36 B): matches/0x00236d10.cpp
// sym: ?vfunc_5@TrackFactory_236d10@fn_f5a78e74@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TrackFactory_236d10* TrackFactory_236d10::vfunc_5(signed char flags) {
    *(void***)this = Entity_236d10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00236d40 FUN_00236d40 (17 B): matches/0x00236d40.cpp
// sym: ??0Track_236d40@fn_f5a78e74@@QAE@XZ
// Same code shape as 0x0008c7f0 (propagated; names are from that function)
Track_236d40::Track_236d40() {
    a = 0;
    b = 0;
}


// 0x00236d60 FUN_00236d60 (38 B): matches/0x00236d60.cpp
// sym: ??1Track_236d60@fn_f5a78e74@@UAE@XZ
// Same code shape as 0x002345b0 (propagated; names are from that function)
Track_236d60::~Track_236d60() {
    if (mRef)
        mRef->Release(1);
    mRef = 0;
    FUN_00234210(this);
}

} // namespace fn_f5a78e74

// 0x00236d90 fight::Track::vfunc_5 (59 B): matches/0x00236d90.cpp [wrapped: conflict: Track]
// sym: ?v5@Track@fn_00236d90@@UAEPAV12@H@Z
namespace fn_00236d90 {
extern int Track_vftable;
class Param {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int);
};
class Track : public Param {
  public:
    virtual void v3();
    virtual void v4();
    virtual Track* v5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    void helper();
    Param* mThing;
};
void __cdecl thunk_FUN_00267090(Track*);
Track* Track::v5(int flag) {
    Param* p = mThing;
    *(void**)this = (void*)&Track_vftable;
    if (p)
        p->f(1);
    mThing = 0;
    helper();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00236d90

