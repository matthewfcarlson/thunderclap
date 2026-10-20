// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_001195c0 @ 0x001195c0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class MotionBoostTrack {
public:
    void FUN_001151e0();
    void FUN_001151f0();
    void FUN_00115210();
    void FUN_00115230();
    void FUN_00115240();
    void FUN_00115250();
    void FUN_00115270();
    void FUN_00115280();
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

void FUN_001195c0()
{
    if (DAT_004e0c60 == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<MotionBoostTrack>("timeBegin", &MotionBoostTrack::FUN_001151e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<MotionBoostTrack>("timeEnd", &MotionBoostTrack::FUN_001151f0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<MotionBoostTrack>("distanceMin", &MotionBoostTrack::FUN_00115210);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<MotionBoostTrack>("distanceMax", &MotionBoostTrack::FUN_00115230);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<MotionBoostTrack>("heightMin", &MotionBoostTrack::FUN_00115240);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<MotionBoostTrack>("heightMax", &MotionBoostTrack::FUN_00115250);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<MotionBoostTrack>("speed", &MotionBoostTrack::FUN_00115270);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<MotionBoostTrack>("boost", &MotionBoostTrack::FUN_00115280);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c5c), params, 8);
    }
    DAT_004e0c60++;
}
