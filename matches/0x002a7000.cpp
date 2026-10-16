#include "gen/pure3d.h"

namespace pure3d {
class AnimationFrameController_2a7000 {
  public:
    float vfunc_20();
};
const float gMaxFloat = 3.402823466e+38F;

} // namespace pure3d
float pure3d::ParticleController::vfunc_20() {
    if (this->f_20 == 0) {
        if (this->f_40 == 1)
            return gMaxFloat;
        return (*(float *)&this->f_30) - (*(float *)&this->f_2c);
    }
    return ((AnimationFrameController_2a7000*)this)->vfunc_20();
}
