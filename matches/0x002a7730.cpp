class SceneGraphTransformAnimationController {
public:
    char pad[0x110];
    int value;
    void First();
    void Second(int);
    SceneGraphTransformAnimationController* Init();
};
extern void* gVftable;
SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::Init() {
    First();
    *(void**)this = &gVftable;
    value = 0;
    Second(1);
    return this;
}