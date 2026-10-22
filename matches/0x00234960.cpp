extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub_234960 {
    void Init(int a);
};
class ParamValueFloat_234960 {
  public:
    void* vptr;
    char pad4[4];
    Sub_234960 m8;
    ParamValueFloat_234960* ctor(int a);
};
ParamValueFloat_234960* ParamValueFloat_234960::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
