#include "gen/pure3d.h"

class Item_296740 {
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
    virtual void k(int, int, int, int);
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o(void*);
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
};

void pure3d::scenegraph::BranchNode::vfunc_18(void* __p0) { Item_296740 * item = (Item_296740 *)__p0;

    if (item) {
        Item_296740** slot = (*(Item_296740 ** *)&this->f_1c) + (*(int *)&this->f_18);
        item->a();
        Item_296740* old = *slot;
        if (old)
            old->b();
        *slot = item;
        ++(*(int *)&this->f_18);
        item->o(this);
        item->k(1, 2, 1, 1);
        item->k(1, 6, 2, 1);
    }
}
