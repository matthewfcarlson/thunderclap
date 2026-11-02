#include "decls/data/engine/audio.h"

extern int __fastcall FUN_00267f80(void*);
extern "C" void __cdecl FUN_0024c060();
extern "C" void __cdecl FUN_00243090(int, float);
extern "C" void __cdecl FUN_00240f50();
extern "C" void __fastcall FUN_00240bb0(void* p) {
    int i = FUN_00267f80(p) - DAT_004e5ca8;
    FUN_0024c060();
    FUN_00243090(DAT_004e5cac, (float)i);
    FUN_00240f50();
}
