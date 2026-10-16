#include "gen/fight.h"

struct Rd_23bcb0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Read(char* buf, unsigned n);
};

bool fight::BinReader::vfunc_10(int a, int b, void* __p2) { char * buf = (char *)__p2;

    int* q = &this->f_10;
    *q = -1;
    unsigned n = this->f_20;
    if (n > 4)
        n = 4;
    int r = (*(Rd_23bcb0 * *)&this->f_08)->Read(buf, n);
    this->f_20 -= n;
    bool ok = r == 4;
    if (this->f_0d) {
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
