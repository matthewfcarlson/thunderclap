struct Y_29fca0 {
    bool Chk(void* a, int b);
};
struct N_29fca0 {
    char p[0x1c];
    int m1c;
    int m20;
    char p2[4];
    char m28[0x14];
    int m3c;
    int m40;
    void Do(int a);
};
struct X_29fca0 {
    char p[0x24];
    int m24;
    bool Fn(int a, Y_29fca0* y, N_29fca0* n);
};
bool X_29fca0::Fn(int a, Y_29fca0* y, N_29fca0* n) {
    bool r = false;
    if (n) {
        int c = --n->m3c;
        if (c > 0) {
            n->Do(a);
            r = true;
        } else {
            n->m3c = n->m40 + c;
            if (y->Chk(n->m28, n->m20) && m24 == n->m1c) {
                n->Do(a);
                r = true;
            }
        }
    }
    return r;
}
