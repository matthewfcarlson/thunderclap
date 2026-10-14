typedef unsigned int u32_2495f0;
struct A_2495f0 {
    char pad[0x10];
    u32_2495f0 value;
};
u32_2495f0 __cdecl target(A_2495f0* p) {
    return p->value;
}