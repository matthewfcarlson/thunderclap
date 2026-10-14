typedef unsigned int u32_305170;
namespace physics {
class CollisionObject {
  public:
    char pad[0x20];
    int m;
    void vfunc_6(u32_305170 a, u32_305170 b);
};
} // namespace physics
extern void __stdcall FUN_00304bd0(u32_305170, u32_305170, u32_305170);
void physics::CollisionObject::vfunc_6(u32_305170 a, u32_305170 b) {
    FUN_00304bd0(m, a, b);
}