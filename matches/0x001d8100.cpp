class Item_1d8100 {
  public:
    virtual void A();
    virtual void B();
    int Get();
    void Act(int);
};
struct Box_1d8100 {
    char pad[0x10];
    int value;
};
struct State_1d8100 : Item_1d8100 {
    char pad[4];
    Item_1d8100* ptr;
    int state;
};
struct Manager_1d8100 {
    char pad[0xa0];
    Box_1d8100* box;
    char pad2[0x140];
    State_1d8100* item;
    void Run();
};
void Manager_1d8100::Run() {
    State_1d8100* s = item;
    if (s && s->state == 1) {
        Item_1d8100* p = s->ptr;
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