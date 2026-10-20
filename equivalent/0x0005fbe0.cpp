// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0005fbe0 @ 0x0005fbe0
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CProceduralDurationAnimationTrack {
public:
    void FUN_0005d700();
    void FUN_0005d710();
    void FUN_0005d720();
    void FUN_00013090();
    void FUN_0005d730();
    void FUN_0005d740();
    void FUN_0005d750();
    void FUN_0005d760();
    void FUN_0005d770();
    void FUN_000130f0();
    void FUN_0005d780();
    void FUN_0005d790();
    void FUN_0005d7a0();
    void FUN_0005d7b0();
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
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005fbe0()
{
    if (DAT_004dc5e4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("timeBegin", &CProceduralDurationAnimationTrack::FUN_0005d700);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("timeScale", &CProceduralDurationAnimationTrack::FUN_0005d710);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("timeEndMin", &CProceduralDurationAnimationTrack::FUN_0005d720);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName<CProceduralDurationAnimationTrack>("animation", &CProceduralDurationAnimationTrack::FUN_00013090);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("speed", &CProceduralDurationAnimationTrack::FUN_0005d730);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("initFrame", &CProceduralDurationAnimationTrack::FUN_0005d740);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("startFrame", &CProceduralDurationAnimationTrack::FUN_0005d750);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("endFrame", &CProceduralDurationAnimationTrack::FUN_0005d760);
        mem = FUN_0008d690(0x20);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList<CProceduralDurationAnimationTrack>("cyclic", ((const char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &CProceduralDurationAnimationTrack::FUN_0005d770);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName<CProceduralDurationAnimationTrack>("partition", &CProceduralDurationAnimationTrack::FUN_000130f0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamIntConstRange<CProceduralDurationAnimationTrack>("priority", &CProceduralDurationAnimationTrack::FUN_0005d780);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("blendInTime", &CProceduralDurationAnimationTrack::FUN_0005d790);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>("blendOutTime", &CProceduralDurationAnimationTrack::FUN_0005d7a0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool<CProceduralDurationAnimationTrack>("useRootMotion", &CProceduralDurationAnimationTrack::FUN_0005d7b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5e0), params, 14);
    }
    DAT_004dc5e4++;
}
