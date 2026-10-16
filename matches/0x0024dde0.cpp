// Same code shape as 0x000862b0 (propagated; names are from that function)
#include "gen/om.h"

template <> unsigned int om::MetaTypeAttribScalar<int>::vfunc_5() {
    return *(unsigned int*)((char*)this + 0x2c);
}
