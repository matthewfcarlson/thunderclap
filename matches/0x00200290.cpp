#include "gen/global.h"

class CTriggerVolumeManager_200290 {
  public:
    bool Fire(const char*, int, int, bool);
};
struct Args {
    const char* a;
    int b, c;
    bool d;
};

template <> void Closure4<CTriggerVolumeManager, bool, const char *, int, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { int n = (int)__p0; Args * args = (Args *)__p1; bool * out = (bool *)__p2;

    CTriggerVolumeManager_200290* o = (*(CTriggerVolumeManager_200290 * *)&this->f_20);
    bool (CTriggerVolumeManager_200290::*fn)(const char*, int, int, bool) = (*(bool (CTriggerVolumeManager_200290::**)(const char *, int, int, bool))&this->f_1c);
    char* p = (char*)args;
    const char* a = *(const char**)p;
    int b = *(int*)(p += 4);
    int c = *(int*)(p += 4);
    bool d = *(bool*)(p += 4);
    bool r = (o->*fn)(a, b, c, d);
    if (out)
        *out = r;
}
