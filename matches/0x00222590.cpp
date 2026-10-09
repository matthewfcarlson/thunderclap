class Obj {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    virtual void Init();
    char pad[12];
    Base();
};
class PartitionDriver : public Base {
  public:
    PartitionDriver(const PartitionDriver* src);
    virtual void Init();
    Obj* mObj;
    int a;
    int b;
    int c;
};
PartitionDriver::PartitionDriver(const PartitionDriver* src) : Base() {
    mObj = 0;
    Obj* p = src->mObj;
    if (p)
        p->A();
    if (mObj)
        mObj->B();
    mObj = p;
    a = src->a;
    b = src->b;
    c = src->c;
}
