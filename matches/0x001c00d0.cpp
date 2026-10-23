#include "decls/address.h"
extern char DAT_0048e100[];
extern char DAT_0048e128[];
class Function_1c00d0 {
  public:
    Function_1c00d0(void*, int);
    virtual void Run();
    char pad[12];
};
class Method1 : public Function_1c00d0 {
  public:
    Method1(void* a, void* c) : Function_1c00d0(a, 1) {
        p = c;
        y = FUN_001d04d0(DAT_0048e100);
        x = FUN_001d04d0(DAT_0048e128);
    }
    virtual void Run();
    char x;
    char pad2[7];
    char y;
    char pad3[3];
    void* p;
};
class Closure1 : public Method1 {
  public:
    Closure1(void* a, void* b, void* c);
    virtual void Run();
    void* q;
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}
