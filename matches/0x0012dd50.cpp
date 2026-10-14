extern "C" void _ReadWriteBarrier();
extern void* g_vt_12dd50[];
void operator delete(void*);
class Ref_12dd50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_12dd50 {
  public:
    void* vptr;
    void Fin();
};
class Obj_12dd50 : public Base_12dd50 {
  public:
    char pad[32 - 4];
    Ref_12dd50* m;
    Obj_12dd50* f2(unsigned char flags);
};
Obj_12dd50* Obj_12dd50::f2(unsigned char flags) {
    vptr = g_vt_12dd50;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
