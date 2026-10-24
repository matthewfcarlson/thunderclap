struct X_2479a0 {
    void A();
    X_2479a0* Target(unsigned char flag);
};
extern int __cdecl B();
extern void __cdecl Finish(int, X_2479a0*);
X_2479a0* X_2479a0::Target(unsigned char flag) {
    A();
    if (flag & 1)
        Finish(B(), this);
    return this;
}