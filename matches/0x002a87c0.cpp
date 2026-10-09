class Base {
  public:
    virtual void Fn();
    Base();
};
class LightAnimationController : public Base {
  public:
    char pad[0x10c];
    int a;
    int b;
    LightAnimationController();
};
LightAnimationController::LightAnimationController() {
    a = -1;
    b = 0;
}