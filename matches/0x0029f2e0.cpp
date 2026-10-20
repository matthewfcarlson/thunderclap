#include "compat/ptr.h"
class Item_29f2e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class List_29f2e0 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    Item_29f2e0** items;
    void init(int);
    void process(int, Item_29f2e0*);
};
class Obj_29f2e0 {
  public:
    char pad0[4];
    List_29f2e0* data;
    char pad8[4];
    List_29f2e0* list;
    int n;
    int run();
};
int Obj_29f2e0::run() {
    list->init(n);
    int i = 0;
    if (n > 0) {
        do {
            Item_29f2e0* x;
            if (i < data->count)
                x = data->items[i];
            else
                x = 0;
            x->f6();
            list->process(i, x);
            ++i;
        } while (i < n);
    }
    return (hulk_intptr)list;
}