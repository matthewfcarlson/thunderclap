// Same code shape as 0x00131e70 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Track_1320f0 {
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
    virtual void f9();
};
struct H {
    int call(hulkfight::XPTrack*, int);
};
extern H* FUN_0008d690(int);

int hulkfight::XPTrack::vfunc_10(int a, int b, int c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call(this, c);
    return 0;
}
