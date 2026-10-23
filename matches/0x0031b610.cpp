#include "gen/pure3d.h"

namespace pure3d {
struct DisplayRect {
    int x;
    int y;
    int height;
    int width;
};
struct d3dDisplay_nv_31b610 {
    void FUN_0031b230(int, int, DisplayRect*, int);
};
} // namespace pure3d
void pure3d::d3dDisplay::vfunc_15(int a, int b) {
    DisplayRect rect;
    rect.y = 0;
    rect.x = 0;
    rect.width = this->f_478;
    rect.height = (*(int *)&this->f_47c);
    ((d3dDisplay_nv_31b610*)this)->FUN_0031b230(a, b, &rect, 0);
}
