struct B_d6f10 {
    void x(int);
};
struct C_d6f10 {
    void y(int);
};
struct A_d6f10 {
    int pad;
    B_d6f10* b;
    C_d6f10* c;
    void run(int);
};
void A_d6f10::run(int v) {
    b->x(v);
    c->y(v);
}
