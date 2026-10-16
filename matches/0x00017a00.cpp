#include "gen/global.h"

struct Obj_17a00 {
    void* f();
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
    void* a = o->f();
    void* b = ((Obj2_17a00*)a)->g();
    ((Obj3_17a00*)((char*)b + 0x1b50))->h((char*)(*(Obj_17a00 * *)&this->f_20) + 0x18);
    return true;
}
