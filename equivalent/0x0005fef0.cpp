// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_0005fef0 @ 0x0005fef0
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CStunAnimationTrack {
public:
    void FUN_0005d7c0();
    void FUN_00013140();
    void FUN_0005d7d0();
    void FUN_0005d7e0();
    void FUN_0005d7f0();
    void FUN_0005d800();
    void FUN_0005d810();
    void FUN_000131a0();
    void FUN_0005d820();
    void FUN_0005d830();
    void FUN_0005d840();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005fef0()
{
    if (DAT_004dc5ec == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("timeBegin", &CStunAnimationTrack::FUN_0005d7c0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName<CStunAnimationTrack>("animation", &CStunAnimationTrack::FUN_00013140);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("speed", &CStunAnimationTrack::FUN_0005d7d0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("initFrame", &CStunAnimationTrack::FUN_0005d7e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("startFrame", &CStunAnimationTrack::FUN_0005d7f0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("endFrame", &CStunAnimationTrack::FUN_0005d800);
        mem = FUN_0008d690(0x20);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamEnumConstList<CStunAnimationTrack>("cyclic", ((const char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &CStunAnimationTrack::FUN_0005d810);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName<CStunAnimationTrack>("partition", &CStunAnimationTrack::FUN_000131a0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<CStunAnimationTrack>("priority", &CStunAnimationTrack::FUN_0005d820);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("blendInTime", &CStunAnimationTrack::FUN_0005d830);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<CStunAnimationTrack>("blendOutTime", &CStunAnimationTrack::FUN_0005d840);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5e8), params, 11);
    }
    DAT_004dc5ec++;
}
