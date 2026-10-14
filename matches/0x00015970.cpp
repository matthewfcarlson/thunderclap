class Obj_15970 {
  public:
    void Fn(int a, int b, int c, int d, int e, int e2, float f, int g);
    char pad[0x334];
    Obj_15970* mA;
    Obj_15970* mB;
};

class Mid_15970 {
  public:
    char pad[0x10];
    int mVal;
};

class Owner_15970 {
  public:
    Obj_15970* Get();
};

class Mgr_15970 {
  public:
    Obj_15970* Get();
};

Mgr_15970* GetMgr(Owner_15970* o);

class Ctx_15970 {
  public:
    Mgr_15970* Get();
};

class CGrappleDetachAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x1c - 4];
    Ctx_15970* mCtx;
    Mid_15970* mMid;
};

void CGrappleDetachAction::v4() {
    Obj_15970* o = mCtx->Get()->Get();
    Obj_15970* p = o->mA;
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
