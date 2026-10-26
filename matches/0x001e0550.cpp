#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_004233f8[];
class Method5_1e0550 {
  public:
    hulk_intptr v;
    char pad[0x14];
    char b18;
    char p19[3];
    int m1c;
    char p20[0x20];
    void Init(const char*, int);
    Method5_1e0550* Make(const char*, int);
};
Method5_1e0550* Method5_1e0550::Make(const char* p, int x) {
    Init(p, 5);
    v = ((hulk_intptr)DAT_004233f8);
    m1c = x;
    b18 = FUN_001d04d0(((char*)&DAT_0048e100));
    pad[12] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    pad[13] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    pad[14] = FUN_001d04d0(((char*)&DAT_0048e128));
    pad[15] = FUN_001d04d0(((char*)&DAT_0048e128));
    pad[16] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}