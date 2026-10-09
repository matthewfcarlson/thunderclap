extern void* __cdecl Alloc(int);
extern void* GrappleVftable;
class CGrappleDamageTrack {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleDamageTrack();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CGrappleDamageTrack* f();
};
CGrappleDamageTrack* Factory::f() {
    CGrappleDamageTrack* p = (CGrappleDamageTrack*)Alloc(0x18);
    if (p) {
        p->CGrappleDamageTrack::CGrappleDamageTrack();
        *(void**)p = &GrappleVftable;
        return p;
    }
    return 0;
}