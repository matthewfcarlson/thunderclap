class Entity {
  public:
    virtual ~Entity();
};
class Shader : public Entity {
  public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Ref_2a9640 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Shader2 : public Entity {};
class DrawablePrimitive : public Entity {
  public:
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual Ref_2a9640* GetShader();
};
class ShaderRef_2a9640 : public Ref_2a9640 {};
class ShaderAnimationController {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void SetTarget(Entity* e);
    char pad[0x40 - 4];
    Ref_2a9640* mTarget;
};
void ShaderAnimationController::SetTarget(Entity* e) {
    Ref_2a9640* r;
    DrawablePrimitive* d = dynamic_cast<DrawablePrimitive*>(e);
    if (d)
        r = d->GetShader();
    else
        r = dynamic_cast<Ref_2a9640*>(e);
    if (r)
        r->AddRef();
    if (mTarget)
        mTarget->Release();
    mTarget = r;
}
