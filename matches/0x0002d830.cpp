#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003f421c[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
extern const char g1_2d830[], g2[], g3[];
class CActorManager : public Ctor_001d0480 {
  public:
    int vptr;
    char pad4[0xc];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
CActorManager::CActorManager(const char* a, int b) : Ctor_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_003f421c);
    m1c = b;
    b18 = FUN_001d04d0(g1_2d830);
    b10 = FUN_001d04d0(g2);
    b11 = FUN_001d04d0(g3);
    b12 = FUN_001d04d0(g3);
    b13 = FUN_001d04d0(g3);
}