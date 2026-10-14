extern void* __cdecl Allocate(unsigned int);
void* operator new(unsigned int, void* p) {
    return p;
}

class Base_132d80 {
  public:
    Base_132d80();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

class DebugPrintTrack : public Base_132d80 {
  public:
    DebugPrintTrack();
    virtual void f5();
    int unused;
    int x;
    int a;
    int b;
    int c;
    int d;
};

DebugPrintTrack::DebugPrintTrack() {
    a = 0;
    b = 0xbf800000;
    c = 0;
    d = 0;
    x = 1;
}

class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
class Factory_132d80 : public TrackFactory {
  public:
    void* f5();
};

void* Factory_132d80::f5() {
    DebugPrintTrack* p = (DebugPrintTrack*)Allocate(0x1c);
    if (p) {
        new (p) DebugPrintTrack();
        return p;
    }
    return 0;
}
