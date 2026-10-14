extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1dc10[];
class Ref_1dc10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1dc10 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1dc10 : public Base_1dc10 {
  public:
    char pad[24];
    Ref_1dc10* m;
    ~Obj_1dc10();
};
Obj_1dc10::~Obj_1dc10() {
    vptr = g_vftable_1dc10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
