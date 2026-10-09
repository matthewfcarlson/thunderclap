class pddiDisplay {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual bool f4(int*);
    virtual bool f5(int, int, int);
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
};
class d3dDisplay : public pddiDisplay {
  public:
    char pad[0x43c - sizeof(pddiDisplay)];
    int a, b, c;
    char gap[0x478 - 0x448];
    int y, x, z;
    bool f5(int, int, int);
};
bool d3dDisplay::f5(int p2, int p3, int p4) {
    if (p2 == x && p3 == y && p4 == z)
        return true;
    a = p2;
    b = p3;
    c = p4;
    return f4(&a);
}
