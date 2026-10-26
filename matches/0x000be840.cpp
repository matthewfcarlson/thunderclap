#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_be840 {
  public:
    Function_be840(void* a, int n);
    virtual void Call();
    char pad[0x0c];
};

class Method7 : public Function_be840 {
  public:
    Method7(void* a, int b);
    virtual void Call();
    char m10, m11, m12, m13, m14, m15, m16, m17;
    char m18;
    char pad2[3];
    int m1c;
};


Method7::Method7(void* a, int b) : Function_be840(a, 7) {
    m1c = b;
    m18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    m10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m11 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m12 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m13 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m14 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m15 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    m16 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
