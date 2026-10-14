class PhaseObj {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_13b040 {
  public:
    void* get();
    void* next();
    void act(void*, int);
};
class AnimationPhaseMatchedAction {
  public:
    char pad[0x20];
    void* source;
    void* a;
    void vfunc_4();
};
void AnimationPhaseMatchedAction::vfunc_4() {
    if (a) {
        void* x = ((Helper_13b040*)source)->get();
        x = ((Helper_13b040*)x)->next();
        if (x) {
            ((Helper_13b040*)x)->act(a, 0);
            if (a) {
                ((PhaseObj*)a)->f1();
                a = 0;
            }
        }
    }
}