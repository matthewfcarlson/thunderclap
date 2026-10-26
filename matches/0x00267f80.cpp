#include "decls/data/engine/unknown.h"

typedef unsigned int DWORD;
struct LARGE_INTEGER {
    DWORD low;
    DWORD high;
};
extern "C" int __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
extern "C" int __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
int Timer() {
    LARGE_INTEGER n;
    QueryPerformanceCounter(&n);
    return FUN_00267e20(n.low, n.high, 1000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}
