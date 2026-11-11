// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f27c0..0x002f2e70 (kind game, layer engine, confidence medium), dominant class physics::PhysicsPropertiesLoader
// (tree_prelude.h: not needed)


// 0x002f2d10 FUN_002f2d10 (258 B): equivalent/0x002f2d10.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_002f2d10@Object@fn_ffa55cb9@@QAEPAU12@XZ @b943d80b32ae @w7c35569d4f24
#include "gen/owners.h"
namespace fn_ffa55cb9 {} using namespace fn_ffa55cb9;
namespace fn_ffa55cb9 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f2d10 @ 0x002f2d10
struct Entry_2f2d10 {
    float x, y, z, w;
    float scale, a, b, c;
};
struct Object {
    Entry_2f2d10 entries[64];
    Object* FUN_002f2d10();
};
Object* Object::FUN_002f2d10() {
    for (int i = 0; i < 64; ++i) {
        entries[i].x = 0.0f;
        entries[i].y = 0.0f;
        entries[i].b = 0.0f;
        entries[i].c = 1.0f;
        entries[i].scale = 1.5f;
        entries[i].a = 0.0f;
        entries[i].z = 0.0f;
        entries[i].w = 1.0f;
    }
    ((owners::Obj_2f2cb0 *)this)->FUN_002f2cb0();
    return this;
}
} // namespace fn_ffa55cb9

