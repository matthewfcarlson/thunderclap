// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 14/14)
// FUN_00179dc0 @ 0x00179dc0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class SuckTrack {
public:
    void FUN_0016ede0();
    void FUN_0016edf0();
    void FUN_0016ee10();
    void FUN_0016ee30();
    void FUN_0016ee50();
    void FUN_0016ee70();
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

void FUN_00179dc0()
{
    if (DAT_004e131c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SuckTrack>("timeBegin", &SuckTrack::FUN_0016ede0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SuckTrack>("timeEnd", &SuckTrack::FUN_0016edf0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<SuckTrack>("distanceMin", &SuckTrack::FUN_0016ee10);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<SuckTrack>("distanceMax", &SuckTrack::FUN_0016ee30);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<SuckTrack>("velocityMin", &SuckTrack::FUN_0016ee50);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<SuckTrack>("velocityMax", &SuckTrack::FUN_0016ee70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1318), params, 6);
    }
    DAT_004e131c++;
}
