// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238190..0x00238850 (kind game, layer engine, confidence high), dominant class fight::MaybeCondition
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f72cb377 {
#define TREE_TU_END }
namespace fn_f72cb377 {} using namespace fn_f72cb377;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f72cb377 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f72cb377
namespace fight {
class MaybeCondition_2385b0 {
public:
    bool FUN_002381c0(int); /* (unb4) as defined; address taken only */
};
}
namespace fn_f72cb377 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f72cb377
namespace fight {
template <class T>
class ParamFloatConstRange_2385b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_2385b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f72cb377 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f72cb377
namespace fight {
class RandomCondition_238610 {
public:
    bool FUN_002381d0(int); /* (unb4) as defined; address taken only */
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_238610 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_238610(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f72cb377 {

// 0x002385b0 FUN_002385b0 (95 B): equivalent/0x002385b0.cpp
// sym: ?FUN_002385b0@fn_f72cb377@@YAXXZ @c25258bbe01e @w9749f6ec8b25
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_002385b0 @ 0x002385b0
void FUN_002385b0()
{
    if (DAT_004e5c10 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_2385b0<fight::MaybeCondition_2385b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_2385b0<fight::MaybeCondition_2385b0>("percent", (void (fight::MaybeCondition_2385b0::*)())&fight::MaybeCondition_2385b0::FUN_002381c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c0c), params, 1);
    }
    DAT_004e5c10++;
}


// 0x00238610 FUN_00238610 (95 B): equivalent/0x00238610.cpp
// sym: ?FUN_00238610@fn_f72cb377@@YAXXZ @9d8aae861901 @w1048e3ee5f6a
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_00238610 @ 0x00238610
void FUN_00238610()
{
    if (DAT_004e5c18 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_238610<fight::RandomCondition_238610>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_238610<fight::RandomCondition_238610>("weight", (void (fight::RandomCondition_238610::*)())&fight::RandomCondition_238610::FUN_002381d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c14), params, 1);
    }
    DAT_004e5c18++;
}

} // namespace fn_f72cb377
