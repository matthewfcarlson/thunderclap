extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
    void Fin29();
};
class Cam : public Base {
  public:
    char pad[0x350 - 4];
    Ref* m350;
    ~Cam();
};
Cam::~Cam() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Fin29();
    Fin();
}
