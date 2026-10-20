// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1296a0 {
  public:
    int x;
};
extern Params_1296a0 TypeA_1296a0;
extern Params_1296a0 TypeB_1296a0;
int __cdecl Check(void*, int, Params_1296a0*, Params_1296a0*, int);
struct TargetClearAction_nv_1296a0 {
    int Init(hulkfight::ai::TargetClearTrack*, int);
};
hulkfight::ai::TargetClearAction* __cdecl Alloc(int);

int hulkfight::ai::TargetClearTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_1296a0, &TypeB_1296a0, 0);
    if (result) {
        hulkfight::ai::TargetClearAction* p = Alloc(0x24);
        if (p)
            return ((TargetClearAction_nv_1296a0*)(p))->Init(this, c);
    }
    return 0;
}
