extern void* g_vftable_2d3c90[];
extern void* g_vftable_base[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Ref_2d3c90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2d3c90 {
  public:
    void* vptr;
    void Fin();
};
class Gen_2d3c90 : public Base_2d3c90 {
  public:
    char pad[0x18];
    unsigned n;
    char pad2[8];
    Ref_2d3c90* m28;
    Ref_2d3c90** arr;
    ~Gen_2d3c90();
};
Gen_2d3c90::~Gen_2d3c90() {
    vptr = g_vftable_2d3c90;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < n; i++) {
        Ref_2d3c90** p = &arr[i];
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
