class CPhysicalController_ae090 {
  public:
    virtual void Init();
    virtual void Release();
    CPhysicalController_ae090* Ctor(int i);
};

class CController_ae090 {
  public:
    char pad[0x10];
    int mCount;
    CPhysicalController_ae090** mItems;
    void Clear();
    void Alloc(int n);
};

extern "C" void* FUN_0008d750(int size, int n);
extern "C" void* FUN_0008d710(int size, int n);

void CController_ae090::Alloc(int n) {
    if (mCount)
        Clear();
    mCount = n;
    mItems = (CPhysicalController_ae090**)FUN_0008d750(n * 4, 4);
    for (int i = 0; i < n; i++) {
        mItems[i] = 0;
        void* mem = FUN_0008d710(0x4b0, 4);
        CPhysicalController_ae090* o;
        if (mem)
            o = ((CPhysicalController_ae090*)mem)->Ctor(i);
        else
            o = 0;
        CPhysicalController_ae090** slot = &mItems[i];
        if (o)
            o->Init();
        if (*slot)
            (*slot)->Release();
        *slot = o;
    }
}
