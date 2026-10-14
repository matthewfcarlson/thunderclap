namespace pure3d {
namespace scenegraph {
class TransformNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool vfunc_7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    char pad[12];
    unsigned char flags;
    char p[7];
    unsigned count;
    void** items;
    char p2[0x88];
    struct Obj_296850* object;
};
class Obj_296850 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual bool check();
};
class Item_296850 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual bool check();
};
bool TransformNode::vfunc_7() {
    if (!(flags & 1) && object && !object->check())
        return false;
    if (!(flags & 1)) {
        for (unsigned i = 0; i < count; ++i)
            if (!((Item_296850*)items[i])->check())
                return false;
    }
    return true;
}
} // namespace scenegraph
} // namespace pure3d