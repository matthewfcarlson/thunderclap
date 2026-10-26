#include "decls/data/engine/core.h"
// data: gBuffer_2726e0 = DAT_0052a1a4, gCallback_2726e0 = DAT_004cdcf8, gFlag_2726e0 = DAT_004cdcf4
// data: gHandler = DAT_0052a1c4, gState_2726e0 = DAT_0052a1c0

extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, const char*, int, const char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
typedef void(__cdecl* Handler_2726e0)(char*);
extern "C" char __cdecl FUN_002726e0(const char* a, const char* b, int c) {
    char text[1024];
    FUN_00267760(text, 1024, "ASSERT FAILED : [%s]\n         Line : [%d] File: [%s]\n", a, c, b);
    text[1023] = 0;
    Handler_2726e0 h = (*(Handler_2726e0*)&DAT_0052a1c4);
    if (h)
        h(text);
    else {
        if ((*(int*)&DAT_0052a1c0) == 0x55555555)
            FUN_0026d850(((char*)&DAT_0052a1a4));
        (*(Handler_2726e0*)&DAT_004cdcf8)(text);
        if ((*(int*)&DAT_0052a1c0) == 0x55555555)
            FUN_0026d840(((char*)&DAT_0052a1a4));
    }
    return DAT_004cdcf4 != 0;
}