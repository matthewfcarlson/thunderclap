// Same code shape as 0x00267f00 (propagated; names are from that function)
#include "decls/data/engine/unknown.h"

typedef unsigned long DWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(DWORD*);
}
int __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
int __cdecl FUN_00267f40(void) {
    DWORD local[2];
    XAPILIB::QueryPerformanceCounter(local);
    return FUN_00267e20(local[0], local[1], 1000000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}
