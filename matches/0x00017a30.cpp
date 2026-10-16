#include "gen/global.h"

extern float kZeroF;
struct A_17a30 {
    char pad[8];
    A_17a30(const float& f);
    void done();
};
struct Obj_17a30 {
    void use(A_17a30* a);
};
struct T_17a30 {
    void* first();
};
struct Base_17a30 {
    char pad[0x1b50];
};
struct U_17a30 {
    Base_17a30* second();
};

void CAIHintAction::vfunc_4() {
    T_17a30* a = (T_17a30*)(*(void * *)&this->f_1c);
    U_17a30* b = (U_17a30*)a->first();
    Base_17a30* o = b->second();
    A_17a30 local(kZeroF);
    ((Obj_17a30*)((char*)o + 0x1b50))->use(&local);
    local.done();
}
