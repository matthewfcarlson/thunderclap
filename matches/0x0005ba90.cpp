class Base {
  public:
    Base(int a);
    virtual void V0();
    char pad[0xc];
};
class Obj : public Base {
  public:
    Obj(int a, int b);
    virtual void V0();
    int m10;
};
Obj::Obj(int a, int b) : Base(a), m10(b) {}
