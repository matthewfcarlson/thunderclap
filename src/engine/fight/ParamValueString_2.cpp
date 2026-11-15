// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002349e0..0x00234af0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueString
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9940245 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9940245 {} using namespace fn_f9940245;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f9940245 {
} // namespace fn_f9940245


// 0x002349e0 FUN_002349e0 (34 B): matches/0x002349e0.cpp
// sym: ??0ParamValueString@fight@@QAE@PBD@Z
// (gx2, D18) the constructor the parameter registrations call (`new ParamString<T>(name, setter)`)
fight::ParamValueString::ParamValueString(const char* s) : fight::ParamValue(s) {}


// 0x00234a90 FUN_00234a90 (34 B): matches/0x00234a90.cpp
// sym: ??0ParamValueName@fight@@QAE@PBD@Z
// (gx4, D18) the constructor the parameter registrations call (`new ParamName<T>(name, setter)`); it inlines
// ParamValueString's (this object's; its vftable store is dead), so it belongs to this object (config/splits.json)
fight::ParamValueName::ParamValueName(const char* name) : fight::ParamValueString(name) {}


// 0x00234ac0 fight::ParamValueName::vfunc_6 (36 B): matches/0x00234ac0.cpp [wrapped: conflict: fight::ParamValueName]
// sym: ?vfunc_6@ParamValueName@fight@fn_00234ac0@@QAE_NPAX0@Z
namespace fn_00234ac0 {
class ParamValueString {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void* get(void*);
};
namespace fight { class ParamValueName : public ParamValueString {
  public:
    bool vfunc_6(void*, void*);
}; }
class Receiver_234ac0 {
  public:
    void run_0027b040(void*);
};
bool fight::ParamValueName::vfunc_6(void* a, void* b) {
    void* x = get(a);
    if (!x)
        return false;
    ((Receiver_234ac0*)x)->run_0027b040(b);
    return true;
}
} // namespace fn_00234ac0
