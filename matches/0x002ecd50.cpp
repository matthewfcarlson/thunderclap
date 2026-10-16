#include "gen/physics.h"

namespace physics {
extern const float one;

} // namespace physics
void physics::SimLength::vfunc_1(float value) {
    *(float*)((char*)this + 8) = value;
    *(float*)((char*)this + 4) = one * value;
}
