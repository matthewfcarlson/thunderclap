class Base {
  public:
    virtual void AddRef();
    virtual void Release();
};

struct TypeInfo {};
extern TypeInfo tiSrc;
extern TypeInfo tiA;
extern TypeInfo tiB;

extern "C" void* __cdecl DynCast(void* p, int off, void* src, void* dst, int isRef);

class Holder {
  public:
    char pad[0x110];
    int mType;
    Base* mObj;
    void Set(Base* p);
};

void Holder::Set(Base* p) {
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
