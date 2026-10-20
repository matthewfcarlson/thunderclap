// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188c40 {
  public:
    int x;
};
extern Params_188c40 TypeA_188c40;
extern Params_188c40 TypeB_188c40;
int __cdecl Check(void*, int, Params_188c40*, Params_188c40*, int);
struct PropSpawnAction_nv_188c40 {
    int Init(hulkfight::motion::PropSpawnTrack*, int);
};
hulkfight::motion::PropSpawnAction* __cdecl Alloc(int);

int hulkfight::motion::PropSpawnTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188c40, &TypeB_188c40, 0);
    if (result) {
        hulkfight::motion::PropSpawnAction* p = Alloc(0x24);
        if (p)
            return ((PropSpawnAction_nv_188c40*)(p))->Init(this, c);
    }
    return 0;
}
