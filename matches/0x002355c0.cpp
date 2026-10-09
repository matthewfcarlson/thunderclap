class ParamValue {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    int pad;
};
class Elem {
  public:
    void Fn();
};
class ParamValueColour : public ParamValue {
  public:
    char gap[4];
    virtual ParamValueColour* vfunc_0(int);
};
extern int vftable;
extern void FUN_00267090(ParamValueColour*);
ParamValueColour* ParamValueColour::vfunc_0(int flags) {
    *(int*)this = (int)&vftable;
    Elem* q = (Elem*)((char*)this + 8);
    q->Fn();
    if (flags & 1)
        FUN_00267090(this);
    return this;
}