extern char vtable_symbol[];
class FrameController {
  public:
    virtual void f();
    char pad[12];
    unsigned char value;
    FrameController* reset();
};
class Base_284a70 {
  public:
    void initialize();
};
FrameController* FrameController::reset() {
    ((Base_284a70*)this)->initialize();
    *(void**)this = vtable_symbol;
    value = 0;
    return this;
}