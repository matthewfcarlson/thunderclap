typedef unsigned int u32;
struct S {
    char pad[0x3c];
    u32 value;
};
u32 __cdecl FUN_00213f90(S* p) {
    return p->value;
}