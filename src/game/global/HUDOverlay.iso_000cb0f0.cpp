// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ca850..0x000cc7e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)


// 0x000cb0f0 FUN_000cb0f0 (53 B): matches/0x000cb0f0.cpp [isolated: compile error C2661: 'fn_fb3f3f46::Obj::Fn' : no overloaded function takes 3 arguments]
// sym: ?Fn@Target@fn_fa4c16dd@@QAEXHHUVec3@2@@Z
namespace fn_fa4c16dd {} using namespace fn_fa4c16dd;
namespace fn_fa4c16dd {
struct Vec3 {
    float x, y, z;
};
class Target {
  public:
    char pad[0x88];
    class Obj* obj;
    void Fn(int a, int b, Vec3 v);
};
class Obj {
  public:
    void Fn(int a, int b, Vec3 v);
};
void Target::Fn(int a, int b, Vec3 v) {
    if (obj)
        obj->Fn(a, b, v);
}
} // namespace fn_fa4c16dd

