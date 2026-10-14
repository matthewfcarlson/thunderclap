// STATUS: equivalent (tools/equiv.py level 3: 681 inputs, branch coverage 11/12, incomplete)
// FUN_001062d0 @ 0x001062d0
struct Entry_1062d0 {
    virtual void AddRef();
    char pad04[4];
    int a;
    int b;
};

class EntrySet {
public:
    char pad00[4];
    int capacity;
    int count;
    Entry_1062d0 **items;
    int Add(Entry_1062d0 *item);
};

int EntrySet::Add(Entry_1062d0 *item)
{
    int n = count;
    if (n >= capacity)
        return -1;
    int a = item->a;
    if (n > 0) {
        int i = 0;
        Entry_1062d0 **p = items;
        do {
            Entry_1062d0 *e = *p;
            if (e->a == a && e->b == item->b)
                return -1;
            i++;
            p++;
        } while (i < count);
    }
    items[n] = item;
    items[n]->AddRef();
    count++;
    return n;
}
