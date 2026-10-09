class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x630];
    Thing* ptr;
    bool Set(Thing* p);
};
bool Owner::Set(Thing* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
    return true;
}