extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    Base();
    void* vptr;
};
class Obj : public Base {
  public:
    Obj();
    char pad[4];
    int mA;
    int mB;
};
Obj::Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    mB = 0;
    mA = 1;
}
