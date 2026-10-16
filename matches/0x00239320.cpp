#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int pad;
    int flag;
};
class PrintTrack_239320 : public Base {
  public:
    PrintTrack_239320() throw() {
        x = 0;
        y = 0;
        z = 0;
        flag = 1;
    }
    virtual void a();
    int x;
    int y;
    int z;
};

template <> void* fight::TrackFactoryTemplate<fight::PrintTrack>::vfunc_5() {
    return (void*)(new PrintTrack_239320);
}
