#include "gen/pure3d.h"

namespace pure3d {
struct Inner_31e0f0 {
    char pad[0x14];
    int value;
};

} // namespace pure3d
int pure3d::pddiBaseContext::vfunc_77() {
    return (*(Inner_31e0f0 * *)&this->f_4c)->value;
}
