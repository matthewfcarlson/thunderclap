struct Item {
    int go();
};
struct Obj {
    char pad[0x10];
    int count;
    Item** items;
    int run();
};
int Obj::run() {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item** base = items;
        Item** p = base;
        do {
            if (*p != 0)
                return base[i]->go();
            ++i;
            ++p;
        } while (i < n);
    }
    return 1;
}
