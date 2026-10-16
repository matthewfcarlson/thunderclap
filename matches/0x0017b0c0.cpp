#include "gen/hulkfight.h"

extern int ParamsRTTI;
extern int CFightParamsRTTI;
extern int TypeCheck(void*, int, int*, int*, int);
extern void* Allocate(int);
class Obj_17b0c0 {
  public:
    int Init(hulkfight::motion::JointTrackerTrack*, void*);
};

int hulkfight::motion::JointTrackerTrack::vfunc_10(int a, int b, int __p2) { void * p = (void *)__p2;

    if (TypeCheck(p, 0, &ParamsRTTI, &CFightParamsRTTI, 0)) {
        void* q = Allocate(0x78);
        if (q)
            return ((Obj_17b0c0*)q)->Init(this, p);
    }
    return 0;
}
