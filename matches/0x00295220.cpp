class Obj_295220 {
  public:
    virtual void First();
    virtual void Release();
};
class TextureFont {
    char pad[0x28];
    Obj_295220* mObj;

  public:
    void vfunc_17(Obj_295220* p);
};
void TextureFont::vfunc_17(Obj_295220* p) {
    if (p)
        p->First();
    if (mObj)
        mObj->Release();
    mObj = p;
}