#include "gen/hulkfight.h"
#include "gen/owners.h"

extern char RTTI_CFightParams_1479f0;
extern char RTTI_FightParams;
extern int __cdecl check(void*, int, char*, char*, int);

class Helper_1479f0 {
  public:
    void* getB();
};

bool hulkfight::motion::GrappleAttachedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * p2 = (void *)__p1;

    if (!check(p2, 0, &RTTI_FightParams, &RTTI_CFightParams_1479f0, 0))
        return false;
    void* a = ((void *)((owners::Object_592a0 *)(((Helper_1479f0*)p2)))->FUN_000592a0());
    void* b = ((Helper_1479f0*)a)->getB();
    int x = *(int*)((char*)b + 0x334);
    bool t = (x != 0);
    return this->f_0c == t;
}
