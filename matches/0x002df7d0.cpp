struct X_2df7d0 {
    void f();
};
struct C_2df7d0 {
    char pad[0x5c];
    X_2df7d0* member;
    void target();
};
void C_2df7d0::target() {
    member->f();
}