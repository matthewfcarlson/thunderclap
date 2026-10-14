struct Mat_292df0 {
    float m[16];
    void Init();
};
struct Src_292df0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float F8();
    virtual void v9();
    virtual float F10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Mat_292df0* GetMat();
    int pad[3];
    int a, b;
};
struct Base_292df0 {
    Base_292df0(Src_292df0* s);
    virtual void bv();
    int pad[6];
};
struct Camera : Base_292df0 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Set(int a, int b);
    Camera(Src_292df0* s);
    float f1c, f20;
    char p[0x28];
    Mat_292df0 m4c, m8c;
    char flag;
};
Camera::Camera(Src_292df0* s) : Base_292df0(s) {
    Set(s->a, s->b);
    f1c = s->F8();
    f20 = s->F10();
    m4c.Init();
    m8c.Init();
    m8c = *s->GetMat();
    m4c.Init();
    flag = 0;
}
