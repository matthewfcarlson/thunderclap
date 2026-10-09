class Stream {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, int);
};
class BinReader {
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
    virtual void v10();
    virtual void v11();
    virtual char vfunc_12(int, int, int*);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    char p4[4];
    Stream* stream;
    unsigned char pC, reverse;
    char pE[2];
    int value;
    char p14[12];
    unsigned remaining;
};
char BinReader::vfunc_12(int a, int b, int* out) {
    unsigned n = remaining;
    if (n > 4)
        n = 4;
    int got = stream->Read(&value, n);
    remaining -= n;
    char ok = got == 4;
    if (reverse) {
        unsigned char* p = (unsigned char*)&value;
        unsigned char* q = p + 3;
        if (p < q) {
            do {
                unsigned char t = *p;
                *p = *q;
                *q = t;
                ++p;
                --q;
            } while (p < q);
        }
    }
    *out = value;
    return ok;
}