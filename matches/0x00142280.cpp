#include "gen/hulkfight.h"

struct Obj_142280 {
    int Init(hulkfight::motion::WallExitTrack*, int);
};
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);
extern int g1_142280, g2;

int hulkfight::motion::WallExitTrack::vfunc_10(int a, int b, int c) {
    if (IsType((void*)c, 0, &g1_142280, &g2, 0)) {
        Obj_142280* p = (Obj_142280*)Alloc(0x4c);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
