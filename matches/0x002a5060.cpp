extern "C" void _ReadWriteBarrier();
class Base_2a5060 {
  public:
    virtual void B();
    int b[3];
    Base_2a5060();
};
class DrawablePrimitive : public Base_2a5060 {
  public:
    virtual void B();
    int a[11];
    DrawablePrimitive();
};
extern int drawable_vtable;
DrawablePrimitive::DrawablePrimitive() : Base_2a5060() {
    a[0] = 0;
    *((int*)this) = (int)&drawable_vtable;
    _ReadWriteBarrier();
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    a[9] = 0;
    a[10] = 0;
}