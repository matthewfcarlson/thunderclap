class Item_232290 {
  public:
    virtual void A();
    virtual void B();
    void Handle(Item_232290*);
    float pad[3];
    float value;
};
class Owner_232290 {
  public:
    bool Attach(Item_232290* item);
    char pad0[0x1c];
    float amount;
    Item_232290* first;
    Item_232290* second;
};

bool Owner_232290::Attach(Item_232290* item) {
    if (!item)
        return false;
    item->value += amount;
    Item_232290* s0 = second;
    if (s0 == 0) {
        item->A();
        if (first != 0)
            first->B();
        first = item;
    } else {
        s0->Handle(item);
    }
    item->A();
    Item_232290* t = second;
    if (t)
        t->B();
    second = item;
    return true;
}
