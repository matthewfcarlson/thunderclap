// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0013e810..0x00143100 (kind game, layer game, confidence high), dominant class hulkfight::motion::WallJumpAction
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3628106 {
#define TREE_TU_END }
namespace fn_f3628106 {} using namespace fn_f3628106;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3628106 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f3628106
namespace hulkfight { namespace motion {
class WallVelocityCondition_141ae0 {
public:
    void FUN_0013e810();
    void FUN_0013e820();
};
} }
namespace fn_f3628106 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f3628106
namespace fight {
template <class T>
class ParamEnumConstList_141ae0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_141ae0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_141ae0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_141ae0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3628106 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f3628106
namespace hulkfight { namespace motion {
class WallJumpTrack_141b90 {
public:
    void FUN_0013ea20();
    void FUN_0013ea30();
    void FUN_0013ea50();
    void FUN_0013ea70();
    void FUN_0013ea90();
    void FUN_0013eab0();
    void FUN_0013ead0();
    void FUN_0013eb00();
    void FUN_0013eb30();
    void FUN_0013eb60();
    void FUN_0013eb90();
    void FUN_0013ebb0();
    void FUN_0013ebd0();
    void FUN_0013ec00();
    void FUN_0013ec30();
    void FUN_0013ec60();
    void FUN_0013ec80();
    void FUN_0013eca0();
};
} }
namespace fn_f3628106 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f3628106
namespace fight {
template <class T>
class ParamBool_141b90 : public ParamBoolBase {
public:
    ParamBool_141b90(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_141b90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_141b90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_141b90 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_141b90(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3628106 {
class WallExitTrack {
public:
    void FUN_0013ecb0();
    void FUN_0013ecc0();
    void FUN_0013ece0();
    void FUN_0013ed00();
    void FUN_0013ed20();
    void FUN_0013ed40();
    void FUN_0013ed70();
    void FUN_0013eda0();
    void FUN_0013edd0();
    void FUN_0013edf0();
    void FUN_0013ee10();
};
} // namespace fn_f3628106
namespace fight {
template <class T>
class ParamFloatConstRange_141f60 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_141f60(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_141f60 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_141f60(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class WallRunTrack_142510 {
public:
    void FUN_0013e830();
    void FUN_0013e840();
    void FUN_0013e860();
    void FUN_0013e880();
    void FUN_0013e8a0();
    void FUN_0013e8c0();
    void FUN_0013e8e0();
    void FUN_0013e900();
    void FUN_0013e920();
    void FUN_0013e940();
    void FUN_0013e970();
    void FUN_0013e990();
    void FUN_0013e9a0();
    void FUN_0013e9b0();
    void FUN_0013e9d0();
    void FUN_0013e9f0();
    void FUN_0013ea10();
};
} }
namespace fn_f3628106 {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f3628106
namespace fight {
template <class T>
class ParamBool_142510 : public ParamBoolBase {
public:
    ParamBool_142510(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_142510 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_142510(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_142510 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_142510(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_142510 : public ParamNameBase {
public:
    ParamName_142510(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f3628106 {

// 0x00141ae0 FUN_00141ae0 (176 B): equivalent/0x00141ae0.cpp
// sym: ?FUN_00141ae0@fn_f3628106@@YAXXZ @f11f7b7820c9 @w41888508869b
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00141ae0 @ 0x00141ae0
void FUN_00141ae0()
{
    if (DAT_004e0f44 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_141ae0<hulkfight::motion::WallVelocityCondition_141ae0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_141ae0<hulkfight::motion::WallVelocityCondition_141ae0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::WallVelocityCondition_141ae0::FUN_0013e810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141ae0<hulkfight::motion::WallVelocityCondition_141ae0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_141ae0<hulkfight::motion::WallVelocityCondition_141ae0>("velocity", &hulkfight::motion::WallVelocityCondition_141ae0::FUN_0013e820);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f40), params, 2);
    }
    DAT_004e0f44++;
}


// 0x00141b90 FUN_00141b90 (970 B): equivalent/0x00141b90.cpp
// sym: ?FUN_00141b90@fn_f3628106@@YAXXZ @e1b1aeba2162 @wb610fddfc85c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_00141b90 @ 0x00141b90
void FUN_00141b90()
{
    if (DAT_004e0f54 == 0) {
        void* params[18];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("timeBegin", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ea20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("timeEnd", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ea30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("velocityMin", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ea50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("velocityMax", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ea70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("velocityXZMax", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ea90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("gravity", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("upAngleMin", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ead0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("upAngleMax", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eb00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("turningVelocity", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("straightUpArc", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("drift", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eb90);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_141b90<hulkfight::motion::WallJumpTrack_141b90>("useCurrentMotionAngle", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ebb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("angle", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ebd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("arc", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ec00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("minYAngle", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ec30);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamIntConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("priority", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ec60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("blendInTime", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013ec80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_141b90<hulkfight::motion::WallJumpTrack_141b90>("blendOutTime", &hulkfight::motion::WallJumpTrack_141b90::FUN_0013eca0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f50), params, 18);
    }
    DAT_004e0f54++;
}


// 0x00141f60 FUN_00141f60 (613 B): equivalent/0x00141f60.cpp
// sym: ?FUN_00141f60@fn_f3628106@@YAXXZ @5400b702e93b @w51fc2eff9fcf
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 24/24)
// FUN_00141f60 @ 0x00141f60
void FUN_00141f60()
{
    if (DAT_004e0f5c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("timeBegin", &WallExitTrack::FUN_0013ecb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("timeEnd", &WallExitTrack::FUN_0013ecc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("velocityMin", &WallExitTrack::FUN_0013ece0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("velocityMax", &WallExitTrack::FUN_0013ed00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("gravity", &WallExitTrack::FUN_0013ed20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("upAngleMin", &WallExitTrack::FUN_0013ed40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("upAngleMax", &WallExitTrack::FUN_0013ed70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("turningVelocity", &WallExitTrack::FUN_0013eda0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_141f60<WallExitTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_141f60<WallExitTrack>("priority", &WallExitTrack::FUN_0013edd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("blendInTime", &WallExitTrack::FUN_0013edf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("blendOutTime", &WallExitTrack::FUN_0013ee10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f58), params, 11);
    }
    DAT_004e0f5c++;
}


// 0x00142510 FUN_00142510 (919 B): equivalent/0x00142510.cpp
// sym: ?FUN_00142510@fn_f3628106@@YAXXZ @90baa01be260 @w5166c0b45f78
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_00142510 @ 0x00142510
void FUN_00142510()
{
    if (DAT_004e0f4c == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("timeBegin", &hulkfight::motion::WallRunTrack_142510::FUN_0013e830);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("timeEnd", &hulkfight::motion::WallRunTrack_142510::FUN_0013e840);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("velocityInit", &hulkfight::motion::WallRunTrack_142510::FUN_0013e860);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("velocityInitY", &hulkfight::motion::WallRunTrack_142510::FUN_0013e880);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("velocityMin", &hulkfight::motion::WallRunTrack_142510::FUN_0013e8a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("velocityMax", &hulkfight::motion::WallRunTrack_142510::FUN_0013e8c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_142510<hulkfight::motion::WallRunTrack_142510>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_142510<hulkfight::motion::WallRunTrack_142510>("useCharge", &hulkfight::motion::WallRunTrack_142510::FUN_0013e8e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("gravity", &hulkfight::motion::WallRunTrack_142510::FUN_0013e900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("friction", &hulkfight::motion::WallRunTrack_142510::FUN_0013e920);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("turningRate", &hulkfight::motion::WallRunTrack_142510::FUN_0013e940);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("maxAngleChange", &hulkfight::motion::WallRunTrack_142510::FUN_0013e970);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>("animLeft", &hulkfight::motion::WallRunTrack_142510::FUN_0013e990);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>("animUp", &hulkfight::motion::WallRunTrack_142510::FUN_0013e9a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamName_142510<hulkfight::motion::WallRunTrack_142510>("animRight", &hulkfight::motion::WallRunTrack_142510::FUN_0013e9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_142510<hulkfight::motion::WallRunTrack_142510>("priority", &hulkfight::motion::WallRunTrack_142510::FUN_0013e9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("blendInTime", &hulkfight::motion::WallRunTrack_142510::FUN_0013e9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_142510<hulkfight::motion::WallRunTrack_142510>("blendOutTime", &hulkfight::motion::WallRunTrack_142510::FUN_0013ea10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f48), params, 17);
    }
    DAT_004e0f4c++;
}

} // namespace fn_f3628106
