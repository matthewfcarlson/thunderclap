// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"


// 0x00072640 FUN_00072640 (95 B): equivalent/0x00072640.cpp [isolated: compile error C2664: 'fn_00072640::fight::ParamFloatConstRange<T>::ParamFloatConstRange(const char *,void (__thiscall CDeathTrack::* )(void))]
// sym: _FUN_00072640
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00072640 @ 0x00072640
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CDeathTrack {
public:
    void FUN_00068b30();
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

extern "C" void FUN_00072640()
{
    if (DAT_004dd004 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CDeathTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CDeathTrack>("timeBegin", &::CDeathTrack::FUN_00068b30);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd000), params, 1);
    }
    DAT_004dd004++;
}

