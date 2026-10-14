class Thing_ebdd0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_ebdd0 {
  public:
    char pad[0x1d90];
    Thing_ebdd0* ptr;
    void Set(Thing_ebdd0* p);
};
void Owner_ebdd0::Set(Thing_ebdd0* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
}