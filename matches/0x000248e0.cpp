extern char gEmpty;
struct Sub {
    void* Lookup(int);
};
struct Item {
    void* Get();
};
struct Owner {
    char pad[0x44];
    Sub* sub;
};
struct Thing {
    Owner* owner;
    char pad[8];
    int count;
    int items[69];
    int excluded;
    void* run(int);
};
void* Thing::run(int index) {
    if (index < 0 || index >= count)
        return &gEmpty;
    int found = 0, i = 0;
    if (count > 0) {
        int* p = items;
        do {
            Sub* s = owner->sub;
            Item* v = (Item*)s->Lookup(*p);
            if (v && (int)v != excluded) {
                if (found == index)
                    return v->Get();
                ++found;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return &gEmpty;
}
