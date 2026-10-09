typedef unsigned char u8;
extern void __cdecl FUN_002e7fb0(void*);
extern void __cdecl FUN_002d9170(void*, int);
struct Obj {
    char pad[0x64];
    u8 flags;
};
void __cdecl target(Obj* p, int a) {
    if ((p->flags & 0x40) == 0)
        FUN_002e7fb0(p);
    FUN_002d9170(p, a);
}