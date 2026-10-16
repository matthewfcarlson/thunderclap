#include "gen/pure3d.h"

namespace pure3d {
namespace scenegraph {
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

} // namespace scenegraph
} // namespace pure3d
bool pure3d::scenegraph::TransformNode::vfunc_7() {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(struct Obj_296850 * *)&this->f_a8) && !(*(struct Obj_296850 * *)&this->f_a8)->check())
        return false;
    if (!((*(unsigned char *)&this->f_10) & 1)) {
        for (unsigned i = 0; i < this->f_18; ++i)
            if (!((Item_296850*)(*(void ** *)&this->f_1c)[i])->check())
                return false;
    }
    return true;
}
