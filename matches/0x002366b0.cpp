// Same code shape as 0x00236630 (propagated; names are from that function)
struct Tmp_2366b0 {
    char pad[0x18];
    Tmp_2366b0(void*);
    void Run(int, int);
};
struct C_2366b0 {
    void F(int, int);
};
void C_2366b0::F(int a, int b) {
    Tmp_2366b0 t(this);
    t.Run(a, b);
}