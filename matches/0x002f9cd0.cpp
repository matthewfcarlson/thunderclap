#include "compat/ptr.h"
void Release(void*);
struct Obj_2f9cd0 {
    char pad[0x30];
    int a;
    hulk_intptr b;
    char pad2[8];
    int c;
    hulk_intptr d;
    void f();
};
void Obj_2f9cd0::f() {
    hulk_intptr x = c;
    d = x;
    if (x)
        Release((void*)x);
    x = a;
    b = x;
    if (x)
        Release((void*)x);
}