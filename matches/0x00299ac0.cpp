class X {
  public:
    virtual void A();
    virtual void B();
};
struct Item {
    char pad[8];
    X* p;
};
void FUN_00299ac0(Item* first, Item* last) {
    for (; first != last; ++first) {
        if (first->p) {
            first->p->B();
            first->p = 0;
        }
    }
}