typedef unsigned int u32_24b0d0;
struct Inner_24b0d0 {
    char pad[0x24];
    u32_24b0d0 value;
};
struct Outer_24b0d0 {
    char pad[0x10];
    Inner_24b0d0* inner;
};
u32_24b0d0 __cdecl FUN_0024b0d0(Outer_24b0d0* p) {
    return p->inner->value;
}
