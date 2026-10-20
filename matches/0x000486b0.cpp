#include "compat/ptr.h"
extern "C" char DAT_003f6e4c[];
struct CAxisTimeCondition {
    void* vtable;
    int pad0[2];
    int fieldC;
    int field10;
    int field14;
    CAxisTimeCondition();
};
struct ThisCall_00234590 {
    void Init(int);
};
CAxisTimeCondition::CAxisTimeCondition() {
    ((ThisCall_00234590*)(this))->Init(0);
    fieldC = 0;
    vtable = (void*)((hulk_intptr)DAT_003f6e4c);
    field10 = 4;
    field14 = 0;
}