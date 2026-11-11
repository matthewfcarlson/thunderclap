// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"


// 0x00064280 FUN_00064280 (95 B): equivalent/0x00064280.cpp [isolated: compile error C2039: 'FUN_00061e50' : is not a member of 'CSmartPropDetachTrack']
// sym: _FUN_00064280
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00064280 @ 0x00064280
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropDetachTrack {
public:
    void FUN_00061e50();
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

extern "C" void FUN_00064280()
{
    if (DAT_004dc644 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CSmartPropDetachTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CSmartPropDetachTrack>("timeBegin", &::CSmartPropDetachTrack::FUN_00061e50);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc640), params, 1);
    }
    DAT_004dc644++;
}

