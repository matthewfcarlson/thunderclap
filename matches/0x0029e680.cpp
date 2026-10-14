struct Item_29e680 {
    void Func(int);
};
struct Obj_29e680 {
    char pad[0x10];
    int limit;
    int count;
    Item_29e680** items;
};
void __stdcall FUN_0029e680(Obj_29e680* p) {
    if (p) {
        int i = 0;
        if (p->count > 0)
            do {
                if (i < p->limit) {
                    Item_29e680* it = p->items[i];
                    if (it)
                        it->Func(1);
                }
                ++i;
            } while (i < p->count);
    }
}
