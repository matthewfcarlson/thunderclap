extern "C" void _ReadWriteBarrier();
extern void* g_vftable_13b9f0[];
class Base_13b9f0 {
  public:
    void* vptr;
    Base_13b9f0() { vptr = 0; }
};
class Factory_13b9f0 : public Base_13b9f0 {
  public:
    Factory_13b9f0();
};
Factory_13b9f0::Factory_13b9f0() {
    vptr = g_vftable_13b9f0;
    _ReadWriteBarrier();
}
