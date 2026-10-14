class Inner_1b8350 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int);
};
class Thing_1b8350 {
  public:
    char p0[4];
    int value;
    char p8;
    char flag9;
    char pa[2];
    Inner_1b8350* inner;
    char p10[0x104];
    unsigned char b114;
    char p115[0x1b];
    char b130;
    char p131[3];
    int arg134;
    void Helper(int, unsigned char);
    void Run(int, int);
};
extern int getval();
extern unsigned char gflag;
void Thing_1b8350::Run(int a, int b) {
    Helper(a, b114);
    if (inner) {
        flag9 = 0;
        inner->v8();
        value = getval() + b;
        gflag = 1;
        if (b130 && inner) {
            inner->v10(arg134);
            b130 = 0;
        }
    }
}
