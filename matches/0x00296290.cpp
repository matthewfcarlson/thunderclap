#include "gen/pure3d.h"

class Visitor_296290 {
  public:
    virtual void a();
    virtual void b();
};
class Item_296290 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int type();
};

bool pure3d::scenegraph::DrawableCounter::vfunc_0(void* __p0) { Visitor_296290 * p = (Visitor_296290 *)__p0;

    if (p && ((Item_296290*)p)->type() == 16)
        ++this->f_04;
    return true;
}
