extern void* g_vftable[];
class ParamValueBool_6c600 {
  public:
    ParamValueBool_6c600(int);
    virtual void f();
    char pad[0x0c];
};
class ParamBool_6c600 : public ParamValueBool_6c600 {
  public:
    ParamBool_6c600(int a, int b);
    virtual void g();
    int m10;
};
ParamBool_6c600::ParamBool_6c600(int a, int b) : ParamValueBool_6c600(a) {
    *(void**)this = g_vftable;
    m10 = b;
}
