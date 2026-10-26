#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00423398[];
class CSPManager {};
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
class Method3_1e0130 : public Ctor_001d0480 {
  public:
    void* vf;
    char p4[12];
    unsigned char b10, b11, b12;
    char p13[5];
    unsigned char b18;
    char p19[3];
    CSPManager* mgr;
    Method3_1e0130(const char*, CSPManager*);
};
Method3_1e0130::Method3_1e0130(const char* a, CSPManager* c) : Ctor_001d0480(a, 3) {
    vf = (void*)((hulk_intptr)DAT_00423398);
    mgr = c;
    b18 = FUN_001d04d0(((const char*)&DAT_0048e100));
    b10 = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    b11 = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    b12 = FUN_001d04d0(((const char*)&DAT_0048e128));
}