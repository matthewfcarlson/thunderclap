struct Mat {
    float m[16];
    void Fn(void* a, void* b);
};
struct Prov;
struct Prov {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual Mat* Get(int id);
};
struct Mid {
    char pad[0x18];
    Prov* prov;
    Mat* Get(int id) { return prov->Get(id); }
};
class CollisionOBB {
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
    virtual void vfunc_13();
    virtual void v14();
    virtual void v15();
    char pad[4];
    int mId;
    char pad1[4];
    Mid* mMid;
    char pad2[5];
    char mFlag;
    char pad3[0x54 - 0x1a];
    char a54[12];
    char a60[12];
    char a6c[12];
    char pad4[0x94 - 0x78];
    char a94[12];
    char aa0[12];
    char aac[12];
};
void CollisionOBB::vfunc_13() {
    mFlag = 1;
    Mat m = *mMid->Get(mId);
    m.Fn(a94, a54);
    m.Fn(aa0, a60);
    m.Fn(aac, a6c);
}
