typedef unsigned int u32;
struct A {
    char pad[0x10];
    u32 value;
};
u32 __cdecl target(A* p) {
    return p->value;
}