// Same code shape as 0x002344a0 (propagated; names are from that function)
class Ref_236b70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_236b70 {
  public:
    char pad[4];
    Ref_236b70* value;
    void Set(Ref_236b70* p);
};
void Owner_236b70::Set(Ref_236b70* p) {
    if (value)
        value->f5(1);
    value = p;
}