#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_00424b2c[];
class Method4_1f4aa0 {
  public:
    hulk_intptr vptr;
    char pad4[0xc];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    hulk_intptr m1c;
    Method4_1f4aa0(char*, char*);
};
struct ThisCall_001d0480 {
    void Init(void*, int);
};
extern "C" char __cdecl Get(void*);
Method4_1f4aa0::Method4_1f4aa0(char* a, char* b) {
    ((ThisCall_001d0480*)(this))->Init(a, 4);
    vptr = ((hulk_intptr)DAT_00424b2c);
    m1c = (hulk_intptr)b;
    b18 = Get((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    b11 = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    b12 = Get((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    b13 = Get((void*)((hulk_intptr)((char*)&DAT_0048e134)));
}