#include "gen/pure3d.h"

class Entity_2a8750 {
  public:
    virtual ~Entity_2a8750();
};
class Shader_2a8750 : public Entity_2a8750 {
  public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Ref_2a8750 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Shader2 : public Entity_2a8750 {};
class DrawablePrimitive_2a8750 : public Entity_2a8750 {
  public:
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual Ref_2a8750* GetShader();
};
class ShaderRef_2a8750 : public Ref_2a8750 {};

void pure3d::ShaderAnimationController::vfunc_5(void* __p0) { Entity_2a8750 * e = (Entity_2a8750 *)__p0;

    Ref_2a8750* r;
    DrawablePrimitive_2a8750* d = dynamic_cast<DrawablePrimitive_2a8750*>(e);
    if (d)
        r = d->GetShader();
    else
        r = dynamic_cast<Ref_2a8750*>(e);
    if (r)
        r->AddRef();
    if ((*(Ref_2a8750 * *)&this->f_40))
        (*(Ref_2a8750 * *)&this->f_40)->Release();
    (*(Ref_2a8750 * *)&this->f_40) = r;
}
