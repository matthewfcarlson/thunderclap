#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_003f5d4c[];
extern "C" void __stdcall FUN_001d0480(const char*, int);
class Target_3efb0 {
  public:
    int vptr;
    char pad04[12];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int m1c;
    Target_3efb0(const char*, int);
};
Target_3efb0::Target_3efb0(const char* a, int b) {
    FUN_001d0480(a, 3);
    vptr = ((int)DAT_003f5d4c);
    m1c = b;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
}