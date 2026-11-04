// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0005d370 @ 0x0005d370
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CHapticTrack_5d370 {
public:
    void FUN_0005d120(float);
    void FUN_0005d130(float);
    void FUN_0005d140(float);
    void FUN_0005d150(float);
    void FUN_0005d160(bool);
};

class __declspec(novtable) ParamFloatBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};

template <class T>
class ParamFloatConstRange : public ParamFloatBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)(float)) : ParamFloatBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)(float);
    int unused14;
};

template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)(bool)) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)(bool);
    int unused14;
};

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005d370()
{
    if (DAT_004dc5cc == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("timeBegin", &CHapticTrack_5d370::FUN_0005d120);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("timeEnd", &CHapticTrack_5d370::FUN_0005d130);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("rumbleStrengthBig", &CHapticTrack_5d370::FUN_0005d140);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("rumbleStrengthSmall", &CHapticTrack_5d370::FUN_0005d150);
        mem = FUN_0008d690((int)sizeof(ParamBool<CHapticTrack_5d370>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<CHapticTrack_5d370>("abortWhenInterrupted", &CHapticTrack_5d370::FUN_0005d160);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5c8), params, 5);
    }
    DAT_004dc5cc++;
}
