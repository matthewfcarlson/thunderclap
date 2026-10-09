class HSlider {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual char vfunc_10(int, int);
    char pad[0x168 - 4];
    int m168;
    int m16c;
    int m170;
    int m174;
    int m178;
    void Change2();
    void Change6();
};
char HSlider::vfunc_10(int op, int value) {
    switch (op) {
    case 2:
        if (m168) {
            Change2();
            m170 = 2;
            m174 = value;
            m178 = 0;
        }
        return 1;
    case 6:
        if (m168) {
            Change6();
            m174 = value;
            m170 = 6;
            m178 = 0;
            return 1;
        }
        return 1;
    default:
        return 0;
    }
}