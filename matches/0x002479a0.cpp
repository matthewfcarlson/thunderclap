struct X_2479a0 {
    void A();
    X_2479a0* Target(unsigned char flag);
};
extern int __cdecl B();
extern "C" void __cdecl FUN_00247550(int, X_2479a0*);
X_2479a0* X_2479a0::Target(unsigned char flag) {
    A();
    if (flag & 1)
        FUN_00247550(B(), this);
    return this;
}