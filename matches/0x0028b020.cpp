class Item { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual bool Match(int); };
class List { public: char pad[8]; int count; Item* items[1]; Item* Find(int arg); };
Item* List::Find(int arg) {
    int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Match(arg) == 1)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}