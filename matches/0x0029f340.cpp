#include "compat/ptr.h"
#include "gen/owners.h"
class Item_29f340 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void q();
    virtual void f();
    virtual void g();
};
struct Arr_29f340 {
    char x[16];
    int count;
    char y[4];
    Item_29f340** items;
};
struct Context {
    void process(int, Item_29f340*);
};
struct Obj_29f340 {
    char x[8];
    Arr_29f340* arr;
    Context* ctx;
    char y[4];
    int n;
    hulk_intptr run();
};
hulk_intptr Obj_29f340::run() {
    ((owners::A_2a1180 *)ctx)->FUN_002a1180(n);
    int i = 0;
    if (n > 0)
        do {
            Item_29f340* p;
            if (i < arr->count)
                p = arr->items[i];
            else
                p = 0;
            p->f();
            ctx->process(i, p);
            ++i;
        } while (i < n);
    return (hulk_intptr)ctx;
}