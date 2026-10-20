#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

typedef unsigned int u32_24a590;
extern void __cdecl F47550(void*, u32_24a590);
extern void __cdecl F4a450(void*);
extern void __cdecl F4a4a0(void*);
struct Obj_24a590 {
    char pad[0x3c];
    u32_24a590 m3c;
    u32_24a590 m40;
};
void __fastcall target(Obj_24a590* p, void*) {
    F47550((void*)((hulk_intptr)((char*)((char*)&DAT_004e6110 + 72))), p->m40);
    F47550((void*)((hulk_intptr)DAT_004e6110), p->m3c);
    char* q = (char*)p + 0x50;
    F4a450(q + 0x14);
    F4a4a0(q);
}