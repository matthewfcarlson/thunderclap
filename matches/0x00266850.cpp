struct Ref_266850 {
    virtual void A();
    virtual void B();
};
struct Owner_266850 {
    char pad[0x1c];
    Ref_266850* member;
    void Set(Ref_266850*);
};
void Owner_266850::Set(Ref_266850* p) {
    if (p)
        p->A();
    if (member)
        member->B();
    member = p;
}