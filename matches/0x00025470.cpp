extern float gValue;
class Item {
  public:
    char pad0[0x128];
    int id;
    char pad1[0x20b4 - 0x12c];
    float value;
    void Set(int);
};
class Manager {
  public:
    Item* Find(int);
};
class Context {
  public:
    char pad[0x44];
    Manager* mgr;
};
class Owner {
  public:
    Context* ctx;
    char pad[8];
    int count;
    int entries[1];
    void Run(int);
};
void Owner::Run(int id) {
    for (int i = 0; i < count; ++i) {
        Context* c = ctx;
        Manager* m = c->mgr;
        Item* item = m->Find(entries[i]);
        if (item && item->id == id) {
            item->Set(1);
            item->value = gValue;
        }
    }
}