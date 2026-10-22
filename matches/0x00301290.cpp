#include "compat/ptr.h"
struct Owner_301290 {
    char pad[0x30];
    int value;
};
extern Owner_301290* g_owner;
extern int vtable_301290;
struct SubCollisionDetector_00313500 {
    SubCollisionDetector_00313500();
};
class CollisionDetector : public SubCollisionDetector_00313500 {
  public:
    char pad[0x40];
    CollisionDetector();
};
CollisionDetector::CollisionDetector() : SubCollisionDetector_00313500() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_301290;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x10) = *(int*)((char*)g_owner + 0x30);
}