// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"


// 0x000726a0 FUN_000726a0 (158 B): equivalent/0x000726a0.cpp [isolated: compile error C2664: 'fn_000726a0::fight::ParamFloatConstRange<T>::ParamFloatConstRange(const char *,void (__thiscall CClearCollisionStun::* ]
// sym: _FUN_000726a0 @5106a02a53aa @w008c54418ff1
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000726a0 @ 0x000726a0
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CClearCollisionStun {
public:
    void FUN_00068b70();
    void FUN_00068b80();
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

extern "C" void FUN_000726a0()
{
    if (DAT_004dd014 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CClearCollisionStun>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CClearCollisionStun>("timeBegin", &::CClearCollisionStun::FUN_00068b70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CClearCollisionStun>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CClearCollisionStun>("timeEnd", &::CClearCollisionStun::FUN_00068b80);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd010), params, 2);
    }
    DAT_004dd014++;
}

