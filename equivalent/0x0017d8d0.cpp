// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0017d8d0 @ 0x0017d8d0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack_17d8d0 {
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
class ParamBool_17d8d0 : public ParamBoolBase {
public:
    ParamBool_17d8d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_17d8d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17d8d0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_17d8d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17d8d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_17d8d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17d8d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_17d8d0 : public ParamNameConstListBase {
public:
    ParamNameConstList_17d8d0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_17d8d0 : public ParamVectorBase {
public:
    ParamVector_17d8d0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017d8d0()
{
    if (DAT_004e136c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("timeBegin", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("timeEnd", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("joint", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f3d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("trackAxis", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f400);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("pivotAxis", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f440);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("turnRate", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f470);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("angleMin", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f4a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("angleMax", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f4d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetRequired", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f500);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetArc", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f520);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetDistance", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f550);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamEnumConstList_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("targetLocation", ((const char**)&DAT_004b7cf0), 3, &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f570);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("priority", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("blendInTime", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_17d8d0<hulkfight::motion::JointPivotTrackerTrack_17d8d0>("blendOutTime", &hulkfight::motion::JointPivotTrackerTrack_17d8d0::FUN_0016f5d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1368), params, 15);
    }
    DAT_004e136c++;
}
