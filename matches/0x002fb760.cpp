extern "C" void _ReadWriteBarrier();
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(float p);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};
class CollisionOBB : public CollisionVolume {
  public:
    virtual void vfunc_7(float p);
    char pad[0x48 - 4];
    float x, y, z;
    char pad2[0x88 - 0x54];
    float sx, sy, sz;
};
void CollisionOBB::vfunc_7(float p) {
    x = p * sx;
    y = p * sy;
    z = p * sz;
    _ReadWriteBarrier();
    this->v9();
    CollisionVolume::vfunc_7(p);
}