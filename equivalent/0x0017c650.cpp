// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_0017c650 @ 0x0017c650
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class JointTrackerTrack_17c650 {
public:
    void FUN_0016e720();
    void FUN_0016e730();
    void FUN_0016e740();
    void FUN_0016e770();
    void FUN_0016e7b0();
    void FUN_0016e7e0();
    void FUN_0016e810();
    void FUN_0016e840();
    void FUN_0016e870();
    void FUN_0016e8a0();
    void FUN_0016e8d0();
    void FUN_0016e8f0();
    void FUN_0016e920();
    void FUN_0016e940();
    void FUN_0016e960();
    void FUN_0016e980();
    void FUN_0016e9a0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool_17c650 : public ParamBoolBase {
public:
    ParamBool_17c650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_17c650 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17c650(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_17c650 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17c650(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_17c650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17c650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_17c650 : public ParamNameConstListBase {
public:
    ParamNameConstList_17c650(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_17c650 : public ParamVectorBase {
public:
    ParamVector_17c650(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017c650()
{
    if (DAT_004e12ec == 0) {
        void* params[17];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("timeBegin", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e720);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("timeEnd", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e730);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>("joint", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e740);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>("north", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e770);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_17c650<hulkfight::motion::JointTrackerTrack_17c650>("east", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e7b0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("turnRate", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e7e0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("vertMinAngle", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e810);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("vertMaxAngle", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e840);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("horzMinAngle", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e870);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("horzMaxAngle", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8a0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetRequired", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8d0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetArc", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e8f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetDistance", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e920);
        mem = FUN_0008d690(0x20);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamEnumConstList_17c650<hulkfight::motion::JointTrackerTrack_17c650>("targetLocation", ((const char**)&DAT_004b7cf0), 3, &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e940);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("priority", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e960);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("blendInTime", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e980);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_17c650<hulkfight::motion::JointTrackerTrack_17c650>("blendOutTime", &hulkfight::motion::JointTrackerTrack_17c650::FUN_0016e9a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e12e8), params, 17);
    }
    DAT_004e12ec++;
}
