class Obj {
  public:
    virtual void First();
    virtual void Release();
};
class TextureFont {
    char pad[0x28];
    Obj* mObj;

  public:
    void vfunc_17(Obj* p);
};
void TextureFont::vfunc_17(Obj* p) {
    if (p)
        p->First();
    if (mObj)
        mObj->Release();
    mObj = p;
}