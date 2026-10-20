#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00425b54[];
class Base_2050f0 {
  public:
    void Init(int, int);
};
class Target_2050f0 : public Base_2050f0 {
  public:
    Target_2050f0(int, int);
    void* vf;
    char pad04[0x0c];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int mgr;
};
Target_2050f0::Target_2050f0(int a, int b) {
    Init(a, 3);
    vf = (void*)((hulk_intptr)DAT_00425b54);
    mgr = b;
    b18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    b11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    b12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}