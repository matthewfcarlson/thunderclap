class CGrappleInvulnerableTrack {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    CGrappleInvulnerableTrack();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern int vtable;
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CGrappleInvulnerableTrack* f();
};
CGrappleInvulnerableTrack* Factory::f() {
    CGrappleInvulnerableTrack* p = (CGrappleInvulnerableTrack*)Alloc(0x18);
    if (p) {
        p->CGrappleInvulnerableTrack::CGrappleInvulnerableTrack();
        *(int*)p = (int)&vtable;
        return p;
    }
    return 0;
}