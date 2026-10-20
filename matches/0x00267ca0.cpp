#include "compat/ptr.h"
#include "gen/core.h"

class TimerBase {
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
    virtual void vfunc_9();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct List_267ca0 {
    char pad[0x1c];
    unsigned int count;
    int* items;
};

void core::Timer::vfunc_9() {
    if (!this->f_10) {
        this->f_14 = 0;
        this->f_10 = 1;
        List_267ca0* p = (*(List_267ca0 *volatile *)&this->f_20);
        unsigned int n = p->count;
        unsigned int i = 0;
        if (n > 0) {
            int* items = p->items;
            int* cur = items;
            do {
                if (*cur == 0) {
                    items[i] = (hulk_intptr)this;
                    return;
                }
                ++i;
                ++cur;
            } while (i < (*(List_267ca0 *volatile *)&this->f_20)->count);
        }
    }
}
