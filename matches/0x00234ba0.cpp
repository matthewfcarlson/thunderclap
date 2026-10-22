extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub_234ba0 {
    void Init(int a);
};
class ParamValueNameList_234ba0 {
  public:
    void* vptr;
    char pad4[4];
    Sub_234ba0 m8;
    ParamValueNameList_234ba0* ctor(int a);
};
ParamValueNameList_234ba0* ParamValueNameList_234ba0::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
