struct Helper { void init(void*, void*, int, int); void fini(); };
extern int __cdecl F247530(void*);
int __cdecl target() {
    char local[0x48];
    ((Helper*)local)->init((void*)0x4e6328, (void*)0x4e6320, 0x30, 4);
    *(void**)local = (void*)0x429434;
    int result = F247530(local);
    ((Helper*)local)->fini();
    return result;
}