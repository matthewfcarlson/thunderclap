#include "decls/data/engine/fight.h"
// data: gCount_2321b0 = DAT_004e5ae8

class Item_2321b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad14[4];
    Item_2321b0* next;
    unsigned int flags;
    void cleanup(int, int);
};
class Obj_2321b0 {
  public:
    Item_2321b0* first;
    char pad04[0x18];
    int value;
    Item_2321b0* list;
    Item_2321b0* extra;
    void run();
};
void Obj_2321b0::run() {
    for (Item_2321b0* i = list; i; i = i->next) {
        bool b = ((i->flags >> 2) & 1) != 0;
        if (b) {
            i->f4();
            --DAT_004e5ae8;
            i->cleanup(8, 1);
        }
    }
    if (extra) {
        extra->f1();
        extra = 0;
    }
    if (list) {
        list->f1();
        list = 0;
    }
    value = 0;
    if (first)
        first->f1();
    first = 0;
}
