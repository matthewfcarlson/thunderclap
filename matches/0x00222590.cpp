class Obj_222590 {
  public:
    virtual void A();
    virtual void B();
};
class Base_222590 {
  public:
    virtual void Init();
    char pad[12];
    Base_222590();
};
class PartitionDriver : public Base_222590 {
  public:
    PartitionDriver(const PartitionDriver* src);
    virtual void Init();
    Obj_222590* mObj;
    int a;
    int b;
    int c;
};
PartitionDriver::PartitionDriver(const PartitionDriver* src) : Base_222590() {
    mObj = 0;
    Obj_222590* p = src->mObj;
    if (p)
        p->A();
    if (mObj)
        mObj->B();
    mObj = p;
    a = src->a;
    b = src->b;
    c = src->c;
}
