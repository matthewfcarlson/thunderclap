// Same code shape as 0x001b75d0 (propagated; names are from that function)
class Ref_2ddbe0 {
  public:
    virtual void F();
};
class Owner_2ddbe0 {
  public:
    Ref_2ddbe0* mRef;
    Owner_2ddbe0* Set(Ref_2ddbe0* r);
};
Owner_2ddbe0* Owner_2ddbe0::Set(Ref_2ddbe0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}