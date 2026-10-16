// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b290 {
  public:
    int x;
};
extern Params_17b290 TypeA_17b290;
extern Params_17b290 TypeB_17b290;
int __cdecl Check(void*, int, Params_17b290*, Params_17b290*, int);
class Object_17b290 {
  public:
    int Init(hulkfight::motion::IntentionClearTrack*, int);
};
Object_17b290* __cdecl Alloc(int);

int hulkfight::motion::IntentionClearTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17b290, &TypeB_17b290, 0);
    if (result) {
        Object_17b290* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
