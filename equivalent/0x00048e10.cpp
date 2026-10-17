// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// CCollisionFlagCondition::vfunc_7 @ 0x00048e10
struct CollisionFlags { int name; int flags; };
struct CollisionContext {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual CollisionFlags* vfunc_3();
};
struct CCollisionFlagCondition {
    void* vtable;
    char pad[8];
    int mode;
    int name;
    int flags;
    unsigned int vfunc_7(CollisionContext* context);
};
unsigned int CCollisionFlagCondition::vfunc_7(CollisionContext* context) {
    CollisionFlags* collision = context->vfunc_3();
    if (!collision || (mode != 0 && mode != 1)) return (unsigned int)collision & ~255u;
    if (mode == 0) return collision->name == name && collision->flags == flags;
    return collision->name != name || collision->flags != flags;
}