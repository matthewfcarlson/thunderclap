extern "C" unsigned char gFlag;
extern "C" char gData[];
extern "C" char gFinal[];
void __cdecl CleanupOne(void*);
void __cdecl StepA();
void __cdecl StepB();
void __cdecl StepC();
void __cdecl StepD();
void __cdecl Finish(void*);
void __cdecl FUN_00271070() {
    if (gFlag) {
        char* p = gData;
        int n = 0x1a;
        do {
            if (*(int*)(p + 0x14) != 0)
                CleanupOne(p);
            p += 0x11c;
            --n;
        } while (n != 0);
    }
    StepA();
    StepB();
    StepC();
    StepD();
    Finish(gFinal);
    gFinal[0x2d] = 0;
}