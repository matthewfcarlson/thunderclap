extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub_235170 {
    void Init(int a);
};
class Obj_235170 {
  public:
    void* vptr;
    char pad4[4];
    Sub_235170 m8;
    Obj_235170* ctor(int a);
};
Obj_235170* Obj_235170::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
