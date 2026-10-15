extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
class Item {
  public:
    virtual void AddRef();
};
class List {
    char pad[8];
    int count;
    Item* items[1];

  public:
    void Add(Item* item);
};
void List::Add(Item* item) {
    if (item) {
        memmove(&items[1], &items[0], count * 4);
        items[0] = item;
        item->AddRef();
        ++count;
    }
}