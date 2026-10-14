extern "C" char DAT_004192cc[];
typedef unsigned int u32_18bda0;
typedef unsigned char u8;
void* __cdecl alloc(unsigned int);
class PropTrack {
  public:
    u32_18bda0 v;
    u32_18bda0 pad[2];
    u32_18bda0 a;
    u32_18bda0 b;
    u8 c;
    u8 d;
    PropTrack();
};
class Factory_18bda0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual PropTrack* f5();
};
void Factory_18bda0::f0() {}
void Factory_18bda0::f1() {}
void Factory_18bda0::f2() {}
void Factory_18bda0::f3() {}
void Factory_18bda0::f4() {}
PropTrack* Factory_18bda0::f5() {
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