struct S1 {
    void f();
};
struct S2 {
    void f();
};
struct S3 {
    void f();
};
struct C {
    char pad[0x70];
    void f();
    C* target();
};
C* C::target() {
    f();
    ((S1*)(pad + 0x70))->f();
    ((S2*)(pad + 0xb0))->f();
    ((S3*)(pad + 0x1b0))->f();
    pad[0x6c] = 0;
    return this;
}