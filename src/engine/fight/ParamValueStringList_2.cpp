// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234af0..0x00234c00 (kind game, layer engine, confidence medium), dominant class fight::ParamValueStringList
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7578ec5 {
#define TREE_TU_END }
namespace fn_f7578ec5 {} using namespace fn_f7578ec5;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7578ec5 {

} // namespace fn_f7578ec5

// 0x00234af0 FUN_00234af0 (34 B): matches/0x00234af0.cpp
// sym: ??0ParamValueStringList@fight@@QAE@PBD@Z
// (gx4, D18) the constructor the parameter registrations call (`new ParamStringConstList<T>(name, setter)`)
fight::ParamValueStringList::ParamValueStringList(const char* name) : fight::ParamValue(name) {}


// 0x00234ba0 FUN_00234ba0 (34 B): matches/0x00234ba0.cpp
// sym: ??0ParamValueNameList@fight@@QAE@PBD@Z
// (gx4, D18) the constructor the parameter registrations call (`new ParamNameConstList<T>(name, setter)`,
// `new ParamNameList<T>(name, setter)`); it inlines ParamValueStringList's (this object's; its vftable store is dead),
// so it belongs to this object (config/splits.json; it was ParamValueScript.iso_00234ba0.cpp)
fight::ParamValueNameList::ParamValueNameList(const char* name) : fight::ParamValueStringList(name) {}


// 0x00234bd0 fight::ParamValueNameList::vfunc_6 (36 B): matches/0x00234bd0.cpp
// sym: ?vfunc_6@ParamValueNameList@fight@fn_f1ee0f39@@QAE_NPAX0@Z
// (gx4) moved from ParamValueScript.cpp with its object (config/splits.json); its declarations kept in its namespace
namespace fn_f1ee0f39 {
class ParamValueStringList_234bd0 {
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
namespace fight {
class ParamValueNameList : public ParamValueStringList_234bd0 {
  public:
    bool vfunc_6(void*, void*);
};
}
class Receiver_234bd0 {
  public:
    void run_0027b040(void*);
};
bool fight::ParamValueNameList::vfunc_6(void* a, void* b) {
    void* x = get(a);
    if (!x)
        return false;
    ((Receiver_234bd0*)x)->run_0027b040(b);
    return true;
}
} // namespace fn_f1ee0f39

