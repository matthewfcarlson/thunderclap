#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00420e24[];
class Base_1b9c50 {
  public:
    void Init(void*, int);
};
class Target_1b9c50 : public Base_1b9c50 {
  public:
    int pad0;
    char pad4[0x0c];
    char b10;
    char b11;
    char b12;
    char b13;
    char b14;
    char b15;
    char b16;
    char b17;
    char b18;
    char pad19[3];
    int member1c;
    Target_1b9c50(void* p, int x);
};
Target_1b9c50::Target_1b9c50(void* p, int x) {
    Init(p, 3);
    *(int*)this = ((int)DAT_00420e24);
    member1c = x;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e134)));
    b11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e134)));
    b12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e134)));
}