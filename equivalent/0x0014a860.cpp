// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a860 @ 0x0014a860
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CivilianThrowTrack {
public:
    void FUN_00146c80();
    void FUN_00146cb0();
    void FUN_00146ce0();
    void FUN_00146d00();
    void FUN_00146d20();
    void FUN_00146d40();
    void FUN_00146d60();
    void FUN_00146d90();
    void FUN_00146dc0();
    void FUN_00146df0();
    void FUN_00146e10();
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

void FUN_0014a860()
{
    if (DAT_004e1000 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("timeBegin", &CivilianThrowTrack::FUN_00146c80);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector<CivilianThrowTrack>("direction", &CivilianThrowTrack::FUN_00146cb0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("distanceMin", &CivilianThrowTrack::FUN_00146ce0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("distanceMax", &CivilianThrowTrack::FUN_00146d00);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("velocityMin", &CivilianThrowTrack::FUN_00146d20);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("velocityMax", &CivilianThrowTrack::FUN_00146d40);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("trackingMin", &CivilianThrowTrack::FUN_00146d60);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("trackingMax", &CivilianThrowTrack::FUN_00146d90);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("yFixupAngle", &CivilianThrowTrack::FUN_00146dc0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("stunTimeMin", &CivilianThrowTrack::FUN_00146df0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<CivilianThrowTrack>("stunTimeMax", &CivilianThrowTrack::FUN_00146e10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ffc), params, 11);
    }
    DAT_004e1000++;
}
