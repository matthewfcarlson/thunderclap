// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0005c6b0 @ 0x0005c6b0
#include "compat/ptr.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CGrappleLocoStrafe4Track {
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
extern ParamRegistry DAT_4dc590;
extern int DAT_4dc594;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005c6b0()
{
    if (DAT_4dc594 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CGrappleLocoStrafe4Track>("timeBegin", &::CGrappleLocoStrafe4Track::FUN_0005a0d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CGrappleLocoStrafe4Track>("timeEnd", &::CGrappleLocoStrafe4Track::FUN_0005a0e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("locomotion", &::CGrappleLocoStrafe4Track::FUN_00012900);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animIdle", &::CGrappleLocoStrafe4Track::FUN_00012910);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animWalkNorth", &::CGrappleLocoStrafe4Track::FUN_00012920);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animWalkEast", &::CGrappleLocoStrafe4Track::FUN_00012930);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animWalkSouth", &::CGrappleLocoStrafe4Track::FUN_00012940);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animWalkWest", &::CGrappleLocoStrafe4Track::FUN_00012950);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animRunNorth", &::CGrappleLocoStrafe4Track::FUN_00012960);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animRunEast", &::CGrappleLocoStrafe4Track::FUN_00012970);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animRunSouth", &::CGrappleLocoStrafe4Track::FUN_00012980);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("animRunWest", &::CGrappleLocoStrafe4Track::FUN_00012990);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<::CGrappleLocoStrafe4Track>("partition", &::CGrappleLocoStrafe4Track::FUN_000129a0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<::CGrappleLocoStrafe4Track>("priority", &::CGrappleLocoStrafe4Track::FUN_0005a0f0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<::CGrappleLocoStrafe4Track>("blendInTime", &::CGrappleLocoStrafe4Track::FUN_0005a100);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<::CGrappleLocoStrafe4Track>("blendOutTime", &::CGrappleLocoStrafe4Track::FUN_0005a110);
        FUN_002347b0(&DAT_4dc590, params, 16);
    }
    DAT_4dc594++;
}
