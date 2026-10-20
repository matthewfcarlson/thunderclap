#include "compat/ptr.h"
class Image {
  public:
    virtual void V0();
    char pad04[0x20];
    int m24;
    virtual ~Image();
    void Finish();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
Image::~Image() {
    thunk_FUN_00267090(m24);
    Finish();
}