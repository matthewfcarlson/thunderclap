// cl-flags: /O1
extern "C" void __stdcall XcSHAFinal(void*, void*);
extern "C" void __stdcall FUN_0020a355(void*, unsigned int);
extern "C" int __stdcall FUN_00212055(char* p1, void* p2) {
    if (p2 != 0)
        XcSHAFinal(p1 + 8, p2);
    FUN_0020a355(p1, 0x24830000);
    return 0;
}
