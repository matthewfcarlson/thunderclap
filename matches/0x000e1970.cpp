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
    FEDoSound* Init(u32_e1970, const char*);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, const char*);
FEDoSound* FEDoSound::Init(u32_e1970 param_2, const char* param_3) {
    a = -1;
    b = -1;
    c = param_2;
    flag = 0;
    vtable = ((hulk_intptr)DAT_0040c02c);
    FUN_000dfcc0(name, 0x20, ((const char*)&DAT_003f3f38), param_3);
    return this;
}