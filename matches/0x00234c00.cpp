extern void* g_vftable_234c00[];
extern void* g_vftable2[];
class Sub_234c00 {
  public:
    void Init(int a);
};
class ParamValue {
  public:
    void* vptr;
    char pad[4];
    Sub_234c00 sub;
    ParamValue(int a);
};
ParamValue::ParamValue(int a) {
    vptr = g_vftable_234c00;
    sub.Init(a);
    vptr = g_vftable2;
}
