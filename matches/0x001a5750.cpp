extern const float gScale;
class Animation {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Play(float, int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual char Ready();
};
class NISAnimationAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual char vfunc_5(float, float);
    char pad[0x20];
    Animation* first;
    char pad2[0x1e8];
    Animation* second;
    void F1();
    void F2(float);
    char F3();
};
char NISAnimationAction::vfunc_5(float unused, float dt) {
    if (first && !first->Ready()) {
        first->Play(dt * 1000.0f, 1);
        F1();
    }
    if (second)
        second->Play(dt * 1000.0f, 1);
    F2(dt);
    return !F3();
}