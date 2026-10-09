struct NonCopyable {
    virtual void f0();
    virtual void f1();
};
struct IRefCount {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void destroy(void*);
struct Sub {
    void cleanup();
};
namespace pure3d {
struct ShadowGenerator : NonCopyable {
    char pad[4];
    Sub sub;
    ShadowGenerator* vfunc_2(unsigned char);
};
} // namespace pure3d
pure3d::ShadowGenerator* pure3d::ShadowGenerator::vfunc_2(unsigned char flags) {
    sub.cleanup();
    *(unsigned long*)this = 0x3f6098;
    if (flags & 1)
        destroy(this);
    return this;
}
