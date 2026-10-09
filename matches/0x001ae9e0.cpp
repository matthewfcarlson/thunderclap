struct Src {
    int d[10];
};
struct Node {
    char pad[0x10];
    Src s;
};
struct Pair {
    Node* n;
    void* o;
};
void* __stdcall FUN_00230be0(void* a, const Src* b);
void* FUN_0008d6d0(unsigned n);
struct O {
    void F(Pair* out, const Src* s);
    void G(Node* n, void* a, void* b);
};
void O::F(Pair* out, const Src* s) {
    void* p = FUN_00230be0((void*)0x1ad4f0, s);
    if (!p) {
        out->n = 0;
        out->o = 0;
        return;
    }
    Node* r = (Node*)FUN_0008d6d0(0x38);
    Node* n;
    if (r) {
        r->s = *s;
        n = r;
    } else
        n = 0;
    G(n, (void*)0x1ad4d0, p);
    out->n = n;
    out->o = this;
}
