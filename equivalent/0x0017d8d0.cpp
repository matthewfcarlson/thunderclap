// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0017d8d0 @ 0x0017d8d0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack {
public:
    void FUN_0016f3b0();
    void FUN_0016f3c0();
    void FUN_0016f3d0();
    void FUN_0016f400();
    void FUN_0016f440();
    void FUN_0016f470();
    void FUN_0016f4a0();
    void FUN_0016f4d0();
    void FUN_0016f500();
    void FUN_0016f520();
    void FUN_0016f550();
    void FUN_0016f570();
    void FUN_0016f590();
    void FUN_0016f5b0();
    void FUN_0016f5d0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
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
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0017d8d0()
{
    if (DAT_004e136c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("timeBegin", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f3b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("timeEnd", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f3c0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList<hulkfight::motion::JointPivotTrackerTrack>("joint", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f3d0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>("trackAxis", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f400);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>("pivotAxis", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f440);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("turnRate", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f470);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("angleMin", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f4a0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("angleMax", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f4d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>("targetRequired", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f500);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("targetArc", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f520);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("targetDistance", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f550);
        mem = FUN_0008d690(0x20);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>("targetLocation", ((const char**)&DAT_004b7cf0), 3, &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f570);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>("priority", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f590);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("blendInTime", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f5b0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>("blendOutTime", &hulkfight::motion::JointPivotTrackerTrack::FUN_0016f5d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1368), params, 15);
    }
    DAT_004e136c++;
}
