#include "gen/fight.h"

class Node_2333c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[0x1c];
    Node_2333c0* next;
};
struct Helper_2333c0 {
    void f(void*);
};

void fight::Branch::vfunc_6() {
    Node_2333c0* p = (*(Node_2333c0 * *)&this->f_1c);
    while (p) {
        p->f6();
        p = p->next;
    }
    ((Helper_2333c0*)((char*)this + 0x18))->f(this);
}
