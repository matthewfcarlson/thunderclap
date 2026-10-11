extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042d2dc[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin_002a35f0();
};
class Obj : public Base {
  public:
    char pad[60];
    Ref* m;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable_0042d2dc;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a35f0();
}
