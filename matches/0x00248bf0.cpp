struct N_248bf0 {
    N_248bf0* next;
    N_248bf0* l;
    N_248bf0* r;
};
extern "C" N_248bf0* __cdecl FUN_00256e80(N_248bf0* s, N_248bf0* n) {
    N_248bf0* x = n->l;
    N_248bf0* end = (N_248bf0*)((char*)s + 4);
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
