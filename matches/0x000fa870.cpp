struct Item_fa870 {
    int a;
    Item_fa870* next;
    void Append(Item_fa870*);
};
struct Hdr_fa870 {
    int count;
    void First(Item_fa870*);
};
struct Lst {
    Hdr_fa870* h;
    void Put(Item_fa870* it);
};
void Lst::Put(Item_fa870* it) {
    static Item_fa870* last = it;
    if (h->count == 0) {
        h->First(it);
        last = it;
        return;
    }
    if (last != it) {
        Item_fa870* n = last->next;
        if (n) {
            n->Append(it);
            last = it;
            return;
        }
        last->next = it;
    }
    last = it;
}
