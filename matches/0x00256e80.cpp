struct N {
    N* next;
    N* l;
    N* r;
};
extern "C" N* __cdecl FUN_00256e80(N* s, N* n) {
    N* x = n->l;
    N* end = (N*)((char*)s + 4);
    if (x != end) {
        while (x->next != end)
            x = x->next;
    } else {
        x = n->r;
        if (x != end) {
            do {
                if (n != x->l)
                    break;
                n = x;
                x = x->r;
            } while (x != end);
        }
    }
    return x == end ? 0 : x;
}
