typedef unsigned int u32_32d230;
namespace pure3d {
class d3dShader {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void vfunc_13();
};
extern u32_32d230 gFlags;
extern u32_32d230 gA;
extern u32_32d230 gB;
class d3dPointSpriteShader : public d3dShader {
  public:
    virtual void b14();
    void vfunc_13();
};
} // namespace pure3d
u32_32d230 pure3d::gFlags;
u32_32d230 pure3d::gA;
u32_32d230 pure3d::gB;
void pure3d::d3dPointSpriteShader::vfunc_13() {
    d3dShader::vfunc_13();
    gA = 0;
    gFlags |= 0x900;
    gB = 0;
}