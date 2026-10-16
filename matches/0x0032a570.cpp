#include "gen/pure3d.h"

namespace pure3d {
} // namespace pure3d
static const char s_empty[] = "";
static const char s_multi[] = "simple_multicbv";
static const char s_prox[] = "simple_proximity";
void* pure3d::d3dSimpleShader::vfunc_23() {
    if (!(*(bool *)&this->f_48) && (*(bool *)&this->f_84))
        return (void*)(s_multi);
    if (!(*(bool *)&this->f_48) && (*(bool *)&this->f_8c))
        return (void*)(s_prox);
    return (void*)(s_empty);
}
