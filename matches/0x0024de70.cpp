// Same code shape as 0x0024ddf0 (propagated; names are from that function)
#include "gen/om.h"

template <> void om::MetaTypeAttribScalar<float>::vfunc_3(int p) {
    *(int*)((char*)p + this->f_14) = this->f_24;
}
