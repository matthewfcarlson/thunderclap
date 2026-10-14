class X_299ac0 {
  public:
    virtual void A();
    virtual void B();
};
struct Item_299ac0 {
    char pad[8];
    X_299ac0* p;
};
void FUN_00299ac0(Item_299ac0* first, Item_299ac0* last) {
    for (; first != last; ++first) {
        if (first->p) {
            first->p->B();
            first->p = 0;
        }
    }
}