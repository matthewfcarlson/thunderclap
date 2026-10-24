class AnimTarget {
    char pad[0x38];

  public:
    int state;
};
class FEAnimation {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(AnimTarget* p);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();

  private:
    char pad[0xc];
    AnimTarget* target;
};
void FEAnimation::vfunc_1(AnimTarget* p) {
    AnimTarget* t = target;
    if (t) {
        if (t->state == 2) {
            t->state = 1;
        }
    }
    target = p;
}