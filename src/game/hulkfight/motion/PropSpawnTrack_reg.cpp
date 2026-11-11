// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001899a0..0x0018b4e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6684e61 {
#define TREE_TU_END }
namespace fn_f6684e61 {} using namespace fn_f6684e61;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_189f30 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_189f30*);
class TrackFactoryCasterTemplate_18a0d0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply_002367c0(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_18a0d0*);
} // namespace fn_f6684e61
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f6684e61 {
void* FUN_0008d690(unsigned int size);
class PropAnimationTrack {
public:
    void FUN_0017f7c0();
    void FUN_0017f7d0();
    void FUN_0017f7f0();
    void FUN_0017f800();
    void FUN_0017f820();
    void FUN_0017f840();
    void FUN_0017f860();
    void FUN_0017f880();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class TrackFactoryCasterTemplate_18a310 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set_002367c0(void*);
    void Add_002367c0(Track*);
};
void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a310*);
} // namespace fn_f6684e61
namespace hulkfight { namespace motion {
class PropThrowTrack_18a340 {
public:
    void FUN_0017f900();
    void FUN_0017f910();
    void FUN_0017f930();
    void FUN_0017f950();
    void FUN_0017f980();
    void FUN_0017f9b0();
    void FUN_0017f9d0();
    void FUN_0017f9f0();
    void FUN_0017fa10();
    void FUN_0017fa30();
    void FUN_0017fa60();
    void FUN_0017fa90();
    void FUN_0017fac0();
    void FUN_0017faf0();
    void FUN_0017fb10();
    void FUN_0017fb30();
    void FUN_0017fb60();
    void FUN_0017fb80();
    void FUN_0017fba0();
    void FUN_0017fbc0();
    void FUN_0017fbe0();
    void FUN_0017fbf0();
    void FUN_0017fc00();
    void FUN_0017fc20();
};
} }
namespace fn_f6684e61 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
} // namespace fn_f6684e61
namespace fight {
template <class T>
class ParamBool_18a340 : public ParamBoolBase {
public:
    ParamBool_18a340(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBranch_18a340 : public ParamBranchBase {
public:
    ParamBranch_18a340(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_18a340 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a340(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18a340 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a340(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18a340 : public ParamNameBase {
public:
    ParamName_18a340(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18a340 : public ParamVectorBase {
public:
    ParamVector_18a340(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class BallAndChainReturnTrack_18a870 {
public:
    void FUN_0017fc30();
    void FUN_0017fc40();
    void FUN_0017fc60();
    void FUN_0017fc80();
    void FUN_0017fca0();
    void FUN_0017fcc0();
    void FUN_0017fcf0();
    void FUN_0017fd10();
    void FUN_0017fd40();
    void FUN_0017fd80();
    void FUN_0017fda0();
    void FUN_0017fdd0();
    void FUN_0017fdf0();
    void FUN_0017fe20();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_18a870 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a870(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18a870 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a870(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18a870 : public ParamNameBase {
public:
    ParamName_18a870(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f6684e61
namespace fight {
template <class T>
class ParamNameConstList_18a870 : public ParamNameConstListBase {
public:
    ParamNameConstList_18a870(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18a870 : public ParamVectorBase {
public:
    ParamVector_18a870(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_18ab70 {
  public:
    virtual void Cast();
};
class Host {
  public:
    void Set_002367c0(void*);
};
extern "C" void* __cdecl Lookup(void*, TrackFactoryCasterTemplate_18ab70*);
} // namespace fn_f6684e61
namespace hulkfight { namespace motion {
class BallAndChainShootTrack_18abd0 {
public:
    void FUN_0017fe90();
    void FUN_0017fea0();
    void FUN_0017fec0();
    void FUN_0017fef0();
    void FUN_0017ff30();
    void FUN_0017ff70();
    void FUN_0017ffa0();
    void FUN_0017ffc0();
    void FUN_0017ffe0();
    void FUN_00180000();
    void FUN_00180020();
    void FUN_00180050();
    void FUN_00180080();
    void FUN_001800b0();
    void FUN_001800c0();
    void FUN_001800f0();
    void FUN_00180110();
    void FUN_00180150();
    void FUN_00180190();
    void FUN_001801b0();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_18abd0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_18abd0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_18abd0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18abd0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18abd0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18abd0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18abd0 : public ParamNameBase {
public:
    ParamName_18abd0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_18abd0 : public ParamNameConstListBase {
public:
    ParamNameConstList_18abd0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18abd0 : public ParamVectorBase {
public:
    ParamVector_18abd0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_18b050 {
  public:
    virtual void Cast();
};
void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b050*);
class TrackFactoryCasterTemplate_18b080 {
  public:
    virtual void cast();
};
extern void* findTrack_00236ac0(int, TrackFactoryCasterTemplate_18b080*);
class Holder {
  public:
    void put_002367c0(void*);
};
class TrackFactoryCasterTemplate_18b0e0 {
  public:
    virtual void Cast();
    TrackFactoryCasterTemplate_18b0e0() {}
};
Track* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18b0e0*);
class TrackFactoryCasterTemplate_18b110 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void* Do_002367c0(void*);
    void* Set_002367c0(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b110*);
class PropSpawnTrack {
public:
    void FUN_00180430();
    void FUN_00181670();
    void FUN_00180450();
    void FUN_00180480();
    void FUN_001804c0();
    void FUN_00180520();
    void FUN_00180560();
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class TrackFactoryCasterTemplate_18b2e0 {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b2e0*);

} // namespace fn_f6684e61

// 0x001899a0 fight::ParamNameConstList<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x001899a0.cpp
// sym: ??_G?$ParamNameConstList@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::PropSpawnTrack>::~ParamNameConstList() {}

namespace fn_f6684e61 {

// 0x00189f30 FUN_00189f30 (38 B): matches/0x00189f30.cpp
// sym: _FUN_00189f30
extern "C" void FUN_00189f30(Obj* o, void* p) {
    TrackFactoryCasterTemplate_189f30 c;
    o->Apply_002367c0(Find(p, &c));
}

} // namespace fn_f6684e61

// 0x00189f60 FUN_00189f60 (38 B): matches/0x00189f60.cpp [wrapped: conflict: Find]
// sym: _FUN_00189f60
namespace fn_00189f60 {
class TrackFactoryCasterTemplate_189f60 {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Do_002367c0(void*);
};
extern void* Find_00236ac0(int, TrackFactoryCasterTemplate_189f60*);
extern "C" int FUN_00189f60(Obj* obj, int name) {
    TrackFactoryCasterTemplate_189f60 c;
    return obj->Do_002367c0(Find_00236ac0(name, &c));
}
} // namespace fn_00189f60


// 0x0018a070 FUN_0018a070 (38 B): matches/0x0018a070.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a070
namespace fn_0018a070 {
class TrackFactoryCasterTemplate_18a070 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Attach_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_18a070*);
extern "C" void FUN_0018a070(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a070 c;
    owner->Attach_002367c0(Find_00236ac0(name, &c));
}
} // namespace fn_0018a070


// 0x0018a0a0 FUN_0018a0a0 (38 B): matches/0x0018a0a0.cpp [wrapped: conflict: Owner]
// sym: _FUN_0018a0a0
namespace fn_0018a0a0 {
class TrackFactoryCasterTemplate_18a0a0 {
  public:
    virtual void* Cast(void*);
};
class Owner {
  public:
    void* Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a0a0*);
extern "C" void* __cdecl FUN_0018a0a0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a0a0 c;
    return owner->Add_002367c0(FUN_00236ac0(name, &c));
}
} // namespace fn_0018a0a0

namespace fn_f6684e61 {

// 0x0018a0d0 FUN_0018a0d0 (38 B): matches/0x0018a0d0.cpp
// sym: _FUN_0018a0d0
extern "C" void FUN_0018a0d0(Track* track, void* name) {
    TrackFactoryCasterTemplate_18a0d0 caster;
    track->apply_002367c0(find(name, &caster));
}


// 0x0018a100 FUN_0018a100 (476 B): equivalent/0x0018a100.cpp
// sym: _FUN_0018a100
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_0018a100 @ 0x0018a100
extern "C" void FUN_0018a100()
{
    if (DAT_004e148c == 0) {
        void* params[8];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropAnimationTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PropAnimationTrack>("timeBegin", &PropAnimationTrack::FUN_0017f7c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropAnimationTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<PropAnimationTrack>("timeEnd", &PropAnimationTrack::FUN_0017f7d0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<PropAnimationTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<PropAnimationTrack>("attachmentIndex", &PropAnimationTrack::FUN_0017f7f0);
        mem = FUN_0008d690((int)sizeof(ParamName<PropAnimationTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamName<PropAnimationTrack>("animation", &PropAnimationTrack::FUN_0017f800);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropAnimationTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<PropAnimationTrack>("speed", &PropAnimationTrack::FUN_0017f820);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropAnimationTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<PropAnimationTrack>("startFrame", &PropAnimationTrack::FUN_0017f840);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropAnimationTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<PropAnimationTrack>("endFrame", &PropAnimationTrack::FUN_0017f860);
        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<PropAnimationTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamEnumConstList<PropAnimationTrack>("cyclic", ((char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &PropAnimationTrack::FUN_0017f880);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1488), params, 8);
    }
    DAT_004e148c++;
}

} // namespace fn_f6684e61

// 0x0018a2e0 FUN_0018a2e0 (38 B): matches/0x0018a2e0.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a2e0
namespace fn_0018a2e0 {
class TrackFactoryCasterTemplate_18a2e0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_18a2e0*);
extern "C" void FUN_0018a2e0(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_18a2e0 c;
    obj->Apply_002367c0(Find_00236ac0(p, &c));
}
} // namespace fn_0018a2e0

namespace fn_f6684e61 {

// 0x0018a310 FUN_0018a310 (38 B): matches/0x0018a310.cpp
// sym: _FUN_0018a310
extern "C" void FUN_0018a310(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a310 c;
    void* p = FUN_00236ac0(name, &c);
    owner->Set_002367c0(p);
}


// 0x0018a340 FUN_0018a340 (1276 B): equivalent/0x0018a340.cpp
// sym: _FUN_0018a340
// STATUS: equivalent (tools/equiv.py level 3: 1986 inputs, branch coverage 50/50)
// FUN_0018a340 @ 0x0018a340
extern "C" void FUN_0018a340()
{
    if (DAT_004e149c == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("timeBegin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("timeEnd", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f910);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("attachmentIndex", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f930);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>("useCameraDirection", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f950);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_18a340<hulkfight::motion::PropThrowTrack_18a340>("direction", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("distanceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("distanceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("velocityMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("velocityMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("spinMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("spinMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("trackingMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("trackingMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("bounceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017faf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("bounceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("yFixupAngle", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("forceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("forceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("damageMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("damageMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("interruptPriority", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBranch_18a340<hulkfight::motion::PropThrowTrack_18a340>("hitBranch", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_18a340<hulkfight::motion::PropThrowTrack_18a340>("hitEffect", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fc00);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>("clearCharge", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fc20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1498), params, 24);
    }
    DAT_004e149c++;
}

} // namespace fn_f6684e61

// 0x0018a840 FUN_0018a840 (38 B): matches/0x0018a840.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a840
namespace fn_0018a840 {
class TrackFactoryCasterTemplate_18a840 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_18a840*);
extern "C" void __cdecl FUN_0018a840(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_18a840 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->Set_002367c0(p);
}
} // namespace fn_0018a840

namespace fn_f6684e61 {

// 0x0018a870 FUN_0018a870 (766 B): equivalent/0x0018a870.cpp
// sym: _FUN_0018a870
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0018a870 @ 0x0018a870
extern "C" void FUN_0018a870()
{
    if (DAT_004e14a4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("timeBegin", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("timeEnd", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("attachmentIndex", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("initVelocity", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("acceleration", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("tracking", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fcc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("targetYOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fcf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("minDistance", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd10);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("offset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("propAxis", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fd80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamEffect", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fda0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fdd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamNameConstList_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamAttachJoint", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fdf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector_18a870<hulkfight::motion::BallAndChainReturnTrack_18a870>("beamAttachJointOffset", &hulkfight::motion::BallAndChainReturnTrack_18a870::FUN_0017fe20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14a0), params, 14);
    }
    DAT_004e14a4++;
}


// 0x0018ab70 FUN_0018ab70 (38 B): matches/0x0018ab70.cpp
// sym: _FUN_0018ab70
extern "C" void __cdecl FUN_0018ab70(Host* host, void* key) {
    TrackFactoryCasterTemplate_18ab70 caster;
    void* result = Lookup(key, &caster);
    host->Set_002367c0(result);
}

} // namespace fn_f6684e61

// 0x0018aba0 FUN_0018aba0 (38 B): matches/0x0018aba0.cpp [wrapped: conflict: Find]
// sym: _FUN_0018aba0
namespace fn_0018aba0 {
class TrackFactoryCasterTemplate_18aba0 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_18aba0*);
extern "C" void __cdecl FUN_0018aba0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_18aba0 caster;
    owner->Add_002367c0(Find_00236ac0(key, &caster));
}
} // namespace fn_0018aba0

namespace fn_f6684e61 {

// 0x0018abd0 FUN_0018abd0 (1090 B): equivalent/0x0018abd0.cpp
// sym: _FUN_0018abd0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 42/42)
// FUN_0018abd0 @ 0x0018abd0
extern "C" void FUN_0018abd0()
{
    if (DAT_004e14b4 == 0) {
        void* params[20];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("timeBegin", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017fe90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("timeEnd", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017fea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("attachmentIndex", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017fec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("initPosition", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017fef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("direction", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017ff30);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("propAxis", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017ff70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("distanceMin", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017ffa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("distanceMax", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017ffc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("velocityMin", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_0017ffe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("velocityMax", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("trackingMin", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180020);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("trackingMax", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180050);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("yFixupAngle", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("targetYOffset", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_001800b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("beamEffect", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_001800c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("beamOffset", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_001800f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamNameConstList_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("beamAttachJoint", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180110);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamVector_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("beamAttachJointOffset", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180150);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamEnumConstList_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("damageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_00180190);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_18abd0<hulkfight::motion::BallAndChainShootTrack_18abd0>("damageScale", &hulkfight::motion::BallAndChainShootTrack_18abd0::FUN_001801b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14b0), params, 20);
    }
    DAT_004e14b4++;
}

} // namespace fn_f6684e61

// 0x0018b020 FUN_0018b020 (38 B): matches/0x0018b020.cpp [wrapped: conflict: Find]
// sym: _FUN_0018b020
namespace fn_0018b020 {
class TrackFactoryCasterTemplate_18b020 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Fn_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_18b020*);
extern "C" void FUN_0018b020(Receiver* receiver, void* name) {
    TrackFactoryCasterTemplate_18b020 caster;
    receiver->Fn_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0018b020

namespace fn_f6684e61 {

// 0x0018b050 FUN_0018b050 (38 B): matches/0x0018b050.cpp
// sym: _FUN_0018b050
extern "C" void __cdecl FUN_0018b050(Owner* owner, void* item) {
    TrackFactoryCasterTemplate_18b050 caster;
    void* p = FUN_00236ac0(item, &caster);
    owner->Set_002367c0(p);
}


// 0x0018b080 FUN_0018b080 (38 B): matches/0x0018b080.cpp
// sym: _FUN_0018b080
extern "C" void FUN_0018b080(Holder* h, int n) {
    TrackFactoryCasterTemplate_18b080 c;
    void* p = findTrack_00236ac0(n, &c);
    h->put_002367c0(p);
}

} // namespace fn_f6684e61

// 0x0018b0b0 FUN_0018b0b0 (38 B): matches/0x0018b0b0.cpp [wrapped: conflict: Lookup]
// sym: _FUN_0018b0b0
namespace fn_0018b0b0 {
class TrackFactoryCasterTemplate_18b0b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Lookup_00236ac0(void*, TrackFactoryCasterTemplate_18b0b0*);
extern "C" void FUN_0018b0b0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_18b0b0 caster;
    void* result = Lookup_00236ac0(name, &caster);
    owner->Add_002367c0(result);
}
} // namespace fn_0018b0b0

namespace fn_f6684e61 {

// 0x0018b0e0 FUN_0018b0e0 (38 B): matches/0x0018b0e0.cpp
// sym: _FUN_0018b0e0
extern "C" void FUN_0018b0e0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18b0e0 caster;
    owner->Add_002367c0(FUN_00236ac0(name, &caster));
}


// 0x0018b110 FUN_0018b110 (38 B): matches/0x0018b110.cpp
// sym: _FUN_0018b110
extern "C" void* FUN_0018b110(Target* t, void* name) {
    TrackFactoryCasterTemplate_18b110 c;
    void* p = FUN_00236ac0(name, &c);
    return t->Do_002367c0(p);
}


// 0x0018b140 FUN_0018b140 (409 B): equivalent/0x0018b140.cpp
// sym: _FUN_0018b140
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_0018b140 @ 0x0018b140
extern "C" void FUN_0018b140()
{
    if (DAT_004e14e4 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PropSpawnTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PropSpawnTrack>("timeBegin", &PropSpawnTrack::FUN_00180430);
        mem = FUN_0008d690((int)sizeof(ParamString<PropSpawnTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamString<PropSpawnTrack>("propName", &PropSpawnTrack::FUN_00181670);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<PropSpawnTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<PropSpawnTrack>("joint", &PropSpawnTrack::FUN_00180450);
        mem = FUN_0008d690((int)sizeof(ParamVector<PropSpawnTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<PropSpawnTrack>("offset", &PropSpawnTrack::FUN_00180480);
        mem = FUN_0008d690((int)sizeof(ParamVector<PropSpawnTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<PropSpawnTrack>("orient", &PropSpawnTrack::FUN_001804c0);
        mem = FUN_0008d690((int)sizeof(ParamVector<PropSpawnTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamVector<PropSpawnTrack>("impulse", &PropSpawnTrack::FUN_00180520);
        mem = FUN_0008d690((int)sizeof(ParamVector<PropSpawnTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamVector<PropSpawnTrack>("impulseOffset", &PropSpawnTrack::FUN_00180560);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14e0), params, 7);
    }
    DAT_004e14e4++;
}


// 0x0018b2e0 FUN_0018b2e0 (38 B): matches/0x0018b2e0.cpp
// sym: _FUN_0018b2e0
extern "C" void* __cdecl FUN_0018b2e0(Target* target, void* arg) {
    TrackFactoryCasterTemplate_18b2e0 caster;
    void* p = FUN_00236ac0(arg, &caster);
    return target->Set_002367c0(p);
}

} // namespace fn_f6684e61

// 0x0018b310 FUN_0018b310 (451 B): matches/0x0018b310.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0018b310
namespace fn_0018b310 {
namespace hulkfight {
namespace motion {
class PropMissionCriticalCondition;
class SmartPropGrabbableCondition;
class GrapplePropStateByNameCondition;
class PropGrabbableIsThrownCondition;
class PropMassCondition;
class PropAtRestCondition;
class PropIsAttachedCondition;
class PropStateByNameCondition;
class PropStateByIndexCondition;
class PropMissileCountCondition;
class PropCollidedWithWorldCondition;
class SmartPropIsCargoCondition;
class CSMPropIsCharacterCondition;
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void create();
    virtual void cast();
    virtual void other();
};
} // namespace fight
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
struct Registry_18b310 {
    void* FUN_00236760(void*);
};
extern "C" void* __cdecl FUN_0018b310(Registry_18b310* registry) {
    using namespace hulkfight::motion;
    {
        fight::ConditionFactoryCasterTemplate<PropAtRestCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propAtRest", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByIndexCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByIndex", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<GrapplePropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grapplePropStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropIsAttachedCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propIsAttached", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSMPropIsCharacterCondition> caster;
        registry->FUN_00236760(FUN_002343e0("csmPropIsCharacter", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropIsCargoCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropIsCargo", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropGrabbableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropGrabbable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropCollidedWithWorldCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propCollidedWithWorld", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissileCountCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissileCount", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropGrabbableIsThrownCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propGrabbableIsThrown", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissionCriticalCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissionCritical", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMassCondition> caster;
        return registry->FUN_00236760(FUN_002343e0("propMass", &caster));
    }
}
} // namespace fn_0018b310

