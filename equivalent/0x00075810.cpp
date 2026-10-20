// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_00075810 @ 0x00075810
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CHeadTrackerTrack {
public:
    void FUN_000689d0();
    void FUN_000689e0();
    void FUN_00012310();
    void FUN_000689f0();
    void FUN_00068a10();
    void FUN_00068a30();
    void FUN_00068a50();
    void FUN_00068a70();
    void FUN_00068a90();
    void FUN_00068ab0();
    void FUN_0006ad10();
    void FUN_00068ad0();
    void FUN_00068ae0();
    void FUN_00068af0();
    void FUN_00068b00();
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

void FUN_00075810()
{
    if (DAT_004dcff4 == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("timeBegin", &::CHeadTrackerTrack::FUN_000689d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("timeEnd", &::CHeadTrackerTrack::FUN_000689e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList<::CHeadTrackerTrack>("joint", &::CHeadTrackerTrack::FUN_00012310);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<::CHeadTrackerTrack>("north", &::CHeadTrackerTrack::FUN_000689f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector<::CHeadTrackerTrack>("east", &::CHeadTrackerTrack::FUN_00068a10);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("turnRate", &::CHeadTrackerTrack::FUN_00068a30);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("verticalMinAngle", &::CHeadTrackerTrack::FUN_00068a50);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("verticalMaxAngle", &::CHeadTrackerTrack::FUN_00068a70);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("horizontalMinAngle", &::CHeadTrackerTrack::FUN_00068a90);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("horizontalMaxAngle", &::CHeadTrackerTrack::FUN_00068ab0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("arc", &::CHeadTrackerTrack::FUN_0006ad10);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("distance", &::CHeadTrackerTrack::FUN_00068ad0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange<::CHeadTrackerTrack>("priority", &::CHeadTrackerTrack::FUN_00068ae0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("blendInTime", &::CHeadTrackerTrack::FUN_00068af0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<::CHeadTrackerTrack>("blendOutTime", &::CHeadTrackerTrack::FUN_00068b00);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcff0), params, 15);
    }
    DAT_004dcff4++;
}
