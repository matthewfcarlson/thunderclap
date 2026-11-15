// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0023d420..0x0023d810 (kind game, layer engine, confidence high), dominant class fight::DebugCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd383094 {
#define TREE_TU_END }
namespace fn_fd383094 {} using namespace fn_fd383094;
namespace fn_fd383094 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fd383094 {
class ConditionFactoryCasterTemplate_23d420 {
  public:
    virtual bool cast_0023d330(void*);
};
extern "C" void* Find(const char*, ConditionFactoryCasterTemplate_23d420*);
class Owner {
  public:
    void Apply_00236760(void*);
    void Set_00236760(void*);
};
class Obj_23d450 {
  public:
    char pad[0xc];
    int mValue;
    bool SetCompare_0023d450(int v);
};
class Obj_23d460 {
  public:
    char pad[0x10];
    int m10;
    bool SetMode_0023d460(int v);
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c54;
class CCondition_23d490 {
  public:
    virtual int vfunc_0(int);
};
class Condition_23d4e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int, int, int);
};
extern void* hulk_at_00428b64[];
class Condition_23d510 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class DebugCondition_23d510 : public Condition_23d510 {
  public:
    DebugCondition_23d510* vfunc_5(signed char flags);
};
struct CAxisArcCondition_23d570;
class CStageCondition_23d580 {};
class ParamValue_23d580 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_23d580 : public ParamValue_23d580 {
  public:
    virtual void f();
};
extern int hulk_at_00491ca8;
class ConditionFactoryCasterTemplate_23d710 {
  public:
    virtual bool Dummy_0023d5e0(void*);
};
extern "C" void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_23d710*);
extern "C" char DAT_00428b64[];
class Factory_23d780 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* V5();
    char pad[8];
    int m0c;
    int m10;
};
struct DebugCondition_nv_23d780 {
    void InitFn_00234590(int);
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_00428bc0;
struct ConditionFactoryTemplate_23d7c0 {
    void* m_vptr;
    void base1_dtor_0023d470();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};


// 0x0023d420 FUN_0023d420 (38 B): matches/0x0023d420.cpp
// sym: _FUN_0023d420
extern "C" void FUN_0023d420(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_23d420 caster;
    void* p = Find(name, &caster);
    owner->Apply_00236760(p);
}


// 0x0023d450 FUN_0023d450 (12 B): matches/0x0023d450.cpp
// sym: ?SetCompare_0023d450@Obj_23d450@fn_fd383094@@QAE_NH@Z
bool Obj_23d450::SetCompare_0023d450(int v) {
    mValue = v;
    return true;
}


// 0x0023d460 FUN_0023d460 (12 B): matches/0x0023d460.cpp
// sym: ?SetMode_0023d460@Obj_23d460@fn_fd383094@@QAE_NH@Z
bool Obj_23d460::SetMode_0023d460(int v) {
    m10 = v;
    return true;
}


// 0x0023d470 FUN_0023d470 (19 B): matches/0x0023d470.cpp
// sym: ?FUN_0023d470@fn_fd383094@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023d470(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e5c54), ((char*)&DAT_004e5c58));
}

} // namespace fn_fd383094

// 0x0023d490 fight::DebugCondition::vfunc_0 (16 B): matches/0x0023d490.cpp
// sym: ?vfunc_0@DebugCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::DebugCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c54;
    return p[index];
}


// 0x0023d4e0 fight::DebugCondition::vfunc_6 (44 B): matches/0x0023d4e0.cpp
// sym: ?vfunc_6@DebugCondition@fight@@UAE_NPAX00@Z
bool fight::DebugCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    switch (this->compare) {
    case 0:
        return this->mode == 2;
    case 1:
        return this->mode != 2;
    default:
        return false;
    }
}

namespace fn_fd383094 {

// 0x0023d510 fight::DebugCondition::vfunc_5 (36 B): matches/0x0023d510.cpp
// sym: ?vfunc_5@DebugCondition_23d510@fn_fd383094@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
DebugCondition_23d510* DebugCondition_23d510::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00428b64;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_fd383094

// 0x0023d570 fight::ParamEnumConstList<fight::DebugCondition>::vfunc_7 (6 B): matches/0x0023d570.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VDebugCondition@fight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<fight::DebugCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0023d580 fight::ParamEnumConstList<fight::DebugCondition>::vfunc_6 (30 B): matches/0x0023d580.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VDebugCondition@fight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<fight::DebugCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_23d580 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_23d580*)&DAT_003f335c));
}


// 0x0023d5a0 fight::ParamEnumConstList<fight::DebugCondition>::vfunc_8 (26 B): matches/0x0023d5a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VDebugCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::DebugCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<fight::DebugCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<fight::DebugCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<fight::DebugCondition>::**)(int))&this->f_18))(b);
}


// 0x0023d5c0 fight::ParamEnumConstList<fight::DebugCondition>::vfunc_2 (11 B): matches/0x0023d5c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VDebugCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::DebugCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0023d5e0 fight::ConditionFactoryCasterTemplate<fight::DebugCondition>::vfunc_0 (36 B): matches/0x0023d5e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VDebugCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::DebugCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023d610 fight::ParamEnumConstList<fight::DebugCondition>::vfunc_0 (30 B): matches/0x0023d610.cpp
// sym: ??_G?$ParamEnumConstList@VDebugCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<fight::DebugCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<fight::DebugCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23d610)
#endif

namespace fn_fd383094 {

// 0x0023d710 FUN_0023d710 (38 B): matches/0x0023d710.cpp
// sym: _FUN_0023d710
extern "C" void FUN_0023d710(Owner* owner, void* ptr) {
    ConditionFactoryCasterTemplate_23d710 caster;
    owner->Set_00236760(FUN_002343e0(ptr, &caster));
}


// 0x0023d780 fight::ConditionFactoryTemplate<fight::DebugCondition>::vfunc_5 (54 B): matches/0x0023d780.cpp
// sym: ?V5@Factory_23d780@fn_fd383094@@UAEPAXXZ
void* Factory_23d780::V5() {
    Factory_23d780* p = (Factory_23d780*)Alloc(0x14);
    if (p) {
        ((DebugCondition_nv_23d780*)(((fight::DebugCondition*)(((fight::DebugCondition*)p)))))->InitFn_00234590(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00428b64);
        p->m0c = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}


// 0x0023d7c0 fight::ConditionFactoryTemplate<fight::DebugCondition>::vfunc_2 (43 B): matches/0x0023d7c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_23d7c0@fn_fd383094@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_23d7c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428bc0;
    base1_dtor_0023d470();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd383094
