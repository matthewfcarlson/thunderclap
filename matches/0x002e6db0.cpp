struct Inner_2e6db0 {
    int v0;
    int v1;
    int v2;
    int flag;
    char pad[4];
    int arg;
};
struct Obj_2e6db0 {
    char pad0[8];
    int a;
    char pad1[8];
    int b;
    int c;
    Inner_2e6db0* inner;
};
int __cdecl helper(int, Obj_2e6db0*, int);
int __cdecl target(Obj_2e6db0* p) {
    if (p && p->inner) {
        p->b = 0;
        p->a = 0;
        p->c = 0;
        Inner_2e6db0* q = p->inner;
        q->v0 = q->flag ? 7 : 0;
        helper(p->inner->arg, p, 0);
        return 0;
    }
    return -2;
}
