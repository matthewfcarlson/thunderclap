#include "gen/hulkfight.h"

class Effect_144cd0 {
  public:
    int init(int, hulkfight::motion::HitEffectTrack*, int);
};
extern int check(void*, int, const void*, const void*, int);
extern void* alloc(unsigned int);
extern const char type1_144cd0[];
extern const char type2_144cd0[];

int hulkfight::motion::HitEffectTrack::vfunc_10(int a, int b, int c) {
    if (check((void*)c, 0, type1_144cd0, type2_144cd0, 0)) {
        Effect_144cd0* p = (Effect_144cd0*)alloc(0x28);
        if (p)
            return p->init(a, this, c);
    }
    return 0;
}
