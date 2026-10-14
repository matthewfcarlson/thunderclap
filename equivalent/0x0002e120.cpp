// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CActorManager,math::Vector,math::Vector,float>::vfunc_2 @ 0x0002e120
struct Vector { float x, y, z; };

class CActorManager {
public:
    Vector Call(Vector arg, float scale);
};

struct CallParams {
    Vector arg;           // 0x00
    float scale;          // 0x0c
};

typedef Vector (CActorManager::*VectorMethod)(Vector, float);

class Method2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* owner, CallParams* params, Vector* out);
    char pad04[0x18];
    VectorMethod method;   // 0x1c
};

void Method2::vfunc_2(CActorManager* owner, CallParams* params, Vector* out)
{
    Vector result = (owner->*method)(params->arg, params->scale);
    if (out != 0)
        *out = result;
}
