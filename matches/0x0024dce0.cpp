extern "C" char DAT_00429434[];
extern "C" char DAT_004e6320[];
extern "C" char DAT_004e6328[];
struct Helper {
    void init(void*, void*, int, int);
    void fini();
};
extern int __cdecl F247530(void*);
int __cdecl target() {
    char local[0x48];
    ((Helper*)local)->init((void*)((int)DAT_004e6328), (void*)((int)DAT_004e6320), 0x30, 4);
    *(void**)local = (void*)((int)DAT_00429434);
    int result = F247530(local);
    ((Helper*)local)->fini();
    return result;
}