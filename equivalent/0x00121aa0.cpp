// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 46/46)
// FUN_00121aa0 @ 0x00121aa0
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class PathTrack {
public:
    void FUN_0011bfd0();
    void FUN_0011bfe0();
    void FUN_0011c000();
    void FUN_0011c010();
    void FUN_0011c030();
    void FUN_0011c040();
    void FUN_0011c050();
    void FUN_0011c060();
    void FUN_0011c070();
    void FUN_0011c080();
    void FUN_0011c0a0();
    void FUN_0011c870();
    void FUN_0011c0d0();
    void FUN_0011c0f0();
    void FUN_0011c100();
    void FUN_0011c120();
    void FUN_0011c140();
    void FUN_0011c160();
    void FUN_0011c180();
    void FUN_0011c1a0();
    void FUN_0011c1c0();
    void FUN_0011c1e0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00121aa0()
{
    if (DAT_004e0ce4 == 0) {
        void* params[22];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("timeBegin", &hulkfight::ai::PathTrack::FUN_0011bfd0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("timeEnd", &hulkfight::ai::PathTrack::FUN_0011bfe0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("distance", &hulkfight::ai::PathTrack::FUN_0011c000);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("turnRate", &hulkfight::ai::PathTrack::FUN_0011c010);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("heightMin", &hulkfight::ai::PathTrack::FUN_0011c030);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("heightMax", &hulkfight::ai::PathTrack::FUN_0011c040);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("speed", &hulkfight::ai::PathTrack::FUN_0011c050);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("destinationX", &hulkfight::ai::PathTrack::FUN_0011c060);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("destinationY", &hulkfight::ai::PathTrack::FUN_0011c070);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("destinationZ", &hulkfight::ai::PathTrack::FUN_0011c080);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("engagementDistance", &hulkfight::ai::PathTrack::FUN_0011c0a0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamString<hulkfight::ai::PathTrack>("tactic", &hulkfight::ai::PathTrack::FUN_0011c870);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool<hulkfight::ai::PathTrack>("defendLocator", &hulkfight::ai::PathTrack::FUN_0011c0d0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool<hulkfight::ai::PathTrack>("myLocator", &hulkfight::ai::PathTrack::FUN_0011c0f0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName<hulkfight::ai::PathTrack>("locatorName", &hulkfight::ai::PathTrack::FUN_0011c100);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamBool<hulkfight::ai::PathTrack>("useAvoidanceCode", &hulkfight::ai::PathTrack::FUN_0011c120);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool<hulkfight::ai::PathTrack>("useFormationPoints", &hulkfight::ai::PathTrack::FUN_0011c140);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("formationOffset", &hulkfight::ai::PathTrack::FUN_0011c160);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("seperationBufferStart", &hulkfight::ai::PathTrack::FUN_0011c180);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("seperationBufferStop", &hulkfight::ai::PathTrack::FUN_0011c1a0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("width", &hulkfight::ai::PathTrack::FUN_0011c1c0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathTrack>("formationWidth", &hulkfight::ai::PathTrack::FUN_0011c1e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ce0), params, 22);
    }
    DAT_004e0ce4++;
}
