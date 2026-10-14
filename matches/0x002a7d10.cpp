typedef unsigned char u8;
struct Helper_2a7d10 {
    void Decode(void* a, u8* out);
};
class SceneGraphVisibilityAnimationController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[0x30];
    void* a;
    char pad2[8];
    Helper_2a7d10* b;
    void* c;
    void vfunc_7();
};
void SceneGraphVisibilityAnimationController::vfunc_7() {
    u8 x;
    b->Decode(a, &x);
    *((u8*)c + 0x28) = x;
}