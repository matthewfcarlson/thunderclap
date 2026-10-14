extern "C" char DAT_004112e4[];
typedef unsigned int u32_132b60;
extern "C" void* __cdecl alloc(unsigned int);
class Track {
  public:
    Track();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Factory_132b60 {
  public:
    Track* vfunc_5();
};
Track* Factory_132b60::vfunc_5() {
    Track* p = (Track*)alloc(0x14);
    if (p) {
        p->Track::Track();
        *(u32_132b60*)p = ((int)DAT_004112e4);
        *(u32_132b60*)((char*)p + 0xc) = 0;
        *(u32_132b60*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}