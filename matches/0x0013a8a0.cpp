// Same code shape as 0x0005e160 (propagated; names are from that function)
struct AnimationTrack_13a8a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual AnimationTrack_13a8a0* vfunc_5(int);
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct H {
    void f();
};
struct G_13a8a0 {
    void g();
};
extern void __cdecl thunk_FUN_00267090(AnimationTrack_13a8a0*);
extern int vftable_13a8a0;
AnimationTrack_13a8a0* AnimationTrack_13a8a0::vfunc_5(int param) {
    *(int*)this = (int)&vftable_13a8a0;
    ((H*)((char*)this + 0x38))->f();
    ((H*)((char*)this + 0x18))->f();
    ((G_13a8a0*)this)->g();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
