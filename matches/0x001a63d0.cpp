class EffectAction {
  public:
    char pad[0x24];
    int a;
    void* b;
    void vfunc_4();
};
struct Helper_1a63d0 {
    void apply(int);
};
Helper_1a63d0* FUN_0027f250();
void FUN_0027ffb0(int);
class Ref_1a63d0 {
  public:
    virtual void f0();
    virtual void f1();
};
void EffectAction::vfunc_4() {
    Helper_1a63d0* x = FUN_0027f250();
    x->apply(a);
    if (b) {
        ((Ref_1a63d0*)b)->f1();
        b = 0;
    }
}