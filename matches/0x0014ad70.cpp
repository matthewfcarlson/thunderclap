#include "gen/hulkfight.h"

class Obj_14ad70 {
  public:
    int Init(hulkfight::motion::GrappleThrowTrack*, int);
};
extern int __cdecl GetThing(int);
extern void* __cdecl Alloc(int);

int hulkfight::motion::GrappleThrowTrack::vfunc_10(int a, int b, int c) {
    int x = GetThing(c);
    if (x) {
        Obj_14ad70* p = (Obj_14ad70*)Alloc(0x54);
        if (p)
            return p->Init(this, x);
    }
    return 0;
}
