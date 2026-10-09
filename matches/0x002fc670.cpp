class Sub2 {
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

class Sub3 {
  public:
    void Fn(int);
};

class Sub1 {
  public:
    void Set(int);
    char pad[0x70];
    Sub2* a;
    Sub3* b;
};

class Obj {
  public:
    char Change(int s);
    char pad[8];
    int mState;
    int pad2;
    Sub1* mSub;
};

char Obj::Change(int s) {
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
