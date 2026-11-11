// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"


// 0x00074cf0 FUN_00074cf0 (158 B): equivalent/0x00074cf0.cpp [isolated: compile error C2664: 'fn_00074cf0::fight::ParamName<T>::ParamName(const char *,void (__thiscall CScrubberTrack::* )(void))' : cannot convert ]
// sym: _FUN_00074cf0 @6549ff266ec9 @w6cab64159398
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00074cf0 @ 0x00074cf0
#include "decls/data/game/global.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CScrubberTrack {
public:
    void FUN_00068e70();
    void FUN_00068eb0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00074cf0()
{
    if (DAT_004dcf14 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName<::CScrubberTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<::CScrubberTrack>("animation", &::CScrubberTrack::FUN_00068e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CScrubberTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CScrubberTrack>("frame", &::CScrubberTrack::FUN_00068eb0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf10), params, 2);
    }
    DAT_004dcf14++;
}

