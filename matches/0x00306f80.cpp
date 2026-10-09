// Same code shape as 0x00306f70 (propagated; names are from that function)
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void* vfunc_16();
    virtual void v17();
    virtual void v18();
};
class CollisionRay : public CollisionVolume {
  public:
    char pad[0x74 - 4];
    virtual void* vfunc_16();
};
void* CollisionRay::vfunc_16() {
    return (char*)this + 0x74;
}