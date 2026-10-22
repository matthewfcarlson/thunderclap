class SimpleFrameController_2a9cb0 {
  public:
    virtual void f();
    char pad[0x3c];
    SimpleFrameController_2a9cb0();
};
class ExpressionAnimationController : public SimpleFrameController_2a9cb0 {
  public:
    int a, b, c, d;
    virtual void g();
    ExpressionAnimationController();
};
ExpressionAnimationController::ExpressionAnimationController() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}
