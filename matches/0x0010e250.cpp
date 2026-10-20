#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
typedef unsigned int u32_10e250;
extern void FUN_00344e74(void*, int, void*, void*, int);

int hulkfight::ai::AIHistoryCountTrack::vfunc_10(int a, int b, int __p2) { void * p = (void *)__p2;

    FUN_00344e74(p, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0);
    return (int)(0);
}
