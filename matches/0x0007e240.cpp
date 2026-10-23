#include "decls/address.h"
class CAmbientsManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern const char DAT_0048e100[];
extern const char DAT_0048e128[];
class Function_7e240 : public CtorV_001d0480 {
  public:
    Function_7e240(void* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_7e240 {
  public:
    virtual void Invoke(float);
    char pad[12];
    char flag1;
    char pad2[7];
    char flag2;
    char pad3[3];
    void* obj;
    Method1(void* x, void* z) : Function_7e240(x) {
        obj = z;
        flag2 = FUN_001d04d0(DAT_0048e100);
        flag1 = FUN_001d04d0(DAT_0048e128);
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
