#include "compat/ptr.h"
extern int vftable_2a3e80;
class RenderObjectLoader {
  public:
    hulk_intptr pad;
    int mValue;
    RenderObjectLoader();
};
RenderObjectLoader::RenderObjectLoader() {
    mValue = 0;
    this->pad = (hulk_intptr)&vftable_2a3e80;
}