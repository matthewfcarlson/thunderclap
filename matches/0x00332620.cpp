class Dev_332620 {
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
    virtual void SetTransform(int s, const float* m);
    virtual void SetState(int s);
};

class Shader {
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
    virtual void f12();
    char pad[0x0c];
    Dev_332620* mDev;
};

void Shader::f12() {
    mDev->SetState(3);
    float m[16];
    m[0] = 0.5f;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0.5f;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1.0f;
    m[11] = 0;
    m[12] = 0.5f;
    m[13] = 0.5f;
    m[14] = 0;
    m[15] = 1.0f;
    mDev->SetTransform(3, m);
}
