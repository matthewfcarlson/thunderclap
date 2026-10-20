#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_004234c8[];
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
class Method6_1e0eb0 : public Ctor_001d0480 {
  public:
    int vp;
    char p04[0xc];
    char m10;
    char m11;
    char m12;
    char m13;
    char m14;
    char m15;
    char p16[2];
    char m18;
    char p19[3];
    int m1c;
    Method6_1e0eb0(int, int);
};
Method6_1e0eb0::Method6_1e0eb0(int a, int b) : Ctor_001d0480((void*)a, 6) {
    vp = ((int)DAT_004234c8);
    m1c = b;
    m18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e134)));
    m11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    m12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    m13 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    m14 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    m15 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e134)));
}