typedef unsigned int U_c5a90;
struct Triple_c5a90 {
    U_c5a90 x, y, z;
};
struct Helper_c5a90 {
    void A(int);
    U_c5a90 B(U_c5a90, U_c5a90);
    void C(U_c5a90, int, Triple_c5a90*);
};
struct Obj_c5a90 {
    Helper_c5a90* h;
    U_c5a90 pad;
    U_c5a90 c;
    U_c5a90 d;
    Triple_c5a90* Go(Triple_c5a90* out);
};
Triple_c5a90* Obj_c5a90::Go(Triple_c5a90* out) {
    Triple_c5a90 t;
    h->A(0);
    U_c5a90 r = h->B(c, d);
    h->C(r, 0, &t);
    *out = t;
    return out;
}
