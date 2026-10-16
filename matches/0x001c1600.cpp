#include "gen/Render.h"

int Render::Canvas::HulkShaderCallback::vfunc_5(int param) {
    if (this->f_08 > 0.0f && param == 0)
        param = 1;
    return param;
}
