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
struct NodeShouldRunImmediatelyCondition {
    bool vfunc_6(u32_1a4a10 a, u32_1a4a10 b, u32_1a4a10 c);
};
bool NodeShouldRunImmediatelyCondition::vfunc_6(u32_1a4a10 a, u32_1a4a10 b, u32_1a4a10 c) {
    gObj_1a4a10->inner->run(a);
    return true;
}
} // namespace scenario
} // namespace hulkfight
