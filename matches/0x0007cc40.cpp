class Item {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class Manager {
  public:
    char pad[0x3800];
    Item* slots[10];
    int count;
    int Search(int, int);
    void Add(Item* item);
};
void Manager::Add(Item* item) {
    int index = Search(*(int*)((char*)item + 8), *(int*)((char*)item + 12));
    if (index < 0 || slots[index] == 0) {
        int n = count;
        if (n != 10) {
            item->A();
            if (slots[n])
                slots[n]->B();
            slots[n] = item;
            ++count;
        }
    }
}