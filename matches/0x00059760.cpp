class Ref_59760 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_59760 {
  public:
    char pad[12];
    Ref_59760* value;
    void Set(Ref_59760* p);
};
void Owner_59760::Set(Ref_59760* p) {
    if (p)
        p->A();
    if (value)
        value->B();
    value = p;
}