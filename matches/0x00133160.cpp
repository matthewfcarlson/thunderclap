class Base {
  public:
    virtual void B0();
    char pad[0x18];
    Base() {}
};
class Obj : public Base {
  public:
    int m1c;
    Obj(int x) { m1c = x; }
    char Set(int x);
};
char Obj::Set(int x) {
    m1c = x;
    return 1;
}
