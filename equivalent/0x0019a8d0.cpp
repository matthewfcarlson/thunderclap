// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 28/28)
// FUN_0019a8d0 @ 0x0019a8d0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class MissileThrowTrack {
public:
    void FUN_00192570();
    void FUN_00192590();
    void FUN_001925c0();
    void FUN_001925f0();
    void FUN_00192610();
    void FUN_00192630();
    void FUN_00192650();
    void FUN_00192670();
    void FUN_001926a0();
    void FUN_001926d0();
    void FUN_00192700();
    void FUN_00192730();
    void FUN_00192760();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
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

void FUN_0019a8d0()
{
    if (DAT_004e1564 == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("timeBegin", &MissileThrowTrack::FUN_00192570);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<MissileThrowTrack>("attachmentIndex", &MissileThrowTrack::FUN_00192590);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector<MissileThrowTrack>("direction", &MissileThrowTrack::FUN_001925c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("distanceMin", &MissileThrowTrack::FUN_001925f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("distanceMax", &MissileThrowTrack::FUN_00192610);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("velocityMin", &MissileThrowTrack::FUN_00192630);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("velocityMax", &MissileThrowTrack::FUN_00192650);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("spinMin", &MissileThrowTrack::FUN_00192670);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("spinMax", &MissileThrowTrack::FUN_001926a0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("trackingMin", &MissileThrowTrack::FUN_001926d0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("trackingMax", &MissileThrowTrack::FUN_00192700);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("yFixupAngle", &MissileThrowTrack::FUN_00192730);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<MissileThrowTrack>("reigniteCharge", &MissileThrowTrack::FUN_00192760);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1560), params, 13);
    }
    DAT_004e1564++;
}
