extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
namespace pure3d {
class Image32 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
    virtual void vfunc_6(int w, int h, const void* src);
    char pad[0x20];
    void* pixels;
};
void Image32::vfunc_6(int w, int h, const void* src) {
    v5(w, h);
    memcpy(pixels, src, w * h * 4);
}
} // namespace pure3d