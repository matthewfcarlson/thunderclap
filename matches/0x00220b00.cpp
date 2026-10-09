struct Table {
    int x[5];
    int* data;
};
struct Obj {
    Table* table;
    char pad[20];
    int count;
};
void target(Obj* a, int value) {
    a->table->data[a->count - 1] = value;
}
