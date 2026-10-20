// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00064520 @ 0x00064520
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CSmartPropThrowingTrack {
public:
    void FUN_00061f30();
    void FUN_00061f40();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00064520()
{
    if (DAT_004dc654 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CSmartPropThrowingTrack>("timeBegin", &::CSmartPropThrowingTrack::FUN_00061f30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CSmartPropThrowingTrack>("timeEnd", &::CSmartPropThrowingTrack::FUN_00061f40);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc650), params, 2);
    }
    DAT_004dc654++;
}
