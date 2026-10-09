typedef unsigned int u32;
struct Item { char pad[8]; volatile u32 handle; char rest[4]; void Process(); };
void __cdecl ReleaseHandle(u32);
void __cdecl FUN_00290500(Item* begin, Item* end) {
    Item* p=begin;
    while (p != end) {
        u32 h=p->handle;
        if (h) { ReleaseHandle(h); p->handle=0; }
        p->Process();
        p=(Item*)((char*)p+16);
    }
}