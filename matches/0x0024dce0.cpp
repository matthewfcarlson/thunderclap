extern "C" char DAT_00429434[];
extern "C" char DAT_004e6320[];
extern "C" char DAT_004e6328[];
struct Helper_24dce0 {
    void init(void*, void*, int, int);
    void fini();
};
extern int __cdecl F247530(void*);
int __cdecl target() {
    char local[0x48];
    ((Helper_24dce0*)local)->init((void*)((int)DAT_004e6328), (void*)((int)DAT_004e6320), 0x30, 4);
    *(void**)local = (void*)((int)DAT_00429434);
    int result = F247530(local);
    ((Helper_24dce0*)local)->fini();
    return result;
}