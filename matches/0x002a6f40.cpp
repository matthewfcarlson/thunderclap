typedef unsigned int u32_2a6f40;
typedef unsigned int Type;
struct R_2a6f40 {
    virtual void f0();
    virtual void f1();
};
extern R_2a6f40* Cast(u32_2a6f40, int, Type*, Type*, int);
extern Type entityType;
extern Type geometryType;
struct VertexAnimController {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(u32_2a6f40);
    char pad[0x40 - 4];
    R_2a6f40* mEntity;
};
void VertexAnimController::vfunc_5(u32_2a6f40 p) {
    R_2a6f40* r = Cast(p, 0, &entityType, &geometryType, 0);
    R_2a6f40* n = *(R_2a6f40**)((char*)r + 0x5c);
    if (n)
        n->f0();
    if (mEntity)
        mEntity->f1();
    mEntity = n;
}
