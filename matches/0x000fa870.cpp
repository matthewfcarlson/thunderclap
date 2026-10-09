struct Item {
    int a;
    Item* next;
    void Append(Item*);
};
struct Hdr {
    int count;
    void First(Item*);
};
struct Lst {
    Hdr* h;
    void Put(Item* it);
};
void Lst::Put(Item* it) {
    static Item* last = it;
    if (h->count == 0) {
        h->First(it);
        last = it;
        return;
    }
    if (last != it) {
        Item* n = last->next;
        if (n) {
            n->Append(it);
            last = it;
            return;
        }
        last->next = it;
    }
    last = it;
}
