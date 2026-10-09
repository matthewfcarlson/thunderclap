class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x1d90];
    Thing* ptr;
    void Set(Thing* p);
};
void Owner::Set(Thing* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
}