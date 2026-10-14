extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    void* vptr;
    int m4;
    int m8;
    Base();
};
class Obj : public Base {
  public:
    int mc;
    Obj();
};
Obj::Obj() : Base() {
    vptr = g_vftable;
    mc = 0;
}
