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
};
class Cam : public Base {
  public:
    char pad[0x170 - 4];
    Ref* m170;
    ~Cam();
};
Cam::~Cam() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m170) {
        m170->Release();
        m170 = 0;
    }
    Fin();
}
