// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_0017ced0 @ 0x0017ced0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class SyncToLocatorTrack {
public:
    void FUN_0016ec60();
    void FUN_0016ec70();
    void FUN_0016ec90();
    void FUN_0016ecb0();
    void FUN_0016ecc0();
    void FUN_00170130();
    void FUN_0016ed00();
    void FUN_0016ed20();
    void FUN_0016ed60();
    void FUN_0016ed90();
    void FUN_0016edb0();
    void FUN_0016edd0();
};
}
}

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
class __declspec(novtable) ParamScriptBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234c00(const char* name);
    ParamScriptBase(const char* name) { FUN_00234c00(name); }
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
template <class T>
class ParamScript : public ParamScriptBase {
public:
    ParamScript(const char* name, void (T::*s)()) : ParamScriptBase(name) { setter = s; }
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

void FUN_0017ced0()
{
    if (DAT_004e1314 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("timeBegin", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ec60);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("timeEnd", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ec70);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("rotationEnd", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ec90);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("translationEnd", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ecb0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName<hulkfight::motion::SyncToLocatorTrack>("locatorName", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ecc0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamScript<hulkfight::motion::SyncToLocatorTrack>("locatorInitScript", &hulkfight::motion::SyncToLocatorTrack::FUN_00170130);
        mem = FUN_0008d690(0x20);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>("rotationOverride", ((const char**)&DAT_004b7cfc), 3, &hulkfight::motion::SyncToLocatorTrack::FUN_0016ed00);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("orientOffset", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ed20);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector<hulkfight::motion::SyncToLocatorTrack>("positionOffset", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ed60);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange<hulkfight::motion::SyncToLocatorTrack>("priority", &hulkfight::motion::SyncToLocatorTrack::FUN_0016ed90);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("blendInTime", &hulkfight::motion::SyncToLocatorTrack::FUN_0016edb0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SyncToLocatorTrack>("blendOutTime", &hulkfight::motion::SyncToLocatorTrack::FUN_0016edd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1310), params, 12);
    }
    DAT_004e1314++;
}
