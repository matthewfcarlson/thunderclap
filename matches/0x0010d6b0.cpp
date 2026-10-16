#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
class P_10d6b0 {
  public:
    void* get();
};
class Q_10d6b0 {
  public:
    void* query();
};
extern int __cdecl FUN_00344e74(void*, int, int, int, int);

bool hulkfight::ai::LeashedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; void * params = (void *)__p1; int unused2 = (int)__p2;

    int ok = FUN_00344e74(params, 0, ((int)DAT_00494b44), ((int)DAT_00494b60), 0);
    if (!ok)
        return false;
    void* a = ((P_10d6b0*)params)->get();
    void* b = ((Q_10d6b0*)a)->query();
    if (!b)
        return false;
    void* c = *(void**)((char*)b + 0x1ca0);
    if (!c)
        return false;
    return *((unsigned char*)c + 0xe8) == this->f_0c;
}
