// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_10bde0 {
  public:
    int x;
};
extern Params_10bde0 TypeA_10bde0;
extern Params_10bde0 TypeB_10bde0;
int __cdecl Check(void*, int, Params_10bde0*, Params_10bde0*, int);
struct FaceMotionAction_nv_10bde0 {
    int Init(hulkfight::ai::FaceMotionTrack*, int);
};
hulkfight::ai::FaceMotionAction* __cdecl Alloc(int);

int hulkfight::ai::FaceMotionTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_10bde0, &TypeB_10bde0, 0);
    if (result) {
        hulkfight::ai::FaceMotionAction* p = Alloc(0x24);
        if (p)
            return ((FaceMotionAction_nv_10bde0*)(p))->Init(this, c);
    }
    return 0;
}
