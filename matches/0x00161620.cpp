#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Result_161620 {
  public:
    int Build(hulkfight::motion::GrappleLocomotionSteerTrack*, int);
};
extern "C" int __cdecl FUN_0005a470(int);
extern void* __cdecl Allocate(unsigned int);

hulk_intptr hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int value = FUN_0005a470(c);
    if (value) {
        Result_161620* p = (Result_161620*)Allocate(0x30);
        if (p)
            return p->Build(this, value);
    }
    return 0;
}
