struct Item {
    void Func(int);
};
struct Obj {
    char pad[0x10];
    int limit;
    int count;
    Item** items;
};
void __stdcall FUN_0029e680(Obj* p) {
    if (p) {
        int i = 0;
        if (p->count > 0)
            do {
                if (i < p->limit) {
                    Item* it = p->items[i];
                    if (it)
                        it->Func(1);
                }
                ++i;
            } while (i < p->count);
    }
}
