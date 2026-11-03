#include "gen/global.h"
#include "gen/owners.h"

struct Obj_17a00 {
};
struct Obj2_17a00 {
    void* g();
};
struct Obj3_17a00 {
    void h(void*);
};
class CAction_17a00 {
  public:
    char pad[0x1c];
    Obj_17a00* one;
    Obj_17a00* two;
};

bool CAIHintAction::vfunc_6(int x) {
    Obj_17a00* o = (*(Obj_17a00 * *)&this->f_1c);
    void* a = ((void *)((owners::Object_592a0 *)o)->FUN_000592a0());
    void* b = ((Obj2_17a00*)a)->g();
    ((Obj3_17a00*)((char*)b + 0x1b50))->h((char*)(*(Obj_17a00 * *)&this->f_20) + 0x18);
    return true;
}
