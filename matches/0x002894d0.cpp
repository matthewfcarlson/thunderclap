extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042c8e8[];
extern void* g_base[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    char pad[0x10];
    Ref* m14;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable_0042c8e8;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base;
}
