// Same code shape as 0x00236630 (propagated; names are from that function)
struct Tmp_29f3a0 {
    char pad[0x18];
    Tmp_29f3a0(void*);
    void Run(int, int);
};
struct C_29f3a0 {
    void F(int, int);
};
void C_29f3a0::F(int a, int b) {
    Tmp_29f3a0 t(this);
    t.Run(a, b);
}