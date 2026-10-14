extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a2e20[];
class Helper_2a2e20 {
  public:
    void Fn();
};
class OT {
  public:
    void* vptr;
    char p4[0x1c];
    void* m20;
    char p24[8];
    void* m2c;
    OT* f2(unsigned char flags);
};
void operator delete(void*);
void operator delete[](void*);
OT* OT::f2(unsigned char flags) {
    vptr = g_vftable_2a2e20;
    _ReadWriteBarrier();
    if (m2c)
        operator delete[](m2c);
    if (m20)
        operator delete[](m20);
    ((Helper_2a2e20*)this)->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
