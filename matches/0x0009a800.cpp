#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00404c10[];
extern "C" char DAT_0048e10c[];
struct Ctor_001d0480 {
    Ctor_001d0480(int, int);
};
class CCameraManager : public Ctor_001d0480 {
  public:
    char pad00[0x10];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int value1c;
    CCameraManager(int a, int b);
};
CCameraManager::CCameraManager(int a, int b) : Ctor_001d0480(a, 4) {
    *(int*)this = ((int)DAT_00404c10);
    value1c = b;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    b11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b13 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
}