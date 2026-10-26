#include "compat/ptr.h"
#include "gen/om.h"

template <> void om::MetaTypeAttribScalar<int>::vfunc_3(hulk_intptr p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}
