typedef unsigned int u32;
extern void __cdecl F47550(void*, u32);
extern void __cdecl F4a450(void*);
extern void __cdecl F4a4a0(void*);
struct Obj {
    char pad[0x3c];
    u32 m3c;
    u32 m40;
};
void __fastcall target(Obj* p, void*) {
    F47550((void*)0x4e6158, p->m40);
    F47550((void*)0x4e6110, p->m3c);
    char* q = (char*)p + 0x50;
    F4a450(q + 0x14);
    F4a4a0(q);
}