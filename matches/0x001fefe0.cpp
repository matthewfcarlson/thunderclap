#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00425334[];
extern "C" char DAT_0048e10c[];
class Method3_1fefe0 {
  public:
    int vftable;
    char pad04[0x0c];
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    void* p1c;
    void Init(void*, int);
    Method3_1fefe0* Build(void*, void*);
};
Method3_1fefe0* Method3_1fefe0::Build(void* arg1, void* arg2) {
    Init(arg1, 3);
    vftable = ((int)DAT_00425334);
    p1c = arg2;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e10c));
    b11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0e4)));
    return this;
}