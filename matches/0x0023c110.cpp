#include "gen/fight.h"

class Stream_23c110 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Read(void*, int);
};
namespace fight {
struct BinReader_nv_23c110 {
    void Prep();
};
} // namespace fight
__int64 fight::BinReader::vfunc_16(int , int ) {
    ((BinReader_nv_23c110*)this)->Prep();
    this->f_18 = this->f_28;
    this->f_1c = this->f_2c;
    (*(Stream_23c110 * *)&this->f_08)->Read((*(char (*)[4])&this->f_20), 4);
    if (this->f_0d) {
        unsigned char* p = (unsigned char*)(*(char (*)[4])&this->f_20);
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
    this->f_28 = 0;
    this->f_2c = 0;
    (*(char *)&this->f_30) = 1;
    return (__int64)(*(__int64*)&this->f_18);
}
