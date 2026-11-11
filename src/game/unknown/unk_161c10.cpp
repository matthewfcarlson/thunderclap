// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00161c10..0x00163a90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f95ed483 {
#define TREE_TU_END }
namespace fn_f95ed483 {} using namespace fn_f95ed483;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_161d20 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply_002367c0(void*);
    void add_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_161d20*);
struct TrackFactoryCasterTemplate_161d50 {
    virtual void cast();
};
extern "C" void* __cdecl findTrack_00236ac0(void*, TrackFactoryCasterTemplate_161d50*);
} // namespace fn_f95ed483
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f95ed483 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class ClimbLocomotion4Track_161d80 {
public:
    void FUN_0015a8c0();
    void FUN_0015a8d0();
    void FUN_0015a8f0();
    void FUN_0015a910();
    void FUN_0015a930();
    void FUN_0015a950();
    void FUN_0015a970();
    void FUN_0015a990();
    void FUN_0015a9b0();
    void FUN_0015a9d0();
    void FUN_0015a9e0();
    void FUN_0015a9f0();
    void FUN_0015aa00();
    void FUN_0015aa10();
    void FUN_0015aa20();
    void FUN_0015aa30();
    void FUN_0015aa40();
    void FUN_0015aa50();
    void FUN_0015aa60();
    void FUN_0015aa70();
    void FUN_0015aa80();
    void FUN_0015aaa0();
    void FUN_0015aac0();
    void FUN_0015aae0();
};
} }
namespace fn_f95ed483 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamFloatConstRange_161d80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_161d80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_161d80 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_161d80(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_161d80 : public ParamNameBase {
public:
    ParamName_161d80(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class TrackFactoryCasterTemplate_162280 {
  public:
    virtual void f();
};
class Obj {
  public:
    void run_002367c0(void*);
    void use_002367c0(void*);
    void Do_002367c0(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_162280*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class LocomotionStrafe4Track_1622b0 {
public:
    void FUN_0015aaf0();
    void FUN_0015ab00();
    void FUN_0015ab20();
    void FUN_0015ab40();
    void FUN_0015ab70();
    void FUN_0015ab90();
    void FUN_0015abb0();
    void FUN_0015abd0();
    void FUN_0015abf0();
    void FUN_0015ac10();
    void FUN_0015ac30();
    void FUN_0015ac50();
    void FUN_0015ac60();
    void FUN_0015ac70();
    void FUN_0015ac80();
    void FUN_0015ac90();
    void FUN_0015aca0();
    void FUN_0015acb0();
    void FUN_0015acc0();
    void FUN_0015acd0();
    void FUN_0015ace0();
    void FUN_0015acf0();
    void FUN_0015ad00();
    void FUN_0015ad20();
    void FUN_0015ad40();
    void FUN_0015ad60();
};
} }
namespace fn_f95ed483 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamBool_1622b0 : public ParamBoolBase {
public:
    ParamBool_1622b0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_1622b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1622b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1622b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1622b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1622b0 : public ParamNameBase {
public:
    ParamName_1622b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_162820 {
  public:
    virtual void f();
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_162820*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class HeliLocomotionTrack_162850 {
public:
    void FUN_0015ad70();
    void FUN_0015ad80();
    void FUN_0015ada0();
    void FUN_0015adc0();
    void FUN_0015ade0();
    void FUN_0015ae10();
    void FUN_0015ae40();
    void FUN_0015ae70();
    void FUN_0015aea0();
    void FUN_0015aed0();
    void FUN_0015af00();
    void FUN_0015af20();
    void FUN_0015af40();
    void FUN_0015af70();
    void FUN_0015afa0();
    void FUN_0015afd0();
    void FUN_0015b000();
    void FUN_0015b030();
    void FUN_0015b060();
    void FUN_0015b080();
    void FUN_0015b0a0();
    void FUN_0015b0b0();
    void FUN_0015b0f0();
    void FUN_0015b140();
    void FUN_0015b180();
    void FUN_0015b1a0();
    void FUN_0015b1c0();
    void FUN_0015b1e0();
    void FUN_0015b1f0();
    void FUN_0015b210();
    void FUN_0015b220();
    void FUN_0015b250();
    void FUN_0015b270();
    void FUN_0015b290();
    void FUN_0015b2b0();
    void FUN_0015b2d0();
    void FUN_0015b310();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_162850 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_162850(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_162850 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_162850(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_162850 : public ParamNameBase {
public:
    ParamName_162850(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_162850 : public ParamVectorBase {
public:
    ParamVector_162850(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class LocomotionSteerTrack_163050 {
public:
    void FUN_0015b340();
    void FUN_0015b350();
    void FUN_0015b370();
    void FUN_0015b390();
    void FUN_0015b3c0();
    void FUN_0015b3e0();
    void FUN_0015b400();
    void FUN_0015b410();
    void FUN_0015b420();
    void FUN_0015b430();
    void FUN_0015b440();
    void FUN_0015b460();
    void FUN_0015b470();
    void FUN_0015b490();
    void FUN_0015b4b0();
    void FUN_0015b4d0();
};
} }
namespace fight {
template <class T>
class ParamBool_163050 : public ParamBoolBase {
public:
    ParamBool_163050(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_163050 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163050(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_163050 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163050(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_163050 : public ParamNameBase {
public:
    ParamName_163050(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_1633c0 {
  public:
    virtual void Cast();
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_1633c0*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class LocomotionSprintTrack_1633f0 {
public:
    void FUN_0015b4e0();
    void FUN_0015b4f0();
    void FUN_0015b510();
    void FUN_0015b530();
    void FUN_0015b560();
    void FUN_0015b590();
    void FUN_0015b5b0();
    void FUN_0015b5d0();
    void FUN_0015b5e0();
    void FUN_0015b5f0();
    void FUN_0015b600();
    void FUN_0015b610();
    void FUN_0015b620();
    void FUN_0015b640();
    void FUN_0015b660();
    void FUN_0015b680();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_1633f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1633f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1633f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1633f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1633f0 : public ParamNameBase {
public:
    ParamName_1633f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_163760 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Use_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_163760*);
class GrappleLocomotionSteerTrack {
public:
    void FUN_0015b690();
    void FUN_0015b6a0();
    void FUN_0015b6b0();
    void FUN_0015b6c0();
    void FUN_0015b6d0();
    void FUN_0015b6e0();
    void FUN_0015b6f0();
    void FUN_0015b710();
    void FUN_0015b730();
    void FUN_0015b750();
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamFloatConstRange_163790 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163790(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_163790 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163790(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_163790 : public ParamNameBase {
public:
    ParamName_163790(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f95ed483 {

// 0x00161d20 FUN_00161d20 (38 B): matches/0x00161d20.cpp
// sym: _FUN_00161d20
extern "C" void __cdecl FUN_00161d20(Owner* owner, void* source) {
    TrackFactoryCasterTemplate_161d20 caster;
    owner->Apply_002367c0(Find_00236ac0(source, &caster));
}


// 0x00161d50 FUN_00161d50 (38 B): matches/0x00161d50.cpp
// sym: _FUN_00161d50
extern "C" void FUN_00161d50(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_161d50 caster;
    owner->add_002367c0(findTrack_00236ac0(value, &caster));
}


// 0x00161d80 FUN_00161d80 (1276 B): equivalent/0x00161d80.cpp
// sym: _FUN_00161d80 @68530ae68429 @wef3428db2a01
// STATUS: equivalent (tools/equiv.py level 3: 1541 inputs, branch coverage 50/50)
// FUN_00161d80 @ 0x00161d80
extern "C" void FUN_00161d80()
{
    if (DAT_004e117c == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("timeBegin", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("timeEnd", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("acceleration", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowNorth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a910);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowStrafe", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a930);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowSouth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a950);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighNorth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a970);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighStrafe", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighSouth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("phase", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("locomotion", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animIdle", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animLowNorth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa00);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animLowEast", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa10);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animLowSouth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa20);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animLowWest", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa30);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animHighNorth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa40);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animHighEast", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa50);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animHighSouth", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa60);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("animHighWest", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa70);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamName_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("partition", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aa80);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("priority", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aaa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("blendInTime", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("blendOutTime", &hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aae0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1178), params, 24);
    }
    DAT_004e117c++;
}


// 0x00162280 FUN_00162280 (38 B): matches/0x00162280.cpp
// sym: _FUN_00162280
extern "C" void FUN_00162280(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_162280 c;
    void* v = find(p, &c);
    obj->run_002367c0(v);
}


// 0x001622b0 FUN_001622b0 (1378 B): equivalent/0x001622b0.cpp
// sym: _FUN_001622b0 @2a8c6c13a2f9 @w53e5b1ceaae2
// STATUS: equivalent (tools/equiv.py level 3: 1835 inputs, branch coverage 54/54)
// FUN_001622b0 @ 0x001622b0
extern "C" void FUN_001622b0()
{
    if (DAT_004e1184 == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeBegin", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015aaf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeEnd", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("acceleration", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("turningVelocity", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab40);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("steering", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkStrafe", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunStrafe", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("phase", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac50);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("locomotion", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac60);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animIdle", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac70);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkEast", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015aca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animWalkWest", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunNorth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunEast", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunSouth", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ace0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("animRunWest", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015acf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("partition", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamIntConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("priority", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendInTime", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendOutTime", &hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1180), params, 26);
    }
    DAT_004e1184++;
}


// 0x00162820 FUN_00162820 (38 B): matches/0x00162820.cpp
// sym: _FUN_00162820
extern "C" void FUN_00162820(Obj* o, void* p) {
    TrackFactoryCasterTemplate_162820 c;
    o->use_002367c0(Find_00236ac0(p, &c));
}


// 0x00162850 FUN_00162850 (1987 B): equivalent/0x00162850.cpp
// sym: _FUN_00162850 @a882f7957c12 @w2bb2896898a4
// STATUS: equivalent (tools/equiv.py level 3: 1031 inputs, branch coverage 76/76)
// FUN_00162850 @ 0x00162850
extern "C" void FUN_00162850()
{
    if (DAT_004e118c == 0) {
        void* params[37];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("timeBegin", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ad70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("timeEnd", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ad80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("acceleration", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ada0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("velocity", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015adc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("turnAcceleration", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ade0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("turnVelocity", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDesiredAtRest", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDesiredAtMaxSpeed", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMin", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015aea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMax", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015aed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMomentOfInertia", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXSpringConstant", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDampingConstant", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXInertiaPoint", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDesiredAtRest", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015afa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDesiredAtMaxSpeed", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015afd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMin", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMax", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMomentOfInertia", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZSpringConstant", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDampingConstant", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZInertiaPoint", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("minimum", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("maximum", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b140);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamIntConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("priority", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("blendInTime", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("blendOutTime", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpSmoothingConstant", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamName_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpJoint", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpRayLength", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b210);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpOffset", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b220);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpVelocity", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b250);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpBoostAcceleration", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b270);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpBoostXMax", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b290);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDecay", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b2b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDecayCutOff", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b2d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDifference", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b310);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1188), params, 37);
    }
    DAT_004e118c++;
}

} // namespace fn_f95ed483

// 0x00163020 FUN_00163020 (38 B): matches/0x00163020.cpp [wrapped: conflict: Find]
// sym: _FUN_00163020
namespace fn_00163020 {
class TrackFactoryCasterTemplate_163020 {
  public:
    virtual void cast();
};
class Track {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_163020*);
extern "C" void __cdecl FUN_00163020(Track* t, const char* name) {
    TrackFactoryCasterTemplate_163020 caster;
    t->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_00163020

namespace fn_f95ed483 {

// 0x00163050 FUN_00163050 (868 B): equivalent/0x00163050.cpp
// sym: _FUN_00163050 @2bc90ccf23a6 @wac5a40abe1c4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_00163050 @ 0x00163050
extern "C" void FUN_00163050()
{
    if ((*(int*)&DAT_004e1194) == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeBegin", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b340);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeEnd", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b350);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("acceleration", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b370);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("turningVelocity", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b390);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityWalk", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityRun", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("phase", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b400);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("locomotion", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b410);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animIdle", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b420);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animWalk", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b430);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animRun", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b440);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_163050<hulkfight::motion::LocomotionSteerTrack_163050>("locomoting", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b460);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("partition", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b470);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("priority", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b490);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendInTime", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendOutTime", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1190), params, 16);
    }
    (*(int*)&DAT_004e1194)++;
}


// 0x001633c0 FUN_001633c0 (38 B): matches/0x001633c0.cpp
// sym: _FUN_001633c0
extern "C" void FUN_001633c0(Obj* obj, void* value) {
    TrackFactoryCasterTemplate_1633c0 c;
    void* p = Find_00236ac0(value, &c);
    obj->Do_002367c0(p);
}


// 0x001633f0 FUN_001633f0 (868 B): equivalent/0x001633f0.cpp
// sym: _FUN_001633f0 @b94080f100b1 @w070ec1580014
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_001633f0 @ 0x001633f0
extern "C" void FUN_001633f0()
{
    if ((*(int*)&DAT_004e119c) == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeBegin", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeEnd", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("velocity", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b510);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnVelocity", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b530);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnAcceleration", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b560);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanThreshold", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanRate", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("phase", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("locomotion", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animRun", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animLeanEast", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b600);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animLeanWest", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b610);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("partition", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b620);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("priority", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b640);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendInTime", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b660);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendOutTime", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b680);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1198), params, 16);
    }
    (*(int*)&DAT_004e119c)++;
}


// 0x00163760 FUN_00163760 (38 B): matches/0x00163760.cpp
// sym: _FUN_00163760
extern "C" void FUN_00163760(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_163760 caster;
    void* result = Find_00236ac0(value, &caster);
    receiver->Use_002367c0(result);
}


// 0x00163790 FUN_00163790 (562 B): equivalent/0x00163790.cpp
// sym: _FUN_00163790 @7a294fdece25 @w847b3a77abbb
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_00163790 @ 0x00163790
extern "C" void FUN_00163790()
{
    if (DAT_004e11a4 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeBegin", &GrappleLocomotionSteerTrack::FUN_0015b690);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeEnd", &GrappleLocomotionSteerTrack::FUN_0015b6a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163790<GrappleLocomotionSteerTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("locomotion", &GrappleLocomotionSteerTrack::FUN_0015b6b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163790<GrappleLocomotionSteerTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animIdle", &GrappleLocomotionSteerTrack::FUN_0015b6c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163790<GrappleLocomotionSteerTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animWalk", &GrappleLocomotionSteerTrack::FUN_0015b6d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163790<GrappleLocomotionSteerTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animRun", &GrappleLocomotionSteerTrack::FUN_0015b6e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163790<GrappleLocomotionSteerTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("partition", &GrappleLocomotionSteerTrack::FUN_0015b6f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_163790<GrappleLocomotionSteerTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_163790<GrappleLocomotionSteerTrack>("priority", &GrappleLocomotionSteerTrack::FUN_0015b710);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendInTime", &GrappleLocomotionSteerTrack::FUN_0015b730);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendOutTime", &GrappleLocomotionSteerTrack::FUN_0015b750);
        FUN_002347b0(((ParamRegistry*)&DAT_004e11a0), params, 10);
    }
    DAT_004e11a4++;
}

} // namespace fn_f95ed483

// 0x00163a20 FUN_00163a20 (111 B): matches/0x00163a20.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00163a20
namespace fn_00163a20 {
// FUN_00163a20 @ 0x00163a20
namespace hulkfight { namespace motion { class PhaseCondition; class JointPlantedCondition; class LocomotingCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_163a20 { void FUN_00236760(void *factory); };
extern "C" void *__cdecl FUN_002343e0(const char *name, void *caster);

extern "C" void __cdecl FUN_00163a20(Registry_163a20 *r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition> caster;
        r->FUN_00236760(FUN_002343e0("phase", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition> caster;
        r->FUN_00236760(FUN_002343e0("jointPlanted", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition> caster;
        r->FUN_00236760(FUN_002343e0("locomoting", &caster));
    }
}
} // namespace fn_00163a20

