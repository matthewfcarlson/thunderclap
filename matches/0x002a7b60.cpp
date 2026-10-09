typedef unsigned int u32;
struct SceneGraphTransformAnimationController {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5(void*);
    char pad[0x110 - 4];
    void* field;
};
struct Type {};
extern Type EntityType;
extern Type TransformNodeType;
extern void* __cdecl Cast(void*, int, Type*, Type*, int);
void SceneGraphTransformAnimationController::vfunc_5(void* p) {
    field = Cast(p, 0, &EntityType, &TransformNodeType, 0);
}