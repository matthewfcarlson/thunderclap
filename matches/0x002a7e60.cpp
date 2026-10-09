typedef unsigned char byte;
class SceneGraphVisibilityAnimationController {
public:
    virtual void f0(); virtual void f1(); virtual SceneGraphVisibilityAnimationController* f2(byte); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26();
    char pad[0x44-4];
};
extern void* visibilityVtable;
extern void FUN_00285800();
extern void thunk_FUN_00267090(SceneGraphVisibilityAnimationController*);
SceneGraphVisibilityAnimationController* SceneGraphVisibilityAnimationController::f2(byte param) {
    *(void**)this = &visibilityVtable;
    *(int*)((char*)this + 0x44) = 0;
    FUN_00285800();
    if (param & 1) thunk_FUN_00267090(this);
    return this;
}