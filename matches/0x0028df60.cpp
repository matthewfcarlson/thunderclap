extern "C" void _ReadWriteBarrier();
extern void* g_vftable_28df60[];
extern void* g_vftable2[];
void operator delete(void*);
void operator delete[](void*);
class Ref_28df60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_28df60 {
  public:
    void* vptr;
};
class Obj_28df60 : public Base_28df60 {
  public:
    char pad[8];
    Ref_28df60* mc;
    void* m10;
    void* m14;
    Obj_28df60* f0(unsigned char flags);
};
Obj_28df60* Obj_28df60::f0(unsigned char flags) {
    vptr = g_vftable_28df60;
    if (!mc) {
        operator delete[](m14);
    } else {
        _ReadWriteBarrier();
        if (mc) {
            mc->Release();
            mc = 0;
        }
    }
    m14 = 0;
    vptr = g_vftable2;
    if (flags & 1)
        operator delete(this);
    return this;
}
