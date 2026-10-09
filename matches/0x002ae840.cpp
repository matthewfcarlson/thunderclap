extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

namespace pure3d {
class TextureBuilder {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(const void* src, unsigned int n);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    int mEnabled;
    char pad[0xc];
    void* mDest;
};
} // namespace pure3d

void pure3d::TextureBuilder::vfunc_3(const void* src, unsigned int n) {
    if (mEnabled) {
        memcpy(mDest, src, n);
    }
}
