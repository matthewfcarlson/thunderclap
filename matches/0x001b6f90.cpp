#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0041dc30[];
struct Other_1b6f90 {
    virtual void A();
    virtual void B();
};
struct C_1b6f90 {
    void* vptr;
    char pad[8];
    Other_1b6f90* obj;
    void F();
};
void C_1b6f90::F() {
    vptr = (void*)((hulk_intptr)DAT_0041dc30);
    obj->B();
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}