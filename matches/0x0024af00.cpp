#include "decls/data/engine/audio.h"

typedef unsigned int uint;
struct Obj_24af00 {
    void Clean();
};
extern void __cdecl FUN_00247550(void*, void*);
extern "C" void __cdecl FUN_0024af00(Obj_24af00* object) {
    if (object) {
        object->Clean();
        FUN_00247550(((char*)&DAT_004e5fa8), object);
    }
}