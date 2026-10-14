struct Sub_30d980 {
    void Process();
};
struct Item_30d980 {
    char pad[0x10];
    Sub_30d980* sub;
};
struct Owner_30d980 {
    char pad[4];
    Item_30d980* begin;
    Item_30d980* end;
    void Target();
};
void Owner_30d980::Target() {
    Item_30d980* p = begin;
    if (p <= end) {
        do {
            p->sub->Process();
            Item_30d980* old = p;
            p = (Item_30d980*)((char*)p + 0x14);
            if (old == end)
                break;
        } while (1);
    }
}