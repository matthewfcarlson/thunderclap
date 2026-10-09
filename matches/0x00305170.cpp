typedef unsigned int u32;
namespace physics {
class CollisionObject {
  public:
    char pad[0x20];
    int m;
    void vfunc_6(u32 a, u32 b);
};
} // namespace physics
extern void __stdcall FUN_00304bd0(u32, u32, u32);
void physics::CollisionObject::vfunc_6(u32 a, u32 b) {
    FUN_00304bd0(m, a, b);
}