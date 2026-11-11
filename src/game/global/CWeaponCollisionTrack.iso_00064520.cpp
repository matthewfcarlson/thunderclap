// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"


// 0x00064520 FUN_00064520 (158 B): equivalent/0x00064520.cpp [isolated: compile error C2039: 'FUN_00061f30' : is not a member of 'CSmartPropThrowingTrack']
// sym: _FUN_00064520 @4b5a3bf62140 @w86fa6f2deb97
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00064520 @ 0x00064520
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

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

extern "C" void FUN_00064520()
{
    if (DAT_004dc654 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CSmartPropThrowingTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CSmartPropThrowingTrack>("timeBegin", &::CSmartPropThrowingTrack::FUN_00061f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CSmartPropThrowingTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CSmartPropThrowingTrack>("timeEnd", &::CSmartPropThrowingTrack::FUN_00061f40);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc650), params, 2);
    }
    DAT_004dc654++;
}

