// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 28/28)
// FUN_0013c650 @ 0x0013c650
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class AnimationTrack_13c650 {
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
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
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
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_13c650 : public ParamBoolBase {
public:
    ParamBool_13c650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_13c650 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_13c650(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_13c650 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13c650(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_13c650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13c650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_13c650 : public ParamNameBase {
public:
    ParamName_13c650(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013c650()
{
    if (DAT_004e0f1c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("timeBegin", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("timeEnd", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a40);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>("animation", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("speed", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a70);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("initFrame", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a90);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("startFrame", &hulkfight::motion::AnimationTrack_13c650::FUN_00139ab0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("endFrame", &hulkfight::motion::AnimationTrack_13c650::FUN_00139ad0);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList_13c650<hulkfight::motion::AnimationTrack_13c650>("cyclic", ((const char**)&DAT_004abf70), 4, &hulkfight::motion::AnimationTrack_13c650::FUN_00139af0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_13c650<hulkfight::motion::AnimationTrack_13c650>("rootMotion", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b10);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>("partition", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b20);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamIntConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("priority", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b40);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("blendInTime", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b60);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("blendOutTime", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b80);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f18), params, 13);
    }
    DAT_004e0f1c++;
}
