#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
typedef unsigned char u8;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Function_9c440 : public CtorV_001d0480 {
  public:
    Function_9c440(void* a) : CtorV_001d0480(a, 2) { }
};
class Method2 : public Function_9c440 {
  public:
    virtual void Fn();
    char pad[0xc];
    u8 b10, b11;
    char pad2[6];
    u8 b18;
    char pad3[3];
    void* p1;
    void* p2;
    Method2(void* a, void* b) : Function_9c440(a) {
        p1 = b;
        b18 = FUN_001d04d0(((int*)&DAT_0048e100));
        b10 = FUN_001d04d0(((int*)&DAT_0048e128));
        b11 = FUN_001d04d0(((int*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void Fn();
    Closure2(void*, void*, void*);
};
Closure2::Closure2(void* a, void* b, void* c) : Method2(a, c) {
    p2 = b;
}