// Same code shape as 0x001b75d0 (propagated; names are from that function)
class Ref_2fc350 {
  public:
    virtual void F();
};
class Owner_2fc350 {
  public:
    Ref_2fc350* mRef;
    Owner_2fc350* Set(Ref_2fc350* r);
};
Owner_2fc350* Owner_2fc350::Set(Ref_2fc350* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}