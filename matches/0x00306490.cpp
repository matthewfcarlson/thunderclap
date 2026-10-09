class Res2 {
  public:
    void Set(void* a, int b);
};

class Mgr {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Res2* Get(int id);
};

class Own {
  public:
    char pad[0x18];
    Mgr* mMgr;
    char pad2[0x6b - 0x1c];
    char mFlag;
};

class Sub {
  public:
    void Update();
};

class Vec {
  public:
    Sub** mBegin;
    Sub** mEnd;
};

class Cls {
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
    Own* mOwn;
    Vec* mVec;
    char pad3;
    char mDone;
    char pad4[2];
    char mBuf[4];
    void Run();
};

void Cls::Run() {
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
