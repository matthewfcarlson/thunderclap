extern void* g_vt_235220[];
extern void* g_vt2[];
struct Sub_235220 {
    void Init(int a) throw();
};
class ParamValueConditionGroup_235220 {
  public:
    void* vptr;
    char pad[4];
    Sub_235220 sub;
    ParamValueConditionGroup_235220(int a) throw();
};
ParamValueConditionGroup_235220::ParamValueConditionGroup_235220(int a) throw() {
    vptr = g_vt_235220;
    sub.Init(a);
    vptr = g_vt2;
}
