extern void* g_vftable[];
extern void* g_vftable_base[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
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
class Gen : public Base {
  public:
    char pad[0x18];
    unsigned n;
    char pad2[8];
    Ref* m28;
    Ref** arr;
    ~Gen();
};
Gen::~Gen() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < n; i++) {
        Ref** p = &arr[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (arr)
        operator delete(arr);
    vptr = g_vftable_base;
    Fin();
}
