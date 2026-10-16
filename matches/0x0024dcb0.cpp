namespace audio { class ListenerEffectPsp {
  public:
    virtual void f0();
    virtual void f1();
    virtual ListenerEffectPsp* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
}; }
extern void __fastcall FUN_00244f70(audio::ListenerEffectPsp*);
extern void FUN_00247550(void*, audio::ListenerEffectPsp*);
extern char DAT_004e6628;
audio::ListenerEffectPsp* audio::ListenerEffectPsp::vfunc_2(int x) {
    FUN_00244f70(this);
    if (x & 1)
        FUN_00247550(&DAT_004e6628, this);
    return this;
}