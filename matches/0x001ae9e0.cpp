struct Src_1ae9e0 {
    int d[10];
};
struct Node {
    char pad[0x10];
    Src_1ae9e0 s;
};
struct Pair_1ae9e0 {
    Node* n;
    void* o;
};
void* __stdcall FUN_00230be0(void* a, const Src_1ae9e0* b);
void* FUN_0008d6d0(unsigned n);
struct O_1ae9e0 {
    void F(Pair_1ae9e0* out, const Src_1ae9e0* s);
    void G(Node* n, void* a, void* b);
};
void O_1ae9e0::F(Pair_1ae9e0* out, const Src_1ae9e0* s) {
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
