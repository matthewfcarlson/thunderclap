class Item {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder {
    char pad[0x14];
    unsigned count;
    Item* slots[4];

  public:
    void Insert(Item* p);
};
void Holder::Insert(Item* p) {
    if (p) {
        unsigned n = count;
        if (n < 4) {
            p->Add();
            if (slots[n])
                slots[n]->Release();
            slots[n] = p;
            ++count;
        }
    }
}