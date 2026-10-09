typedef unsigned int u32;
struct Obj {
    char pad[0x34];
    u32 value;
};
u32 __cdecl target(Obj* p) {
    return p->value;
}