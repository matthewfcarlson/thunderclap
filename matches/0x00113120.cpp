// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_113120 {
  public:
    int x;
};
extern Params_113120 TypeA_113120;
extern Params_113120 TypeB_113120;
int __cdecl Check(void*, int, Params_113120*, Params_113120*, int);
class Object_113120 {
  public:
    int Init(hulkfight::ai::HulkActionTrack*, int);
};
Object_113120* __cdecl Alloc(int);

int hulkfight::ai::HulkActionTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_113120, &TypeB_113120, 0);
    if (result) {
        Object_113120* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
