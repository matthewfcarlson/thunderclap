#include "gen/hulkfight.h"

class Track_131e70 {
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
    int call(hulkfight::DialogueTrack*, int);
};
extern H* FUN_0008d690(int);

int hulkfight::DialogueTrack::vfunc_10(int a, int b, int c) {
    H* p = FUN_0008d690(0x24);
    if (p)
        return p->call(this, c);
    return 0;
}
