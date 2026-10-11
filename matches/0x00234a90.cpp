extern void* g_vftableA[];
extern void* g_vftableB[];
struct Sub {
    void Init(int a);
};
class Obj {
  public:
    void* vptr;
    char pad4[4];
    Sub m8;
    Obj* ctor(int a);
};
Obj* Obj::ctor(int a) {
    *(void* volatile*)&vptr = g_vftableA;
    m8.Init(a);
    vptr = g_vftableB;
    return this;
}
