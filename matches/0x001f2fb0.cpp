class Item_1f2fb0 {
  public:
    char pad[16];
    int key;
};
class Container_1f2fb0 {
  public:
    char pad0[8];
    Item_1f2fb0* items[32];
    int count;
    Item_1f2fb0* excluded;
    Item_1f2fb0* Find(int key);
};
Item_1f2fb0* Container_1f2fb0::Find(int key) {
    int i = 0;
    if (count > 0) {
        Item_1f2fb0** p = items;
        do {
            Item_1f2fb0* item = *p;
            if (item->key == key && item != excluded)
                return items[i];
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}