#include "gen/core.h"

typedef unsigned int u32_26f550;
namespace core {
} // namespace core
extern void __stdcall FUN_0020bbc2(u32_26f550);
int core::XboxDrive::vfunc_20(int __p0) { u32_26f550 * p = (u32_26f550 *)__p0;

    FUN_0020bbc2(*p);
    *p = 0xffffffff;
    return (int)(1);
}
