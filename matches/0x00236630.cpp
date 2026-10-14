struct Tmp_236630 {
    char pad[0x18];
    Tmp_236630(void*);
    void Run(int, int);
};
struct C_236630 {
    void F(int, int);
};
void C_236630::F(int a, int b) {
    Tmp_236630 t(this);
    t.Run(a, b);
}