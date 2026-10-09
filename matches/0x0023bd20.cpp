class Source {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, unsigned int);
};
class BinReader {
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
    virtual char vfunc_9(int, int, char*);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    char p4[4];
    Source* src;
    char p0c[1];
    char flag;
    char p0e[2];
    volatile int status;
    char p14[12];
    volatile unsigned int remaining;
    char p24[4];
};
char BinReader::vfunc_9(int x, int y, char* buf) {
    status = -1;
    unsigned int n = remaining;
    if (n > 4)
        n = 4;
    int r = src->Read(buf, n);
    remaining = remaining - n;
    char result = (r == 4);
    if (flag) {
        char* a = buf;
        char* b = buf + 3;
        while (a < b) {
            char t = *a;
            *a = *b;
            *b = t;
            ++a;
            --b;
        }
    }
    return result;
}