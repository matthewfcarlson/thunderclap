// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_00142510 @ 0x00142510
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
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
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_142510 : public ParamBoolBase {
public:
    ParamBool_142510(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_142510 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_142510(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_142510 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_142510(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_142510 : public ParamNameBase {
public:
    ParamName_142510(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

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
