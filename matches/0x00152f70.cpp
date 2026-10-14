class Base {
  public:
    Base(float f);
    virtual void V0();
    char pad[0xc];
};
class Obj : public Base {
  public:
    Obj(float f, int x);
    virtual void V0();
    int m10;
};
Obj::Obj(float f, int x) : Base(f) {
    m10 = x;
}
