struct Vec3_a8f70 {
    float x, y, z;
};
struct Mat_a8f70 {
    char pad[0x20];
    Vec3_a8f70 a;
    float padf;
    Vec3_a8f70 b;
};

class CDramaticCamera {
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
    virtual Mat_a8f70* GetMat();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void vfunc_27(Vec3_a8f70* out);
};

void CDramaticCamera::vfunc_27(Vec3_a8f70* out) {
    Vec3_a8f70 d;
    Vec3_a8f70* f = &GetMat()->a;
    d.x = f->x * 10.0f;
    d.y = f->y * 10.0f;
    d.z = f->z * 10.0f;
    Vec3_a8f70* p = &GetMat()->b;
    float z = d.z + p->z;
    float y = d.y + p->y;
    float x = d.x + p->x;
    out->x = x;
    out->y = y;
    out->z = z;
}
