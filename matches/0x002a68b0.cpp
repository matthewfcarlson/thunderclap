class Item {
  public:
    virtual void A();
    virtual void Release();
};
void Free(void*);
class Owner {
  public:
    char pad[0x40];
    int x40;
    int x44;
    unsigned int count;
    Item** items;
    void Run();
};
void Owner::Run() {
    unsigned int i = 0;
    if (0 < count) {
        do {
            Item** slot = &items[i];
            Item* p = *slot;
            if (p) {
                p->Release();
                *slot = 0;
            }
            ++i;
        } while (i < count);
    }
    Free(items);
    items = 0;
    x40 = 0;
    x44 = 0;
}
