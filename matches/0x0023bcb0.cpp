struct Rd {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Read(char* buf, unsigned n);
};
struct B {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual bool V10(int a, int b, char* buf);
    char p4[4];
    Rd* rd;
    char p5[1];
    char swap;
    char p6[2];
    int mark;
    char p7[0xc];
    unsigned remain;
};
bool B::V10(int a, int b, char* buf) {
    int* q = &mark;
    *q = -1;
    unsigned n = remain;
    if (n > 4)
        n = 4;
    int r = rd->Read(buf, n);
    remain -= n;
    bool ok = r == 4;
    if (swap) {
        char* hi = buf + 3;
        char* lo = buf;
        if (lo < hi) {
            do {
                char t = *lo;
                *lo = *hi;
                lo++;
                *hi = t;
                hi--;
            } while (lo < hi);
        }
    }
    return ok;
}
