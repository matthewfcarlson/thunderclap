// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00179c10..0x0017afd0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_ff8057c2 {
#define TREE_TU_END }
namespace fn_ff8057c2 {} using namespace fn_ff8057c2;
#include "game/unknown.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_ff8057c2 {
void* FUN_0008d690(unsigned int size);
class ChargeTrack {
public:
    void FUN_0016e9b0();
    void FUN_0016e9c0();
    void FUN_0016e9e0();
    void FUN_0016ea00();
    void FUN_0016ea20();
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
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class SnapToGroundTrack_179d60 {
public:
    void FUN_0016eac0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_179d60 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_179d60(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class SuckTrack {
public:
    void FUN_0016ede0();
    void FUN_0016edf0();
    void FUN_0016ee10();
    void FUN_0016ee30();
    void FUN_0016ee50();
    void FUN_0016ee70();
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class LocomotionStateTrack_179f30 {
public:
    void FUN_0016ee80();
    void FUN_0016eea0();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_179f30 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_179f30(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_179f30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_179f30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class DriftToPositionTrack {
public:
    void FUN_0016f090();
    void FUN_0016f0a0();
    void FUN_0016f0c0();
    void FUN_0016f0f0();
    void FUN_0016f120();
    void FUN_0016f140();
    void FUN_00170480();
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class TargetBreakTrack_17a420 {
public:
    void FUN_0016f240();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a420 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a420(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class TeleportTrack_17a480 {
public:
    void FUN_0016f360();
    void FUN_0016f390();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_17a480 : public ParamVectorBase {
public:
    ParamVector_17a480(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class SurfTrack_17a520 {
public:
    void FUN_0016f5e0();
    void FUN_0016f5f0();
    void FUN_0016f610();
    void FUN_0016f630();
    void FUN_0016f650();
    void FUN_0016f670();
    void FUN_0016f690();
    void FUN_0016f6c0();
    void FUN_0016f6f0();
    void FUN_0016f720();
    void FUN_0016f750();
    void FUN_0016f780();
    void FUN_0016f7b0();
    void FUN_0016f7d0();
    void FUN_0016f7f0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17a520 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a520(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_17a520 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17a520(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class TargetIconDistanceTrack {
public:
    void FUN_0016f800();
    void FUN_0016f810();
    void FUN_0016f830();
    void FUN_0016f850();
    void FUN_0016f870();
};
extern "C" void __cdecl FUN_0016f880();
extern "C" void __cdecl FUN_0016f8a0();
extern "C" char DAT_0041872c[];
struct Param {
    char pad[0x18];
};
} // namespace fn_ff8057c2
void* operator new(size_t n);
namespace fn_ff8057c2 {
void Register_002347b0(void* reg, Param** arr, int n);
struct Base_17a9a0 {
    int vt;
    char pad[0xc];
    int f10;
    int f14;
    Base_17a9a0(const char* name);
};
class SuckInPropsTrack {
public:
    void FUN_0016f8b0();
    void FUN_0016f8c0();
    void FUN_0016f8e0();
    void FUN_0016f900();
    void FUN_0016f920();
};
} // namespace fn_ff8057c2
namespace hulkfight { namespace motion {
class IntentionClearTrack_17ac80 {
public:
    void FUN_0016f9e0();
    void FUN_0016f9f0();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_17ac80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ac80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class VisibilityTrack_17aee0 {
public:
    void FUN_0016faa0();
    void FUN_0016fac0();
};
} }
namespace fight {
template <class T>
class ParamBool_17aee0 : public ParamBoolBase {
public:
    ParamBool_17aee0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_17aee0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17aee0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ff8057c2 {
class Params_17af80 {
  public:
    int x;
};
extern Params_17af80 hulk_at_00494b44;
extern Params_17af80 hulk_at_00494b60;
class Object_17af80 {
  public:
    int Init_001732f0(hulkfight::motion::LocomotionStateTrack*, hulk_intptr);
};
Object_17af80* __cdecl Alloc_0008d690(int);


// 0x00179c10 FUN_00179c10 (325 B): equivalent/0x00179c10.cpp
// sym: ?FUN_00179c10@fn_ff8057c2@@YAXXZ @cc263a2237bd @w31278abd342e
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_00179c10 @ 0x00179c10
void FUN_00179c10()
{
    if (DAT_004e12f4 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ChargeTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ChargeTrack>("timeBegin", &ChargeTrack::FUN_0016e9b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ChargeTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ChargeTrack>("timeEnd", &ChargeTrack::FUN_0016e9c0);
        mem = FUN_0008d690((int)sizeof(ParamEnumConstList<ChargeTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamEnumConstList<ChargeTrack>("type", ((const char**)&DAT_004b4d7c), (*(int*)&DAT_00416640), &ChargeTrack::FUN_0016e9e0);
        mem = FUN_0008d690((int)sizeof(ParamBool<ChargeTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<ChargeTrack>("clearOnBegin", &ChargeTrack::FUN_0016ea00);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ChargeTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<ChargeTrack>("finalCharge", &ChargeTrack::FUN_0016ea20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12f0), params, 5);
    }
    DAT_004e12f4++;
}


// 0x00179d60 FUN_00179d60 (95 B): equivalent/0x00179d60.cpp
// sym: ?FUN_00179d60@fn_ff8057c2@@YAXXZ @80e9922d809d @w5e8f7eea750e
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00179d60 @ 0x00179d60
void FUN_00179d60()
{
    if (DAT_004e1304 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_179d60<hulkfight::motion::SnapToGroundTrack_179d60>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_179d60<hulkfight::motion::SnapToGroundTrack_179d60>("timeBegin", &hulkfight::motion::SnapToGroundTrack_179d60::FUN_0016eac0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1300), params, 1);
    }
    DAT_004e1304++;
}


// 0x00179dc0 FUN_00179dc0 (358 B): equivalent/0x00179dc0.cpp
// sym: _FUN_00179dc0 @6581b81c9a9b @w3af5df5b5457
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 14/14)
// FUN_00179dc0 @ 0x00179dc0
extern "C" void FUN_00179dc0()
{
    if (DAT_004e131c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SuckTrack>("timeBegin", &SuckTrack::FUN_0016ede0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SuckTrack>("timeEnd", &SuckTrack::FUN_0016edf0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<SuckTrack>("distanceMin", &SuckTrack::FUN_0016ee10);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<SuckTrack>("distanceMax", &SuckTrack::FUN_0016ee30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<SuckTrack>("velocityMin", &SuckTrack::FUN_0016ee50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<SuckTrack>("velocityMax", &SuckTrack::FUN_0016ee70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1318), params, 6);
    }
    DAT_004e131c++;
}


// 0x00179f30 FUN_00179f30 (170 B): equivalent/0x00179f30.cpp
// sym: _FUN_00179f30 @ee6826e94088 @w47e831858b81
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00179f30 @ 0x00179f30
extern "C" void FUN_00179f30()
{
    if (DAT_004e1324 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_179f30<hulkfight::motion::LocomotionStateTrack_179f30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_179f30<hulkfight::motion::LocomotionStateTrack_179f30>("timeBegin", &hulkfight::motion::LocomotionStateTrack_179f30::FUN_0016ee80);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_179f30<hulkfight::motion::LocomotionStateTrack_179f30>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_179f30<hulkfight::motion::LocomotionStateTrack_179f30>("locomotionState", ((const char**)&DAT_0048f590), (*(int*)&DAT_003f5bbc), &hulkfight::motion::LocomotionStateTrack_179f30::FUN_0016eea0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1320), params, 2);
    }
    DAT_004e1324++;
}


// 0x00179fe0 FUN_00179fe0 (409 B): equivalent/0x00179fe0.cpp
// sym: _FUN_00179fe0 @bc491c1438ea @wa3552a894f51
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 16/16)
// FUN_00179fe0 @ 0x00179fe0
extern "C" void FUN_00179fe0()
{
    if (DAT_004e1334 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<DriftToPositionTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<DriftToPositionTrack>("timeBegin", &DriftToPositionTrack::FUN_0016f090);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<DriftToPositionTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<DriftToPositionTrack>("timeEnd", &DriftToPositionTrack::FUN_0016f0a0);
        mem = FUN_0008d690((int)sizeof(ParamBool<DriftToPositionTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<DriftToPositionTrack>("letMeSpecifyPosition", &DriftToPositionTrack::FUN_0016f0c0);
        mem = FUN_0008d690((int)sizeof(ParamVector<DriftToPositionTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<DriftToPositionTrack>("position", &DriftToPositionTrack::FUN_0016f0f0);
        mem = FUN_0008d690((int)sizeof(ParamBool<DriftToPositionTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<DriftToPositionTrack>("ditchYIfInDefaultMode", &DriftToPositionTrack::FUN_0016f120);
        mem = FUN_0008d690((int)sizeof(ParamBool<DriftToPositionTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<DriftToPositionTrack>("teleportAtEnd", &DriftToPositionTrack::FUN_0016f140);
        mem = FUN_0008d690((int)sizeof(ParamString<DriftToPositionTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamString<DriftToPositionTrack>("variable", &DriftToPositionTrack::FUN_00170480);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1330), params, 7);
    }
    DAT_004e1334++;
}


// 0x0017a420 FUN_0017a420 (95 B): equivalent/0x0017a420.cpp
// sym: _FUN_0017a420 @c4b50e640876 @w8ccbefda1d54
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0017a420 @ 0x0017a420
extern "C" void FUN_0017a420()
{
    if (DAT_004e1354 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a420<hulkfight::motion::TargetBreakTrack_17a420>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17a420<hulkfight::motion::TargetBreakTrack_17a420>("timeBegin", &hulkfight::motion::TargetBreakTrack_17a420::FUN_0016f240);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1350), params, 1);
    }
    DAT_004e1354++;
}


// 0x0017a480 FUN_0017a480 (158 B): equivalent/0x0017a480.cpp
// sym: _FUN_0017a480 @58083968d8f5 @w83b55ff7ef24
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0017a480 @ 0x0017a480
extern "C" void FUN_0017a480()
{
    if (DAT_004e1364 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a480<hulkfight::motion::TeleportTrack_17a480>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17a480<hulkfight::motion::TeleportTrack_17a480>("timeBegin", &hulkfight::motion::TeleportTrack_17a480::FUN_0016f360);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17a480<hulkfight::motion::TeleportTrack_17a480>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_17a480<hulkfight::motion::TeleportTrack_17a480>("vector", &hulkfight::motion::TeleportTrack_17a480::FUN_0016f390);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1360), params, 2);
    }
    DAT_004e1364++;
}


// 0x0017a520 FUN_0017a520 (817 B): equivalent/0x0017a520.cpp
// sym: _FUN_0017a520 @422569fc01d8 @w1b0c3dde7e5e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0017a520 @ 0x0017a520
extern "C" void FUN_0017a520()
{
    if (DAT_004e1374 == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("timeBegin", &hulkfight::motion::SurfTrack_17a520::FUN_0016f5e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("timeEnd", &hulkfight::motion::SurfTrack_17a520::FUN_0016f5f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("minInitVelocity", &hulkfight::motion::SurfTrack_17a520::FUN_0016f610);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("minVelocity", &hulkfight::motion::SurfTrack_17a520::FUN_0016f630);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("deceleration", &hulkfight::motion::SurfTrack_17a520::FUN_0016f650);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("userDeceleration", &hulkfight::motion::SurfTrack_17a520::FUN_0016f670);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("turnVelocity", &hulkfight::motion::SurfTrack_17a520::FUN_0016f690);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("turnAcceleration", &hulkfight::motion::SurfTrack_17a520::FUN_0016f6c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("leanMaxAngle", &hulkfight::motion::SurfTrack_17a520::FUN_0016f6f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("leanActiveRate", &hulkfight::motion::SurfTrack_17a520::FUN_0016f720);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("leanPassiveRate", &hulkfight::motion::SurfTrack_17a520::FUN_0016f750);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("slopeRate", &hulkfight::motion::SurfTrack_17a520::FUN_0016f780);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("priority", &hulkfight::motion::SurfTrack_17a520::FUN_0016f7b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("blendInTime", &hulkfight::motion::SurfTrack_17a520::FUN_0016f7d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_17a520<hulkfight::motion::SurfTrack_17a520>("blendOutTime", &hulkfight::motion::SurfTrack_17a520::FUN_0016f7f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1370), params, 15);
    }
    DAT_004e1374++;
}


// 0x0017a860 FUN_0017a860 (307 B): equivalent/0x0017a860.cpp
// sym: _FUN_0017a860 @baa1b5dbabba @w09c26df65477
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0017a860 @ 0x0017a860
extern "C" void FUN_0017a860()
{
    if (DAT_004e137c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetIconDistanceTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("timeBegin", &TargetIconDistanceTrack::FUN_0016f800);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetIconDistanceTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("timeEnd", &TargetIconDistanceTrack::FUN_0016f810);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetIconDistanceTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("distanceMin", &TargetIconDistanceTrack::FUN_0016f830);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetIconDistanceTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("distanceMax", &TargetIconDistanceTrack::FUN_0016f850);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<TargetIconDistanceTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("extensionTime", &TargetIconDistanceTrack::FUN_0016f870);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1378), params, 5);
    }
    DAT_004e137c++;
}


// 0x0017a9a0 FUN_0017a9a0 (158 B): matches/0x0017a9a0.cpp
// sym: _FUN_0017a9a0
// data: gCount_17a9a0 = DAT_004e1384
extern "C" void FUN_0017a9a0() {
    if ((*(int*)&DAT_004e1384) == 0) {
        Param* arr[2];
        Param* a = (Param*)operator new(sizeof(Param));
        if (a) {
            ((Param *)((fight::ParamValueFloat *)a)->FUN_00234960("timeBegin"));
            *(hulk_intptr*)a = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)a + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f880);
            arr[0] = a;
        } else {
            arr[0] = 0;
        }
        Param* b = (Param*)operator new(sizeof(Param));
        if (b) {
            ((Param *)((fight::ParamValueFloat *)b)->FUN_00234960("power"));
            *(hulk_intptr*)b = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)b + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f8a0);
            arr[1] = b;
        } else {
            arr[1] = 0;
        }
        Register_002347b0(((char*)&DAT_004e1380), arr, 2);
    }
    (*(int*)&DAT_004e1384)++;
}


// 0x0017aa40 FUN_0017aa40 (307 B): equivalent/0x0017aa40.cpp
// sym: _FUN_0017aa40 @2a49e5292e51 @wd9f554f0aae5
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0017aa40 @ 0x0017aa40
extern "C" void FUN_0017aa40()
{
    if (DAT_004e138c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckInPropsTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SuckInPropsTrack>("timeBegin", &SuckInPropsTrack::FUN_0016f8b0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckInPropsTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SuckInPropsTrack>("timeEnd", &SuckInPropsTrack::FUN_0016f8c0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<SuckInPropsTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<SuckInPropsTrack>("number", &SuckInPropsTrack::FUN_0016f8e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckInPropsTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<SuckInPropsTrack>("velocity", &SuckInPropsTrack::FUN_0016f900);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SuckInPropsTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<SuckInPropsTrack>("distance", &SuckInPropsTrack::FUN_0016f920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1388), params, 5);
    }
    DAT_004e138c++;
}


// 0x0017ac80 FUN_0017ac80 (158 B): equivalent/0x0017ac80.cpp
// sym: _FUN_0017ac80 @bbd2a2c7b423 @w9e059a52282e
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0017ac80 @ 0x0017ac80
extern "C" void FUN_0017ac80()
{
    if (DAT_004e139c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ac80<hulkfight::motion::IntentionClearTrack_17ac80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17ac80<hulkfight::motion::IntentionClearTrack_17ac80>("timeBegin", &hulkfight::motion::IntentionClearTrack_17ac80::FUN_0016f9e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ac80<hulkfight::motion::IntentionClearTrack_17ac80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17ac80<hulkfight::motion::IntentionClearTrack_17ac80>("timeEnd", &hulkfight::motion::IntentionClearTrack_17ac80::FUN_0016f9f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1398), params, 2);
    }
    DAT_004e139c++;
}


// 0x0017aee0 FUN_0017aee0 (158 B): equivalent/0x0017aee0.cpp
// sym: _FUN_0017aee0 @a0237b2447a5 @wa307e2bd225b
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0017aee0 @ 0x0017aee0
extern "C" void FUN_0017aee0()
{
    if (DAT_004e13b4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17aee0<hulkfight::motion::VisibilityTrack_17aee0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17aee0<hulkfight::motion::VisibilityTrack_17aee0>("timeBegin", &hulkfight::motion::VisibilityTrack_17aee0::FUN_0016faa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17aee0<hulkfight::motion::VisibilityTrack_17aee0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_17aee0<hulkfight::motion::VisibilityTrack_17aee0>("visible", &hulkfight::motion::VisibilityTrack_17aee0::FUN_0016fac0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e13b0), params, 2);
    }
    DAT_004e13b4++;
}

} // namespace fn_ff8057c2

// 0x0017af80 hulkfight::motion::LocomotionStateTrack::vfunc_10 (70 B): matches/0x0017af80.cpp
// sym: ?vfunc_10@LocomotionStateTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionStateTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_17af80* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_001732f0(this, c);
    }
    return 0;
}

