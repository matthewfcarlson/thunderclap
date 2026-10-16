#include "gen/pure3d.h"

class Node_296310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int Type();
    char pad[0x18 - 4];
    Node_296310* child;
};
class Callback_296310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(int);
    virtual void f14();
};
class pure3d_scenegraph_Traversal_Visitor {
  public:
    int pad;
    int callback;
};

bool pure3d::scenegraph::ShaderCallbackVisitor::vfunc_0(void* __p0) { Node_296310 * p = (Node_296310 *)__p0;

    if (p) {
        if (p->Type() == 0x10 && p->child) {
            Callback_296310* c = (Callback_296310*)p->child;
            if (this->f_04)
                c->f13(this->f_04);
            else
                c->f14();
        }
    }
    return true;
}
