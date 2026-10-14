extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base_147650 {
  public:
    void* vptr;
    int m4;
    int m8;
    Base_147650();
};
class Obj_147650 : public Base_147650 {
  public:
    int mc;
    Obj_147650();
};
Obj_147650::Obj_147650() : Base_147650() {
    vptr = g_vftable;
    mc = 0;
}
