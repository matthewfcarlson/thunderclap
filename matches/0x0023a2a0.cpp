struct Ref {
    virtual void AddRef();
    virtual void Release();
};
struct Sub {
    Sub();
    char p[0x28];
};
struct Base {
    Base();
    virtual void f();
    char pad[0xc];
    int a;
    int b;
    int c;
};
struct QueuedNodeAction : Base {
    Ref* mNode;
    int mA;
    int mB;
    Ref* mOther;
    Sub mSub;
    int m54;
    char m58;
    QueuedNodeAction(Ref* n, int a, int b, Ref* o);
    virtual void f();
};
QueuedNodeAction::QueuedNodeAction(Ref* n, int x, int y, Ref* o) : mNode(0), mA(x), mB(y), mOther(0) {
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