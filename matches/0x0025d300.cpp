#include "decls/data/engine/audio.h"
#include "decls/data/platform/xbox/unknown.h"

extern "C" void __cdecl FUN_00257f00(void*, void*);
extern "C" void __cdecl FUN_00240c60(void*);
struct At {
    char pad[0x1c];
    void f();
};
struct Obj_25d300 {
    char pad[0x10];
    void* p;
    char pad2[8];
};
void __cdecl f247550(void*, void*);
extern "C" void __cdecl FUN_0025d300(Obj_25d300* p) {
    FUN_00257f00((*(char**)&DAT_004e5ce0) + 0x14, p);
    if (p->p)
        FUN_00240c60(p->p);
    ((At*)((char*)p + 0x1c))->f();
    f247550(DAT_004e7898, p);
}
