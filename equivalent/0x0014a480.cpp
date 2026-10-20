// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a480 @ 0x0014a480
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class GrappleThrowTrack {
public:
    void FUN_00146a40();
    void FUN_00146a70();
    void FUN_00146aa0();
    void FUN_00146ac0();
    void FUN_00146ae0();
    void FUN_00146b00();
    void FUN_00146b20();
    void FUN_00146b50();
    void FUN_00146b80();
    void FUN_00146bb0();
    void FUN_00146bd0();
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

void FUN_0014a480()
{
    if (DAT_004e0ff0 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("timeBegin", &GrappleThrowTrack::FUN_00146a40);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector<GrappleThrowTrack>("direction", &GrappleThrowTrack::FUN_00146a70);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("distanceMin", &GrappleThrowTrack::FUN_00146aa0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("distanceMax", &GrappleThrowTrack::FUN_00146ac0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("velocityMin", &GrappleThrowTrack::FUN_00146ae0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("velocityMax", &GrappleThrowTrack::FUN_00146b00);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("trackingMin", &GrappleThrowTrack::FUN_00146b20);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("trackingMax", &GrappleThrowTrack::FUN_00146b50);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("yFixupAngle", &GrappleThrowTrack::FUN_00146b80);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("stunTimeMin", &GrappleThrowTrack::FUN_00146bb0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<GrappleThrowTrack>("stunTimeMax", &GrappleThrowTrack::FUN_00146bd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fec), params, 11);
    }
    DAT_004e0ff0++;
}
