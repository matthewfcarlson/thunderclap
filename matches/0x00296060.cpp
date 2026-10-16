#include "gen/pure3d.h"

class Obj_296060 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual bool h();
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
};

bool pure3d::scenegraph::DrawableNode::vfunc_7() {
    if (((*(unsigned char *)&this->f_10) & 1) == 0 && (*(Obj_296060 * *)&this->f_18) != 0 && !(*(Obj_296060 * *)&this->f_18)->h())
        return false;
    return true;
}
