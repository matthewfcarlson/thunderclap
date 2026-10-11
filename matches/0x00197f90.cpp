extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
    Ref* m14;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m4)
        m4 = 0;
}
