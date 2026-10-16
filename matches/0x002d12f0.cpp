struct Obj {
    char pad[0x14];
    float a;
    char gap[4];
    float b;
};
void __cdecl FUN_002d12f0(float x, int p2, int p3, int p4, Obj* o) {
    o->a += x * o->b;
}