class BlendFrameController_2a87c0 {
  public:
    virtual void Fn();
    BlendFrameController_2a87c0();
};
class LightAnimationController : public BlendFrameController_2a87c0 {
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