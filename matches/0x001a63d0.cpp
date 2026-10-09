class EffectAction {
  public:
    char pad[0x24];
    int a;
    void* b;
    void vfunc_4();
};
struct Helper {
    void apply(int);
};
Helper* FUN_0027f250();
void FUN_0027ffb0(int);
class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
void EffectAction::vfunc_4() {
    Helper* x = FUN_0027f250();
    x->apply(a);
    if (b) {
        ((Ref*)b)->f1();
        b = 0;
    }
}