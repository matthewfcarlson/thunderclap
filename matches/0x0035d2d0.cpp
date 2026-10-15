typedef void(__cdecl* Fn)();
extern "C" void __stdcall init(void*, int, int, Fn);
extern "C" void __cdecl destroyItem();
extern "C" void __cdecl cleanup();
extern "C" int __cdecl atexit(Fn);
struct Item {
    char bytes[0x30];
};
extern Item items[2];
void __cdecl target() {
    Item* p = items;
    int n = 2;
    do {
        init(p, 8, 6, destroyItem);
        ++p;
    } while (--n);
    atexit(cleanup);
}
