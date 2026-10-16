namespace pure3d {
class pddiBaseContext {
  public:
    virtual void vfunc_70(unsigned);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_70(unsigned);
};
} // namespace pure3d
namespace D3D8 {
void __fastcall D3DDevice_SetRenderState_Simple(unsigned, unsigned);
}
extern unsigned state;
void pure3d::d3dContext::vfunc_70(unsigned x) {
    pddiBaseContext::vfunc_70(x);
    D3D8::D3DDevice_SetRenderState_Simple(0x4036c, x);
    state = x;
}