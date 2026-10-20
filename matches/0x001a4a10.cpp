#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_1a4a10;
struct Inner_1a4a10 {
    void run(hulk_uintptr);
};
struct GlobalObj_1a4a10 {
    char pad[0x30];
    Inner_1a4a10* inner;
};
extern GlobalObj_1a4a10* gObj_1a4a10;
namespace hulkfight {
namespace scenario {

} // namespace scenario
} // namespace hulkfight
bool hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_uintptr a = (hulk_uintptr)__p0; hulk_uintptr b = (hulk_uintptr)__p1; hulk_uintptr c = (hulk_uintptr)__p2;

    gObj_1a4a10->inner->run(a);
    return true;
}
