#include "gen/global.h"

class CSoundSystem_1f1ec0 {
  public:
    void Play(char*, char*, float, float, float, float);
};

template <> void Closure6<CSoundSystem, void, char *, char *, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void ** a = (void **)__p1;

    char* x = (char*)*a++;
    char* y = (char*)*a++;
    float z = *(float*)a++;
    float w = *(float*)a++;
    float v = *(float*)a++;
    float u = *(float*)a++;
    ((*(CSoundSystem_1f1ec0 * *)&this->f_20)->*(*(void (CSoundSystem_1f1ec0::**)(char *, char *, float, float, float, float))&this->f_1c))(x, y, z, w, v, u);
}
