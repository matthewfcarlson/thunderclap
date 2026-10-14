extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1bef80[];
extern void* g_vftable2[];
class Ref_1bef80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1bef80 {
  public:
    void* vptr;
};
class Obj_1bef80 : public Base_1bef80 {
  public:
    char pad[0x14];
    Ref_1bef80* m18;
    ~Obj_1bef80() throw();
};
Obj_1bef80::~Obj_1bef80() throw() {
    vptr = g_vftable_1bef80;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
}
