class Base {
  public:
    virtual ~Base();
    Base(int a);
};
class Obj : public Base {
  public:
    char pad[12];
    int mVal;
    Obj(int a, int b);
};
Obj::Obj(int a, int b) : Base(a) {
    mVal = b;
}
