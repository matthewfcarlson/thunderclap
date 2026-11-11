// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"


// 0x00072590 FUN_00072590 (170 B): equivalent/0x00072590.cpp [isolated: compile error C2664: 'fn_00072590::fight::ParamFloatConstRange<T>::ParamFloatConstRange(const char *,void (__thiscall CAlertStatusTrack::* )(]
// sym: _FUN_00072590 @44375d533dcf @w915d2a90ad3f
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00072590 @ 0x00072590
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CAlertStatusTrack {
public:
    void FUN_00068b10();
    void FUN_00068b20();
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
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

extern "C" void FUN_00072590()
{
    if (DAT_004dcffc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<::CAlertStatusTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CAlertStatusTrack>("timeBegin", &::CAlertStatusTrack::FUN_00068b10);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<::CAlertStatusTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<::CAlertStatusTrack>("status", ((const char**)&DAT_004a1ab4), (*(int*)&DAT_0040d0e4), &::CAlertStatusTrack::FUN_00068b20);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcff8), params, 2);
    }
    DAT_004dcffc++;
}

