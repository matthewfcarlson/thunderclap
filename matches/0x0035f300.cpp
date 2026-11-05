#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
struct MixType_35f300 {
    void FUN_00242010();
};
extern "C" void FUN_003641a0();
extern int __cdecl atexit(void (*f)());

void __cdecl FUN_0035f300() {
    (*(MixType_35f300*)&DAT_004e5cf8).FUN_00242010();
    atexit((void (*)())(hulk_ulongptr)FUN_003641a0);
}
