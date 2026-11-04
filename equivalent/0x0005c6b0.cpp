// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0005c6b0 @ 0x0005c6b0
#include "gen/fight.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CGrappleLocoStrafe4Track_5c6b0 {
public:
    void FUN_0005a0d0();
    void FUN_0005a0e0();
    void FUN_00012900();
    void FUN_00012910();
    void FUN_00012920();
    void FUN_00012930();
    void FUN_00012940();
    void FUN_00012950();
    void FUN_00012960();
    void FUN_00012970();
    void FUN_00012980();
    void FUN_00012990();
    void FUN_000129a0();
    void FUN_0005a0f0();
    void FUN_0005a100();
    void FUN_0005a110();
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
class ParamFloatConstRange_5c6b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5c6b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_5c6b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5c6b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_5c6b0 : public ParamNameBase {
public:
    ParamName_5c6b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_4dc590;
extern int DAT_4dc594;

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005c6b0()
{
    if (DAT_4dc594 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("timeBegin", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("timeEnd", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("locomotion", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012900);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animIdle", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012910);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkNorth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012920);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkEast", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012930);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkSouth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012940);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animWalkWest", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012950);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunNorth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012960);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunEast", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012970);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunSouth", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012980);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("animRunWest", &::CGrappleLocoStrafe4Track_5c6b0::FUN_00012990);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("partition", &::CGrappleLocoStrafe4Track_5c6b0::FUN_000129a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("priority", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("blendInTime", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_5c6b0<::CGrappleLocoStrafe4Track_5c6b0>("blendOutTime", &::CGrappleLocoStrafe4Track_5c6b0::FUN_0005a110);
        FUN_002347b0(&DAT_4dc590, params, 16);
    }
    DAT_4dc594++;
}
