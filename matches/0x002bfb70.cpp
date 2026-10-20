#include "compat/ptr.h"
extern int Image_vftable[];
class Image {
  public:
    int pad[8];
    int m24;
    virtual void F();
    void Fn();
    void Next();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
void Image::Fn() {
    int x = m24;
    *(hulk_intptr*)this = (hulk_intptr)Image_vftable;
    thunk_FUN_00267090(x);
    Next();
}