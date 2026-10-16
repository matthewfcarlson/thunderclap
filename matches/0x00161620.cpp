#include "gen/hulkfight.h"

class Result_161620 {
  public:
    int Build(hulkfight::motion::GrappleLocomotionSteerTrack*, int);
};
extern int __cdecl Get(int);
extern void* __cdecl Allocate(unsigned int);

int hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_10(int a, int b, int c) {
    int value = Get(c);
    if (value) {
        Result_161620* p = (Result_161620*)Allocate(0x30);
        if (p)
            return p->Build(this, value);
    }
    return 0;
}
