#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_10bd40 {
  public:
    int x;
};
extern Params_10bd40 TypeA_10bd40;
extern Params_10bd40 TypeB_10bd40;
int __cdecl Check(void*, int, Params_10bd40*, Params_10bd40*, int);
class Object_10bd40 {
  public:
    int Init(hulkfight::ai::FaceTargetTrack*, int);
};
Object_10bd40* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::FaceTargetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_10bd40, &TypeB_10bd40, 0);
    if (result) {
        Object_10bd40* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
