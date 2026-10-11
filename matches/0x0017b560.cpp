extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class FootPivotAction {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref* m20;
    char p24[4];
    Ref* m28;
    FootPivotAction* f2(unsigned char);
};
class Helper {
  public:
    void Fn();
};
extern void __cdecl thunk_FUN_00267090(FootPivotAction*);
FootPivotAction* FootPivotAction::f2(unsigned char flags) {
    *(void**)this = &g_vftable;
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
    ((Helper*)this)->Fn();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
