struct Base {
    int vptr;
    Base();
};
struct H : Base {
    char pad[8];
    int m0c;
    int m10;
    char m14, m15, m16;
    H();
};
H::H() : Base() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    m15 = 0;
    m16 = 0;
    vptr = 0x414420;
}
