extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, const char*, int, const char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
typedef void(__cdecl* Handler_2726e0)(char*);
extern Handler_2726e0 gHandler;
extern Handler_2726e0 gCallback_2726e0;
extern unsigned char gFlag_2726e0;
extern int gState_2726e0;
extern char gBuffer_2726e0;
extern "C" char __cdecl FUN_002726e0(const char* a, const char* b, int c) {
    char text[1024];
    FUN_00267760(text, 1024, "ASSERT FAILED : [%s]\n         Line : [%d] File: [%s]\n", a, c, b);
    text[1023] = 0;
    Handler_2726e0 h = gHandler;
    if (h)
        h(text);
    else {
        if (gState_2726e0 == 0x55555555)
            FUN_0026d850(&gBuffer_2726e0);
        gCallback_2726e0(text);
        if (gState_2726e0 == 0x55555555)
            FUN_0026d840(&gBuffer_2726e0);
    }
    return gFlag_2726e0 != 0;
}