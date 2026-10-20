// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 28/28)
// FUN_0013c650 @ 0x0013c650
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class AnimationTrack {
public:
    void FUN_00139a30();
    void FUN_00139a40();
    void FUN_00139a50();
    void FUN_00139a70();
    void FUN_00139a90();
    void FUN_00139ab0();
    void FUN_00139ad0();
    void FUN_00139af0();
    void FUN_00139b10();
    void FUN_00139b20();
    void FUN_00139b40();
    void FUN_00139b60();
    void FUN_00139b80();
};
}
}

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

void FUN_0013c650()
{
    if (DAT_004e0f1c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("timeBegin", &hulkfight::motion::AnimationTrack::FUN_00139a30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("timeEnd", &hulkfight::motion::AnimationTrack::FUN_00139a40);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<hulkfight::motion::AnimationTrack>("animation", &hulkfight::motion::AnimationTrack::FUN_00139a50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("speed", &hulkfight::motion::AnimationTrack::FUN_00139a70);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("initFrame", &hulkfight::motion::AnimationTrack::FUN_00139a90);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("startFrame", &hulkfight::motion::AnimationTrack::FUN_00139ab0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("endFrame", &hulkfight::motion::AnimationTrack::FUN_00139ad0);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>("cyclic", ((const char**)&DAT_004abf70), 4, &hulkfight::motion::AnimationTrack::FUN_00139af0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<hulkfight::motion::AnimationTrack>("rootMotion", &hulkfight::motion::AnimationTrack::FUN_00139b10);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName<hulkfight::motion::AnimationTrack>("partition", &hulkfight::motion::AnimationTrack::FUN_00139b20);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamIntConstRange<hulkfight::motion::AnimationTrack>("priority", &hulkfight::motion::AnimationTrack::FUN_00139b40);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("blendInTime", &hulkfight::motion::AnimationTrack::FUN_00139b60);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationTrack>("blendOutTime", &hulkfight::motion::AnimationTrack::FUN_00139b80);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f18), params, 13);
    }
    DAT_004e0f1c++;
}
