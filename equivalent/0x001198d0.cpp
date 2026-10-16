// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001198d0 @ 0x001198d0
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class MotionChaseTrack {
public:
    void FUN_00115490();
    void FUN_001154a0();
    void FUN_001154c0();
    void FUN_001154e0();
    void FUN_00115500();
    void FUN_00115520();
    void FUN_00115540();
    void FUN_00115550();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001198d0()
{
    if (DAT_004e0c78 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionChaseTrack>("timeBegin", &MotionChaseTrack::FUN_00115490);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionChaseTrack>("timeEnd", &MotionChaseTrack::FUN_001154a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionChaseTrack>("distanceMin", &MotionChaseTrack::FUN_001154c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<MotionChaseTrack>("distanceMax", &MotionChaseTrack::FUN_001154e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionChaseTrack>("heightMin", &MotionChaseTrack::FUN_00115500);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<MotionChaseTrack>("heightMax", &MotionChaseTrack::FUN_00115520);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<MotionChaseTrack>("speed", &MotionChaseTrack::FUN_00115540);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<MotionChaseTrack>("boost", &MotionChaseTrack::FUN_00115550);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c74), params, 8);
    }
    DAT_004e0c78++;
}
