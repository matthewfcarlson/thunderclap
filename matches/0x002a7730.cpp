class SceneGraphTransformAnimationController {
  public:
    char pad[0x110];
    int value;
    void First();
    void Second(int);
    SceneGraphTransformAnimationController* Init();
};
extern void* gVftable_2a7730;
SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::Init() {
    First();
    *(void**)this = &gVftable_2a7730;
    value = 0;
    Second(1);
    return this;
}