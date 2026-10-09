extern int Image_vftable[];
class Image {
  public:
    int pad[8];
    int m24;
    virtual void F();
    void Fn();
    void Next();
};
extern void __cdecl thunk_FUN_00267090(int);
void Image::Fn() {
    int x = m24;
    *(int*)this = (int)Image_vftable;
    thunk_FUN_00267090(x);
    Next();
}