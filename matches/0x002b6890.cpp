extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b6890[];
class Ref_2b6890 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2b6890 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2b6890 : public Base_2b6890 {
  public:
    char pad[60];
    Ref_2b6890* m;
    ~Obj_2b6890();
};
Obj_2b6890::~Obj_2b6890() {
    vptr = g_vftable_2b6890;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
