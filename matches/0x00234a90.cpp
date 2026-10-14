extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub_234a90 {
    void Init(int a);
};
class Obj_234a90 {
  public:
    void* vptr;
    char pad4[4];
    Sub_234a90 m8;
    Obj_234a90* ctor(int a);
};
Obj_234a90* Obj_234a90::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
