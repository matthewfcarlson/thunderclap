#include "gen/fight.h"

extern void* __cdecl Allocate(unsigned int);
void* operator new(unsigned int, void* p) {
    return p;
}

class Track_132d80 {
  public:
    Track_132d80();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

class DebugPrintTrack_132d80 : public Track_132d80 {
  public:
    DebugPrintTrack_132d80();
    virtual void f5();
    int unused;
    int x;
    int a;
    int b;
    int c;
    int d;
};

DebugPrintTrack_132d80::DebugPrintTrack_132d80() {
    a = 0;
    b = 0xbf800000;
    c = 0;
    d = 0;
    x = 1;
}

class TrackFactory_132d80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::DebugPrintTrack>::vfunc_5() {
    DebugPrintTrack_132d80* p = (DebugPrintTrack_132d80*)Allocate(0x1c);
    if (p) {
        new (p) DebugPrintTrack_132d80();
        return (void*)(p);
    }
    return (void*)(0);
}
