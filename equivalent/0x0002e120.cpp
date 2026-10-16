// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CActorManager,math::Vector,math::Vector,float>::vfunc_2 @ 0x0002e120
#include "gen/global.h"

struct Vector_2e120 { float x, y, z; };

class CActorManager_2e120 {
public:
    Vector_2e120 Call(Vector_2e120 arg, float scale);
};

struct CallParams {
    Vector_2e120 arg;           // 0x00
    float scale;          // 0x0c
};

typedef Vector_2e120 (CActorManager_2e120::*VectorMethod)(Vector_2e120, float);

template <> void Method2<CActorManager,math::Vector,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e120 * owner = (CActorManager_2e120 *)__p0; CallParams * params = (CallParams *)__p1; Vector_2e120 * out = (Vector_2e120 *)__p2;

    Vector_2e120 result = (owner->*(*(VectorMethod *)&this->f_1c))(params->arg, params->scale);
    if (out != 0)
        *out = result;
}
