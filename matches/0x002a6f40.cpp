typedef unsigned int u32;
typedef unsigned int Type;
struct R {
    virtual void f0();
    virtual void f1();
};
extern R* Cast(u32, int, Type*, Type*, int);
extern Type entityType;
extern Type geometryType;
struct VertexAnimController {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(u32);
    char pad[0x40 - 4];
    R* mEntity;
};
void VertexAnimController::vfunc_5(u32 p) {
    R* r = Cast(p, 0, &entityType, &geometryType, 0);
    R* n = *(R**)((char*)r + 0x5c);
    if (n)
        n->f0();
    if (mEntity)
        mEntity->f1();
    mEntity = n;
}
