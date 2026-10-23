#include "gen/global.h"

typedef unsigned int uint_efe20;
extern void* __cdecl FUN_0008d690(uint_efe20);
class TextTable_efe20 {
  public:
    uint_efe20 run(uint_efe20);
};

int FEThingsBase::vfunc_54(int __p0) { uint_efe20 a = (uint_efe20)__p0;

    TextTable_efe20* p = (TextTable_efe20*)FUN_0008d690(0x4990);
    if (p)
        return (int)(p->run(a));
    return (int)(0);
}
