extern "C" char DAT_0042fd84[];
namespace pure3d { class Language {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual Language* vfunc_2(int flag);
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[0x18];
    void* x;
    void* y;
    void* z;
    void finish();
}; }
void release(void*);
void destroy(void*);
pure3d::Language* pure3d::Language::vfunc_2(int flag) {
    *(void**)this = (void*)((int)DAT_0042fd84);
    release(x);
    release(y);
    release(z);
    finish();
    if (flag & 1)
        destroy(this);
    return this;
}
