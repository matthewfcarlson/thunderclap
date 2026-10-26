// Same code shape as 0x0031e230 (propagated; names are from that function)
#include "gen/pure3d.h"
#include "decls/data/engine/pure3d.h"
// data: g_value_31ed10 = DAT_005554ac

typedef unsigned int u32_31ed10;

void pure3d::_pddiExtMemRegistration::vfunc_1(int __p0) { u32_31ed10 value = (u32_31ed10)__p0;

    (*(u32_31ed10*)&DAT_005554ac) = value;
}
