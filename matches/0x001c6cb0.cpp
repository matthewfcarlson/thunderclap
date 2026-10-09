// Same code shape as 0x00059760 (propagated; names are from that function)
class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[12];
    Ref* value;
    void Set(Ref* p);
};
void Owner::Set(Ref* p) {
    if (p)
        p->A();
    if (value)
        value->B();
    value = p;
}