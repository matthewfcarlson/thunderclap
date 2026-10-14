class Stream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Read(void*, int);
};
namespace fight {
class BinReader {
  public:
    char pad0[8];
    Stream* stream;
    char padC[1];
    char swap;
    char padE[10];
    int a;
    int b;
    char data[4];
    char pad24[4];
    int nextA;
    int nextB;
    char done;
    void Prep();
    __int64 vfunc_16(int, int);
};
} // namespace fight
__int64 fight::BinReader::vfunc_16(int, int) {
    Prep();
    a = nextA;
    b = nextB;
    stream->Read(data, 4);
    if (swap) {
        unsigned char* p = (unsigned char*)data;
        unsigned char* q = p + 3;
        if (p < q)
            do {
                unsigned char t = *p;
                *p = *q;
                ++p;
                *q = t;
                --q;
            } while (p < q);
    }
    nextA = 0;
    nextB = 0;
    done = 1;
    return *(__int64*)&a;
}