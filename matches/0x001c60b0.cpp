namespace Render {
class CRenderableCharacter {
  public:
    virtual CRenderableCharacter* vfunc_0(unsigned char flag);
    char pad[4];
};
} // namespace Render
struct Sub_1c60b0 {
    void f();
    void g();
};
extern "C" Sub_1c60b0* __stdcall FUN_001c3d90(void*);
extern "C" void thunk_FUN_00267090(Render::CRenderableCharacter*);
extern int g_vft_1c60b0;

Render::CRenderableCharacter* Render::CRenderableCharacter::vfunc_0(unsigned char flag) {
    Sub_1c60b0* p = (Sub_1c60b0*)((char*)this + 8);
    *(int*)this = (int)&g_vft_1c60b0;
    Sub_1c60b0* r = FUN_001c3d90(p);
    r->f();
    p->g();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
