#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
void pure3d::MultiController::vfunc_18(int value) {
    if (this->f_38 != value) {
        this->f_38 = value;
        this->f_34 = vfunc_20();
        int r;
        if (this->f_3c == 3 || this->f_3c == 5)
            r = 0;
        else
            r = 1;
        this->f_40 = (char)r;
    }
}
