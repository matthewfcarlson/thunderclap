struct X { void A(); X* Target(unsigned char flag); };
extern int __cdecl B(X*);
extern void __cdecl Finish(int);
X* X::Target(unsigned char flag) {
    A();
    if (flag & 1) Finish(B(this));
    return this;
}