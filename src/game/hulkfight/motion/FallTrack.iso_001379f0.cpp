// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"


// 0x001379f0 FUN_001379f0 (358 B): equivalent/0x001379f0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?FUN_001379f0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 14/14)
// FUN_001379f0 @ 0x001379f0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class FlyingDashTrack {
public:
    void FUN_00133010();
    void FUN_00133020();
    void FUN_00133040();
    void FUN_00133060();
    void FUN_00133080();
    void FUN_001330a0();
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

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001379f0()
{
    if (DAT_004e0ec4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<FlyingDashTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<FlyingDashTrack>("timeBegin", &FlyingDashTrack::FUN_00133010);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<FlyingDashTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<FlyingDashTrack>("timeEnd", &FlyingDashTrack::FUN_00133020);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<FlyingDashTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<FlyingDashTrack>("velocity", &FlyingDashTrack::FUN_00133040);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<FlyingDashTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<FlyingDashTrack>("priority", &FlyingDashTrack::FUN_00133060);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<FlyingDashTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<FlyingDashTrack>("blendInTime", &FlyingDashTrack::FUN_00133080);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<FlyingDashTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<FlyingDashTrack>("blendOutTime", &FlyingDashTrack::FUN_001330a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ec0), params, 6);
    }
    DAT_004e0ec4++;
}

