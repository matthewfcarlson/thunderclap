struct B_2752e0 {
    B_2752e0(int) throw();
    virtual void V0();
    char pad[8];
};
void After();
struct FWR : B_2752e0 {
    int m0c, m10, m14;
    FWR(int a, int b, int c, int d);
    virtual void V0();
};
FWR::FWR(int a, int b, int c, int d) : B_2752e0(a) {
    m0c = b;
    m10 = c;
    m14 = d;
    After();
}
