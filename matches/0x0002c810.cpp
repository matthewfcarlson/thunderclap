#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
extern "C" char DAT_003f408c[];
typedef unsigned char u8;
typedef unsigned int u32_2c810;
struct ThisCall_001d0480 {
    void setup(void*, int);
};
u8 __cdecl getval(const void*);
class Method3 {
  public:
    hulk_uintptr vf;
    char pad4[12];
    u8 b10, b11, b12;
    char pad13[5];
    u8 b18;
    char pad19[3];
    u32_2c810 value;
    Method3* target(void*, u32_2c810);
};
Method3* Method3::target(void* a, u32_2c810 c) {
    ((ThisCall_001d0480*)(this))->setup(a, 3);
    vf = ((hulk_intptr)DAT_003f408c);
    value = c;
    b18 = getval(((char*)&DAT_0048e100));
    b10 = getval(((char*)&DAT_0048e0f0));
    b11 = getval(((char*)&DAT_0048e128));
    b12 = getval(((char*)&DAT_0048e0e4));
    return this;
}