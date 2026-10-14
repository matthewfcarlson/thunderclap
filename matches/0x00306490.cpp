class Res2 {
  public:
    void Set(void* a, int b);
};

class Mgr_306490 {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Res2* Get(int id);
};

class Own_306490 {
  public:
    char pad[0x18];
    Mgr_306490* mMgr;
    char pad2[0x6b - 0x1c];
    char mFlag;
};

class Sub_306490 {
  public:
    void Update();
};

class Vec_306490 {
  public:
    Sub_306490** mBegin;
    Sub_306490** mEnd;
};

class Cls_306490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int GetKind();
    virtual void v5();
    virtual int GetId();
    int pad1;
    int m8;
    int mC;
    Own_306490* mOwn;
    Vec_306490* mVec;
    char pad3;
    char mDone;
    char pad4[2];
    char mBuf[4];
    void Run();
};

void Cls_306490::Run() {
    if (mOwn) {
        mDone = 0;
        if (GetId() != 1 && !mOwn->mFlag) {
            int id = m8;
            Res2* r = mOwn->mMgr->Get(id);
            r->Set(mBuf, GetKind());
        }
    } else {
        mDone = 1;
    }
    if (mVec) {
        for (unsigned i = 0; i < (unsigned)(mVec->mEnd - mVec->mBegin); i++) {
            mVec->mBegin[i]->Update();
        }
    }
}
