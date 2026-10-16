#include "gen/fight.h"

class Stream_23bd90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, int);
};

char fight::BinReader::vfunc_12(int a, int b, void* __p2) { int * out = (int *)__p2;

    unsigned n = this->f_20;
    if (n > 4)
        n = 4;
    int got = (*(Stream_23bd90 * *)&this->f_08)->Read(&this->f_10, n);
    this->f_20 -= n;
    char ok = got == 4;
    if ((*(unsigned char *)&this->f_0d)) {
        unsigned char* p = (unsigned char*)&this->f_10;
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
    *out = this->f_10;
    return ok;
}
