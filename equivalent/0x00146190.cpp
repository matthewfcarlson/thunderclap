// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_00146190 @ 0x00146190
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class WorldDamageTrack {
public:
    void FUN_001432e0();
    void FUN_001432f0();
    void FUN_00143320();
    void FUN_00143360();
    void FUN_00143390();
    void FUN_001433b0();
    void FUN_001433d0();
    void FUN_001433f0();
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

class __declspec(novtable) ParamEnumBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumBase(const char* name) { FUN_00234cc0(name); }
};
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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

void FUN_00146190()
{
    if (DAT_004e0f94 == 0) {
        void* params[8];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<WorldDamageTrack>("timeBegin", &WorldDamageTrack::FUN_001432e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamNameConstList<WorldDamageTrack>("joint", &WorldDamageTrack::FUN_001432f0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<WorldDamageTrack>("position", &WorldDamageTrack::FUN_00143320);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<WorldDamageTrack>("direction", &WorldDamageTrack::FUN_00143360);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<WorldDamageTrack>("distance", &WorldDamageTrack::FUN_00143390);
        mem = FUN_0008d690(0x20);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamEnumConstList<WorldDamageTrack>("damageType", ((char**)&DAT_004ad788), 7, &WorldDamageTrack::FUN_001433b0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<WorldDamageTrack>("scaleX", &WorldDamageTrack::FUN_001433d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<WorldDamageTrack>("scaleY", &WorldDamageTrack::FUN_001433f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f90), params, 8);
    }
    DAT_004e0f94++;
}
