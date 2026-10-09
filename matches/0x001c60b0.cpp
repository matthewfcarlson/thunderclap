namespace Render {
class CRenderableCharacter {
public:
    virtual CRenderableCharacter* vfunc_0(unsigned char flag);
    char pad[4];
};
}
struct Sub { void f(); void g(); };
extern "C" Sub* __stdcall FUN_001c3d90(void*);
extern "C" void thunk_FUN_00267090(Render::CRenderableCharacter*);
extern int g_vft;

Render::CRenderableCharacter* Render::CRenderableCharacter::vfunc_0(unsigned char flag) {
    Sub* p = (Sub*)((char*)this + 8);
    *(int*)this = (int)&g_vft;
    Sub* r = FUN_001c3d90(p);
    r->f();
    p->g();
    if (flag & 1) thunk_FUN_00267090(this);
    return this;
}
