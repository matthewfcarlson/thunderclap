extern void* g_vftable[];
class ParamValueBool_50410 {
  public:
    ParamValueBool_50410(int);
    virtual void f0();
    char pad[0x0c];
};
class ParamBool_50410 : public ParamValueBool_50410 {
  public:
    ParamBool_50410(int a, int b);
    int m10;
};
ParamBool_50410::ParamBool_50410(int a, int b) : ParamValueBool_50410(a) {
    *(void**)this = g_vftable;
    m10 = b;
}
