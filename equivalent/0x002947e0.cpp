// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 4/4)
// FUN_002947e0 @ 0x002947e0
struct V3 {
    float x, y, z;
};

struct Matrix4 {
    float m[16];
    void FUN_0022c2b0(const V3 *in, V3 *out);
};

class Frame {
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
    virtual Matrix4 *GetMatrix();
};

class Holder {
public:
    void FUN_002947e0(V3 in, V3 *out);

    char pad0[0x18];
    Frame *frame;
};

void Holder::FUN_002947e0(V3 in, V3 *out) {
    if (frame == 0) {
        return;
    }
    V3 local;
    frame->GetMatrix()->FUN_0022c2b0(&in, &local);
    if (local.z == 0.0f) {
        out->x = 0;
        out->y = 0;
        out->z = 1.0f;
    } else {
        float h = 0.5f / local.z;
        *(unsigned *)&out->z = *(unsigned *)&local.z;  // raw copy, no FPU round trip
        out->x = local.x * h;
        out->y = local.y * h;
    }
}
