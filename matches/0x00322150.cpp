extern "C" char DAT_0043276c[];
extern "C" char DAT_00433094[];
class RefCounted_322150 {
  public:
    virtual void f0();
    virtual void Release();
};
class ProjectedTexture {
  public:
    void* vftable;
    RefCounted_322150* items[16];
    void f();
};
void ProjectedTexture::f() {
    vftable = (void*)((int)DAT_00433094);
    for (int i = 0; i < 16; ++i)
        if (items[i])
            items[i]->Release();
    vftable = (void*)((int)DAT_0043276c);
}
