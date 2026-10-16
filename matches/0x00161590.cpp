// Same code shape as 0x00161500 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct Result_161590 {
    int Init(hulkfight::motion::LocomotionSteerTrack*, int);
};
extern Result_161590* Alloc(unsigned int);

int hulkfight::motion::LocomotionSteerTrack::vfunc_10(int a, int b, int c) {
    Result_161590* p = Alloc(0x30);
    if (p)
        return p->Init(this, c);
    return 0;
}
