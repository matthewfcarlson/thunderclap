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
    virtual bool Cast_00160ed0(void*);
};
class Owner {
  public:
    void Apply_002367c0(void*);
    void add_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_161d20*);
struct TrackFactoryCasterTemplate_161d50 {
    virtual bool cast_00160f30(void*);
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
    bool FUN_0015a8c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a8d0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a8f0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a910(int); /* (unb4) as defined; address taken only */
    char FUN_0015a930(int); /* (unb4) as defined; address taken only */
    char FUN_0015a950(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a970(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a990(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a9b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a9d0(int); /* (unb4) as defined; address taken only */
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
    char FUN_0015aaa0(int); /* (unb4) as defined; address taken only */
    char FUN_0015aac0(int); /* (unb4) as defined; address taken only */
    char FUN_0015aae0(int); /* (unb4) as defined; address taken only */
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
    virtual bool Fnf_00160fb0(void*);
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
    bool FUN_0015aaf0(int); /* (unb4) as defined; address taken only */
    char FUN_0015ab00(int); /* (unb4) as defined; address taken only */
    char FUN_0015ab20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ab40(float); /* (unb4) as defined; address taken only */
    char FUN_0015ab70(char); /* (unb4) as defined; address taken only */
    char FUN_0015ab90(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abb0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abd0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac10(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac30(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac50(int); /* (unb4) as defined; address taken only */
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
    char FUN_0015ad20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ad40(int); /* (unb4) as defined; address taken only */
    char FUN_0015ad60(int); /* (unb4) as defined; address taken only */
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
    virtual bool Fnf_00161050(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_162820*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class HeliLocomotionTrack_162850 {
public:
    bool FUN_0015ad70(int); /* (unb4) as defined; address taken only */
    char FUN_0015ad80(int); /* (unb4) as defined; address taken only */
    char FUN_0015ada0(int); /* (unb4) as defined; address taken only */
    char FUN_0015adc0(int); /* (unb4) as defined; address taken only */
    char FUN_0015ade0(float); /* (unb4) as defined; address taken only */
    char FUN_0015ae10(float); /* (unb4) as defined; address taken only */
    char FUN_0015ae40(float); /* (unb4) as defined; address taken only */
    bool FUN_0015ae70(float); /* (unb4) as defined; address taken only */
    bool FUN_0015aea0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015aed0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015af00(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af40(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af70(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015afa0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015afd0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b000(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b030(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b060(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b080(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b0a0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b0b0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015b0f0(void*); /* (unb4) as defined; address taken only */
    char FUN_0015b140(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015b180(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b1a0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b1c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b1e0(int); /* (unb4) as defined; address taken only */
    void FUN_0015b1f0();
    bool FUN_0015b210(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b220(void*); /* (unb4) as defined; address taken only */
    char FUN_0015b250(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b270(int); /* (unb4) as defined; address taken only */
    char FUN_0015b290(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b2b0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b2d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b310(void*); /* (unb4) as defined; address taken only */
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
    char FUN_0015b340(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b350(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b370(int); /* (unb4) as defined; address taken only */
    char FUN_0015b390(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b3c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b3e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b400(int); /* (unb4) as defined; address taken only */
    void FUN_0015b410();
    void FUN_0015b420();
    void FUN_0015b430();
    void FUN_0015b440();
    char FUN_0015b460(char); /* (unb4) as defined; address taken only */
    void FUN_0015b470();
    char FUN_0015b490(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4d0(int); /* (unb4) as defined; address taken only */
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
    virtual int Cast_00161190(void*);
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_1633c0*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class LocomotionSprintTrack_1633f0 {
public:
    char FUN_0015b4e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4f0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b510(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b530(float); /* (unb4) as defined; address taken only */
    char FUN_0015b560(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b590(int); /* (unb4) as defined; address taken only */
    char FUN_0015b5b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b5d0(void*); /* (unb4) as defined; address taken only */
    void FUN_0015b5e0();
    void FUN_0015b5f0();
    void FUN_0015b600();
    void FUN_0015b610();
    void FUN_0015b620();
    bool FUN_0015b640(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b660(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b680(int); /* (unb4) as defined; address taken only */
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
    virtual bool Cast_00161210(void*);
};
class Receiver {
  public:
    void Use_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_163760*);
class GrappleLocomotionSteerTrack {
public:
    char FUN_0015b690(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b6a0(int); /* (unb4) as defined; address taken only */
    void FUN_0015b6b0();
    void FUN_0015b6c0();
    void FUN_0015b6d0();
    void FUN_0015b6e0();
    void FUN_0015b6f0();
    bool FUN_0015b710(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b730(int); /* (unb4) as defined; address taken only */
    char FUN_0015b750(int); /* (unb4) as defined; address taken only */
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
            params[0] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("timeBegin", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("timeEnd", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("acceleration", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowNorth", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a910);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowStrafe", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a930);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityLowSouth", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a950);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighNorth", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a970);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighStrafe", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("velocityHighSouth", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("phase", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015a9d0);
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
            params[21] = new (mem) fight::ParamIntConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("priority", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aaa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("blendInTime", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange_161d80<hulkfight::motion::ClimbLocomotion4Track_161d80>("blendOutTime", (void (hulkfight::motion::ClimbLocomotion4Track_161d80::*)())&hulkfight::motion::ClimbLocomotion4Track_161d80::FUN_0015aae0);
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
            params[0] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeBegin", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015aaf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("timeEnd", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("acceleration", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("turningVelocity", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab40);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("steering", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkNorth", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ab90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkStrafe", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityWalkSouth", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunNorth", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015abf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunStrafe", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("velocityRunSouth", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("phase", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ac50);
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
            params[23] = new (mem) fight::ParamIntConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("priority", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendInTime", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_1622b0<hulkfight::motion::LocomotionStrafe4Track_1622b0>("blendOutTime", (void (hulkfight::motion::LocomotionStrafe4Track_1622b0::*)())&hulkfight::motion::LocomotionStrafe4Track_1622b0::FUN_0015ad60);
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
            params[0] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("timeBegin", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ad70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("timeEnd", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ad80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("acceleration", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ada0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("velocity", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015adc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("turnAcceleration", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ade0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("turnVelocity", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDesiredAtRest", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDesiredAtMaxSpeed", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015ae70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMin", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015aea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMax", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015aed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXMomentOfInertia", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXSpringConstant", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXDampingConstant", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltXInertiaPoint", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015af70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDesiredAtRest", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015afa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDesiredAtMaxSpeed", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015afd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMin", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMax", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZMomentOfInertia", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZSpringConstant", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZDampingConstant", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("tiltZInertiaPoint", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("minimum", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("maximum", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b140);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamIntConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("priority", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("blendInTime", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("blendOutTime", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpSmoothingConstant", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamName_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpJoint", &hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b1f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpRayLength", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b210);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpOffset", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b220);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpVelocity", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b250);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpBoostAcceleration", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b270);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpBoostXMax", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b290);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDecay", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b2b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatConstRange_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDecayCutOff", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b2d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>));
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamVector_162850<hulkfight::motion::HeliLocomotionTrack_162850>("riseUpDifference", (void (hulkfight::motion::HeliLocomotionTrack_162850::*)())&hulkfight::motion::HeliLocomotionTrack_162850::FUN_0015b310);
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
    virtual bool cast_001610f0(void*);
};
class Track {
  public:
    void Set_002367c0(void*);
};
extern "C++" void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_163020*);
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
            params[0] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeBegin", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b340);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeEnd", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b350);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("acceleration", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b370);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("turningVelocity", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b390);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityWalk", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityRun", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("phase", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b400);
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
            params[11] = new (mem) fight::ParamBool_163050<hulkfight::motion::LocomotionSteerTrack_163050>("locomoting", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b460);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("partition", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b470);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("priority", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b490);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendInTime", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendOutTime", (void (hulkfight::motion::LocomotionSteerTrack_163050::*)())&hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4d0);
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
            params[0] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeBegin", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeEnd", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("velocity", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b510);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnVelocity", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b530);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnAcceleration", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b560);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanThreshold", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanRate", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("phase", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5d0);
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
            params[13] = new (mem) fight::ParamIntConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("priority", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b640);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendInTime", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b660);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendOutTime", (void (hulkfight::motion::LocomotionSprintTrack_1633f0::*)())&hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b680);
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
            params[0] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeBegin", (void (GrappleLocomotionSteerTrack::*)())&GrappleLocomotionSteerTrack::FUN_0015b690);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeEnd", (void (GrappleLocomotionSteerTrack::*)())&GrappleLocomotionSteerTrack::FUN_0015b6a0);
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
            params[7] = new (mem) fight::ParamIntConstRange_163790<GrappleLocomotionSteerTrack>("priority", (void (GrappleLocomotionSteerTrack::*)())&GrappleLocomotionSteerTrack::FUN_0015b710);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendInTime", (void (GrappleLocomotionSteerTrack::*)())&GrappleLocomotionSteerTrack::FUN_0015b730);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendOutTime", (void (GrappleLocomotionSteerTrack::*)())&GrappleLocomotionSteerTrack::FUN_0015b750);
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

