struct S1_2ef050 {
    void f();
};
struct S2_2ef050 {
    void f();
};
struct S3 {
    void f();
};
struct C_2ef050 {
    char pad[0x70];
    void f();
    C_2ef050* target();
};
C_2ef050* C_2ef050::target() {
    f();
    ((S1_2ef050*)(pad + 0x70))->f();
    ((S2_2ef050*)(pad + 0xb0))->f();
    ((S3*)(pad + 0x1b0))->f();
    pad[0x6c] = 0;
    return this;
}