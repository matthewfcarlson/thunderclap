#include "gen/pure3d.h"

class Item_2826e0 {
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
    virtual void call(int, int);
    virtual bool test();
};
struct Entry_2826e0 {
    Item_2826e0* p;
    char pad[12];
};

void pure3d::prop::CMotionTrailQueue::vfunc_6(int arg, int unused) {
    int i;
    for (i = 0; i < 6; i++) {
        Item_2826e0* p = (*(Entry_2826e0 * *)&this->f_48)[i].p;
        if ((*(char * *)&this->f_5c)[i * 8 + 4] && p) {
            p->call(arg, 0);
            if (p->test())
                (*(char * *)&this->f_5c)[i * 8 + 4] = 0;
        }
    }
}
