class Sub2_2fc670 {
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
    void Fn(int);
};

class Sub3_2fc670 {
  public:
    void Fn(int);
};

class Sub1_2fc670 {
  public:
    void Set(int);
    char pad[0x70];
    Sub2_2fc670* a;
    Sub3_2fc670* b;
};

class Obj_2fc670 {
  public:
    char Change(int s);
    char pad[8];
    int mState;
    int pad2;
    Sub1_2fc670* mSub;
};

char Obj_2fc670::Change(int s) {
    int old = mState;
    if (s == old)
        return 1;
    switch (s) {
    case 0:
        mSub->Set(1);
        mSub->b->Fn(1);
        break;
    case 1:
        if (!mSub->a)
            return 0;
        mSub->Set(1);
        mSub->a->v13();
        break;
    case 2:
        mSub->Set(0);
        break;
    default:
        return 0;
    }
    mState = s;
    return 1;
}
