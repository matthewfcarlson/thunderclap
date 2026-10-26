// Same code shape as 0x00131e70 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Track_131f70 {
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
    int call(hulkfight::StatTrack*, int);
};
extern H* FUN_0008d690(int);

hulk_intptr hulkfight::StatTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call(this, c);
    return 0;
}
