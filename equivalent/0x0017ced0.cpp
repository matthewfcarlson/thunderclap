// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_0017ced0 @ 0x0017ced0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class SyncToLocatorTrack_17ced0 {
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
class ParamEnumConstList_17ced0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_17ced0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_17ced0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ced0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_17ced0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17ced0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_17ced0 : public ParamNameBase {
public:
    ParamName_17ced0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamScript_17ced0 : public ParamScriptBase {
public:
    ParamScript_17ced0(const char* name, void (T::*s)()) : ParamScriptBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_17ced0 : public ParamVectorBase {
public:
    ParamVector_17ced0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017ced0()
{
    if (DAT_004e1314 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("timeBegin", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec60);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("timeEnd", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec70);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("rotationEnd", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ec90);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("translationEnd", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ecb0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("locatorName", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ecc0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamScript_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("locatorInitScript", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_00170130);
        mem = FUN_0008d690(0x20);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamEnumConstList_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("rotationOverride", ((const char**)&DAT_004b7cfc), 3, &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed00);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("orientOffset", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed20);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("positionOffset", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed60);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("priority", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016ed90);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("blendInTime", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016edb0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_17ced0<hulkfight::motion::SyncToLocatorTrack_17ced0>("blendOutTime", &hulkfight::motion::SyncToLocatorTrack_17ced0::FUN_0016edd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1310), params, 12);
    }
    DAT_004e1314++;
}
