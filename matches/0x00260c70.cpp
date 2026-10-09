typedef unsigned int u32;
extern void __stdcall Init(void*, void*, int, int);
extern "C" void* __fastcall Target(void* p, void* edx) {
    Init((void*)0x4e58d0, (void*)0x4e58c8, 0x24, 4);
    *(u32*)p = 0x42aad0;
    return p;
}