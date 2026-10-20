#include "compat/ptr.h"
namespace Render {
class CRenderableCharacter {
  public:
    virtual CRenderableCharacter* vfunc_0(unsigned char flag);
    char pad[4];
};
} // namespace Render
struct Sub_1c60b0 {
    void f(void*);
    void g();
};
Sub_1c60b0* FUN_001c3d90();  // 0-argument singleton getter
extern "C" void thunk_FUN_00267090(Render::CRenderableCharacter*);
extern int g_vft_1c60b0;

Render::CRenderableCharacter* Render::CRenderableCharacter::vfunc_0(unsigned char flag) {
    Sub_1c60b0* p = (Sub_1c60b0*)((char*)this + 8);
    *(hulk_intptr*)this = (hulk_intptr)&g_vft_1c60b0;
    FUN_001c3d90()->f(p);
    p->g();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
