extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class ParamValueBool_110740 {
  public:
    ParamValueBool_110740(int a);
    virtual void f0();
    char pad[12];
};
class ParamBool_110740 : public ParamValueBool_110740 {
  public:
    ParamBool_110740(int a, int b);
    virtual void f0();
    int m10;
};
ParamBool_110740::ParamBool_110740(int a, int b) : ParamValueBool_110740(a) {
    m10 = b;
}
