struct A_1c59d0 {
    char pad[8];
};
struct B_1c59d0 {
    int F(int);
};
struct X_1c59d0 : A_1c59d0, B_1c59d0 {
    int G(int);
};
int X_1c59d0::G(int a0) {
    return B_1c59d0::F(a0);
}