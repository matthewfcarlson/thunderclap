#include "compat/ptr.h"
extern int vftable_2a3e80;
class RenderObjectLoader {
  public:
    int pad;
    int mValue;
    RenderObjectLoader();
};
RenderObjectLoader::RenderObjectLoader() {
    mValue = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vftable_2a3e80;
}