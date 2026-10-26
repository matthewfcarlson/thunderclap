#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct TypeDesc_123450 {
    int a;
    int b;
};
extern int TypeCheck(void*, int, const void*, const void*, int);
extern void* Alloc(hulk_uintptr);
struct NewTrack {
    int run(hulkfight::ai::PathTrack* t, void* p);
};
extern TypeDesc_123450 typeA_123450;
extern TypeDesc_123450 typeB_123450;

hulk_intptr hulkfight::ai::PathTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { void * p = (void *)__p2;

    if (TypeCheck(p, 0, &typeA_123450, &typeB_123450, 0)) {
        NewTrack* q = (NewTrack*)Alloc(0xf0);
        if (q)
            return q->run(this, p);
    }
    return 0;
}
