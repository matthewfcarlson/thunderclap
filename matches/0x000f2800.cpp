#include "gen/global.h"
extern void* __cdecl Alloc(unsigned int);
struct FEParticleAnimation_nv_f2800 {
    int Build(int, int, int);
};
class Thing_f2800 {
  public:
    int value;
    int ref;
    volatile int slots[32];
    int Run(int, int);
};
int Thing_f2800::Run(int a, int b) {
    if (ref == 0)
        return 0;
    FEParticleAnimation* p = (FEParticleAnimation*)Alloc(0x68);
    int result;
    if (p != 0)
        result = ((FEParticleAnimation_nv_f2800*)(p))->Build(ref, a, b);
    else
        result = 0;
    int i = 0;
    while (i < 32) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
        ++i;
    }
    return result;
}