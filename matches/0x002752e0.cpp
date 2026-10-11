struct B {
    B(int) throw();
    virtual void V0();
    char pad[8];
};
void After();
struct FWR : B {
    int m0c, m10, m14;
    FWR(int a, int b, int c, int d);
    virtual void V0();
};
FWR::FWR(int a, int b, int c, int d) : B(a) {
    m0c = b;
    m10 = c;
    m14 = d;
    After();
}
