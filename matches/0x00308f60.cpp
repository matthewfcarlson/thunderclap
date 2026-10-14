class PhysicsObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7();
};
struct Owner_308f60 {
    char pad[0xc];
    float scale;
};
struct Elem_308f60 {
    char pad[0x28];
    float a;
    float b;
    char pad2[4];
    void Fn(float);
};
class HairclubPhysicsObject : public PhysicsObject {
  public:
    char pad18[0x18 - sizeof(PhysicsObject)];
    Owner_308f60* p18;
    char pad1f8[0x1f8 - 0x1c];
    Elem_308f60* arr;
    int count;
    virtual void vfunc_7();
};

void HairclubPhysicsObject::vfunc_7() {
    PhysicsObject::vfunc_7();
    for (int i = 0; i < count; i++) {
        float old = arr[i].a;
        arr[i].a = p18->scale * arr[i].b;
        if (old > 0.0f)
            arr[i].Fn(arr[i].a / old);
    }
}
