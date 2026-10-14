struct Sub_96a40 {
    void f(void*);
    void g(void*);
};
struct Obj_96a40 {
    char pad[8];
    Sub_96a40* sub;
    int kind;
    char q[0x30];
    unsigned a, b, c;
};
void __cdecl target(Obj_96a40* p, unsigned* out) {
    if (p->kind == 5) {
        p->sub->f(out);
        return;
    }
    if (p->kind == 1) {
        p->sub->g(out);
        return;
    }
    out[0] = p->a;
    out[1] = p->b;
    out[2] = p->c;
}