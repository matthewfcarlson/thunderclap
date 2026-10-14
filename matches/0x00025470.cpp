extern float gValue_25470;
class Item_25470 {
  public:
    char pad0[0x128];
    int id;
    char pad1[0x20b4 - 0x12c];
    float value;
    void Set(int);
};
class Manager_25470 {
  public:
    Item_25470* Find(int);
};
class Context {
  public:
    char pad[0x44];
    Manager_25470* mgr;
};
class Owner_25470 {
  public:
    Context* ctx;
    char pad[8];
    int count;
    int entries[1];
    void Run(int);
};
void Owner_25470::Run(int id) {
    for (int i = 0; i < count; ++i) {
        Context* c = ctx;
        Manager_25470* m = c->mgr;
        Item_25470* item = m->Find(entries[i]);
        if (item && item->id == id) {
            item->Set(1);
            item->value = gValue_25470;
        }
    }
}