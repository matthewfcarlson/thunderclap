extern void* g_vftable_234c00[];
extern void* g_vftable2[];
class Sub_234c00 {
  public:
    void Init(int a);
};
class ParamValueScript_234c00 {
  public:
    void* vptr;
    char pad[4];
    Sub_234c00 sub;
    ParamValueScript_234c00(int a);
};
ParamValueScript_234c00::ParamValueScript_234c00(int a) {
    vptr = g_vftable_234c00;
    sub.Init(a);
    vptr = g_vftable2;
}
