struct Vec {
    unsigned x, y, z;
};
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec* v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(CollisionVolume*);
};
class CollisionAABB : public CollisionVolume {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void vfunc_14(CollisionVolume*);
};
void CollisionAABB::vfunc_14(CollisionVolume* param) {
    CollisionVolume::vfunc_14(param);
    Vec* a = v4();
    Vec* b = param->v4();
    b->x = a->x;
    b->y = a->y;
    b->z = a->z;
}