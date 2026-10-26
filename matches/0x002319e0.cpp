#include "compat/ptr.h"
#include "gen/fight.h"

struct Node_nv_2319e0 {
    char helper(unsigned int, unsigned int);
};

hulk_uintptr fight::Node::vfunc_8(hulk_uintptr a, unsigned int b) {
    if (((Node_nv_2319e0*)this)->helper(a, b))
        return (hulk_uintptr)this;
    return 0;
}
