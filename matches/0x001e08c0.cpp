#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423438[];
class CSPManager {
  public:
    int vtable;
    char pad4[0xc];
    unsigned char a10, a11, a12, a13;
    char pad14[4];
    unsigned char a18;
    char pad19[3];
    int field1c;
    CSPManager* Init(void*, int);
};
extern "C" void __stdcall FUN_001d0480(void*, int);
CSPManager* CSPManager::Init(void* p, int b) {
    FUN_001d0480(p, 4);
    vtable = ((int)DAT_00423438);
    field1c = b;
    a18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0e4)));
    a10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    a11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    a12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    a13 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    return this;
}