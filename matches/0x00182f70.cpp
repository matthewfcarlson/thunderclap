extern int vftable_182f70;
class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Elem_182f70 {
  public:
    void Fn();
};
class GrapplePropStateByNameCondition : public Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual GrapplePropStateByNameCondition* vfunc_5(int);
    virtual void v6();
    char pad0[0x14];
    Elem_182f70 elem;
    void Init();
};
extern void __cdecl thunk(GrapplePropStateByNameCondition*);
GrapplePropStateByNameCondition* GrapplePropStateByNameCondition::vfunc_5(int flag) {
    *(int*)this = (int)&vftable_182f70;
    elem.Fn();
    Init();
    if (flag & 1)
        thunk(this);
    return this;
}