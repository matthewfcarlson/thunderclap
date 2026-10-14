class Item_288960 {
  public:
    virtual int A();
    virtual int B();
    virtual int Get();
    int a4;
    int key;
};
class Owner_288960 {
  public:
    char a[0x14];
    unsigned count;
    Item_288960** items;
    Item_288960* Find(int key, int value);
};
Item_288960* Owner_288960::Find(int key, int value) {
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
