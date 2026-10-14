// Same code shape as 0x0022d240 (propagated; names are from that function)
struct H {
    void Run(int a, int originalThis);
};
struct C_22d290 {
    void Target(int a, int b);
};
void C_22d290::Target(int a, int b) {
    ((H*)b)->Run(a, (int)this);
}