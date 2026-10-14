// STATUS: equivalent (tools/equiv.py level 3: 681 inputs, branch coverage 11/12, incomplete)
// FUN_001062d0 @ 0x001062d0
struct Entry {
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
    Entry **items;
    int Add(Entry *item);
};

int EntrySet::Add(Entry *item)
{
    int n = count;
    if (n >= capacity)
        return -1;
    int a = item->a;
    if (n > 0) {
        int i = 0;
        Entry **p = items;
        do {
            Entry *e = *p;
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
