#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00420e84[];
extern "C" char DAT_0048e10c[];
struct C_1ba090 {
    int v;
    char pad4[0xc];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int p1c;
    void Init(const char*, int);
    C_1ba090(const char*, int);
};
C_1ba090::C_1ba090(const char* x, int y) {
    Init(x, 4);
    v = ((int)DAT_00420e84);
    p1c = y;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0049b95c)));
    b10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b13 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
}