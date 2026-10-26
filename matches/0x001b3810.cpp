#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
extern const int Function4_vftable;
class Function4 : public Ctor_001d0480 {
  public:
    hulk_intptr vf;
    char p4[12];
    char m10, m11, m12, m13;
    char m14[4];
    char m18;
    char p19[3];
    int m1c;
    Function4(void*, int);
};
Function4::Function4(void* a, int b) : Ctor_001d0480(a, 4) {
    vf = (hulk_intptr)&Function4_vftable;
    m1c = b;
    m18 = FUN_001d04d0(((char*)&DAT_0048e100));
    m10 = FUN_001d04d0(((char*)&DAT_0048e134));
    m11 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    m12 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    m13 = FUN_001d04d0(((char*)&DAT_0048e128));
}
