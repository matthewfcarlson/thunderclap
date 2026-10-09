struct Sub {
    void A(int);
    void B();
    void C();
};
struct Obj2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Parent {
    void Done();
};
extern Obj2* g_obj;
extern const float kZero;

class Thing {
  public:
    void Fn();
    void Set(float a, float b);
    char pad0[4];
    Parent* mParent;
    char pad1[0xb4];
    Sub* mSub;
    int mVal;
    char pad2[12];
    float mF;
    float mG;
};

void Thing::Fn() {
    mSub->A(mVal);
    mSub->B();
    mSub->C();
    if (g_obj && mF != kZero) {
        Set(mF, mG);
        g_obj->v2();
    }
    mParent->Done();
}
