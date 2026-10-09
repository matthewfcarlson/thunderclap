typedef unsigned char u8;
extern "C" void* memcpy(void*, const void*, unsigned int);
class Image8 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void vfunc_5(int, int);
    virtual void vfunc_6(int, int, const void*);
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    char pad[0x20];
    u8* pixels;
};
void Image8::vfunc_6(int width, int height, const void* src) {
    vfunc_5(width, height);
    memcpy(pixels, src, width * height);
}