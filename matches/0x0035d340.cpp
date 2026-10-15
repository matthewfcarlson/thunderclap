struct Item {
    char bytes[8];
};
extern Item items[2][6];
extern "C" void __stdcall initvec(Item*, int, int, void(__cdecl*)(Item*));
extern "C" void __cdecl construct(Item*);
extern "C" void cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_0035d340() {
    Item* p = &items[0][0];
    int n = 2;
    do {
        initvec(p, 8, 6, construct);
        p += 6;
    } while (--n);
    atexit(cleanup);
}