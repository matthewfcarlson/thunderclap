// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_0018b140 @ 0x0018b140
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class PropSpawnTrack {
public:
    void FUN_00180430();
    void FUN_00181670();
    void FUN_00180450();
    void FUN_00180480();
    void FUN_001804c0();
    void FUN_00180520();
    void FUN_00180560();
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

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
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

void FUN_0018b140()
{
    if (DAT_004e14e4 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PropSpawnTrack>("timeBegin", &PropSpawnTrack::FUN_00180430);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamString<PropSpawnTrack>("propName", &PropSpawnTrack::FUN_00181670);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<PropSpawnTrack>("joint", &PropSpawnTrack::FUN_00180450);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<PropSpawnTrack>("offset", &PropSpawnTrack::FUN_00180480);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<PropSpawnTrack>("orient", &PropSpawnTrack::FUN_001804c0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamVector<PropSpawnTrack>("impulse", &PropSpawnTrack::FUN_00180520);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamVector<PropSpawnTrack>("impulseOffset", &PropSpawnTrack::FUN_00180560);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14e0), params, 7);
    }
    DAT_004e14e4++;
}
