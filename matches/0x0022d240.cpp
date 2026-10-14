struct H {
    void Run(int a, int originalThis);
};
struct C_22d240 {
    void Target(int a, int b);
};
void C_22d240::Target(int a, int b) {
    ((H*)b)->Run(a, (int)this);
}