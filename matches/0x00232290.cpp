class Item {
  public:
    virtual void A();
    virtual void B();
    void Handle(Item*);
    float pad[3];
    float value;
};
class Owner {
  public:
    bool Attach(Item* item);
    char pad0[0x1c];
    float amount;
    Item* first;
    Item* second;
};

bool Owner::Attach(Item* item) {
    if (!item)
        return false;
    item->value += amount;
    Item* s0 = second;
    if (s0 == 0) {
        item->A();
        if (first != 0)
            first->B();
        first = item;
    } else {
        s0->Handle(item);
    }
    item->A();
    Item* t = second;
    if (t)
        t->B();
    second = item;
    return true;
}
