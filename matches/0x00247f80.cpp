struct N {
    N* l;
    N* r;
    N* p;
};
N* Next(N* head, N* x) {
    N* s = (N*)((char*)head + 4);
    N* n = x->r;
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
