class Base_133160 {
  public:
    virtual void B0();
    char pad[0x18];
    Base_133160() {}
};
class Obj_133160 : public Base_133160 {
  public:
    int m1c;
    Obj_133160(int x) { m1c = x; }
    char Set(int x);
};
char Obj_133160::Set(int x) {
    m1c = x;
    return 1;
}
