#include "gen/physics.h"

namespace physics {
struct Part_2f55b0 {
    void work(int);
};

} // namespace physics
void physics::PhysicsObject::vfunc_9(int a0) {
    (*(char *)&this->f_1c4) = 1;
    ((Part_2f55b0*)((char*)this + 0x168))->work(a0);
}
