extern "C" void _ReadWriteBarrier();
extern void* g_f2[];
void __cdecl Drop(void*);
class Res_28c130 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_28c130 {
  public:
    void* vptr;
    char pad[8];
    Res_28c130* p0;
    void Fin();
};
class Obj_28c130 : public Base_28c130 {
  public:
    char pad2[4];
    void* p1;

    void* p2;
    void F();
};
void Obj_28c130::F() {
    if (!p0) {
        vptr = g_f2;
        Drop(p2);
    } else
        vptr = g_f2;
    p2 = 0;
    if (!p0) {
        Drop(p1);
    } else {
        _ReadWriteBarrier();
        if (p0) {
            p0->Release();
            p0 = 0;
        }
    }
    p1 = 0;
    Fin();
}
