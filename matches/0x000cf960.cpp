#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class Function_cf960 {
  public:
    virtual void Invoke(float);
    Function_cf960(void*, int);
};
class Method1 : public Function_cf960 {
  public:
    virtual void Invoke(float);
    char pad[0x0c];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* obj;
    Method1(void* x, void* y) : Function_cf960(x, 1) {
        obj = y;
        b = FUN_001d04d0(((const char*)&DAT_0048e100));
        a = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* extra;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    extra = y;
}