class Sub_235530 {
  public:
    Sub_235530();
};
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class ParamValueScript : public ParamValue {
  public:
    char pad[4];
    Sub_235530 sub;
    ParamValueScript(int);
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_5();
};
extern void __cdecl thunk_FUN_00267090(ParamValueScript*);
ParamValueScript::ParamValueScript(int f) : sub() {
    if (f & 1)
        thunk_FUN_00267090(this);
}
void ParamValueScript::vfunc_0() {}
