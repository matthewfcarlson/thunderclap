struct S_246a40 {
    int Fn();
};
struct A_246a40 {
    char pad[0x1c];
    S_246a40* m;
};
bool Target(A_246a40* a, int* b) {
    S_246a40* sub = a->m;
    int r = sub->Fn();
    *b = r;
    return true;
}
