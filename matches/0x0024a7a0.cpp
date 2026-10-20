#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

typedef unsigned char u8_24a7a0;
class Obj_24a7a0 {
  public:
    char pad[0x3c];
    int m3c;
    int m40;
    Obj_24a7a0* Update(u8_24a7a0);
};
extern void Copy(void*, int);
extern void InitA(void*);
extern void InitB(void*);
Obj_24a7a0* Obj_24a7a0::Update(u8_24a7a0 flag) {
    Copy((void*)((hulk_intptr)((char*)((char*)&DAT_004e6110 + 72))), m40);
    Copy((void*)((hulk_intptr)DAT_004e6110), m3c);
    char* base = (char*)this + 0x50;
    InitA(base + 0x14);
    InitB(base);
    if (flag & 1)
        Copy((void*)((hulk_intptr)DAT_004e60c8), (hulk_intptr)this);
    return this;
}