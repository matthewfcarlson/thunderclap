// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234a90..0x00234ba0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueStringList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7578ec5 {
#define TREE_TU_END }
namespace fn_f7578ec5 {} using namespace fn_f7578ec5;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7578ec5 {
extern "C" char DAT_00427a98[];
struct Member_234a90 {
    void Init(const char*);
};
extern int vtBase_234af0;
extern int vtList;
class Part_234af0 {
  public:
    void Init(int);
};
class ParamValueStringList {
  public:
    int vptr;
    int pad;
    Part_234af0 part;
    ParamValueStringList(hulk_intptr);
};

} // namespace fn_f7578ec5

// 0x00234a90 FUN_00234a90 (34 B): matches/0x00234a90.cpp
// sym: ?FUN_00234a90@ParamValueName@fight@@QAEPAV12@PBD@Z
fight::ParamValueName* fight::ParamValueName::FUN_00234a90(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234a90*)((char*)this + 8))->Init(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a98);
    return (fight::ParamValueName*)(this);
}


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
    void run(void*);
};
bool fight::ParamValueName::vfunc_6(void* a, void* b) {
    void* x = get(a);
    if (!x)
        return false;
    ((Receiver_234ac0*)x)->run(b);
    return true;
}
} // namespace fn_00234ac0

namespace fn_f7578ec5 {

// 0x00234af0 FUN_00234af0 (34 B): matches/0x00234af0.cpp
// sym: ??0ParamValueStringList@fn_f7578ec5@@QAE@H@Z
ParamValueStringList::ParamValueStringList(hulk_intptr x) {
    int* p = &vptr;
    *(hulk_intptr*)p = (hulk_intptr)&vtBase_234af0;
    part.Init(x);
    *(hulk_intptr*)p = (hulk_intptr)&vtList;
}

} // namespace fn_f7578ec5
