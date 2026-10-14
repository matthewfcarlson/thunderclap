struct Base_2d3de0 {
    Base_2d3de0();
    virtual void f();
    char p[0x3c];
};
struct Sub_2d3de0 {
    void Init();
    char q[0x40];
};
struct PE : Base_2d3de0 {
    Sub_2d3de0 s;
    int a[9];
    char b0, b1, b2;
    PE();
    virtual void f();
};
PE::PE() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    b0 = 0;
    b1 = 1;
    b2 = 0;
    s.Init();
}
