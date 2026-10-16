#include "gen/pure3d.h"

namespace pure3d {
struct S_31d530 {
    char pad[0xc];
    void* value;
};

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_10(void* __p0) { void * value = (void *)__p0;

    (*(S_31d530 * *)&this->f_48)->value = value;
}
