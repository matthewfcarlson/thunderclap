class Ref {
  public:
    virtual void A();
    virtual void B();
};
class OldBillboardObjectLoader : public Ref {
  public:
    virtual void v0();
    virtual void v1();
    virtual OldBillboardObjectLoader* v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x14 - sizeof(Ref)];
    Ref* volatile mRef;
};
extern void __cdecl thunk(OldBillboardObjectLoader*);
OldBillboardObjectLoader* OldBillboardObjectLoader::v2(int flags) {
    *(volatile int*)this = 0x42e7f0;
    Ref* r = mRef;
    if (r) {
        r->B();
        mRef = 0;
    }
    *(volatile int*)this = 0x3f6098;
    if (flags & 1)
        thunk(this);
    return this;
}