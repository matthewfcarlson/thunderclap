class Item { public: char pad[16]; int key; };
class Container { public: char pad0[8]; Item* items[32]; int count; Item* excluded; Item* Find(int key); };
Item* Container::Find(int key) {
    int i = 0;
    if (count > 0) {
        Item** p = items;
        do {
            Item* item = *p;
            if (item->key == key && item != excluded)
                return items[i];
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}