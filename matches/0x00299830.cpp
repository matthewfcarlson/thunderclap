extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base_vftable[];
void operator delete(void*);
void operator delete[](void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    char pad[8];
    void* mc;
    char pad2[8];
    void* m18;
    char pad3[8];
    Ref** m24;
    Ref** m28;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    unsigned n = m28 - m24;
    for (unsigned i = 0; i < n; i++) {
        Ref** p = &m24[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m24)
        operator delete[](m24);
    if (m18)
        operator delete[](m18);
    if (mc)
        operator delete[](mc);
    vptr = g_base_vftable;
}
