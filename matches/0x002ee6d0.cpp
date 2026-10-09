class Item {
  public:
    virtual void Execute();
};
class Container {
  public:
    char pad[0x40];
    unsigned int* current;
    unsigned int* end;
    void Add(Item* item);
};
void Container::Add(Item* item) {
    unsigned int* p = current;
    if (p < end) {
        current = p + 1;
        if (p != 0)
            *p = (unsigned int)item;
    }
    item->Execute();
}