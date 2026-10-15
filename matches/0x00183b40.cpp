class Ref {
  public:
    virtual void f0();
    virtual void release();
};
class Anim {
    char pad[0x40];

  public:
    int state;
    int get();
    void set(int, int, int);
};
namespace hulkfight {
namespace motion {
class PropAnimationAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad[0x20];
    Anim* anim;
    Ref* ref;
};
void PropAnimationAction::vfunc_4() {
    if (anim) {
        if (anim->state == -1 && anim->get() == (int)ref)
            anim->set(0, 0, 0);
        if (ref) {
            ref->release();
            ref = 0;
        }
    }
}
} // namespace motion
} // namespace hulkfight