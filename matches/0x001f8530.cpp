class Base_1f8530 {
  public:
    virtual void Foo();
};
class Holder_1f8530 {
  public:
    Base_1f8530* ptr;
    Holder_1f8530* Set(Base_1f8530* p);
};
Holder_1f8530* Holder_1f8530::Set(Base_1f8530* p) {
    ptr = p;
    p->Foo();
    return this;
}