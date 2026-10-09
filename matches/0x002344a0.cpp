class Ref {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner {
  public:
    char pad[4];
    Ref* value;
    void Set(Ref* p);
};
void Owner::Set(Ref* p) {
    if (value)
        value->f5(1);
    value = p;
}