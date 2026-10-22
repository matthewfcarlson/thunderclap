extern void* g_vftable[];
extern void* g_vftable2[];
class ParamValueInt_13b630 {
  public:
    void* vptr;
    ParamValueInt_13b630(int a);
};
class ParamIntConstRange_13b630 : public ParamValueInt_13b630 {
  public:
    char pad[12];
    int m10;
    ParamIntConstRange_13b630(int a, int b);
};
ParamIntConstRange_13b630::ParamIntConstRange_13b630(int a, int b) : ParamValueInt_13b630(a) {
    vptr = g_vftable;
    m10 = b;
}
