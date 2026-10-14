struct N_256e80 {
    N_256e80* next;
    N_256e80* l;
    N_256e80* r;
};
extern "C" N_256e80* __cdecl FUN_00256e80(N_256e80* s, N_256e80* n) {
    N_256e80* x = n->l;
    N_256e80* end = (N_256e80*)((char*)s + 4);
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
