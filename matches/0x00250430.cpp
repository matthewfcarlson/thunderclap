namespace audio {
class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class SeqActionWait : public SeqAction {
  public:
    virtual SeqActionWait* vfunc_0(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
extern int global_bss;
audio::SeqActionWait* audio::SeqActionWait::vfunc_0(int x) {
    SeqActionWait* p = this;
    *(void**)p = (void*)0x4298fc;
    if (x & 1)
        FUN_00247550(&global_bss, this);
    return this;
}
