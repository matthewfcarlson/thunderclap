#include "gen/fight.h"

class Sub_233390 {
  public:
    void helper(fight::Branch*);
};
class Node_233390 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    Node_233390* next;
};

void fight::Branch::vfunc_5() {
    ((Sub_233390*)((char*)this + 0x18))->helper(this);
    for (Node_233390* p = (*(Node_233390 * *)&this->f_1c); p; p = p->next)
        p->f5();
}
