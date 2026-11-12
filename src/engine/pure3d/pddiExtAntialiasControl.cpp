// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0031ffc0..0x00320100 (kind game, layer engine, confidence medium), dominant class pure3d::pddiExtAntialiasControl
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f5eace43 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5eace43 {} using namespace fn_f5eace43;
namespace fn_f5eace43 { extern "C" char DAT_0043276c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f5eace43 {
struct Color_31ffc0 { float r, g, b, a; };
class Target_320080 {
  public:
    char pad[0x42c];
    void* m;
    void* FUN_00320080();
};
class pddiExtension_3200c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public pddiExtension_3200c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x0031ffc0 FUN_0031ffc0 (105 B): equivalent/0x0031ffc0.cpp
// sym: _FUN_0031ffc0 @a122b9768665 @w8ddd4ac52033
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0031ffc0 @ 0x0031ffc0
// equiv-conv: FUN_0031ffc0 ecx stack
extern "C" void __cdecl FUN_0031ffc0(Color_31ffc0* color, unsigned int packed)
{
    color->r = (float)((packed >> 16) & 255) * 0.0039215688593685626983642578125f;
    color->g = (float)((packed >> 8) & 255) * 0.0039215688593685626983642578125f;
    color->b = (float)(packed & 255) * 0.0039215688593685626983642578125f;
    color->a = (float)(packed >> 24) * 0.0039215688593685626983642578125f;
}


// 0x00320080 FUN_00320080 (7 B): matches/0x00320080.cpp
// sym: ?FUN_00320080@Target_320080@fn_f5eace43@@QAEPAXXZ
void* Target_320080::FUN_00320080() {
    return m;
}


// 0x003200c0 pure3d::pddiExtAntialiasControl::vfunc_0 (31 B): matches/0x003200c0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f5eace43@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0043276c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f5eace43
