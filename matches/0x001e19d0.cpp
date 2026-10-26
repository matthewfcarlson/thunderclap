#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class CSPManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_1e19d0 : public Base {
  public:
    virtual void invoke(float);
    char pad[0x0c];
    char x;
    char pad2[7];
    char y;
    char pad3[3];
    void* obj;
    Closure1_1e19d0(void*, void*);
};
class Closure1 : public Closure1_1e19d0 {
  public:
    virtual void invoke(float);
    void* data;
    Closure1(void*, void*, void*);
};
Closure1_1e19d0::Closure1_1e19d0(void* p, void* f) : Base(p) {
    obj = f;
    y = FUN_001d04d0(((const char*)&DAT_0048e100));
    x = FUN_001d04d0(((const char*)&DAT_0048e128));
}
Closure1::Closure1(void* p, void* f, void* q) : Closure1_1e19d0(p, q) {
    data = f;
}