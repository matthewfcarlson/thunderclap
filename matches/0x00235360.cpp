class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int pad;
};
class Sub {
  public:
    Sub();
};
class ParamValueFloat : public ParamValue {
  public:
    ParamValueFloat(unsigned int);
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_5();
    Sub sub;
};
extern void __cdecl thunk_FUN_00267090(ParamValueFloat*);
ParamValueFloat::ParamValueFloat(unsigned int flags) {
    if (flags & 1)
        thunk_FUN_00267090(this);
}