class Inner_23ec00 {
  public:
    void f();
};
class SpawnAction {
    char pad[0x24];
    Inner_23ec00 inner;

  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
};
void SpawnAction::vfunc_4() {
    inner.f();
}
