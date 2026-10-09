class d3dPrimBuffer {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void vfunc_8(unsigned int);
    char pad[0x35 - sizeof(void*)];
};
void d3dPrimBuffer::vfunc_8(unsigned int x) {
    *((unsigned char*)this + 0x35) = 0;
    *((unsigned int*)this + 9) = x;
}