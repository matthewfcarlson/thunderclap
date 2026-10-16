#include "gen/om.h"

template <> void om::MetaTypeAttribScalar<int>::vfunc_3(int p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}
