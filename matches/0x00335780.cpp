struct Item {
    char pad[8];
    int type;
};
struct Manager {
    char pad[0x44];
    int count;
    Item* get(int);
};
struct Obj {
    char pad[4];
    Manager* mgr;
    int** entries;
    char fn(int index, int* x, int* y, int* z);
};
char Obj::fn(int index, int* x, int* y, int* z) {
    if (index < 0)
        return 0;
    if (index >= mgr->count)
        return 0;
    if (mgr->get(index)->type != 8)
        return 0;
    int* v = entries[index];
    *x = *v;
    *y = *(++v);
    *z = *(++v);
    return 1;
}