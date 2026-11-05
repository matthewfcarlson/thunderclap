#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

extern "C" char DAT_0040c02c[];
typedef unsigned int u32_e1970;
class FEDoSound {
  public:
    hulk_intptr vtable;
    int pad4;
    int a;
    int b;
    int c;
    char flag;
    char pad15[0x1f];
    char name[0x20];
    FEDoSound* Init(hulk_uintptr, const char*);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, ...);
FEDoSound* FEDoSound::Init(hulk_uintptr id, const char* soundName) {
    a = -1;
    b = -1;
    c = id;
    flag = 0;
    vtable = ((hulk_intptr)DAT_0040c02c);
    FUN_000dfcc0(name, 0x20, ((const char*)&DAT_003f3f38), soundName);
    return this;
}