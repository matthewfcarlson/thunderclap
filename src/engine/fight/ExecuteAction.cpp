// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002393a0..0x00239d50 (kind game, layer engine, confidence high), dominant class fight::ExecuteAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd5a1171 {
#define TREE_TU_END }
namespace fn_fd5a1171 {} using namespace fn_fd5a1171;
namespace fn_fd5a1171 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fd5a1171 {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c38;
class CCondition_239420 {
  public:
    virtual int vfunc_0(int);
};
class Track_239430 {
  public:
    virtual void Dummy();
    Track_239430();
    char pad[8];
};
class A {
  public:
    A();
    char bytes[12];
};
class B {
  public:
    B();
};
class ExecuteTrack_239430 : public Track_239430 {
  public:
    virtual void Dummy();
    ExecuteTrack_239430();
    int x;
    float y;
    A a;
    int z;
    B b;
};
struct Param_239480 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_239480 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_00428418[];
struct SubA_239490 {
    void Fin_00236fd0() throw();
};
struct SubB_239490 {
    void Fin_00234150() throw();
};
class Track_239490 {
  public:
    void* vptr;
    ~Track_239490() throw();
};
class ExecuteTrack_239490 : public Track_239490 {
  public:
    char pad[0x14 - 4];
    SubB_239490 b;
    char pad2[0x24 - 0x14 - 1];
    SubA_239490 a;
    ~ExecuteTrack_239490() throw();
};
class Action_239770 {
    char x[0x38];
};
class Base_239770 {
  public:
    void vfunc_00232240();
};
class ExecuteAction : public Action_239770, public Base_239770 {
  public:
    void vfunc_4();
};
extern "C" char DAT_00428418[];
class ExecuteTrack {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual ExecuteTrack* vfunc_5(int);
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    char _m_pad_4[0x10];
    int field14;
    char _m_pad_18[0x8];
    int field20;
    char field24;
    char _m_pad_25[0xb];
    int vfunc_10(int a, int b, int c);
};
class A_239780 {
  public:
    void First_00236fd0();
};
class B_239780 {
  public:
    void Second_00234150();
};
class C_239780 {
  public:
    void Third_00236d60();
};
extern void __cdecl thunk_FUN_00267090(ExecuteTrack*);
struct Ref_2397c0 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_2397c0 {
    Action_2397c0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct S_2397c0 {
    S_2397c0() throw();
    char p[0x28];
};
struct ExecuteAction_2397c0 : Action_2397c0 {
    Ref_2397c0* m1c;
    hulk_intptr m20;
    Ref_2397c0* m24;
    int m28;
    Ref_2397c0* m2c;
    Ref_2397c0* m30;
    Ref_2397c0* m34;
    S_2397c0 s;
    int m60;
    char m64;
    ExecuteAction_2397c0(Ref_2397c0* a, Ref_2397c0* b, Ref_2397c0* c, int d, Ref_2397c0* e, Ref_2397c0* f, Ref_2397c0* g);
    virtual void V0();
};
class Ref_239870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Part_239870 {
  public:
    void Fini_002325f0() throw();
};
struct Action_239870 {
    void* vf;
    void Dtor_002326a0() throw();
};
struct ExecuteAction_239870 : Action_239870 {
    char pad[0x18];
    Ref_239870* p1c;
    void* p20;
    Ref_239870* p24;
    char pad2[0xc];
    Ref_239870* p34;
    Part_239870 p38;
    void Dtor2() throw();
};
class CStageCondition_239910;
class ParamValue_239910 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_239910 : public ParamValue_239910 {
  public:
    int pad;
};
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_239990;
class ParamValue_239990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_239990 : public ParamValue_239990 {
  public:
    int pad;
};
extern int hulk_at_0049850c;
struct ExecuteAction_239bd0 {
    int FUN_002397c0(int, ExecuteTrack*, int, int, void*, int, int);
};
extern "C" ExecuteAction_239bd0* __cdecl FUN_0008d690(int);
extern char hulk_at_004284e4[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_239c50 {
    void Finish_002367c0(Track*);
};
} // namespace fn_fd5a1171
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd5a1171 {
class TrackFactoryTemplate_239c80 {
  public:
    TrackFactoryTemplate_239c80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00239a90();
} // namespace fn_fd5a1171
void* __cdecl operator new(size_t);
namespace fight {
class Base {
  public:
    Base() throw();
    virtual hulk_intptr Fna_00239420(int);
    virtual bool Fnb_00234270(void*);
    virtual bool Fnc_002342b0(int);
    virtual bool Fnd_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool Fne_00234350(int, int);
    virtual void* Fnf_00239780(int);
    char pad[8];
};
}
namespace fight {
class Sub {
  public:
    Sub() throw();
};
}
namespace fight {
class Tail {
  public:
    Tail() throw();
};
}
namespace fight {
class ExecuteTrack_239cc0 : public Base {
  public:
    ExecuteTrack_239cc0() throw() : fieldC(0), field10(-1.0f), field20(-1000) {}
    int fieldC;
    float field10;
    Sub sub;
    char pad2[11];
    int field20;
    Tail tail;
};
}
namespace fn_fd5a1171 {
extern int hulk_at_004284f0;

} // namespace fn_fd5a1171

// 0x002393a0 FUN_002393a0 (12 B): matches/0x002393a0.cpp
// sym: ?FUN_002393a0@Obj_2393a0@owners@@QAEDH@Z
char owners::Obj_2393a0::FUN_002393a0(int v) {
    mValue = v;
    return 1;
}


// 0x002393b0 FUN_002393b0 (12 B): matches/0x002393b0.cpp
// sym: ?FUN_002393b0@O_2393b0@owners@@QAEDH@Z
char owners::O_2393b0::FUN_002393b0(int x) {
    m = x;
    return 1;
}


// 0x002393c0 FUN_002393c0 (4 B): matches/0x002393c0.cpp
// sym: ?FUN_002393c0@X_2393c0@owners@@QAEPAPAHXZ
int** owners::X_2393c0::FUN_002393c0() {
    return &m;
}


// 0x002393e0 FUN_002393e0 (12 B): matches/0x002393e0.cpp
// sym: ?FUN_002393e0@O_2393e0@owners@@QAE_NH@Z
bool owners::O_2393e0::FUN_002393e0(int v) {
    *(int*)((char*)this + 0x20) = v;
    return true;
}


// 0x002393f0 FUN_002393f0 (4 B): matches/0x002393f0.cpp
// sym: ?FUN_002393f0@C_2393f0@owners@@QAEPADXZ
char* owners::C_2393f0::FUN_002393f0() {
    return (char*)((hulk_intptr)this + 0x24);
}

namespace fn_fd5a1171 {

// 0x00239400 FUN_00239400 (19 B): matches/0x00239400.cpp
// sym: ?FUN_00239400@fn_fd5a1171@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00239400() {
    FUN_00234810(((char*)&DAT_004e5c38), ((char*)&DAT_004e5c3c));
}

} // namespace fn_fd5a1171

// 0x00239420 fight::ExecuteTrack::vfunc_0 (16 B): matches/0x00239420.cpp
// sym: ?vfunc_0@ExecuteTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::ExecuteTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c38;
    return p[index];
}

namespace fn_fd5a1171 {

// 0x00239430 FUN_00239430 (55 B): matches/0x00239430.cpp
// sym: ??0ExecuteTrack_239430@fn_fd5a1171@@QAE@XZ
ExecuteTrack_239430::ExecuteTrack_239430() : x(0), y(-1.0f), z(-1000) {}

} // namespace fn_fd5a1171

// 0x00239470 fight::ExecuteTrack::vfunc_6 (4 B): matches/0x00239470.cpp
// sym: ?vfunc_6@ExecuteTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::ExecuteTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00239480 fight::ExecuteTrack::vfunc_7 (7 B): matches/0x00239480.cpp
// sym: ?vfunc_7@ExecuteTrack@fight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg fight::ExecuteTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fd5a1171 {

// 0x00239490 FUN_00239490 (33 B): matches/0x00239490.cpp
// sym: ??1ExecuteTrack_239490@fn_fd5a1171@@QAE@XZ
ExecuteTrack_239490::~ExecuteTrack_239490() throw() {
    vptr = hulk_at_00428418;
    a.Fin_00236fd0();
    b.Fin_00234150();
}

} // namespace fn_fd5a1171

// 0x002396f0 fight::ExecuteAction::vfunc_5 (120 B): matches/0x002396f0.cpp [wrapped: conflict: fight::ExecuteAction]
// sym: ?V5@ExecuteAction@fight@fn_002396f0@@UAEXIH@Z
namespace fn_002396f0 {
class Action {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5(unsigned int, int);
    int pad4[2];
    unsigned int flags;
    char pad10[0x28];
};
class Sub_2396f0 {
  public:
    void Init_002322f0(unsigned int, int);
    void Run_00231f20(unsigned int);
    bool Check_002324b0(int);
    void Finish_00231ee0();
};
namespace fight {
class ExecuteAction : public Action {
  public:
    Sub_2396f0 sub;
    char pad39[0x27];
    unsigned int mCount;
    unsigned char mFlag;
    void V5(unsigned int, int);
};
} // namespace fight
void fight::ExecuteAction::V5(unsigned int index, int arg) {
    if (index == 0 && !mFlag)
        sub.Init_002322f0(mCount, arg);
    mFlag = 0;
    sub.Run_00231f20(index);
    if (index == mCount - 1) {
        if (sub.Check_002324b0(0)) {
            flags &= 0xfffffffc;
            sub.Finish_00231ee0();
            return;
        }
        flags = (flags & 0xfffffffd) | 1;
    }
    sub.Finish_00231ee0();
}
} // namespace fn_002396f0

namespace fn_fd5a1171 {

// 0x00239770 fight::ExecuteAction::vfunc_4 (8 B): matches/0x00239770.cpp
// sym: ?vfunc_4@ExecuteAction@fn_fd5a1171@@QAEXXZ
void ExecuteAction::vfunc_4() {
    Base_239770::vfunc_00232240();
}


// 0x00239780 fight::ExecuteTrack::vfunc_5 (54 B): matches/0x00239780.cpp
// sym: ?vfunc_5@ExecuteTrack@fn_fd5a1171@@UAEPAV12@H@Z
ExecuteTrack* ExecuteTrack::vfunc_5(int flags) {
    ExecuteTrack* p = this;
    *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00428418);
    ((A_239780*)((char*)&p->field24))->First_00236fd0();
    ((B_239780*)((char*)&p->field14))->Second_00234150();
    ((C_239780*)p)->Third_00236d60();
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}


// 0x002397c0 FUN_002397c0 (167 B): matches/0x002397c0.cpp
// sym: ??0ExecuteAction_2397c0@fn_fd5a1171@@QAE@PAURef_2397c0@1@00H000@Z
ExecuteAction_2397c0::ExecuteAction_2397c0(Ref_2397c0* a, Ref_2397c0* b, Ref_2397c0* c, int d, Ref_2397c0* e, Ref_2397c0* f, Ref_2397c0* g)
    : m1c(0), m20(0), m24(0), m28(d), m2c(e), m30(f), m34(0) {
    m60 = 0;
    m64 = 0;
    if (a)
        a->AddRef();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = (hulk_intptr)b;
    if (c)
        c->AddRef();
    if (m24)
        m24->Release();
    m24 = c;
    if (g)
        g->AddRef();
    if (m34)
        m34->Release();
    m34 = g;
}


// 0x00239870 FUN_00239870 (82 B): matches/0x00239870.cpp
// sym: ?Dtor2@ExecuteAction_239870@fn_fd5a1171@@QAEXXZ
void ExecuteAction_239870::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p34) {
        p34->Release();
        p34 = 0;
    }
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    if (p20)
        p20 = 0;
    if (p1c) {
        p1c->Release();
        p1c = 0;
    }
    p38.Fini_002325f0();
    Action_239870::Dtor_002326a0();
}

} // namespace fn_fd5a1171

// 0x002398f0 fight::ParamFloatConstRange<fight::ExecuteTrack>::vfunc_6 (26 B): matches/0x002398f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VExecuteTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::ExecuteTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::ExecuteTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::ExecuteTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::ExecuteTrack>::**)(int))&this->f_10))(b);
}


// 0x00239910 fight::ParamFloatConstRange<fight::ExecuteTrack>::vfunc_2 (11 B): matches/0x00239910.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VExecuteTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::ExecuteTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fd5a1171 {

// 0x00239940 fight::ParamBranch<fight::ExecuteTrack>::vfunc_6 (12 B): matches/0x00239940.cpp
// sym: ?vfunc_6@ParamBranch@fn_fd5a1171@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fd5a1171

// 0x00239970 fight::ParamIntConstRange<fight::ExecuteTrack>::vfunc_6 (26 B): matches/0x00239970.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VExecuteTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::ExecuteTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<fight::ExecuteTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<fight::ExecuteTrack>*)a)->*(*(bool (fight::ParamIntConstRange<fight::ExecuteTrack>::**)(int))&this->f_10))(b);
}


// 0x00239990 fight::ParamIntConstRange<fight::ExecuteTrack>::vfunc_2 (11 B): matches/0x00239990.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VExecuteTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::ExecuteTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x002399c0 fight::ParamConditionGroup<fight::ExecuteTrack>::vfunc_6 (12 B): matches/0x002399c0.cpp [wrapped: same definition as 0x00239940 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_002399c0@@UAEXPAX@Z
namespace fn_002399c0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_002399c0


// 0x002399e0 fight::TrackFactoryCasterTemplate<fight::ExecuteTrack>::vfunc_0 (36 B): matches/0x002399e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VExecuteTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::ExecuteTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00239a10 fight::ParamFloatConstRange<fight::ExecuteTrack>::vfunc_0 (30 B): matches/0x00239a10.cpp
// sym: ??_G?$ParamFloatConstRange@VExecuteTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::ExecuteTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::ExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x239a10)
#endif


// 0x00239a30 fight::ParamBranch<fight::ExecuteTrack>::vfunc_0 (30 B): matches/0x00239a30.cpp
// sym: ??_G?$ParamBranch@VExecuteTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::ExecuteTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<fight::ExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x239a30)
#endif


// 0x00239a50 fight::ParamIntConstRange<fight::ExecuteTrack>::vfunc_0 (30 B): matches/0x00239a50.cpp
// sym: ??_G?$ParamIntConstRange@VExecuteTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<fight::ExecuteTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<fight::ExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x239a50)
#endif


// 0x00239a70 fight::ParamConditionGroup<fight::ExecuteTrack>::vfunc_0 (30 B): matches/0x00239a70.cpp
// sym: ??_G?$ParamConditionGroup@VExecuteTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::ExecuteTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<fight::ExecuteTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x239a70)
#endif

namespace fn_fd5a1171 {

// 0x00239bd0 fight::ExecuteTrack::vfunc_10 (64 B): matches/0x00239bd0.cpp
// sym: ?vfunc_10@ExecuteTrack@fn_fd5a1171@@QAEHHHH@Z
int ExecuteTrack::vfunc_10(int a, int b, int c) {
    ExecuteAction_239bd0* p = FUN_0008d690(0x68);
    int result;
    if (p) {
        int x = field20;
        int y = field14;
        result = p->FUN_002397c0(a, this, y, x, &field24, b, c);
    } else
        result = 0;
    return result;
}

} // namespace fn_fd5a1171

// 0x00239c10 fight::ExecuteAction::vfunc_2 (30 B): matches/0x00239c10.cpp
// sym: ??_GExecuteAction@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::ExecuteAction::~ExecuteAction() {}

namespace fn_fd5a1171 {

// 0x00239c50 FUN_00239c50 (38 B): matches/0x00239c50.cpp
// sym: _FUN_00239c50
extern "C" void FUN_00239c50(Receiver_239c50* c, int b) {
    Track t;
    *(void**)&t = hulk_at_004284e4;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish_002367c0(p);
}

} // namespace fn_fd5a1171

// 0x00239c80 fight::TrackFactoryCasterTemplate<fight::ExecuteTrack>::vfunc_1 (60 B): matches/0x00239c80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VExecuteTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::ExecuteTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_239c80));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_239c80* t = new (mem) TrackFactoryTemplate_239c80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00239a90();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00239cc0 fight::TrackFactoryTemplate<fight::ExecuteTrack>::vfunc_5 (75 B): matches/0x00239cc0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VExecuteTrack@fight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<fight::ExecuteTrack>::vfunc_5() {
    return (void*)(new ExecuteTrack_239cc0);
}

namespace fn_fd5a1171 {

// 0x00239d10 fight::TrackFactoryTemplate<fight::ExecuteTrack>::vfunc_2 (43 B): matches/0x00239d10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd5a1171@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004284f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd5a1171
