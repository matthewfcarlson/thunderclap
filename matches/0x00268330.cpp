#include "compat/ptr.h"
extern "C" char hulk_at_003f6094[];
class IRefCount_268330 {
  public:
    void Init();
};
void IRefCount_268330::Init() {
    *(hulk_intptr*)this = ((hulk_intptr)(hulk_at_003f6094 + 0x4));
}
