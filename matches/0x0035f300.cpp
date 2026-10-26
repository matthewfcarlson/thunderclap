#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
struct MixType_35f300 {
    void Run();
};
extern void Fn_003641a0();
extern int __cdecl atexit(void (*f)());

void __cdecl FUN_0035f300() {
    (*(MixType_35f300*)&DAT_004e5cf8).Run();
    atexit((void (*)())(hulk_ulongptr)Fn_003641a0);
}
