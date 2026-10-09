class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(float);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};
class CollisionSphere : public CollisionVolume {
  public:
    char pad[0x34];
    float radius;
    void vfunc_7(float);
};
void CollisionSphere::vfunc_7(float x) {
    CollisionVolume::v7(x);
    x = x * radius;
    *(float*)((char*)this + 0x34) = x;
    *(float*)((char*)this + 0x28) = x;
    *(float*)((char*)this + 0x2c) = x;
    *(float*)((char*)this + 0x30) = x;
}
