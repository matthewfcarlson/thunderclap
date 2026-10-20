#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_003f428c[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
class CActorManager : public Ctor_001d0480 {
  public:
    int vptr;
    char pad04[0x0c];
    char m10, m11, m12, m13;
    char pad14[4];
    char m18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
CActorManager::CActorManager(const char* a, int b) : Ctor_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_003f428c);
    m1c = b;
    m18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    m13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}