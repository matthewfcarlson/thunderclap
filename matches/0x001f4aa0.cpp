#include "decls/data/game/global.h"

extern "C" char DAT_00424b2c[];
class Obj_1f4aa0 {
  public:
    int vptr;
    char pad4[0xc];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int m1c;
    Obj_1f4aa0(char*, char*);
};
struct ThisCall_001d0480 {
    void Init(void*, int);
};
extern "C" char __cdecl Get(void*);
Obj_1f4aa0::Obj_1f4aa0(char* a, char* b) {
    ((ThisCall_001d0480*)(this))->Init(a, 4);
    vptr = ((int)DAT_00424b2c);
    m1c = (int)b;
    b18 = Get((void*)((int)((char*)&DAT_0048e100)));
    b10 = Get((void*)((int)((char*)&DAT_0049cad8)));
    b11 = Get((void*)((int)((char*)&DAT_0049cad8)));
    b12 = Get((void*)((int)((char*)&DAT_0049cad8)));
    b13 = Get((void*)((int)((char*)&DAT_0048e134)));
}