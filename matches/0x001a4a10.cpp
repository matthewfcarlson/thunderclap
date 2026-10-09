typedef unsigned int u32;
struct Inner { void run(u32); };
struct GlobalObj { char pad[0x30]; Inner* inner; };
extern GlobalObj* gObj;
namespace hulkfight { namespace scenario {
struct NodeShouldRunImmediatelyCondition {
    bool vfunc_6(u32 a, u32 b, u32 c);
};
bool NodeShouldRunImmediatelyCondition::vfunc_6(u32 a, u32 b, u32 c) {
    gObj->inner->run(a);
    return true;
}
}}
