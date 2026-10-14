struct Vec_309aa0 {
    char p[4];
    float a;
    char q[8];
    float b;
    char r[4];
    float c;
    void apply(float);
};
class PJ_309aa0;
struct Manager_309aa0 {
    char p[0x218];
    PJ_309aa0* joint;
};
class PJ_309aa0 {
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
    virtual void v13(void* x, Vec_309aa0* y);
    char flag;
    char pad5[0x18 - 5];
    Manager_309aa0* mgr;
    PJ_309aa0* other;
    char q[0xe8 - 0x20];
    float limit;
    char r[4];
    float force;
};
void PJ_309aa0::v13(void* x, Vec_309aa0* y) {
    if (this == mgr->joint)
        return;
    if (other)
        other->v13(x, y);
    if (limit > 1e-5f && flag) {
        y->apply(1.0f - limit);
        float t = force * limit;
        y->a += t;
        y->b += t;
        y->c += t;
    }
}
