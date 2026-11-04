#include "compat/ptr.h"
class RDLObject {
  public:
    hulk_intptr vtable;
    char pad[0x10 - 4];
    int a;
    int b;
    char pad2[0x1f];
    unsigned char c;
    void Initialize();
    RDLObject();
};
extern int vtable_27a890;
RDLObject::RDLObject() {
    Initialize();
    a = 0;
    b = 0;
    c = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtable_27a890;
}
