extern int Track_vftable;
class Param {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int);
};
class Track : public Param {
  public:
    virtual void v3();
    virtual void v4();
    virtual Track* v5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    void helper();
    Param* mThing;
};
void __cdecl thunk_FUN_00267090(Track*);
Track* Track::v5(int flag) {
    Param* p = mThing;
    *(void**)this = (void*)&Track_vftable;
    if (p)
        p->f(1);
    mThing = 0;
    helper();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
