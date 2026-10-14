class Base_293100 {
  public:
    virtual void AddRef();
    virtual void Release();
};

struct TypeInfo_293100 {};
extern TypeInfo_293100 tiSrc;
extern TypeInfo_293100 tiA;
extern TypeInfo_293100 tiB;

extern "C" void* __cdecl DynCast(void* p, int off, void* src, void* dst, int isRef);

class Holder_293100 {
  public:
    char pad[0x110];
    int mType;
    Base_293100* mObj;
    void Set(Base_293100* p);
};

void Holder_293100::Set(Base_293100* p) {
    if (mObj) {
        mObj->Release();
        mObj = 0;
    }
    mType = -1;
    if (!p)
        return;
    if (DynCast(p, 0, &tiSrc, &tiA, 0)) {
        p->AddRef();
        if (mObj)
            mObj->Release();
        mObj = p;
        int* q = &mType;
        *q = 0;
        return;
    }
    if (DynCast(p, 0, &tiSrc, &tiB, 0)) {
        p->AddRef();
        if (mObj)
            mObj->Release();
        mObj = p;
        int* q = &mType;
        *q = 1;
    }
}
