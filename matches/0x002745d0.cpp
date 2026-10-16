#include "gen/core.h"

class Req_2745d0 {
  public:
    virtual void v0();
    virtual void v1();
};
class Dev_2745d0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual unsigned g();
    unsigned MakeValue();
};
struct Ctx_2745d0 {
    char pad0[4];
    Req_2745d0 sub;
    char pad1[4];
    Dev_2745d0* dev;
    char pad2[8];
    unsigned value;
};

int core::DriveFormatRequest::vfunc_1() {
    Dev_2745d0* d = (*(Ctx_2745d0 * *)&this->f_08)->dev;
    unsigned x = d->g();
    unsigned y = d->MakeValue();
    (*(Ctx_2745d0 * *)&this->f_08)->sub.v0();
    (*(Ctx_2745d0 * *)&this->f_08)->value = y;
    (*(Ctx_2745d0 * *)&this->f_08)->sub.v1();
    return (int)(x);
}
