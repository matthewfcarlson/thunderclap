struct Vec3_310490 {
    int x, y, z;
};
struct Item_310490 {
    char pad[0x98];
    int a, b, c;
};
struct Holder_310490 {
    char pad[0x10];
    int* records;
};
struct Ctx_310490 {
  public:
    void* Get(int);
};
struct A_310490 {
  public:
    void* Next();
};
struct B_310490 {
  public:
    void* Next();
};
struct C_310490 {
  public:
    void Run(int*, Vec3_310490*);
};
struct Root_310490 {
    char pad[0x1fc];
    Item_310490** items;
    char pad2[8];
    Ctx_310490* context;
    char pad3[0x14];
    Holder_310490* holder;
    void Do(int, Vec3_310490*, char);
};
void Root_310490::Do(int index, Vec3_310490* out, char flag) {
    if (!flag) {
        Item_310490* item = items[index];
        if (item) {
            out->x = item->a;
            out->y = item->b;
            out->z = item->c;
            return;
        }
    }
    void* a = context->Get(index);
    void* b = ((A_310490*)a)->Next();
    void* c = ((B_310490*)b)->Next();
    ((C_310490*)c)->Run(holder->records + index * 7, out);
}