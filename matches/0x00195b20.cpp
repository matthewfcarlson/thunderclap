class ProjectileEffect {
  public:
    char pad[0x34];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ProjectileEffect* vfunc_3();
};
ProjectileEffect* ProjectileEffect::vfunc_3() {
    return (ProjectileEffect*)((char*)this + 0x34);
}