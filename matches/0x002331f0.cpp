#include "gen/fight.h"

typedef unsigned int u32_2331f0;
struct Node_2331f0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char a[0x10];
    int field14;
    char b[8];
    Node_2331f0* next;
};
struct Helper_2331f0 {
    void go();
};

void fight::Branch::vfunc_7() {
    ((Helper_2331f0*)((char*)this + 0x18))->go();
    Node_2331f0* p = (*(Node_2331f0 * *)&this->f_1c);
    while (p) {
        Node_2331f0* c = p;
        p = c->next;
        c->next = 0;
        c->field14 = 0;
        c->f1();
    }
    (*(Node_2331f0 * *)&this->f_1c) = 0;
}
