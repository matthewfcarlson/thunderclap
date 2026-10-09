// Same code shape as 0x00267f00 (propagated; names are from that function)
typedef unsigned long DWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(DWORD*);
}
extern DWORD DAT_00528380;
extern DWORD DAT_00528384;
void __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
void __cdecl FUN_00267f00(void) {
    DWORD local[2];
    XAPILIB::QueryPerformanceCounter(local);
    FUN_00267e20(local[0], local[1], 1000000, 0, DAT_00528380, DAT_00528384);
}
