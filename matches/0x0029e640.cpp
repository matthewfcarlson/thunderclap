struct ItemList {
    char pad[0x10];
    int capacity;
    int count;
    void** items;
};
struct Grow_29e640 {
    void FUN_002a1180(int);
};
void __stdcall FUN_0029e640(ItemList* list) {
    if (!list)
        return;
    int n = 0;
    int i = 0;
    while (i < list->count) {
        if (i >= list->capacity || !list->items[i])
            break;
        ++n;
        ++i;
    }
    ((Grow_29e640*)list)->FUN_002a1180(n);
}