#include "gen/pure3d.h"

namespace pure3d {
extern const float ratio1;
extern const float ratio2;

} // namespace pure3d
float pure3d::d3dDisplay::vfunc_16() {
    if (this->f_437)
        return ratio2;
    return ratio1;
}
