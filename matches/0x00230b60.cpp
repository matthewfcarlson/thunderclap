#include "compat/ptr.h"
struct X_230b60 {
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    char pad[3];
    int f;
    void Init();
};
void X_230b60::Init() {
    int* p = &b;
    a = (hulk_intptr)p;
    b = (hulk_intptr)p;
    c = (hulk_intptr)p;
    d = (hulk_intptr)p;
    e = 0;
    f = 0;
}