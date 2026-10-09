class Item {
  public:
    virtual int A();
    virtual int B();
    virtual int Get();
    int a4;
    int key;
};
class Owner {
  public:
    char a[0x14];
    unsigned count;
    Item** items;
    Item* Find(int key, int value);
};
Item* Owner::Find(int key, int value) {
    unsigned i = 0;
    if (count > 0) {
        do {
            if (key == items[i]->key && value == items[i]->Get())
                return items[i];
            i = i + 1;
        } while (i < count);
    }
    return 0;
}
