#include "gen/physics.h"

struct Block_309a40 {
    unsigned int x[16];
};
class Buf_309a40 {
  public:
    void run(void*, void*);
};
struct Node_309a40 {
    char pad[0x10];
    char* base;
};
struct Manager_309a40 {
    char pad[0x220];
    Node_309a40* node;
};

void physics::PhysicsJoint::vfunc_10(int __p0) { void * arg = (void *)__p0;

    char* p = (char*)this;
    *(Block_309a40*)(p + 0xa4) = *(Block_309a40*)arg;
    ((Buf_309a40*)(p + 0xa4))->run(p + 0x8c, p + 0x80);
    Manager_309a40* m = (Manager_309a40*)(*(void * *)&this->f_18);
    char* base = m->node->base;
    ((Buf_309a40*)(p + 0xa4))->run(base + this->f_08 * 0x1c, p + 0x98);
}
