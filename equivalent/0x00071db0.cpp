// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00071db0 @ 0x00071db0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CJumpAttackTrack_71db0 {
public:
    void FUN_000687a0();
    void FUN_000687b0();
    void FUN_000687c0();
    void FUN_000687e0();
    void FUN_00068800();
    void FUN_00068810();
    void FUN_00068820();
    void FUN_00068830();
    void FUN_00068840();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00071db0()
{
    if (DAT_004dcfbc == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("timeBegin", &CJumpAttackTrack_71db0::FUN_000687a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("timeEnd", &CJumpAttackTrack_71db0::FUN_000687b0);
        mem = FUN_0008d690((int)sizeof(ParamVector<CJumpAttackTrack_71db0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<CJumpAttackTrack_71db0>("direction", &CJumpAttackTrack_71db0::FUN_000687c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("arc", &CJumpAttackTrack_71db0::FUN_000687e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("distance", &CJumpAttackTrack_71db0::FUN_00068800);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("speed", &CJumpAttackTrack_71db0::FUN_00068810);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CJumpAttackTrack_71db0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CJumpAttackTrack_71db0>("priority", &CJumpAttackTrack_71db0::FUN_00068820);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("rootBlendInTime", &CJumpAttackTrack_71db0::FUN_00068830);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CJumpAttackTrack_71db0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CJumpAttackTrack_71db0>("rootBlendOutTime", &CJumpAttackTrack_71db0::FUN_00068840);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfb8), params, 9);
    }
    DAT_004dcfbc++;
}
