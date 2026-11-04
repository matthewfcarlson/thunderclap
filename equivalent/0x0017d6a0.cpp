// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_0017d6a0 @ 0x0017d6a0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class PushOutTrack {
public:
    void FUN_0016f250();
    void FUN_0016f260();
    void FUN_0016f270();
    void FUN_0016f2a0();
    void FUN_0016f2e0();
    void FUN_0016f310();
    void FUN_0016f330();
    void FUN_0016f350();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
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
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017d6a0()
{
    if (DAT_004e135c == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PushOutTrack>("timeBegin", &PushOutTrack::FUN_0016f250);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<PushOutTrack>("timeEnd", &PushOutTrack::FUN_0016f260);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<PushOutTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<PushOutTrack>("joint", &PushOutTrack::FUN_0016f270);
        mem = FUN_0008d690((int)sizeof(ParamVector<PushOutTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<PushOutTrack>("offset", &PushOutTrack::FUN_0016f2a0);
        mem = FUN_0008d690((int)sizeof(ParamVector<PushOutTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<PushOutTrack>("direction", &PushOutTrack::FUN_0016f2e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<PushOutTrack>("distance", &PushOutTrack::FUN_0016f310);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<PushOutTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<PushOutTrack>("velocity", &PushOutTrack::FUN_0016f330);
        mem = FUN_0008d690((int)sizeof(ParamBool<PushOutTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamBool<PushOutTrack>("allowY", &PushOutTrack::FUN_0016f350);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1358), params, 8);
    }
    DAT_004e135c++;
}
