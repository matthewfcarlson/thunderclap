class ParamValue {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    int pad;
};
class Elem_2355c0 {
  public:
    void Fn();
};
class ParamValueColour : public ParamValue {
  public:
    char gap[4];
    virtual ParamValueColour* vfunc_0(int);
};
extern int vftable_2355c0;
extern void FUN_00267090(ParamValueColour*);
ParamValueColour* ParamValueColour::vfunc_0(int flags) {
    *(int*)this = (int)&vftable_2355c0;
    Elem_2355c0* q = (Elem_2355c0*)((char*)this + 8);
    q->Fn();
    if (flags & 1)
        FUN_00267090(this);
    return this;
}