// Same code shape as 0x002226e0 (propagated; names are from that function)
#include "gen/core.h"

class Inner_2777b0 {
  public:
    void call();
};

void core::CementLibrary::vfunc_1() {
    ((Inner_2777b0*)((char*)this + 0x10))->call();
}
