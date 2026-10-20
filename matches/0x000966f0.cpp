#include "compat/ptr.h"
extern "C" hulk_intptr Alloc(hulk_intptr);
class Inner_966f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Send(int, int);
};
class Obj_966f0 {
  public:
    virtual void v0();
    Obj_966f0* Init();
    char pad[12];
    Inner_966f0* inner;
};
extern "C" unsigned char gEnabled_966f0;
extern "C" Obj_966f0* gObject_966f0;
void Target() {
    if (gEnabled_966f0 && gObject_966f0 == 0) {
        Obj_966f0* p = (Obj_966f0*)Alloc(0x20);
        if (p)
            p = p->Init();
        else
            p = 0;
        gObject_966f0 = p;
        gObject_966f0->v0();
        gObject_966f0->inner->Send(0x444d4c42, 1);
    }
}
