extern "C" void _ReadWriteBarrier();
extern void* g_f2[];
void __cdecl Drop(void*);
class Res {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    char pad[8];
    Res* p0;
    void Fin();
};
class Obj : public Base {
  public:
    char pad2[4];
    void* p1;

    void* p2;
    void F();
};
void Obj::F() {
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
