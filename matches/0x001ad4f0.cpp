struct A {
    unsigned int x;
};
struct B {
    char pad[16];
    unsigned int x;
};
int __cdecl FUN_001ad4f0(A* a, B* b) {
    unsigned int ax = a->x;
    unsigned int bx = b->x;
    if (bx > ax)
        return -1;
    return bx < ax;
}