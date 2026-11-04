// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 26/26)
// FUN_00121250 @ 0x00121250
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class StrafeRunTrack {
public:
    void FUN_0011bbc0();
    void FUN_0011bbd0();
    void FUN_0011bbf0();
    void FUN_0011bc10();
    void FUN_0011bc40();
    void FUN_0011bc60();
    void FUN_0011bc80();
    void FUN_0011bca0();
    void FUN_0011bcc0();
    void FUN_0011bce0();
    void FUN_0011bd00();
    void FUN_0011bd20();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_121250 : public ParamBoolBase {
public:
    ParamBool_121250(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_121250 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_121250(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00121250()
{
    if (DAT_004e0cc4 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeBegin", &StrafeRunTrack::FUN_0011bbc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("timeEnd", &StrafeRunTrack::FUN_0011bbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("distance", &StrafeRunTrack::FUN_0011bbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("turnRate", &StrafeRunTrack::FUN_0011bc10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMin", &StrafeRunTrack::FUN_0011bc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("heightMax", &StrafeRunTrack::FUN_0011bc60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("groundHeightCutoff", &StrafeRunTrack::FUN_0011bc80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("cutoffExponent", &StrafeRunTrack::FUN_0011bca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useGroundHeightCutoff", &StrafeRunTrack::FUN_0011bcc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_121250<StrafeRunTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_121250<StrafeRunTrack>("useOffset", &StrafeRunTrack::FUN_0011bce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("offset", &StrafeRunTrack::FUN_0011bd00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_121250<StrafeRunTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_121250<StrafeRunTrack>("speed", &StrafeRunTrack::FUN_0011bd20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cc0), params, 12);
    }
    DAT_004e0cc4++;
}
