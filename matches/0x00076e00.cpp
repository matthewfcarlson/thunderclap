#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
class CTrack_76e00 {
  public:
    CTrack_76e00() throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int x;
    int flag;
};
class CInvulnerableTrack_76e00 : public CTrack_76e00 {
  public:
    CInvulnerableTrack_76e00() throw();
    virtual void f0();
    int a;
    float b;
    int c;
};
CInvulnerableTrack_76e00::CInvulnerableTrack_76e00() throw() {
    a = 0;
    b = -1.0f;
    c = 0;
    flag = 1;
}

template <> void* fight::TrackFactoryTemplate<CInvulnerableTrack>::vfunc_5() {
    return (void*)(new CInvulnerableTrack_76e00);
}
