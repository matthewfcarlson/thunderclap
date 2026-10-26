#include "compat/ptr.h"
#include "gen/global.h"

class CSoundSystem_1f1fe0;
typedef void (CSoundSystem_1f1fe0::*SoundMethod)(char*, char*, float, float, float);
class CSoundSystem_1f1fe0 {
  public:
    void dummy();
};

template <> void Closure5<CSoundSystem, void, char *, char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * args = (unsigned int *)__p1;

    char* first = (char*)*(hulk_uintptr*)args;
    char* second = (char*)*++args;
    float third = *(float*)++args;
    float fourth = *(float*)++args;
    float fifth = *(float*)++args;
    ((*(CSoundSystem_1f1fe0 * *)&this->f_20)->*(*(SoundMethod *)&this->f_1c))(first, second, third, fourth, fifth);
}
