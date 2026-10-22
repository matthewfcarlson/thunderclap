#include "decls/address.h"
extern const char gA_2e9a0[];
extern const char gB_2e9a0[];
struct Function_2e9a0 {
    virtual void f0();
    Function_2e9a0(int, int);
    char pad[12];
    char b10;
    char p11[7];
    char b18;
};
struct Method1 : Function_2e9a0 {
    Method1(int a, int b) : Function_2e9a0(a, 1) {
        m1c = b;
        b18 = FUN_001d04d0(gA_2e9a0);
        b10 = FUN_001d04d0(gB_2e9a0);
    }
    virtual void f0();
    int m1c;
};
struct Closure1 : Method1 {
    Closure1(int a, int c, int b);
    virtual void f0();
    int m20;
};
Closure1::Closure1(int a, int c, int b) : Method1(a, b) {
    m20 = c;
}
