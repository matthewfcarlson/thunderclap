#include "gen/hulkfight.h"

typedef unsigned int u32_1a4a10;
struct Inner_1a4a10 {
    void run(u32_1a4a10);
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
bool hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { u32_1a4a10 a = (u32_1a4a10)__p0; u32_1a4a10 b = (u32_1a4a10)__p1; u32_1a4a10 c = (u32_1a4a10)__p2;

    gObj_1a4a10->inner->run(a);
    return true;
}
