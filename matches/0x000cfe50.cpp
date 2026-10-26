#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: a_cfe50 = DAT_0048e100
class Function_cfe50 {
  public:
    virtual void f();
    Function_cfe50(void*, int);
};
class Method2 : public Function_cfe50 {
  public:
    virtual void g();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    void* obj;
    Method2(void* p, void* q) : Function_cfe50(p, 2) {
        obj = q;
        z = FUN_001d04d0(((char*)&DAT_0048e100));
        x = FUN_001d04d0(&DAT_0048e0e4);
        y = FUN_001d04d0(((char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void h();
    void* extra;
    Closure2(void* p, void* q, void* r);
};
Closure2::Closure2(void* p, void* q, void* r) : Method2(p, r) {
    extra = q;
}