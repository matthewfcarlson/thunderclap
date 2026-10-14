// Same code shape as 0x001b75d0 (propagated; names are from that function)
class Ref_1b7670 {
  public:
    virtual void F();
};
class Owner_1b7670 {
  public:
    Ref_1b7670* mRef;
    Owner_1b7670* Set(Ref_1b7670* r);
};
Owner_1b7670* Owner_1b7670::Set(Ref_1b7670* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}