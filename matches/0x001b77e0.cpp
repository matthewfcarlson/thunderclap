class RC {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Obj3 : public RC {
  public:
    virtual void Fn2();
    virtual void Fn3(RC* a, RC* b);
};

class Res : public RC {};

class Sub {
  public:
    Sub* Init();
};

class Mgr {
  public:
    void Fn();
};

class Target {
  public:
    void Run();
    char pad0[0xc];
    Obj3* mObj;
    char pad1[0x120 - 0x10];
    Mgr* mMgr;
    char pad2[4];
    RC* mSub;
};

void* __cdecl Alloc(int size, int tag);
int __cdecl Push(int a);
RC* __cdecl GetA(int a);
Obj3* __cdecl GetB(int a);

void Target::Run() {
    mMgr->Fn();
    int saved = Push(7);
    void* mem = Alloc(0x10, 7);
    RC* s;
    if (mem)
        s = (RC*)((Sub*)mem)->Init();
    else
        s = 0;
    mSub = s;
    if (s)
        s->AddRef();
    RC* a = GetA(7);
    if (a)
        a->AddRef();
    Obj3* nw = GetB(7);
    Obj3* old = mObj;
    if (old != nw) {
        mObj = nw;
        if (nw)
            nw->AddRef();
        if (old)
            old->Release();
    }
    mObj->Fn3(s, a);
    if (a)
        a->Release();
    if (s)
        s->Release();
    Push(saved);
}
