// Same code shape as 0x001b75d0 (propagated; names are from that function)
class Ref_1b76c0 {
  public:
    virtual void F();
};
class Owner_1b76c0 {
  public:
    Ref_1b76c0* mRef;
    Owner_1b76c0* Set(Ref_1b76c0* r);
};
Owner_1b76c0* Owner_1b76c0::Set(Ref_1b76c0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}