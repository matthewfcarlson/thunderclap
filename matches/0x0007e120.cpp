#include "decls/address.h"
extern void __stdcall FUN_001d0480(const char*, int);
extern const char a[], b[];
class Init {
  public:
    Init(const char* s) { FUN_001d0480(s, 1); }
};
class Method1 : public Init {
  public:
    virtual void f();
    char pad[0xc];
    char y;
    char pad2[7];
    char x;
    char pad3[3];
    void* name;
    Method1(const char* s, void* p) : Init(s) {
        name = p;
        x = FUN_001d04d0(a);
        y = FUN_001d04d0(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* obj;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* o, void* p) : Method1(s, p) {
    obj = o;
}