struct Vec3 {
    int x, y, z;
};
struct Item {
    char pad[0x98];
    int a, b, c;
};
struct Holder {
    char pad[0x10];
    int* records;
};
struct Ctx {
  public:
    void* Get(int);
};
struct A {
  public:
    void* Next();
};
struct B {
  public:
    void* Next();
};
struct C {
  public:
    void Run(int*, Vec3*);
};
struct Root {
    char pad[0x1fc];
    Item** items;
    char pad2[8];
    Ctx* context;
    char pad3[0x14];
    Holder* holder;
    void Do(int, Vec3*, char);
};
void Root::Do(int index, Vec3* out, char flag) {
    if (!flag) {
        Item* item = items[index];
        if (item) {
            out->x = item->a;
            out->y = item->b;
            out->z = item->c;
            return;
        }
    }
    void* a = context->Get(index);
    void* b = ((A*)a)->Next();
    void* c = ((B*)b)->Next();
    ((C*)c)->Run(holder->records + index * 7, out);
}