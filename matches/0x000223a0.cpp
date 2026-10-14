extern "C" void _ReadWriteBarrier();
extern int orient_vftable, action_vftable;
class Ref_223a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class CAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};
class COrientAction : public CAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual COrientAction* vfunc_2(unsigned int);
    char pad[0x18];
    Ref_223a0* mSecond;
    char pad2[4];
    Ref_223a0* mFirst;
    void helper();
};
void __cdecl thunk_FUN_00267090(COrientAction*);
COrientAction* COrientAction::vfunc_2(unsigned int flags) {
    *(void**)this = &orient_vftable;
    _ReadWriteBarrier();
    Ref_223a0* q = mFirst;
    if (q) {
        q->Release();
        mFirst = 0;
    }
    *(void**)this = &action_vftable;
    _ReadWriteBarrier();
    q = mSecond;
    if (q) {
        q->Release();
        mSecond = 0;
    }
    helper();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}