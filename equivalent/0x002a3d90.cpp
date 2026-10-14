// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a3d90 @ 0x002a3d90
struct Matrix {
    float m[16];
    void FUN_0022b980();
};

namespace pure3d {
class ParticleSystem;
}

class Emitter {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Emitter *Clone();
    virtual void Attach(pure3d::ParticleSystem *owner);
};

namespace pure3d {

class __declspec(novtable) DrawableContainerBase {
public:
    virtual void v0();
    char pad04[0x54];
    void FUN_002a4e40(const ParticleSystem *src);
    DrawableContainerBase(const ParticleSystem *src) { FUN_002a4e40(src); }
};

class ParticleSystem : public DrawableContainerBase {
public:
    virtual void v0();
    unsigned char flag58;
    char pad59[3];
    int f5c;
    int f60;
    Matrix transform;
    Emitter *emitter;
    int fa8;
    ParticleSystem(const ParticleSystem *src);
};

ParticleSystem::ParticleSystem(const ParticleSystem *src) : DrawableContainerBase(src)
{
    flag58 = src->flag58;
    f5c = src->f5c;
    f60 = src->f60;
    emitter = 0;
    fa8 = 0;
    transform.FUN_0022b980();
    if (src->emitter != 0) {
        Emitter *copy = src->emitter->Clone();
        if (copy != 0)
            copy->AddRef();
        if (emitter != 0)
            emitter->Release();
        emitter = copy;
        if (copy != 0)
            copy->Attach(this);
    }
}

}
