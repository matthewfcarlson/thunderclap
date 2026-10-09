struct V3 {
    float x, y, z;
};
void __stdcall GetVel(V3* out);
struct D {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Update(float dt);
    char pad[0x89c - 4];
    bool enabled;
    char pad2[0x900 - 0x89d];
    float px, py, pz;
    void Base(float dt);
};
void D::Update(float dt) {
    if (enabled && *(int*)((char*)this + 0x18) == 0) {
        V3 v;
        GetVel(&v);
        v.x *= dt;
        v.y *= dt;
        v.z *= dt;
        px += v.x;
        py += v.y;
        pz += v.z;
    }
    Base(dt);
}
