struct Table_220b00 {
    int x[5];
    int* data;
};
struct Obj_220b00 {
    Table_220b00* table;
    char pad[20];
    int count;
};
extern "C" void FUN_00220b00(void * a, int value) {
    ((Obj_220b00 *)a)->table->data[((Obj_220b00 *)a)->count - 1] = value;
}
