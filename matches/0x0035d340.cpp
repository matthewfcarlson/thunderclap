struct Item {
    char bytes[8];
};
extern Item items[2][6];
extern "C" void __stdcall FUN_00011520(Item*, int, int, void(__cdecl*)(Item*));
extern "C" void __cdecl FUN_000b06e0(Item*);
extern "C" void cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_0035d340() {
    Item* p = &items[0][0];
    int n = 2;
    do {
        FUN_00011520(p, 8, 6, FUN_000b06e0);
        p += 6;
    } while (--n);
    atexit(cleanup);
}