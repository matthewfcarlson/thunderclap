extern "C" char DAT_0042aad0[];
extern "C" char DAT_004e58c8[];
extern "C" char DAT_004e58d0[];
typedef unsigned int u32;
extern void __stdcall Init(void*, void*, int, int);
extern "C" void* __fastcall Target(void* p, void* edx) {
    Init((void*)((int)DAT_004e58d0), (void*)((int)DAT_004e58c8), 0x24, 4);
    *(u32*)p = ((int)DAT_0042aad0);
    return p;
}