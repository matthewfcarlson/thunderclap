extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, const char*, int, const char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
typedef void(__cdecl* Handler)(char*);
extern Handler gHandler;
extern Handler gCallback;
extern unsigned char gFlag;
extern int gState;
extern char gBuffer;
extern "C" char __cdecl FUN_002726e0(const char* a, const char* b, int c) {
    char text[1024];
    FUN_00267760(text, 1024, "ASSERT FAILED : [%s]\n         Line : [%d] File: [%s]\n", a, c, b);
    text[1023] = 0;
    Handler h = gHandler;
    if (h)
        h(text);
    else {
        if (gState == 0x55555555)
            FUN_0026d850(&gBuffer);
        gCallback(text);
        if (gState == 0x55555555)
            FUN_0026d840(&gBuffer);
    }
    return gFlag != 0;
}