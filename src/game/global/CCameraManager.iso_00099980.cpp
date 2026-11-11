// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)


// 0x00099980 FUN_00099980 (35 B): matches/0x00099980.cpp [isolated: compile error C2039: 'x' : is not a member of 'fn_f5ef2b3f::Sub']
// sym: ?Set@Target@fn_fdb5f040@@QAEXHH@Z
namespace fn_fdb5f040 {} using namespace fn_fdb5f040;
namespace fn_fdb5f040 {
class Target {
  public:
    char pad[0xc4];
    struct Sub* m;
    void Set(int a, int b);
};
struct Sub {
    char pad[0x258];
    int x;
    int y;
};
void Target::Set(int a, int b) {
    m->x = a;
    m->y = b;
}
} // namespace fn_fdb5f040

