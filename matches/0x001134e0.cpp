#include "gen/hulkfight.h"

extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
extern int RTTI_Type1;
extern int RTTI_Type2;
class AllocObj_1134e0 {
  public:
    int init(hulkfight::ai::KeywordWaitTrack*, int);
};

int hulkfight::ai::KeywordWaitTrack::vfunc_10(int a, int b, int c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_1134e0* p = (AllocObj_1134e0*)FUN_0008d690(0x2c);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
