// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_113440 {
  public:
    int x;
};
extern Params_113440 TypeA_113440;
extern Params_113440 TypeB_113440;
int __cdecl Check(void*, int, Params_113440*, Params_113440*, int);
class Object_113440 {
  public:
    int Init(hulkfight::ai::SemaphoreClearTrack*, hulk_intptr);
};
Object_113440* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::SemaphoreClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_113440, &TypeB_113440, 0);
    if (result) {
        Object_113440* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
