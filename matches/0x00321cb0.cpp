namespace pure3d {
class pddiBaseContext {
  public:
    virtual void f();
    void vfunc_78(unsigned int);
};
class d3dContext : public pddiBaseContext {
  public:
    void vfunc_78(unsigned int);
};
} // namespace pure3d
extern unsigned int gFlags;
extern unsigned int gFog;
void pure3d::d3dContext::vfunc_78(unsigned int x) {
    pddiBaseContext::vfunc_78(x);
    gFlags |= 0x2000;
    gFog = (unsigned char)x;
}