extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub_234ba0 {
    void Init(int a);
};
class Obj_234ba0 {
  public:
    void* vptr;
    char pad4[4];
    Sub_234ba0 m8;
    Obj_234ba0* ctor(int a);
};
Obj_234ba0* Obj_234ba0::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
