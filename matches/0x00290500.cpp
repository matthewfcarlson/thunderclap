typedef unsigned int u32_290500;
struct Item_290500 {
    char pad[8];
    volatile u32_290500 handle;
    char rest[4];
    void Process();
};
void __cdecl ReleaseHandle(u32_290500);
void __cdecl FUN_00290500(Item_290500* begin, Item_290500* end) {
    Item_290500* p = begin;
    while (p != end) {
        u32_290500 h = p->handle;
        if (h) {
            ReleaseHandle(h);
            p->handle = 0;
        }
        p->Process();
        p = (Item_290500*)((char*)p + 16);
    }
}