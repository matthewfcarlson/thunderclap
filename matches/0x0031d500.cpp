#include "gen/pure3d.h"

namespace pure3d {
struct State {
    int a;
    int value;
};

} // namespace pure3d
void* pure3d::pddiBaseContext::vfunc_7(int __p0) { int * out = (int *)__p0;

    *out = (*(State * *)&this->f_48)->value;
    return (void*)(out);
}
