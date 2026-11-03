#include "gen/owners.h"
class Inner_246a60 {
  public:
    unsigned int Size();
};
class Outer_246a60 {
  public:
    char pad[0x1c];
    Inner_246a60* inner;
};
extern "C" bool FUN_00246a60(Outer_246a60* self, unsigned int value) {
    unsigned int n = self->inner->Size();
    if (value >= n) {
        ((owners::S_264510 *)(self->inner))->FUN_00264510((unsigned)(value - n));
        return true;
    }
    return false;
}