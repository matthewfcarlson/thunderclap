extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1b7cd0[];
extern void* g_vftable2[];
class Ref_1b7cd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1b7cd0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

class CFMVManager_1b7cd0 : public Base_1b7cd0 {
  public:
    char pad[8];
    Ref_1b7cd0* mc;
    CFMVManager_1b7cd0* f0(unsigned char fl);
};
CFMVManager_1b7cd0* CFMVManager_1b7cd0::f0(unsigned char fl) {
    vptr = g_vftable_1b7cd0;
    _ReadWriteBarrier();
    Ref_1b7cd0* t = mc;
    if (t) {
        mc = 0;
        t->Release();
    }
    if (fl & 1)
        Free(this);
    return this;
}
