struct Mat_1d7810 {
    float m[12];
    float x, y, z, w;
};
struct O_1d7810 {
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
    virtual Mat_1d7810* GetMat();
    char pad[0x154 - 0x40 + 0x40];
    float px, py, pz;
    void Fn(float x, float y, float z);
    void Apply(Mat_1d7810 m, int f);
};
void O_1d7810::Fn(float x, float y, float z) {
    Mat_1d7810 m = *GetMat();
    m.x = x;
    m.y = y;
    m.z = z;
    Apply(m, 0);
    px = x;
    py = y;
    pz = z;
}
