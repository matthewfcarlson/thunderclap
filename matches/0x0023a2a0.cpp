struct Ref_23a2a0 {
    virtual void AddRef();
    virtual void Release();
};
struct Sub_23a2a0 {
    Sub_23a2a0();
    char p[0x28];
};
struct Base_23a2a0 {
    Base_23a2a0();
    virtual void f();
    char pad[0xc];
    int a;
    int b;
    int c;
};
struct QueuedNodeAction : Base_23a2a0 {
    Ref_23a2a0* mNode;
    int mA;
    int mB;
    Ref_23a2a0* mOther;
    Sub_23a2a0 mSub;
    int m54;
    char m58;
    QueuedNodeAction(Ref_23a2a0* n, int a, int b, Ref_23a2a0* o);
    virtual void f();
};
QueuedNodeAction::QueuedNodeAction(Ref_23a2a0* n, int x, int y, Ref_23a2a0* o) : mNode(0), mA(x), mB(y), mOther(0) {
    m54 = 0;
    m58 = 0;
    if (n)
        n->AddRef();
    if (mNode)
        mNode->Release();
    mNode = n;
    if (o)
        o->AddRef();
    if (mOther)
        mOther->Release();
    mOther = o;
    a = 0;
    b = 0xbf800000;
}