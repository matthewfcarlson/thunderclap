struct S {
    int Fn();
};
struct A {
    char pad[0x1c];
    S* m;
};
bool Target(A* a, int* b) {
    S* sub = a->m;
    int r = sub->Fn();
    *b = r;
    return true;
}
