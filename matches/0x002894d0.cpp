extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042c8e8[];
extern void* g_base_2894d0[];
class Ref_2894d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj_2894d0 {
  public:
    void* vptr;
    char pad[0x10];
    Ref_2894d0* m14;
    ~Obj_2894d0();
};
Obj_2894d0::~Obj_2894d0() {
    vptr = g_vftable_0042c8e8;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base_2894d0;
}
