extern "C" void _ReadWriteBarrier();
extern char HitEffectAction_vftable[];
class Ref_145da0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_145da0 {
  public:
    void Fn();
};
extern void __cdecl thunk_FUN_00267090(void*);
class HitEffectAction {
  public:
    void* vptr;
    char p[0x18];
    Ref_145da0* m1c;
    int m20;
    Ref_145da0* m24;
    HitEffectAction* f2(unsigned char);
};
HitEffectAction* HitEffectAction::f2(unsigned char flags) {
    vptr = HitEffectAction_vftable;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20)
        m20 = 0;
    if (m1c) {
        m1c->f1();
        m1c = 0;
    }
    ((Helper_145da0*)this)->Fn();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
