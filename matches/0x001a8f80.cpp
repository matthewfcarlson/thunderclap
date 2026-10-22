extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1a8f80[];
class Ref_1a8f80 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class EffectAction {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1a8f80* m20;
    char p24[4];
    Ref_1a8f80* m28;
    EffectAction* f2(int);
};
class EffectAction_1a8f80 {
  public:
    void Fn();
};
extern void __cdecl thunk_FUN_00267090(EffectAction*);
EffectAction* EffectAction::f2(int flags) {
    *(void* volatile*)this = &g_vftable_1a8f80;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((EffectAction_1a8f80*)this)->Fn();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
