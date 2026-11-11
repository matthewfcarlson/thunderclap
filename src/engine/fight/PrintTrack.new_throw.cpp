// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f3f601e0 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3f601e0 {} using namespace fn_f3f601e0;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3f601e0 {
extern "C" void* FUN_0008d690(unsigned int size);
namespace fight {
class PrintCondition {
public:
    void FUN_00238910();
    void FUN_00238970();
};
}
namespace fight {
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x00238f70 FUN_00238f70 (158 B): equivalent/0x00238f70.cpp
// sym: ?FUN_00238f70@fn_f3f601e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00238f70 @ 0x00238f70
void FUN_00238f70()
{
    if (DAT_004e5c24 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::PrintCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<fight::PrintCondition>("channel", &fight::PrintCondition::FUN_00238910);
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::PrintCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<fight::PrintCondition>("text", &fight::PrintCondition::FUN_00238970);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c20), params, 2);
    }
    DAT_004e5c24++;
}

} // namespace fn_f3f601e0
