class Obj {
  public:
    void Fn(int a, int b, int c, int d, int e, int e2, float f, int g);
    char pad[0x334];
    Obj* mA;
    Obj* mB;
};

class Mid {
  public:
    char pad[0x10];
    int mVal;
};

class Owner {
  public:
    Obj* Get();
};

class Mgr {
  public:
    Obj* Get();
};

Mgr* GetMgr(Owner* o);

class Ctx {
  public:
    Mgr* Get();
};

class CGrappleDetachAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x1c - 4];
    Ctx* mCtx;
    Mid* mMid;
};

void CGrappleDetachAction::v4() {
    Obj* o = mCtx->Get()->Get();
    Obj* p = o->mA;
    if (p) {
        p->Fn(0, -1, 0, 0, 0, 0, 1.0f, mMid->mVal);
        p->mA = 0;
    }
    p = o->mB;
    if (p) {
        p->Fn(0, -1, 0, 0, 0, 0, 1.0f, mMid->mVal);
        p->mA = 0;
    }
    o->Fn(0, -1, 0, 0, 0, 0, 1.0f, mMid->mVal);
    o->mA = 0;
}
