class Owner_25d740;
class Item_25d740 {
  public:
    virtual void v0();
    virtual void Act(Owner_25d740*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Check(Owner_25d740*);
};
class Owner_25d740 {
  public:
    char pad[0x40];
    Item_25d740* field;
    char pad2[0x14];
    int state;
    void Run();
};
void Owner_25d740::Run() {
    if (field != 0) {
        Item_25d740* p = (Item_25d740*)((char*)field - 4);
        if (p != 0) {
            int r = p->Check(this);
            if (r == 2 || r == 4)
                p->Act(this);
        }
    }
    state = 3;
}