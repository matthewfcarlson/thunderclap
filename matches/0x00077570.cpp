#include "gen/fight.h"

class Base_77570 {
  public:
    Base_77570();
    virtual void bv();
    int bx;
};
class CSoundTrack_77570 : public Base_77570 {
  public:
    CSoundTrack_77570() : Base_77570() {
        zero = 0;
        flag = 0;
        flag2 = 0;
        one = 1;
    }
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int one;
    int zero;
    unsigned char flag;
    char pad[0x3f];
    unsigned char flag2;
};
void* operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSoundTrack>::vfunc_5() {
    CSoundTrack_77570* p = (CSoundTrack_77570*)operator_new(0x54);
    if (p) {
        p->CSoundTrack_77570::CSoundTrack_77570();
        return (void*)(p);
    }
    return (void*)(0);
}
