extern int gId_26e2a0;
void Hook();
void PoolInit(void* pool, int a, int b, int c, int d, const char* name, int e);

class IRefCount {
  public:
    IRefCount();
    virtual void f0();
};

class Obj_26e2a0 {
  public:
    Obj_26e2a0();
    virtual void g0();
    int mId;
};

class RefC : public Obj_26e2a0 {
  public:
    RefC();
    virtual void g1();
    int mRef;
};

class ConsoleClient : public IRefCount, public RefC {
  public:
    ConsoleClient(int a, int b);
    virtual void f1();
    char pad[0xb0];
    int m0;
    int mPool;
    int m1;
    char pad2[0x108];
    int m2;
};

IRefCount::IRefCount() {}
void IRefCount::f0() {}
Obj_26e2a0::Obj_26e2a0() {
    mId = gId_26e2a0;
    Hook();
}
void Obj_26e2a0::g0() {}
RefC::RefC() {
    mRef = 1;
    Hook();
}
void RefC::g1() {}
void ConsoleClient::f1() {}

ConsoleClient::ConsoleClient(int a, int b) {
    m0 = 0;
    mPool = 0;
    m1 = 0;
    m2 = 0;
    PoolInit(&mPool, 0x110, 0x80, 1, a, "ConsoleClient::mInitContentTxBufferPool", 4);
    Hook();
}
