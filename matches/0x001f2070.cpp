#include "gen/global.h"

class CSoundSystem_1f2070 {
  public:
    void Play(char*, char*, char*, float, float, float);
};

template <> void Closure6<CSoundSystem, void, char *, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * x = (unsigned int *)__p1;

    char* a = (char*)*x++;
    char* b = (char*)*x++;
    char* c = (char*)*x++;
    float d = *(float*)x++;
    float e = *(float*)x++;
    float f = *(float*)x++;
    ((*(CSoundSystem_1f2070 * *)&this->f_20)->*(*(void (CSoundSystem_1f2070::**)(char *, char *, char *, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}
