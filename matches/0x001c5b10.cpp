#include "gen/owners.h"
typedef unsigned int U_1c5b10;
struct Part_1c5b10 {
    void f5d30();
};
struct Sub_1c5b10 {
    U_1c5b10 f75e0(U_1c5b10);
    void f7550(U_1c5b10);
};
extern void __cdecl thunk(U_1c5b10);
void owners::Obj_1c5b10::FUN_001c5b10(U_1c5b10 arg) {
    Sub_1c5b10* sub = (Sub_1c5b10*)((char*)this + 0x128);
    U_1c5b10 r = sub->f75e0(arg);
    sub->f7550(arg);
    if (r) {
        ((Part_1c5b10*)r)->f5d30();
        thunk(r);
    }
}
