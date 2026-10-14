typedef unsigned int u32_2d8820;
struct Thing_2d8820 {
    char pad[0x68];
    u32_2d8820 flags;
};
void __cdecl FUN_002d8820(Thing_2d8820* p) {
    p->flags |= 0x400;
}