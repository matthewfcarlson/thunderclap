struct N_247f80 {
    N_247f80* l;
    N_247f80* r;
    N_247f80* p;
};
N_247f80* Next(N_247f80* head, N_247f80* x) {
    N_247f80* s = (N_247f80*)((char*)head + 4);
    N_247f80* n = x->r;
    if (n != s) {
        while (n->l != s)
            n = n->l;
        return n;
    }
    n = x->p;
    while (n != s && x == n->r) {
        x = n;
        n = n->p;
    }
    return n;
}
