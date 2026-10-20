#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00424d6c[];
class CEffectManager {
  public:
    hulk_intptr vtable;
    char pad4[0x0c];
    char pad10[8];
    char c18;
    char pad19[3];
    int field1c;
    void Base(int, int);
    CEffectManager* Build(int, int);
};
CEffectManager* CEffectManager::Build(int a, int b) {
    Base(a, 3);
    vtable = ((hulk_intptr)DAT_00424d6c);
    field1c = b;
    c18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    *((char*)this + 0x10) = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049cad8)));
    *((char*)this + 0x11) = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    *((char*)this + 0x12) = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}