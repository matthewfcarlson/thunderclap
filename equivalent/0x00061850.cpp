// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 28/28)
// FUN_00061850 @ 0x00061850
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CEffectTrack {
public:
    void FUN_00060430();
    void FUN_00060440();
    void FUN_00012db0();
    void FUN_00060470();
    void FUN_00012d80();
    void FUN_00060450();
    void FUN_000607d0();
    void FUN_00060480();
    void FUN_00012da0();
    void FUN_00060490();
    void FUN_000604a0();
    void FUN_000604b0();
    void FUN_000604c0();
};

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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
        : ParamEnumConstListBase(name) { names = n; count = c; setter = s; }
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
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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

void FUN_00061850()
{
    if (DAT_004dc60c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CEffectTrack>("timeBegin", &CEffectTrack::FUN_00060430);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CEffectTrack>("timeEnd", &CEffectTrack::FUN_00060440);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<CEffectTrack>("effectName", &CEffectTrack::FUN_00012db0);
        mem = FUN_0008d690(0x20);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList<CEffectTrack>("emitSpace", ((const char**)&DAT_00495d60), 5, &CEffectTrack::FUN_00060470);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList<CEffectTrack>("emitJoint", &CEffectTrack::FUN_00012d80);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector<CEffectTrack>("offset", &CEffectTrack::FUN_00060450);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector<CEffectTrack>("orientation", &CEffectTrack::FUN_000607d0);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList<CEffectTrack>("attachSpace", ((const char**)&DAT_00495d50), 4, &CEffectTrack::FUN_00060480);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamNameConstList<CEffectTrack>("attachJoint", &CEffectTrack::FUN_00012da0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool<CEffectTrack>("abortWhenInterrupted", &CEffectTrack::FUN_00060490);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<CEffectTrack>("runTillStop", &CEffectTrack::FUN_000604a0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamIntConstRange<CEffectTrack>("slot", &CEffectTrack::FUN_000604b0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<CEffectTrack>("scale", &CEffectTrack::FUN_000604c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc608), params, 13);
    }
    DAT_004dc60c++;
}
