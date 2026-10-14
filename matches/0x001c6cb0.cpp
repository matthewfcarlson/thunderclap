// Same code shape as 0x00059760 (propagated; names are from that function)
class Ref_1c6cb0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1c6cb0 {
  public:
    char pad[12];
    Ref_1c6cb0* value;
    void Set(Ref_1c6cb0* p);
};
void Owner_1c6cb0::Set(Ref_1c6cb0* p) {
    if (p)
        p->A();
    if (value)
        value->B();
    value = p;
}