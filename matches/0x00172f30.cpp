extern "C" void _ReadWriteBarrier();
extern void* g_vftable_172f30[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_172f30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_172f30 {
  public:
    void* vptr;
    void Fin();
};

class Sub_172f30 {
  public:
    void Fin();
};
class Obj_172f30 : public Base_172f30 {
  public:
    char pad[0x14];
    Sub_172f30 s18;
    char pad2[7];
    Sub_172f30 s20;
    Obj_172f30* f2(unsigned char flags);
};
Obj_172f30* Obj_172f30::f2(unsigned char flags) {
    vptr = g_vftable_172f30;
    s20.Fin();
    s18.Fin();
    Base_172f30::Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
