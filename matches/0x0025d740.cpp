class Owner;
class Item {
  public:
    virtual void v0();
    virtual void Act(Owner*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Check(Owner*);
};
class Owner {
  public:
    char pad[0x40];
    Item* field;
    char pad2[0x14];
    int state;
    void Run();
};
void Owner::Run() {
    if (field != 0) {
        Item* p = (Item*)((char*)field - 4);
        if (p != 0) {
            int r = p->Check(this);
            if (r == 2 || r == 4)
                p->Act(this);
        }
    }
    state = 3;
}