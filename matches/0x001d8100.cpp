class Item {
  public:
    virtual void A();
    virtual void B();
    int Get();
    void Act(int);
};
struct Box {
    char pad[0x10];
    int value;
};
struct State : Item {
    char pad[4];
    Item* ptr;
    int state;
};
struct Manager {
    char pad[0xa0];
    Box* box;
    char pad2[0x140];
    State* item;
    void Run();
};
void Manager::Run() {
    State* s = item;
    if (s && s->state == 1) {
        Item* p = s->ptr;
        if (p) {
            int v = box ? box->value : 0;
            if (p->Get() == v)
                p->Act(0);
        }
    }
    if (item) {
        item->B();
        item = 0;
    }
}