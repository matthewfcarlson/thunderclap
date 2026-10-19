#include "decls/address.h"
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
extern char G0, G1, G2, G3;
extern const int Function4_vftable;
class Function4 : public Ctor_001d0480 {
  public:
    int vf;
    char p4[12];
    char m10, m11, m12, m13;
    char m14[4];
    char m18;
    char p19[3];
    int m1c;
    Function4(void*, int);
};
Function4::Function4(void* a, int b) : Ctor_001d0480(a, 4) {
    vf = (int)&Function4_vftable;
    m1c = b;
    m18 = FUN_001d04d0(&G0);
    m10 = FUN_001d04d0(&G1);
    m11 = FUN_001d04d0(&G2);
    m12 = FUN_001d04d0(&G2);
    m13 = FUN_001d04d0(&G3);
}
