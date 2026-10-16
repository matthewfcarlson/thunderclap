#include "gen/fight.h"

class Source_23bd20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, unsigned int);
};

char fight::BinReader::vfunc_9(int x, int y, void* __p2) { char * buf = (char *)__p2;

    (*(volatile int *)&this->f_10) = -1;
    unsigned int n = (*(volatile unsigned int *)&this->f_20);
    if (n > 4)
        n = 4;
    int r = (*(Source_23bd20 * *)&this->f_08)->Read(buf, n);
    (*(volatile unsigned int *)&this->f_20) = (*(volatile unsigned int *)&this->f_20) - n;
    char result = (r == 4);
    if (this->f_0d) {
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
