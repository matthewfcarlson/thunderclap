struct S {
    char pad[8];
    int n;
    float f;
};
struct A {
    char pad[0x1bc];
    S* s;
};
struct B {
    char pad[0x19];
    char v;
    char p[0x12];
    float f;
};
void __cdecl FUN_002d15f0(int a, int b, A* x, B* y) {
    S* s = x->s;
    y->v = (char)(__int64)(((int)(__int64)(y->f / s->f)) % s->n);
}