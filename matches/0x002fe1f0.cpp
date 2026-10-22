#include "compat/ptr.h"
extern "C" char DAT_00431968[];
class Ref_2fe1f0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Entity_2fe1f0 {
  public:
    void finish();
};
class WorldCollisionObject_2fe1f0 : public Entity_2fe1f0 {
  public:
    char pad[16];
    Ref_2fe1f0* member;
    void run();
};
void WorldCollisionObject_2fe1f0::run() {
    *(void**)this = (void*)((hulk_intptr)DAT_00431968);
    if (member)
        member->f1();
    finish();
}
