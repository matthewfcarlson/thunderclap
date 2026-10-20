#include "compat/ptr.h"
extern int vftable_327030;
class pddiPrimBuffer {
  public:
    void Init();
    pddiPrimBuffer();
};
pddiPrimBuffer::pddiPrimBuffer() {
    Init();
    *(hulk_intptr*)this = (hulk_intptr)&vftable_327030;
}