// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0017a860 @ 0x0017a860
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class TargetIconDistanceTrack {
public:
    void FUN_0016f800();
    void FUN_0016f810();
    void FUN_0016f830();
    void FUN_0016f850();
    void FUN_0016f870();
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

void FUN_0017a860()
{
    if (DAT_004e137c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("timeBegin", &TargetIconDistanceTrack::FUN_0016f800);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("timeEnd", &TargetIconDistanceTrack::FUN_0016f810);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("distanceMin", &TargetIconDistanceTrack::FUN_0016f830);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("distanceMax", &TargetIconDistanceTrack::FUN_0016f850);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<TargetIconDistanceTrack>("extensionTime", &TargetIconDistanceTrack::FUN_0016f870);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1378), params, 5);
    }
    DAT_004e137c++;
}
