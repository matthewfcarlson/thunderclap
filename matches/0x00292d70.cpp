class Entity_292d70 {
  public:
    virtual void b0();
    Entity_292d70();
};
class Camera : public Entity_292d70 {
  public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void hulk_slot_vfunc_5(float, float) = 0; void vfunc_5(float, float);
    char p0[0x18];
    float a;
    float b;
    char p1[0x28];
    struct Sub {
        char x[0x40];
        void init();
    } sub1, sub2;
    unsigned char flag;
    Camera();
};
Camera::Camera() : Entity_292d70() {
    vfunc_5(1.5707964f, 1.0f);
    a = 1.0f;
    b = 1000.0f;
    sub1.init();
    sub2.init();
    flag = 1;
}
