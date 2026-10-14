struct A_1c59d0 {
    char pad[8];
};
struct B_1c59d0 {
    void F();
};
struct X_1c59d0 : A_1c59d0, B_1c59d0 {
    void G();
};
void X_1c59d0::G() {
    B_1c59d0::F();
}