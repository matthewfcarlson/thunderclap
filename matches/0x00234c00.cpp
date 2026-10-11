extern void* g_vftable[];
extern void* g_vftable2[];
class Sub {
  public:
    void Init(int a);
};
class ParamValue {
  public:
    void* vptr;
    char pad[4];
    Sub sub;
    ParamValue(int a);
};
ParamValue::ParamValue(int a) {
    vptr = g_vftable;
    sub.Init(a);
    vptr = g_vftable2;
}
