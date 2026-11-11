// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d850..0x0005fa10 (kind game, layer game, confidence high), dominant class CCollisionTrack
#include "tree_prelude.h"


// 0x0005ef60 FUN_0005ef60 (95 B): equivalent/0x0005ef60.cpp [isolated: compile error C2039: 'FUN_0005d8f0' : is not a member of 'CClearHitRecordsTrack']
// sym: _FUN_0005ef60
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0005ef60 @ 0x0005ef60
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CClearHitRecordsTrack {
public:
    void FUN_0005d8f0();
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

extern "C" void FUN_0005ef60()
{
    if (DAT_004dc5fc == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CClearHitRecordsTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CClearHitRecordsTrack>("timeBegin", &::CClearHitRecordsTrack::FUN_0005d8f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5f8), params, 1);
    }
    DAT_004dc5fc++;
}

