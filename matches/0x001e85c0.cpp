#include "compat/ptr.h"
extern int v_1e85c0[];
class Stream {
  public:
    void Init();
};
void Stream::Init() {
    *(hulk_intptr*)this = (hulk_intptr)v_1e85c0;
}
