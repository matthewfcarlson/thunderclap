class Ref_2344a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_2344a0 {
  public:
    char pad[4];
    Ref_2344a0* value;
    void Set(Ref_2344a0* p);
};
void Owner_2344a0::Set(Ref_2344a0* p) {
    if (value)
        value->f5(1);
    value = p;
}