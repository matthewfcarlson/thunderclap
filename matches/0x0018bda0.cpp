extern "C" char DAT_004192cc[];
typedef unsigned int u32;
typedef unsigned char u8;
void* __cdecl alloc(unsigned int);
class PropTrack {
  public:
    u32 v;
    u32 pad[2];
    u32 a;
    u32 b;
    u8 c;
    u8 d;
    PropTrack();
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual PropTrack* f5();
};
void Factory::f0() {}
void Factory::f1() {}
void Factory::f2() {}
void Factory::f3() {}
void Factory::f4() {}
PropTrack* Factory::f5() {
    PropTrack* p = (PropTrack*)alloc(0x18);
    if (p) {
        p->PropTrack::PropTrack();
        p->v = ((int)DAT_004192cc);
        p->a = 0;
        p->b = 0xffffffff;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return (PropTrack*)0;
}