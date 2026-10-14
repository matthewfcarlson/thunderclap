extern "C" char DAT_003fe6c8[];
typedef unsigned int u32_76590;
void* __cdecl Allocate(unsigned int);
class Track {
  public:
    void Init();
};
class Template_76590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
};
void* Template_76590::f() {
    void* p = Allocate(0x3c);
    if (p) {
        ((Track*)p)->Init();
        *(u32_76590*)p = ((int)DAT_003fe6c8);
        return p;
    }
    return 0;
}