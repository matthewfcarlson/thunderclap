#include "decls/data/engine/unknown.h"

typedef unsigned long DWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(DWORD*);
}
void __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
void __cdecl FUN_00267f00(void) {
    DWORD local[2];
    XAPILIB::QueryPerformanceCounter(local);
    FUN_00267e20(local[0], local[1], 1000000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}
