extern int base_vtable;
class ParamValue {
  public:
    virtual ParamValue* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    int pad;
};
class Part {
  public:
    void Init();
};
class ParamValueString : public ParamValue {
  public:
    virtual ParamValueString* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_5();
    Part part;
};
extern void thunk_FUN_00267090(ParamValueString*);
ParamValueString* ParamValueString::vfunc_0(int x) {
    *(int*)this = (int)&base_vtable;
    part.Init();
    if (x & 1)
        thunk_FUN_00267090(this);
    return this;
}