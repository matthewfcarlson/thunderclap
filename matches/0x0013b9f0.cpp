extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    void* vptr;
    Base() { vptr = 0; }
};
class Factory : public Base {
  public:
    Factory();
};
Factory::Factory() {
    vptr = g_vftable;
    _ReadWriteBarrier();
}
