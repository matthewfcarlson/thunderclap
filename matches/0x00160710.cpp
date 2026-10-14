extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_160710 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_160710 {
  public:
    void* vptr;
    void Fin();
};
class Obj_160710 : public Base_160710 {
  public:
    char pad[24];
    Ref_160710* m;
    ~Obj_160710() throw();
};
Obj_160710::~Obj_160710() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
