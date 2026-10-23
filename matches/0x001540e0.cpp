#include "gen/fight.h"

struct Data {
    int x;
};
extern Data a, b;
extern int __cdecl check(void*, int, Data*, Data*, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &a, &b, 0) != 0;
}
