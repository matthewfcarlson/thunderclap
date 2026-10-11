extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete[](void*);
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
class Obj : public Base {
  public:
    char pad4[0x24];
    Ref* m28;
    char pad2c[8];
    char* m34;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m34)
        operator delete[](m34 - 4);
    Fin();
}
