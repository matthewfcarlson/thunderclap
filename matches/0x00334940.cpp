// Same code shape as 0x0029c3b0 (propagated; names are from that function)
#include "decls/data/platform/xbox/movie.h"
// data: gThing_334940 = DAT_00555ba8

class Thing_334940 {
  public:
    virtual void F(int);
};
void FUN_00334940() {
    if ((*(Thing_334940**)&DAT_00555ba8))
        (*(Thing_334940**)&DAT_00555ba8)->F(1);
    (*(Thing_334940**)&DAT_00555ba8) = 0;
}