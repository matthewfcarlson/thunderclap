// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fe570 @ 0x002fe570
#include "decls/data/engine/physics.h"

namespace physics {
struct Base {
    virtual void dummy();
    char pad[12];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char active;
    char pad2[3];
    unsigned int type;
    unsigned int id;
    Base();
};
struct SimulatedObject : Base {
    virtual void dummy();
    SimulatedObject(unsigned int value);
};
SimulatedObject::SimulatedObject(unsigned int value) {
    a = 0;
    b = 0;
    d = 0;
    c = value;
    active = 1;
    type = 3;
    id = (*(unsigned int*)&DAT_00555478)++;
}
}