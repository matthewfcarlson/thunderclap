#include "decls/address.h"
struct MessageOverlay;
extern int g1, g2;
struct Function_d6290 {
    virtual void f();
    Function_d6290(void*, int);
};
struct Method1 : Function_d6290 {
    char pad[0xc];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    void* p;
    Method1(void*, void*);
    virtual void f();
};
struct Closure1 : Method1 {
    void* q;
    Closure1(void*, void*, void*);
    virtual void f();
};
inline Method1::Method1(void* x, void* y) : Function_d6290(x, 1) {
    p = y;
    a = FUN_001d04d0(&g1);
    b = FUN_001d04d0(&g2);
}
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}
