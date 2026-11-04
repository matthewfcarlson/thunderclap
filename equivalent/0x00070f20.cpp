// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 16/16)
// FUN_00070f20 @ 0x00070f20
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CMoveTrack_70f20 {
public:
    void FUN_00068280();
    void FUN_00068290();
    void FUN_000682a0();
    void FUN_000682b0();
    void FUN_000682c0();
    void FUN_000682d0();
    void FUN_0006b6f0();
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
namespace fight {
template <class T>
class ParamFloatConstRange_70f20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70f20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_70f20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70f20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00070f20()
{
    if (DAT_004dcf4c == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("timeBegin", &CMoveTrack_70f20::FUN_00068280);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("timeEnd", &CMoveTrack_70f20::FUN_00068290);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("distance", &CMoveTrack_70f20::FUN_000682a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("direction", &CMoveTrack_70f20::FUN_0006b6f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_70f20<CMoveTrack_70f20>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_70f20<CMoveTrack_70f20>("priority", &CMoveTrack_70f20::FUN_000682b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("blendInTime", &CMoveTrack_70f20::FUN_000682c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_70f20<CMoveTrack_70f20>("blendOutTime", &CMoveTrack_70f20::FUN_000682d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf48), params, 7);
    }
    DAT_004dcf4c++;
}
