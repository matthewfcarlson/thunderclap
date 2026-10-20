// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00071db0 @ 0x00071db0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CJumpAttackTrack {
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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

void FUN_00071db0()
{
    if (DAT_004dcfbc == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("timeBegin", &CJumpAttackTrack::FUN_000687a0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("timeEnd", &CJumpAttackTrack::FUN_000687b0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<CJumpAttackTrack>("direction", &CJumpAttackTrack::FUN_000687c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("arc", &CJumpAttackTrack::FUN_000687e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("distance", &CJumpAttackTrack::FUN_00068800);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("speed", &CJumpAttackTrack::FUN_00068810);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<CJumpAttackTrack>("priority", &CJumpAttackTrack::FUN_00068820);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("rootBlendInTime", &CJumpAttackTrack::FUN_00068830);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CJumpAttackTrack>("rootBlendOutTime", &CJumpAttackTrack::FUN_00068840);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcfb8), params, 9);
    }
    DAT_004dcfbc++;
}
