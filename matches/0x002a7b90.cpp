class SceneGraphVisibilityAnimationController {
  public:
    void* vtable;
    char pad[0x3c];
    int a;
    int b;
    void base_ctor();
    void base_init(int);
    void* init();
};
void* SceneGraphVisibilityAnimationController::init() {
    base_ctor();
    vtable = (void*)0x42dc24;
    a = 0;
    b = 0;
    base_init(1);
    return this;
}