struct Table_220b00 {
    int x[5];
    int* data;
};
struct Obj_220b00 {
    Table_220b00* table;
    char pad[20];
    int count;
};
void target(Obj_220b00* a, int value) {
    a->table->data[a->count - 1] = value;
}
