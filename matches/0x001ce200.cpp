#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class Function_1ce200 {
  public:
    virtual void Invoke(float);
    Function_1ce200(void*, int);
};
class Method1 : public Function_1ce200 {
  public:
    virtual void Invoke(float);
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* obj;
    Method1(void* p, void* q) : Function_1ce200(p, 1) {
        obj = q;
        y = FUN_001d04d0(((const char*)&DAT_0048e100));
        x = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* fn;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    fn = q;
}